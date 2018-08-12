#include "NodeModel.h";
#include <stdio.h>;
#include <stdlib.h>;

Node* createNode(int i, int j){
  Node* p = (Node*)malloc(sizeof(Node));
  Record* r = (Record*)malloc(sizeof(Record));
  p->value = r;
  p->value->i = i;
  p->value->j = j;
  p->value->value= i + j;
  p->next= NULL;
}

void addNode(Node* next, Node** head){
		next->next = *head;
		*head = next;
}


