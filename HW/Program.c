#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "NodeModel.h"

#define MATRIXC 3
#define MATRIXR 3


int** createMatrix(int coll, int row);
void EX1(); 
void EX2();
void EX03();
int** multyplayMatrix(int matrixA[MATRIXC][MATRIXR], int matrixB[MATRIXC][MATRIXR]);
unsigned int * powerArray(int length);
void printMatrix(int*** matrix);
int scanMatrixToNode(int** matrix, int row, int col, Record** list, Node** head );



void main(){
	//EX1();
	//EX2();
	EX03();
}

void EX1(){

	int length = 0, i = 0, temp;
	unsigned int *p;

	do {
		// get numb from user
		printf("enter number bigger than 0 ");
		scanf("%d",&length);
  
		} while( length<1 );

	
	p = powerArray(length);


	for(i = 0; i<length; i++){
		temp = i;
		printf("%d: %u\n",i, p[i]);
	}

	free(p);
}
unsigned int * powerArray(int length){
	unsigned int value;
	int i;
	unsigned int *p = (unsigned int *) malloc(sizeof(unsigned int)*length);

	if(*p == NULL){
		 printf("Not enoght memory");
		 return NULL;
	}
	else{
	for(i = 0; i<length; i++){

		if(i<32){
			value =  (unsigned int) pow((double)2,i);
			p[i]= value;
		}
		else{
			p[i]= (unsigned int )p[i%32];
			}
		}
	}
	return p;
	
}
void EX2(){
	
	int** multypliedMatrix;
	int matrixA[MATRIXC][MATRIXR]={{1, 5, 6},{4, 4, 8},{2, 3, 4}};
	int matrixB[MATRIXC][MATRIXR]={{1, 5, 6},{4, 4, 8},{2, 3, 4}};
	
	
	multypliedMatrix = multyplayMatrix(matrixA,matrixB);
	
	//printMatrix(&multypliedMatrix);
	}
int** multyplayMatrix(int matrixA[MATRIXC][MATRIXR], int matrixB[MATRIXC][MATRIXR]){
	int** multypliedMatrix;
	int i, j, value;
	
	multypliedMatrix =	createMatrix(MATRIXC, MATRIXR);

	// math
	for(i = 0; i<MATRIXC; i++){
		for(j=0; j<MATRIXR; j++){
			value= (matrixA[i][j] *  matrixB[i][j]);
			multypliedMatrix[i][j]  = value;
		}
	}
	// return poinet of metrix
	return multypliedMatrix;
}
void printMatrix(int*** matrix){
	int i,j, value;
	for(i = 0; i<MATRIXC; i++){
		for(j=0; j<MATRIXR; j++){
			printf("%3d",(*(*matrix + i) + j));
		}
		printf("\n");
	}
	printf("_______________________________________________\n");
}

void EX03(){
	int** matrix;
	int row, coll, result;
	Record* list;
	Node* head;

	/*printf("Enter number of rows");
	scanf("%d",&row);
	printf("Enter number of colooms");
	scanf("%d",&coll);*/
	
	row = 4;
	coll = 5;
	matrix = createMatrix(coll,row);

	matrix[0][0] = 3;
	matrix[0][1] = 2;
	matrix[0][2] = 5;
	matrix[0][3] = 3;
	matrix[0][4] = 6;

	matrix[1][0] = 8;
	matrix[1][1] = 3;
	matrix[1][2] =4;
	matrix[1][3] =6;
	matrix[1][4] =5;
				   
	matrix[2][0] =0;
	matrix[2][1] =6;
	matrix[2][2] =4;
	matrix[2][3] =5;
	matrix[2][4] =7;
				   
	matrix[3][0] =9;
	matrix[3][1] =8;
	matrix[3][2] =6;
	matrix[3][3] =6;
	matrix[3][4] =1;


	
	result = scanMatrixToNode(matrix, row, coll, &list, &head);


}

int scanMatrixToNode(int** matrix, int row, int col, Record** list, Node** head ){

	Node* headT;
	int i,j, index = 0, count = 0;
	for(i =0; i< row; i++){
		for(j =0; j< col; j++){
			if(matrix[i][j] == i+j){
					addNode(createNode(i,j),head);
					count ++;
				}
			}
		}

	if(count == 0)
		return;


	 // create array og node
	 *list = (Record*) malloc(sizeof(Record)*count);
	 
	 headT = *head;
	 while(index!=count){
		*(list+index) = headT->value;
		 headT = headT->next;
		 index++;
	 }

	 return count;
}

int** createMatrix(int col, int row){
	int i;
	int** multypliedMatrix;
	
	// get pointer for metrix
	multypliedMatrix = (int**) malloc(row*(sizeof(int**)));
	
	// create matrix 
	for(i =0; i<row; i++){
		multypliedMatrix[i] = (int*) calloc(col, (sizeof(int*)));
	}

	return multypliedMatrix;
}
