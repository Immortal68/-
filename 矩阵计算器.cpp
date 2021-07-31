#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define SIZE 100
using namespace std;
int a_column;
int a_row ;
int b_row;

int c[SIZE][SIZE] = {0};

//矩阵的输入函数
void inputMatrix(int a[][SIZE], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

//矩阵的输出函数
void outputMatrix(int c[][SIZE], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

//矩阵的乘法
void matrixMultiplication(int a[][SIZE], int b[][SIZE]) {
	int i, j, k;
	for (i = 0; i < a_column; i++) {
		for (j = 0; j < b_row ; j++) {
			for (k = 0; k < a_row; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}
}

//矩阵的加法
void jianMultiplication(int a[][SIZE], int b[][SIZE]) {
	int i, j, k;
	for (i = 0; i < a_column; i++) {
		for (j = 0; j < b_row ; j++) {
			for (k = 0; k < a_row; k++) {
				c[i][j] = a[i][j] + b[i][j];
			}
		}
	}
}

//矩阵的减法
void jiaMultiplication(int a[][SIZE], int b[][SIZE]) {
	int i, j, k;
	for (i = 0; i < a_column; i++) {
		for (j = 0; j < b_row ; j++) {
			for (k = 0; k < a_row; k++) {
				c[i][j] = a[i][j] - b[i][j];
			}
		}
	}
}

//矩阵A的转置
void zzMultiplication(int a[][SIZE]) {
	int i, j, k;
	for (i = 0; i < a_column; i++) {
		for (j = 0; j < b_row ; j++) {
			for (k = 0; k < a_row; k++) {
				c[i][j] = a[j][i];
			}
		}
	}
}

//矩阵B的转置
void zz2Multiplication(int b[][SIZE]) {
	int i, j, k;
	for (i = 0; i < a_column; i++) {
		for (j = 0; j < b_row ; j++) {
			for (k = 0; k < a_row; k++) {
				c[i][j] = b[j][i];
			}
		}
	}
}

int main() {
//初始化
	int a[SIZE][SIZE] = {0};
	int b[SIZE][SIZE] = {0};
	cout << "************矩阵计算器***************" << endl;
	cout << "***可以实现100阶以内两个矩阵的加法、减法、乘法、转置***" << endl;
	printf("请输入第一个矩阵的行数 :");
	scanf("%d", &a_column);
	printf("请输入第一个矩阵的列数 :");
	scanf("%d", &a_row);
//函数调用
	printf("\n请输入矩阵A( %d X %d 形式)\n", a_column, a_row);
	inputMatrix(a, a_column, a_row);
	printf("注意：根据数学原理，第二个矩阵的行数为 %d\n", a_row);
	printf("请输入矩阵B的列数 : ");
	scanf("%d", &b_row);
	printf("\n请输入矩阵B( %d X %d 形式) : \n", a_row, b_row);
	inputMatrix(b, a_row, b_row);
	matrixMultiplication(a, b);
	printf("A与B相乘后的矩阵C是:\n");
	outputMatrix(c, a_column, b_row);
	jiaMultiplication(a, b);
	printf("A与B相加后的矩阵C是:\n");
	outputMatrix(c, a_column, b_row);
	jianMultiplication(a, b);
	printf("A与B相减后的矩阵C是:\n");
	outputMatrix(c, a_column, b_row);
	zzMultiplication(a);
	printf("A的转置是:\n");
	outputMatrix(c, a_column, b_row);
	zz2Multiplication(b);
	printf("B的转置是:\n");
	outputMatrix(c, a_column, b_row);
	getchar();
	return 0;
}