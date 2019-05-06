/* Pointer assignments program */

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

int get_length(struct node* head) {
  int length = 0;
  while (head != NULL) {
    length++;
    head = head->next;
  }

  return length;
}

void print_list(struct node* head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void append_data(struct node** headRef, int data) {
  assert(headRef != NULL);
  if (*headRef == NULL) {
   *headRef = (struct node*)malloc(sizeof(struct node));
   (*headRef)->data = data;
   (*headRef)->next = NULL;
   (*headRef)->prev = NULL;
   return;
  } 

  struct node* head = *headRef;
  while (head->next != NULL) {
    head = head->next;
  }

    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = data;
    head->next->next = NULL;
    head->next->prev = head;
}

void delete_node(struct node** headRef, int data) {
  assert(headRef != NULL);

  struct node* head = *headRef;
  while (head != NULL && head->data != data) {
    head = head->next;
  }

  if (head == NULL) {
    return;
  }

  // head will point to the node which should be deleted.
  if (head->prev != NULL) {
    head->prev->next = head->next;
  } else {
    *headRef = head->next;
  }

  if (head->next != NULL) {
    head->next->prev = head->prev;
  }
  
  head->prev = NULL;
  head->next = NULL;
  free(head);
}

int main() {
  struct node* head = NULL;
 
  append_data(&head, 4);
  append_data(&head, 5);
  append_data(&head, 6);
  print_list(head);
  
  delete_node(&head, 6);
  print_list(head);
}
