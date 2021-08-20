#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/* Structs */
struct Node_ {
  char* key;
  char* value;
  struct Node_* prev;
  struct Node_* next;
};

struct List_ {
  int size;
  struct Node_* first;
  struct Node_* last;
};

typedef struct Node_ Node; /* to avoid writing "struct" everywhere */
typedef struct List_ List;

/* Functions */
char* copy_string(const char* string);

Node* new_node(const char* key, const char* value);

void delete_node(Node* node, int recursive);

List* new_list(void);

void delete_list(List* list);

int list_empty(const List* list);

void list_add(List* list, int index, const char* key, const char* value);

void list_add_head(List* list, const char* key, const char* value);

void list_add_tail(List* list, const char* key, const char* value);

void list_remove(List* list, int index);

void list_remove_head(List* list);

void list_remove_tail(List* list);

void list_remove_key(List* list, const char* key);

int list_search(const List* list, const char* key);

List* list_copy(const List* list);

void list_sort(List* list);

void list_show(const List* list);

void list_menu(List* list);

#endif
