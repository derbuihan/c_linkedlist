#ifndef C_LINKEDLIST_LINKEDLIST_H
#define C_LINKEDLIST_LINKEDLIST_H

typedef struct Node Node;

struct Node {
  int data;
  Node *next;
};

typedef struct LinkedList LinkedList;

struct LinkedList {
  Node *head;
};

LinkedList *newLinkedList(int arr[], int size);

void freeLinkedList(LinkedList *linkedlist);

void appendLinkedList(LinkedList *linkedlist, int data);

void extendLinkedList(LinkedList *linkedlist, LinkedList *other);

void insertLinkedList(LinkedList *linkedlist, int index, int data);

void removeLinkedList(LinkedList *linkedlist, int data);

void popLinkedList(LinkedList *linkedlist, int index);

void clearLinkedList(LinkedList *linkedlist);

int indexLinkedList(LinkedList *linkedlist, int data);

int countLinkedList(LinkedList *linkedlist, int data);

void sortLinkedList(LinkedList *linkedlist);

void reverseLinkedList(LinkedList *linkedlist);

LinkedList *copyLinkedList(LinkedList *linkedlist);

#endif  // C_LINKEDLIST_LINKEDLIST_H
