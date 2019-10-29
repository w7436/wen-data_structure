#pragma once
#include <stdio.h>
#include<malloc.h>
typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
}Node;


void  preorder(Node *root) { //前序

	if (root==NULL) {
		return;
	}
	printf("%d", root->val);
	preorder(root->left);
	preorder(root->right);
	
}

Node *buyNode(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}


void Test() {
	Node *a = buyNode(1);
	Node *b = buyNode(2);
	Node *c= buyNode(3);
	Node *d = buyNode(4);
	Node *e = buyNode(5);
	Node *f= buyNode(6);
	Node *g = buyNode(7);

	a->left = b;
	a->right = c;
	c->left = d;
	c->right = f;
	d->right = e;
	f->right = g;

	preorder(a);

}

//是否对称
int  isMirror(Node *p,Node *q ){
	if (p==NULL&&q==NULL) {
		return 1;
	}
	if (p==NULL||q==NULL) {
		return 0;
	}
	//递推
	return p->val == q->val&&isMirror(p->left, q->right) && isMirror(p->right, q->left);
}
int isSymmetric(Node *root) {
	if (root==NULL) {
		return 1;
	}
	return  isMirror(root->left, root->right);
}
//是否相等
int isSameTree(Node *p,Node *q) {
	if (p == NULL && q == NULL) {
		return 1;
	}
	if (p == NULL || q == NULL) {
		return 0;
	}
	return p->val == q->val&& isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
//另一个数的子树
//前序遍历
//数的相等
//返回值的处理
int isSameTree(Node *p, Node *q) {
	if (p == NULL && q == NULL) {
		return 1;
	}
	if (p == NULL || q == NULL) {
		return 0;
	}
	return p->val == q->val&& isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
int preorderTraversal(Node *root, Node *t) {
	if (root==NULL) {
		return ;
	}
	//根
	int root_ret;
	if (root->val==t->val&&isSameTree(root,t)) {
		return 1;
	}
	//左子树
	int left = preorderTraversal(root->left, t);
	if (left==1){
		return 1;
	}
	//柚子树
	int right=preorderTraversal(root->left,t);
		return 1;
	
}
int isSubtree(Node *s,Node *t) {
	if (t==NULL) {
		return 1;
	}
	return  preorderTraversal(s,t);

}