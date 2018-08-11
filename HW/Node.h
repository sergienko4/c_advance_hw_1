#pragma once


typedef struct nodeR {
	int value;
	struct nodeR* next;
}NodeR;

NodeR* createNodeR(int value);
void addNodeTail(NodeR* next, NodeR** head);
void addNodeHead(NodeR* next, NodeR** head);