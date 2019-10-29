#include <stdio.h>
#include "BinaryTree.h"
#include <stdlib.h>
//没有父节点的结点称为根节点
//没有子节点的结点称为叶结点
/*树的特点：1.子树是不相交的，
					2.除了根节点外，每个结点有且只有一个父结点
					3.一颗n个结点的树有n-1个边
	二叉树特点：1.每个结点最多有两棵子树
						2.二叉树有左右之分，其子树的顺序不能颠倒
	1.顺序表示2.链式表示
	特殊的二叉树：1.满二叉树2.完全二叉树

*/

int main() {
	Test();
	system("pause");
	return 0;
}
//typedef struct Node {
//	int value;
//	struct Node *left;//左子树的根节点
//	struct Node *right;//右子树的根节点
//};
//typedef struct Node {
//	int value;
//	struct Node *left;
//	struct Node*right;
//	struct Node *parent;
//};