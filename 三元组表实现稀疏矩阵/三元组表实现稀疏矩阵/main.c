#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
//定义三元组
typedef struct {
	int i, j;//行数、列数
	int val;//非零值
}Node;

typedef struct {
	Node data[Maxsize+1];
	int m, n, t;//行数、列数、长度
}Matrix;

void InitSPNode(Matrix *p) {
	int count = 0;
	int num = 0;
	int row=0, col=0, va = 0;
	printf("请用户输入个数：");
	scanf("%d", &count);
	while (count) {
		printf("请输入行、列、值：");
		scanf("%d%d%d", &row, &col, &va);
		p->data[num].i = row;
		p->data[num].j = col;
		p->data[num].val = va;
		num++;
		count--;
	}
	p->m = row;
	p->n = col;
	p->t = num - 1;
}
void display(Matrix *p) {
	int t = 0;
	for (int i = 0; i <= p->m;i++) {
		for (int j = 0; j <= p->n;j++) {
			if (p->data[t].i==i&&p->data[t].j==j) {
				printf("%d ", p->data[t].val);
				t++;
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
int value(Matrix A,int i,int j) {
	int k = 0;
	while (k<=A.t&&A.data[k].i<=i) {
		if (A.data[k].i==i&&A.data[k].j==j) {
			return A.data[k].val;
		}
		k++;
	}
	return 0;
}
Matrix MultSmatrix(Matrix *A, Matrix *B) {
	Matrix C;
	C.m = A->m;
	C.n = B->n;
	int t = 0;
	if (A->t*B->t!=0) {
		for (int p = 0; p <= A->m;p++) {//行数
			for (int q = 0; q <= B->n;q++) {//列数
				int sum = 0;
				for (int k = 0; k <= A->n;k++) {
					sum += value(*A, p, k)*value(*B,k,q);
				}
				if (sum!=0) {
					C.data[t].i = p;
					C.data[t].j = q;
					C.data[t].val = sum;
					t++;
				}
			}

		}
		C.t = t;
	}

	return C;
}
int main() {
	Matrix a,b;
	InitSPNode(&a);
	printf("\n");
	InitSPNode(&b);

	printf("请输出a的矩阵：\n");
	display(&a);
	printf("请输出b的矩阵：");
	printf("\n");
	display(&b);

	Matrix p = MultSmatrix(&a, &b);
	printf("相乘后的矩阵为：\n");
	display(&p);
	
	system("pause");
	return 0;

}