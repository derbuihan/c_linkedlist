#include <stdio.h>

#include "linkedlist.h"

void printLinkedList(LinkedList *linkedlist) {
  for (Node *node = linkedlist->head; node; node = node->next) {
    printf("%d -> ", node->data);
  }
  printf("NULL\n");
}

int main(void) {
  printf("Hello, World!\n");

  LinkedList *list = newLinkedList();

  // append
  appendLinkedList(list, 11);
  appendLinkedList(list, 22);
  printLinkedList(list);

  // insert
  insertLinkedList(list, 1, 33);
  printLinkedList(list);

  // extend
  LinkedList *other = newLinkedList();
  appendLinkedList(other, 44);
  appendLinkedList(other, 55);
  extendLinkedList(list, other);
  printLinkedList(list);

  // remove
  removeLinkedList(list, 44);
  printLinkedList(list);

  // pop
  popLinkedList(list, 1);
  printLinkedList(list);

  // clear
  clearLinkedList(list);
  printLinkedList(list);

  // index
  appendLinkedList(list, 66);
  appendLinkedList(list, 77);
  appendLinkedList(list, 88);
  int i = indexLinkedList(list, 77);
  printLinkedList(list);
  printf("Index of 77: %d\n", i);

  // count
  appendLinkedList(list, 77);
  int c = countLinkedList(list, 77);
  printf("Count of 77: %d\n", c);

  // sort
  printLinkedList(list);
  sortLinkedList(list);
  printLinkedList(list);

  // reverse
  printLinkedList(list);
  reverseLinkedList(list);
  printLinkedList(list);

  // copy
  LinkedList *new_list = copyLinkedList(list);
  printLinkedList(new_list);
  freeLinkedList(new_list);

  freeLinkedList(list);

  return 0;
}
