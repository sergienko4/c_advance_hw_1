#include "Node.h";
#include <stdio.h>;
#include <stdlib.h>;

NodeR* createNodeR(int value) {
	NodeR* p = (NodeR*)malloc(sizeof(NodeR));
	p->value = value;
	p->next = NULL;
}

void addNodeTail(NodeR* next, NodeR** head) {

	if (*head == NULL) {
		head = next;
	}
	else {
		while ((*head)->next != NULL)
		{
			(*head) = (*head)->next;
		}
		(*head)->next = next;
	}
}


