#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define MATRIXC 3
#define MATRIXR 3


void EX1(); 
void EX2();
int** multyplayMatrix(int matrixA[MATRIXC][MATRIXR], int matrixB[MATRIXC][MATRIXR]);
unsigned int * powerArray(int length);
void printMatrix(int*** matrix);

void main(){
	//EX1();
	EX2();
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
	
	printMatrix(multypliedMatrix);
	}

int** multyplayMatrix(int matrixA[MATRIXC][MATRIXR], int matrixB[MATRIXC][MATRIXR]){
	int** multypliedMatrix;
	int i, j, value;
	
	// get pointer for metrix
	multypliedMatrix = (int**) malloc((sizeof(int**)*MATRIXC));
	
	// create matrix 
	for(i =0; i<MATRIXC; i++){
		multypliedMatrix[i] = (int*) malloc((sizeof(int*) *MATRIXR) );
	}

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


