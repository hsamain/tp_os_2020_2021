#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

char* copy_string(const char* string)
{
  char* new = (char*)malloc(sizeof(char) * (strlen(string) + 1));
  strcpy(new, string);
  
  return new;
}

Node* new_node(const char* key, const char* value)
{
  Node* node = (Node*)malloc(sizeof(Node));
  
  node->key = copy_string(key);
  node->value = copy_string(value);
  node->prev = NULL;
  node->next = NULL;
  
  return node;
}

void delete_node(Node* node, int recursive)
{
  if (recursive && node->next != NULL) {
    /* Recursive call to delete every subsequent node */
    delete_node(node->next, 1);
  }
  
  free(node->key);
  free(node->value);
  free(node);
}

List* new_list(void)
{
  List* list = (List*)malloc(sizeof(List));
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  
  return list;
}

void delete_list(List* list)
{
  if (list->first != NULL) {
    delete_node(list->first, 1);
  }
  
  free(list);
}

int list_empty(const List* list)
{
  return list->size == 0;
}

void list_add(List* list, int index, const char* key, const char* value)
{
  if (index >= 0 && index <= list->size) {
    Node* node = new_node(key, value);
    
    if (index == 0) {
      node->next = list->first;
      list->first = node;
    }
    
    else {
      Node* prev = list->first;
      Node* next;
      
      while (--index > 0) {
        prev = prev->next;
      }
      
      next = prev->next;
      
      if (next != NULL) {
        next->prev = node;
      }
      
      prev->next = node;
      node->next = next;
      node->prev = prev;
    }
    
    if (index == list->size++) {
      list->last = node;
    }
  }
}

void list_add_head(List* list, const char* key, const char* value)
{
  list_add(list, 0, key, value);
}

void list_add_tail(List* list, const char* key, const char* value)
{
  list_add(list, list->size, key, value);
}

void list_remove(List* list, int index)
{
  if (index >= 0 && index < list->size) {
    Node* node;

    if (index == 0) {
      node = list->first;
      list->first = list->first->next;
      
      if (list->first != NULL) {
        list->first->prev = NULL;
      }
    }
    
    else {
      Node* prev = list->first;
      Node* next;
      while (--index > 0) {
        prev = prev->next;
      }
      
      node = prev->next;
      next = node->next;
      prev->next = next;
      
      if (next != NULL) {
        next->prev = prev;
      }
    }
    
    if (index == --list->size) {
      list->last = node->prev;
    }
   
    delete_node(node, 0);
  }
}

void list_remove_head(List* list)
{
  list_remove(list, 0);
}

void list_remove_tail(List* list)
{
  list_remove(list, list->size - 1);
}

void list_remove_key(List* list, const char* word)
{
  list_remove(list, list_search(list, word));
}

int list_search(const List* list, const char* key)
{
  Node* node = list->first;
  int index = 0;
  
  while (node != NULL) {
    if (strcmp(key, node->key) == 0) {
      return index;
    }
    
    node = node->next;
    ++index;
  }
  
  return -1;
}

List* list_copy(const List* list)
{
  List* new = new_list();
  
  Node* node = list->first;
  while (node != NULL) {
    list_add_tail(new, node->key, node->value);
    node = node->next;
  }
  
  return new;
}

void list_sort(List* list)
{
  /* Insertion sort algorithm */
  Node* node1 = list->first;
  Node* head = NULL;
  Node* tail = NULL;
      
  while (node1 != NULL) {
    Node* node2 = head;
    Node* prev = NULL;
    Node* temp = node1;
    
    while (node2 != NULL && strcmp(node1->key, node2->key) > 0) {
      prev = node2;
      node2 = node2->next;
    }
    
    node1 = node1->next;
    temp->next = node2;
    temp->prev = prev;
    
    if (prev == NULL) {
      head = temp;
    }
    else {
      prev->next = temp;
    }
    
    if (temp->next == NULL) {
      tail = temp;
    }
    else {
      temp->next->prev = temp;
    }
  }
  
  list->first = head;
  list->last = tail;
}

void list_show(const List* list)
{
  Node* node = list->first;
  int page = 0;
  
  while (node != NULL) {
    int i;
    for (i = 0; i < 10 && node != NULL; ++i) {
      printf("%d. \"%s\": \"%s\"\n", i + page * 10, node->key, node->value);
      node = node->next;
    }
    
    getchar(); /* input pause */
    ++page;
  }
}

void list_menu(List* list)
{
  int choice;
  int index;
  char key[1024];
  char value[1024];

  for (;;) { /* endless loop */
    printf(" 0. Exit\n"
           " 1. Insert item at index\n"
           " 2. Insert head\n"
           " 3. Insert tail\n"
           " 4. Remove item at index\n"
           " 5. Remove head\n"
           " 6. Remove tail\n"
           " 7. Remove item by key\n"
           " 8. Search index by key\n"
           " 9. Sort list\n"
           "10. Show list\n"
           "> ");
    
    scanf("%d", &choice);
  
    switch (choice) {
      case 1:
        printf("Index: ");  scanf("%d", &index);
        printf("Key: ");    scanf("%s", key);
        printf("Value: ");  scanf("%s", value);
        list_add(list, index, key, value);
        break;
        
      case 2:
        printf("Key: ");    scanf("%s", key);
        printf("Value: ");  scanf("%s", value);
        list_add_head(list, key, value);
        break;
        
      case 3:
        printf("Key: ");    scanf("%s", key);
        printf("Value: ");  scanf("%s", value);
        list_add_tail(list, key, value);
        break;
      
      case 4:
        printf("Index: ");  scanf("%d", &index);
        list_remove(list, index);
        break;
      
      case 5:
        list_remove_head(list);
        break;
      
      case 6:
        list_remove_tail(list);
        break;
      
      case 7:
        printf("Key: ");    scanf("%s", key);
        list_remove_key(list, key);
        break;
      
      case 8:
        printf("Key: ");    scanf("%s", key);
        printf("The index of \"%s\" is %d\n", key, list_search(list, key));
        break;
      
      case 9:
        list_sort(list);
        break;
       
      case 10:
        list_show(list);
        break;
      
      default:
        return;
    }
    
    printf("\n");
  }
}
