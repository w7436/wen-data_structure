#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Node;
//先序遍历二叉树（递归）
void PreOrder(Node *root) {
	if (root==NULL) {
		return;
	}
	printf("%d", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//先序遍历二叉树（非递归）:采用栈的形式
void PreOrder_1(Node *root) {
	if (root==NULL) {
		return;
	}
	Node *stack[SIZE];//栈用来存储结点的地址
	Node *tmp = root;
	int top = 0;//top代表栈顶
	while (tmp!=NULL||top!=0) {
		while (tmp!=NULL) {
			printf("%d", tmp->data);
			//将指针入栈,判断栈
			if (top<=SIZE-1) {
				stack[top] = tmp;
				top++;
			}
			else {
				
				return;
			}
			tmp = tmp->left;
		}
		//出栈
	
		//栈为空
		if (top<=0) {
			return;
		}
		else {
			top--;
			tmp = stack[top];
			tmp = tmp->right;
		}
	}
}
//中序遍历二叉树(递归)
void InOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}
void InOreder_1(Node *root) {
	while (root==NULL) {
		return;
	}
	Node* stack[SIZE];
	Node* tmp = root;
	int top = 0;//代表栈顶
	while (tmp!=NULL||top!=0){
		while (tmp != NULL) {
			if (top<SIZE) {
				stack[top] = tmp;
				tmp = tmp->left;
				top++;
			}
			else {
				return;
			}
		}
		if (top<=0) {
			return;
		}else{
			top--;
			tmp = stack[top];
			printf("%d", tmp->data);
			tmp = tmp->right;
		}

	}
}
//后序遍二叉树(递归)
void PostOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	printf("%c ", root->data);
	PostOrder(root->right);
}
//后序遍历二叉树（非递归），相对于前序和中序较为复杂
void PostOrder_1(Node *root) {
	if (root==NULL) {
		return;
	}
	Node *stack[SIZE];
	Node *tmp = root;
	int top = 0;
	Node*re = NULL;
	while (tmp!=NULL||top!=0) {
		while (tmp!=NULL) {
			if (top<SIZE) {
				stack[top] = tmp;
				tmp = tmp->left;
				top++;
			}else {
				return;
			}
		}
		top--;
		tmp = stack[top];
		if (tmp->right&&tmp->right!=re) {
			tmp = tmp->right;
			top++;//将其入栈
		}
		else {
			printf("%d", tmp->data);
			re = tmp;
			tmp = NULL;
		}
	}
}
//二叉树的层次遍历（采用队列结构）
void LevelOrder(Node* root) {
	if (root==NULL) {
		return NULL;
	}
	Node* queue[SIZE];
	int front=-1, rear=0;//rear代表尾，front代表头
	queue[rear] = root;
	while (front!=rear) {
		front++;
		printf("%d", queue[front]->data);
		if (queue[front]->left!=NULL) {
			rear++;
			queue[rear] = queue[front]->left;
		}
		if (queue[front]->right!=NULL) {
			rear++;
			queue[rear] = queue[front]->right;
		}
	}

}

Node* buyNode(int data) {
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
void Test() {
	Node *a = buyNode(1);
	Node *b = buyNode(2);
	Node *c = buyNode(3);
	Node *d = buyNode(4);
	Node *e = buyNode(5);
	Node *f = buyNode(6);
	Node *g = buyNode(7);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	//PreOrder(a);
	//PreOrder_1(a);
//	InOreder_1(a);
	//PostOrder_1(a);
	LevelOrder(a);
}

int main() {
	Node* root=NULL;
	Test();
	//PostOrder(root);
	system("pause");
	return 0;
}