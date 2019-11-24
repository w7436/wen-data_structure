#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
int visited[MAXVEX];//用于标记结点是否访问，为1则表示已经访问，为0则表示未访问

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
	char vexs[MAXVEX];//存储顶点的信息的一维数组
	int  arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexs, numEdges;
}Graph;

void creatGraph(Graph *G) {
	int i, j, k;
	printf("请输入顶点数和边数：");
	scanf("%d %d", &(G->numVertexs), &(G->numEdges));
	getchar();
	for (i = 0; i < G->numVertexs;i++) {//顶点数
		printf("请输入顶点信息：");
		scanf("%[^\n]%*c" ,&(G->vexs[i]));
	}
	for (i = 0; i < G->numVertexs; i++) {//初始化为0
		for (j = 0; j < G->numVertexs;j++) {
			G->arc[i][j] =0;
		}
	}
	for (k = 0; k < G->numEdges;k++) {//边数
		printf("输入边的（vi,vj）边上的下标i，下标j：");
		scanf("%d,%d", &i, &j);
		G->arc[i][j] =1;
		G->arc[j][i] = G->arc[i][j];//无向图沿对角线对称
	}
}

//深度优先
void DFS(Graph G, int i) {
	int j = 0;
	visited[i] = 1;
	printf("%c ", G.vexs[i]);//打印顶点
	for (j = 0; j < G.numVertexs;j++) {
		if (G.arc[i][j]==1&&!visited[j]) {
			DFS(G, j);
		}
	}
}
void DFSTraverse(Graph G) {
	int i;
	for (i = 0; i < G.numVertexs;i++) {//初始化所有的顶点
		visited[i] = 0;
	}
	for (i = 0; i < G.numVertexs;i++) {
		if (!visited[i]) {//对未访问的顶点调用DFS
			DFS(G, i);
		}
	}
}
////广度
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
//			EnQueue(&Q, i);//入队
//			while (!QueueEmpty(Q)) {//当前队列不为空
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