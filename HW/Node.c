#include "Node.h";
#include <stdio.h>;
#include <stdlib.h>;

NodeR* createNodeR(int value) {
	NodeR* p = (NodeR*)malloc(sizeof(NodeR));
	p->value = value;
	p->next = NULL;
	return p;
}

void addNodeTail(NodeR* next, NodeR** head) {

	NodeR* temp = (*head);
	if (temp == NULL) {
		*head = createNodeR(next->value);
	}
	else {
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = createNodeR(next->value);
	}
}

void addNodeHead(NodeR* next, NodeR** head) {
	NodeR* temp = createNodeR(next->value);
	temp->next = (*head);
	*head = temp;
}


