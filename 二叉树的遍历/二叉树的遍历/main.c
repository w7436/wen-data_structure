#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Node;
//����������������ݹ飩
void PreOrder(Node *root) {
	if (root==NULL) {
		return;
	}
	printf("%d", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//����������������ǵݹ飩:����ջ����ʽ
void PreOrder_1(Node *root) {
	if (root==NULL) {
		return;
	}
	Node *stack[SIZE];//ջ�����洢���ĵ�ַ
	Node *tmp = root;
	int top = 0;//top����ջ��
	while (tmp!=NULL||top!=0) {
		while (tmp!=NULL) {
			printf("%d", tmp->data);
			//��ָ����ջ,�ж�ջ
			if (top<=SIZE-1) {
				stack[top] = tmp;
				top++;
			}
			else {
				
				return;
			}
			tmp = tmp->left;
		}
		//��ջ
	
		//ջΪ��
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
//�������������(�ݹ�)
void InOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}
//����������(�ݹ�)
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