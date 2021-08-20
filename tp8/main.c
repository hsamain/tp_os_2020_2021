#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define N_PHILOSOPHERS 5
#define LEFT(i)  ((i + 1) % N_PHILOSOPHERS)
#define RIGHT(i) ((i - 1) % N_PHILOSOPHERS)

enum State
{
    THINKING,
    HUNGRY,
    EATING
};

pthread_t philosophers[N_PHILOSOPHERS];
pthread_mutex_t table = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t can_eat[N_PHILOSOPHERS];
enum State states[N_PHILOSOPHERS];

void try(int id)
{
    if (states[id] == HUNGRY && states[LEFT(id)] != EATING && states[RIGHT(id)] != EATING) {
        states[id] = EATING;
        pthread_mutex_unlock(&can_eat[id]);

        printf("Philosopher %d is eating\n", id);
        sleep(rand() % 5);
    }
}

void take(int id)
{
    printf("Philosopher %d is hungry\n", id);

    pthread_mutex_lock(&table);
    states[id] = HUNGRY;
    try(id);
    pthread_mutex_unlock(&table);
    pthread_mutex_lock(&can_eat[id]);
}

void drop(int id)
{
    pthread_mutex_lock(&table);
    states[id] = THINKING;
    try(LEFT(id));
    try(RIGHT(id));
    pthread_mutex_unlock(&table);
}

void* philosopher(void* id)
{
    for (;;) {
        printf("Philosopher %d is thinking\n", id);
        sleep(rand() % 10);

        take((int)id);
        drop((int)id);
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    for (int id = 0; id < N_PHILOSOPHERS; ++id) {
        pthread_create(&philosophers[id], NULL, &philosopher, (void*)id);
    }

    for (int id = 0; id < N_PHILOSOPHERS; ++id) {
        pthread_join(philosophers[id], NULL);
    }

    return 0;
}
