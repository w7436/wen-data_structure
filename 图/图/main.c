#include <stdio.h>
#include <stdlib.h>
typedef int Boolean;
Boolean visited[100];


#define MAXVEX 100
#define INFINITY 65535
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	int data[MAXVEX];
	int front;
	int rear;
}Queue;
int InitQueue(Queue *Q){
	Q->front = 0;
	Q->rear = 0;
	return 1;
}
int EnQueue(Queue *Q, int e) {

}
typedef struct  {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexs, numEdges;
}Graph;
void creatGraph(Graph *G) {
	int i, j, k, w;
	printf("请输入顶点的边数和顶点数：");
	scanf("%d,%d", &G->numVertexs, &G->numEdges);
	for (i = 0; i < G->numVertexs;i++) {
		scanf("%c",&G->numVertexs);

	}
	for (i = 0; i < G->numVertexs; i++) {
		for (j = 0; j < G->numVertexs;j++) {
			G->arc[i][j] = INFINITY;
		}
	}
	for (k = 0; k < G->numEdges;k++) {
		printf("输入边的（vi,vj）边上的下标i，下标j,和权值w：");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];//无向图沿对角线对称
	}
}
//深度优先
void DFS(Graph G, int i) {
	int j = 0;
	visited[i] = 1;
	printf("%c", G.vexs[i]);//打印顶点
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
//广度
void BFSTraverse(Graph G) {
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexs;i++) {
		visited[i] = 0;
	}
	InitQueue(&Q);
	for (i = 0; i < G.numVertexs;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			printf("%c", G.vexs[i]);
			EnQueue(&Q, i);//入队
			while (!QueueEmpty(Q)) {//当前队列不为空
				DeQueue(&Q,&i);
				for (j = 0; j < G.numVertexs;j++) {
					if (G.arc[i][j]==1&&!visited[j]) {
						visited[j] = 1;
						printf("%c", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}
int main(){

	system("pause");
	return 0; 
}