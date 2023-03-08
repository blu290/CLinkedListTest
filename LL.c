#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *makeNode(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void addData(struct Node *node, int data) {
  if (node->next == NULL)
    node->next = makeNode(data);
  else
    addData(node->next, data);
}

void printList(Node *node) {
  printf("[");
  while (node != NULL) {
    printf("%d", node->data);
    node = node -> next;
    if(node != NULL)
      printf(",");
  }
  printf("]\n");
}

int getElemAtIndex(Node *head, int index) {
  if (index == 0)
    return head->data;
  else
    return getElemAtIndex(head->next, index - 1);
}
int deleteHead(Node **head) {
  if (*head == NULL)
    return -1;
  Node *toDelete = *head;
  *head = (*head)->next;
  free(toDelete);
  return 0;
}

int delValue(Node **head, int value) {
  Node *current = *head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->data == value) {
      if (previous == NULL) {
        deleteHead(head);
        return 0;
      } else {
        previous->next = current->next;
        free(current);
        return 0;
      }
    }
    previous = current;
    current = current->next;
  }
  return -1;
}
int delIndex(Node **head, int index) {
  Node *current = *head;
  Node *previous = NULL;
  for (int i = index; i >= 0; i--) {
    if (i == 0) {
      if (previous == NULL) {
        deleteHead(head);
        return 0;
      } else {
        previous->next = current->next;
        free(current);
        return 0;
      }
    }

    if (current == NULL)
      return -1;
    previous = current;
    current = current->next;
  }
}
int length(Node* head){
  Node* current = head;
  int count = 0;
  while(current != NULL){
    count++;
    current = current -> next;
  }
  return count;
}
int main(void) {
  Node * head = makeNode(rand()%1000);
  for(int i = 0;i<=5000;i++){
    addData(head,rand()%1000);
  }
  printList(head);
  return 0;
}