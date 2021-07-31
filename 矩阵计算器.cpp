#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define SIZE 100
using namespace std;
int a_column;
int a_row ;
int b_row;

int c[SIZE][SIZE] = {0};

//��������뺯��
void inputMatrix(int a[][SIZE], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

//������������
void outputMatrix(int c[][SIZE], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

//����ĳ˷�
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

//����ļӷ�
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

//����ļ���
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

//����A��ת��
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

//����B��ת��
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
//��ʼ��
	int a[SIZE][SIZE] = {0};
	int b[SIZE][SIZE] = {0};
	cout << "************���������***************" << endl;
	cout << "***����ʵ��100��������������ļӷ����������˷���ת��***" << endl;
	printf("�������һ����������� :");
	scanf("%d", &a_column);
	printf("�������һ����������� :");
	scanf("%d", &a_row);
//��������
	printf("\n���������A( %d X %d ��ʽ)\n", a_column, a_row);
	inputMatrix(a, a_column, a_row);
	printf("ע�⣺������ѧԭ���ڶ������������Ϊ %d\n", a_row);
	printf("���������B������ : ");
	scanf("%d", &b_row);
	printf("\n���������B( %d X %d ��ʽ) : \n", a_row, b_row);
	inputMatrix(b, a_row, b_row);
	matrixMultiplication(a, b);
	printf("A��B��˺�ľ���C��:\n");
	outputMatrix(c, a_column, b_row);
	jiaMultiplication(a, b);
	printf("A��B��Ӻ�ľ���C��:\n");
	outputMatrix(c, a_column, b_row);
	jianMultiplication(a, b);
	printf("A��B�����ľ���C��:\n");
	outputMatrix(c, a_column, b_row);
	zzMultiplication(a);
	printf("A��ת����:\n");
	outputMatrix(c, a_column, b_row);
	zz2Multiplication(b);
	printf("B��ת����:\n");
	outputMatrix(c, a_column, b_row);
	getchar();
	return 0;
}