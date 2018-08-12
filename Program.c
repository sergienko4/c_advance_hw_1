#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "NodeModel.h"
#include "Node.h"

#define M 3
#define N 2
#define P 4

int** createMatrix(int coll, int row);
void FreeForMatrix(int** matrix, int row, int col);
void FreeForNodeR(NodeR** list);
int getNumber();
void printNodeR(NodeR* head);


void printMatrix(int*** matrix, int row, int col);

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

int** multyplayMatrix(int matrixA[M][N], int matrixB[N][P]);
unsigned int * powerArray(int length);
int scanMatrixToNode(int** matrix, int row, int col, Record** list, Node** head);
void insertDataToMatrix(int** matrix, int row, int col);
NodeR* initNode();
NodeR* SplitNodeToOdd(NodeR** sourceHead);
NodeR* SplitNodeToOddByRef(NodeR** sourceHead);



void main() {
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;

}
void Ex1() {

	int length, i;
	unsigned int* p;


	length = getNumber();
	
	// from 2^0 to 2^length
	length++;
	
	p = powerArray(length);


	for (i = 0; i < length; i++) {
		printf("index: %3d -> 2^%3d: = %u\n", i, (i % 32), p[i]);
	}

	free(p);
}
void Ex2() {

	int** multypliedMatrix;
	int matrixA[M][N] = { 
							{ 1, 5 },
							{ 4, 4 },
							{ 2, 3 } };
	int matrixB[N][P] = { { 1, 5, 6,5 },
						  { 4, 4, 8,8 }};


	multypliedMatrix = multyplayMatrix(matrixA, matrixB);

	// print result
	printMatrix(&multypliedMatrix, M,P);
	// free memory
	FreeForMatrix(multypliedMatrix,M, P);

}
void Ex3() {
	int** matrix;
	int row, col, arrayLength;
	Record* list = NULL;
	Node* head = NULL;
	Node* headT;

	printf("number of rows ");
	row = getNumber();
	printf("number of col ");
	col = getNumber();

	// get matrix
	matrix = createMatrix(row,col);

	//init matrix
	insertDataToMatrix(matrix, row, col);
	// print matrix 
	printMatrix(&matrix,row,col);
	
	// get length node
	arrayLength = scanMatrixToNode(matrix, row, col, &list, &head);

	FreeForMatrix(matrix, row, col);

	// print node and free memory 
	printf("Print List: \n");
	while (head != NULL) {
		printf("value: %d i: %d j:%d \n",head->value->value, head->value->i, head->value->j);
		
		headT = head->next;
		free(head->value);
		free(head);
		head = headT;
	}

	
}
void Ex4() {
	NodeR* head = NULL;
	NodeR* headOdd = NULL;

	head = initNode();
	// print after init 
	printNodeR(head);
	
	// print odd by value 
	headOdd = SplitNodeToOdd(&head);
	
	// print head 
	printNodeR(head);
	// print odd by value 
	printNodeR(headOdd);

	FreeForNodeR(&head);
	FreeForNodeR(&headOdd);
}
void Ex5() {
	NodeR* head = NULL;
	NodeR* headOdd = NULL;

	head = initNode();
	
	// print after init 
	printNodeR(head);


	headOdd = SplitNodeToOddByRef(&head);

	// print head 
	printNodeR(head);
	// print odd by value 
	printNodeR(headOdd);


	FreeForNodeR(&head);
	FreeForNodeR(&headOdd);
}



