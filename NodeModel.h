#pragma once

typedef struct record{
	int i;
	int j;
	int value;
}Record;

typedef struct node{
	Record* value;
	struct node* next;
}Node;

Node* createNode(int i, int j);
void addNode(Node* next, Node** head);