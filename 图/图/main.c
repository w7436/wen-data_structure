#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
int visited[MAXVEX];//���ڱ�ǽ���Ƿ���ʣ�Ϊ1���ʾ�Ѿ����ʣ�Ϊ0���ʾδ����

//typedef struct {
//	int data[MAXVEX];
//	int front;
//	int rear;
//}Queue;
//int InitQueue(Queue *Q){
//	Q->front = 0;
//	Q->rear = 0;
//	return 1;
//}
//int EnQueue(Queue *Q, int e) {
//
//}

typedef struct  {
	char vexs[MAXVEX];//�洢�������Ϣ��һά����
	int  arc[MAXVEX][MAXVEX];//�ڽӾ���
	int numVertexs, numEdges;
}Graph;

void creatGraph(Graph *G) {
	int i, j, k;
	printf("�����붥�����ͱ�����");
	scanf("%d %d", &(G->numVertexs), &(G->numEdges));
	getchar();
	for (i = 0; i < G->numVertexs;i++) {//������
		printf("�����붥����Ϣ��");
		scanf("%[^\n]%*c" ,&(G->vexs[i]));
	}
	for (i = 0; i < G->numVertexs; i++) {//��ʼ��Ϊ0
		for (j = 0; j < G->numVertexs;j++) {
			G->arc[i][j] =0;
		}
	}
	for (k = 0; k < G->numEdges;k++) {//����
		printf("����ߵģ�vi,vj�����ϵ��±�i���±�j��");
		scanf("%d,%d", &i, &j);
		G->arc[i][j] =1;
		G->arc[j][i] = G->arc[i][j];//����ͼ�ضԽ��߶Գ�
	}
}

//�������
void DFS(Graph G, int i) {
	int j = 0;
	visited[i] = 1;
	printf("%c ", G.vexs[i]);//��ӡ����
	for (j = 0; j < G.numVertexs;j++) {
		if (G.arc[i][j]==1&&!visited[j]) {
			DFS(G, j);
		}
	}
}
void DFSTraverse(Graph G) {
	int i;
	for (i = 0; i < G.numVertexs;i++) {//��ʼ�����еĶ���
		visited[i] = 0;
	}
	for (i = 0; i < G.numVertexs;i++) {
		if (!visited[i]) {//��δ���ʵĶ������DFS
			DFS(G, i);
		}
	}
}
////���
//void BFSTraverse(Graph G) {
//	int i, j;
//	Queue Q;
//	for (i = 0; i < G.numVertexs;i++) {
//		visited[i] = 0;
//	}
//	InitQueue(&Q);
//	for (i = 0; i < G.numVertexs;i++) {
//		if (!visited[i]) {
//			visited[i] = 1;
//			printf("%c", G.vexs[i]);
//			EnQueue(&Q, i);//���
//			while (!QueueEmpty(Q)) {//��ǰ���в�Ϊ��
//				DeQueue(&Q,&i);
//				for (j = 0; j < G.numVertexs;j++) {
//					if (G.arc[i][j]==1&&!visited[j]) {
//						visited[j] = 1;
//						printf("%c", G.vexs[j]);
//						EnQueue(&Q, j);
//					}
//				}
//			}
//		}
//	}
//}
int main(){
	Graph G;
	creatGraph(&G);
	DFSTraverse(G);
	system("pause");
	return 0; 
}