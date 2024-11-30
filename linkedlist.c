#include "linkedlist.h"

#include <stdlib.h>

static Node *newNode(int data) {
  Node *node = malloc(sizeof(Node));

  node->data = data;
  node->next = NULL;

  return node;
}

static void freeNode(Node *node) { free(node); }

LinkedList *newLinkedList() {
  LinkedList *linkedlist = malloc(sizeof(LinkedList));
  linkedlist->head = NULL;

  return linkedlist;
}

void freeLinkedList(LinkedList *linkedlist) {
  Node *node = linkedlist->head;
  while (node != NULL) {
    Node *next = node->next;
    freeNode(node);
    node = next;
  }

  free(linkedlist);
}

void appendLinkedList(LinkedList *linkedlist, int data) {
  Node *node = newNode(data);

  if (linkedlist->head == NULL) {
    linkedlist->head = node;
    return;
  }

  Node *last = linkedlist->head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = node;
}

static Node *copyNode(Node *node) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = node->data;
  new_node->next = NULL;

  return new_node;
}

void extendLinkedList(LinkedList *linkedlist, LinkedList *other) {
  Node *end = linkedlist->head;
  while (end->next != NULL) {
    end = end->next;
  }

  Node *curr = other->head;
  while (curr != NULL) {
    end = end->next = copyNode(curr);
    curr = curr->next;
  }
}

void insertLinkedList(LinkedList *linkedlist, int index, int data) {
  Node *node = newNode(data);

  if (index == 0) {
    node->next = linkedlist->head;
    linkedlist->head = node;
    return;
  }

  Node *curr = linkedlist->head;
  for (int i = 0; i < index - 1; i++) {
    if (curr->next == NULL) {
      break;
    }
    curr = curr->next;
  }

  node->next = curr->next;
  curr->next = node;
}

void removeLinkedList(LinkedList *linkedlist, int data) {
  Node *curr = linkedlist->head;

  if (curr->data == data) {
    linkedlist->head = curr->next;
    freeNode(curr);
    return;
  }

  while (curr->next != NULL) {
    Node *temp = curr->next;
    if (temp->data == data) {
      curr->next = temp->next;
      freeNode(temp);
      return;
    }
    curr = curr->next;
  }
}

void popLinkedList(LinkedList *linkedlist, int index) {
  if (index < 0 || linkedlist->head == NULL) {
    return;
  }

  if (index == 0) {
    Node *temp = linkedlist->head;
    linkedlist->head = temp->next;
    freeNode(temp);
    return;
  }

  Node *curr = linkedlist->head;
  for (int i = 0; i < index - 1; i++) {
    if (curr->next == NULL) {
      return;
    }
    curr = curr->next;
  }

  Node *temp = curr->next;
  curr->next = temp->next;
  freeNode(temp);
}

void clearLinkedList(LinkedList *linkedlist) {
  Node *curr = linkedlist->head;
  while (curr != NULL) {
    Node *temp = curr;
    curr = curr->next;
    freeNode(temp);
  }
  linkedlist->head = NULL;
}

int indexLinkedList(LinkedList *linkedlist, int data) {
  Node *curr = linkedlist->head;

  for (int i = 0; curr != NULL; i++) {
    if (curr->data == data) {
      return i;
    }
    curr = curr->next;
  }

  return -1;
}

int countLinkedList(LinkedList *linkedlist, int data) {
  Node *curr = linkedlist->head;
  int count = 0;

  while (curr != NULL) {
    if (curr->data == data) {
      count++;
    }
    curr = curr->next;
  }

  return count;
}

void sortLinkedList(LinkedList *linkedlist) {
  Node *curr = linkedlist->head;

  while (curr != NULL) {
    Node *node = curr->next;

    while (node != NULL) {
      if (curr->data > node->data) {
        int temp = curr->data;
        curr->data = node->data;
        node->data = temp;
      }
      node = node->next;
    }
    curr = curr->next;
  }
}

void reverseLinkedList(LinkedList *linkedlist) {
  Node *prev = NULL;
  Node *curr = linkedlist->head;
  Node *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  linkedlist->head = prev;
}

LinkedList *copyLinkedList(LinkedList *linkedlist) {
  Node *curr = linkedlist->head;

  Node head = {};
  Node *end = &head;
  while (curr != NULL) {
    end = end->next = copyNode(curr);
    curr = curr->next;
  }
  LinkedList *new_linkedlist = newLinkedList();
  new_linkedlist->head = head.next;

  return new_linkedlist;
}