unsigned int* powerArray(int length) {
	unsigned int value;
	int i;
	int base = 2;
	unsigned int *p = (unsigned int *)malloc(sizeof(unsigned int)*length);

	if (p == NULL) {
		printf("Not enoght memory");
		return NULL;
	}
	else {

		p[0] = 1;
		for (i = 1; i < length; i++) {
			if (i < 32) {
				value = (p[i - 1] * base);
				p[i] = value;
			}
			else {
				p[i] = (unsigned int)p[i % 32];
			}
		}

	}
	return p;
}
int** multyplayMatrix(int matrixA[M][N], int matrixB[N][P]) {
	int** multypliedMatrix;
	int i, j, k, value;

	// get new matrix (dynamic) 
	multypliedMatrix = createMatrix(M, P);
	
	//  print before
	printMatrix(&multypliedMatrix, M,P);


	// multiply
	for(i = 0; i < M; ++i)
	{
		for(j = 0; j < P; ++j)
		{
			for(k=0; k<N; ++k)
			{
				multypliedMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	
	return multypliedMatrix;
}
void printMatrix(int*** matrix, int row , int col) {
	int i, j, value;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%3d", *(*(*matrix + i) + j));
		}
		printf("\n");
	}
	printf("_______________________________________________\n");
}
void insertDataToMatrix(int** matrix, int row, int col) {

	int i, j;
	int input;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("Enter value to index %d (row)  x %d (col) \n", i + 1, j + 1);
			scanf("%d", &input);
			matrix[i][j] = input;
		}
	}
}
int scanMatrixToNode(int** matrix, int row, int col, Record** list, Node** head) {

	Record* temp1;
	Node* headT;
	int i, j, index = 0, count = 0;

	//run matrix
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			// check the vlue to parten
			if (matrix[i][j] == i + j) {
				addNode(createNode(i, j), head);
				count++;
			}
		}
	}

	if (count == 0)
		return count;


	// create array of node
	*list = (Record*)calloc(count, sizeof(Record));


	// coppy values to array
	headT = *head;
	while (count != index) {
		*(list + index) = (Record*)malloc(sizeof(Record));
		(*list)[index].i = headT->value->i;
		(*list)[index].j = headT->value->j;
		(*list)[index].value = headT->value->value;

		headT = headT->next;
		index++;
	}

	return count;
}
int** createMatrix(int row, int col) {
	int i;
	int** multypliedMatrix;

	// get pointer for metrix
	multypliedMatrix = (int**)malloc(row*(sizeof(int**)));

	// create matrix 
	for (i = 0; i < row; i++) {
		multypliedMatrix[i] = (int*)calloc(col, (sizeof(int)));
	}

	return multypliedMatrix;
}
void FreeForMatrix(int** matrix, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}
void FreeForNodeR(NodeR** list) {

	NodeR* temp;
	while (*list != NULL) {
		temp = *list;
		(*list) = temp->next;
		free(temp);
	}

}
NodeR* initNode() {
	NodeR* headT = NULL;
	NodeR* head = NULL;
	int value = 0;


	while (value != -1) {

		printf("enter number, for exit enter -1\n");
		scanf("%d", &value);
		printf("Got %d \n", value);

		
		if (value != -1) {
			headT = createNodeR(value);

			if (head == NULL) {
				head = headT;
			}
			else
			{
				addNodeTail(headT, &head);
			}
		}

	}

	return head;

}
NodeR* SplitNodeToOdd(NodeR** sourceHead) {
	NodeR* newList = NULL;
	NodeR* toFree = NULL;

	NodeR* temp = *sourceHead;

	while (temp != NULL && temp->next != NULL) {
		if (temp->next->value % 2 == 1) {
			addNodeTail(temp->next, &newList);
			toFree = temp->next;
			temp->next = temp->next->next;
			free(toFree);
		}
		else {
			temp = temp->next;
		}
	}

	// for first chain
	if ((*sourceHead) != NULL && (*sourceHead)->value % 2 == 1) {
		addNodeHead(*sourceHead, &newList);
		toFree = *sourceHead;
		*sourceHead = (*sourceHead)->next;
		free(toFree);
	}

	return newList;
}
NodeR* SplitNodeToOddByRef(NodeR** sourceHead) {
	NodeR* newList = NULL;
	NodeR* toFree = NULL;
	NodeR* newListT = NULL;
	NodeR* temp = *sourceHead;

	while (temp != NULL && temp->next != NULL) {
		if (temp->next->value % 2 == 1) {
			if (newList == NULL) {
				newListT = temp->next;
				newList = newListT;
				temp->next = temp->next->next;
				newList->next = NULL;
			}
			else {
				newListT->next = temp->next;
				newListT = newListT->next;
				temp->next = temp->next->next;
				newListT->next = NULL;
			}
		}
		else {
			temp = temp->next;
		}
	}

	// for first chain
	if ((*sourceHead) != NULL && (*sourceHead)->value % 2 == 1) {
		newListT = (*sourceHead);
		*sourceHead = (*sourceHead)->next;
		newListT->next = newList;
		newList = newListT;
	}

	return newList;
}
int getNumber() {

	int input = 0;
	do {
		// get numb from user
		printf("enter number bigger than 0: ");
		scanf("%d", &input);
		printf("Got %d \n", input);

	} while (input < 1);

	return input;
}
void printNodeR(NodeR* head){

	printf("Print node \n");
	while(head != NULL){
		printf("%d,",head->value );
		head = head -> next;
	}
	printf("\n");
}
