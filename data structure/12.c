#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode {
  element data;
  struct ListNode* link;
} ListNode;

void error(char* message){
  fprintf(stderr, "%s\n", message);
  exit(1);
}

ListNode* insert_first(ListNode* head, element value){
  ListNode* p = (ListNode*)malloc(sizeof(ListNode));
  p->data = value;
  p->link = head;
  head = p;
  return head;
}

void print_list(ListNode* head){
  for (ListNode* p = head; p != NULL; p = p->link)
    printf("%d->", p->data);
  printf("NULL \n");
}

ListNode* reverse(ListNode* head){
  ListNode *p, *q, *r;
  p = head;
  q = NULL;
  while (p != NULL) {
    r=q;
    q=p;
    p=p->link;
    q->link = r;
  }
  return q;
}

int main(void)
{
  ListNode* head = NULL;
  
  printf(
