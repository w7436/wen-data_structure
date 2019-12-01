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
		if (top<0) {
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
//后序遍二叉树(递归)
void PostOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	printf("%c ", root->data);
	PostOrder(root->right);
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
	c->left = d;
	c->right = f;
	d->right = e;
	f->right = g;

	//PreOrder(a);
	PreOrder_1(a);

}

int main() {
	Node* root=NULL;
	Test();
	//PostOrder(root);
	system("pause");
	return 0;
}