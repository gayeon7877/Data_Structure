#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int SparseMatrix_B[7][3] = {
		{0,3,7},
		{1,0,9},
		{1,5,8},
		{3,0,6},
		{3,1,5},
		{4,5,1},
		{5,2,2}
	};


	int row = sizeof(SparseMatrix_B) / sizeof(SparseMatrix_B[0]);
	int col = sizeof(SparseMatrix_B[0]) / sizeof(int);
	int rows = 0;
	int cols = 0;
	for (int i = 0; i < row; i++) {

		if (SparseMatrix_B[i][0] > SparseMatrix_B[i - 1][0])
			rows = SparseMatrix_B[i][0] + 1;

	}//원래의 matrix의 colum과 row의 수를 알기위함
	for (int i = 0; i < col; i++) {
		if (SparseMatrix_B[i][1] > SparseMatrix_B[i - 1][1])
			cols = SparseMatrix_B[i][1] + 1;
	}
	//원래 matrixB의 할당
	int** matrixB = (int**)malloc(sizeof(int*) * rows);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼
										   // 동적 메모리 할당. 배열의 세로

	for (int i = 0; i < rows; i++)            // 세로 크기만큼 반복
	{
		matrixB[i] = (int*)malloc(sizeof(int) * cols);
	} // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
										   // 배열의 가로
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			matrixB[i][j] = 0;
		}
	for (int i = 0; i < row; i++)
	{
		matrixB[SparseMatrix_B[i][0]][SparseMatrix_B[i][1]] = SparseMatrix_B[i][2];
	}
	int** matrixB_T = (int**)malloc(sizeof(int*) * row);   // 이중 포인터에 (int 포인터 크기 * 세로 크기)만큼
										   // 동적 메모리 할당. 배열의 세로

	for (int i = 0; i < row; i++)            // 세로 크기만큼 반복
	{
		matrixB_T[i] = (int*)malloc(sizeof(int) * col);
	} // (int 크기 * 가로 크기)만큼 동적 메모리 할당.
							   // 배열의 가로
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			matrixB_T[i][j] = 0;
		}

	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			
			if (matrixB[j][i] != 0) {
				matrixB_T[k][0] = i;
				matrixB_T[k][1] = j;
				matrixB_T[k][2] = matrixB[j][i];
				k++;
			}

		}
	

	
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col; j++) {
			
			printf("%d", matrixB_T[i][j]);
		}

	}



	
	
	
	//B출력
	for (int i = 0; i < rows; i++) {

		printf("\n");
		for (int j = 0; j < cols; j++) {
			printf("%d", matrixB[i][j]);

		}
	}

	//B^T 출력
	for (int i = 0; i < rows; i++) {

		printf("\n");
		for (int j = 0; j < cols; j++) {
			printf("%d", matrixB[j][i]);

		}
	}

}