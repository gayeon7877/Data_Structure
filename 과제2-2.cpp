#include<stdio.h>
#include<stdlib.h>
#define WIDTH 2
#define LENGTH 3
#define HEIGHT 4

int main(void)
{
	

	double*** A = (double***)malloc(sizeof(double**) * WIDTH);
	
	for (int i = 0; i < LENGTH; i++) {
		A[i] = (double**)malloc(sizeof(double) * LENGTH);
		
		for (int j = 0; j < HEIGHT; j++) {
			A[i][j] = (double*)malloc(sizeof(double) *HEIGHT);
		}
	}
	double count = 0;
	for (int i = 0; i <WIDTH; i++) {
		
		for (int j = 0; j < LENGTH; j++) {
			printf("\n");
			for (int k = 0; k < HEIGHT; k++) {
				*(*(*(A + i) + j) + k) = ++count;
				scanf_s("%lf", &*(*(*(A + i) + j) + k));
				
				
			}

		}
	}
	double*** B = (double***)malloc(sizeof(double**) * WIDTH);

	for (int i = 0; i < LENGTH; i++) {
		B[i] = (double**)malloc(sizeof(double) * LENGTH);

		for (int j = 0; j < HEIGHT; j++) {
			B[i][j] = (double*)malloc(sizeof(double) * HEIGHT);
		}
	}

	for (int i = 0; i < WIDTH; i++) {

		for (int j = 0; j < LENGTH; j++) {
			printf("\n");
			for (int k = 0; k < HEIGHT; k++) {
				*(*(*(B + i) + j) + k) = ++count;
				scanf_s("%lf", &*(*(*(B + i) + j) + k));


			}

		}
	}
	for (int i = 0; i < WIDTH; i++) {

		for (int j = 0; j < LENGTH; j++) {
			printf("\n");
			for (int k = 0; k < HEIGHT; k++) {
				printf("%lf", *(*(*(A + i) + j) + k));
				


			}

		}
	}
	printf("\n\n");
	for (int i = 0; i < WIDTH; i++) {

		for (int j = 0; j < LENGTH; j++) {
			printf("\n");
			for (int k = 0; k < HEIGHT; k++) {
				printf("%lf", *(*(*(B + i) + j) + k));



			}

		}
	}

	//addition 3D
	printf("\n\n");
	for (int i = 0; i < WIDTH; i++) {

		for (int j = 0; j < LENGTH; j++) {
			printf("\n");
			for (int k = 0; k < HEIGHT; k++) {
				printf("%lf", (*(*(*(B + i) + j) + k))+ *(*(*(A + i) + j) + k));



			}

		}
	}


	free(A);
	free(B);

}