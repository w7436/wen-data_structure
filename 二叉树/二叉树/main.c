#include <stdio.h>
#include "BinaryTree.h"
#include <stdlib.h>
//û�и��ڵ�Ľ���Ϊ���ڵ�
//û���ӽڵ�Ľ���ΪҶ���
/*�����ص㣺1.�����ǲ��ཻ�ģ�
					2.���˸��ڵ��⣬ÿ���������ֻ��һ�������
					3.һ��n����������n-1����
	�������ص㣺1.ÿ������������������
						2.������������֮�֣���������˳���ܵߵ�
	1.˳���ʾ2.��ʽ��ʾ
	����Ķ�������1.��������2.��ȫ������

*/

int main() {
	Test();
	system("pause");
	return 0;
}
//typedef struct Node {
//	int value;
//	struct Node *left;//�������ĸ��ڵ�
//	struct Node *right;//�������ĸ��ڵ�
//};
//typedef struct Node {
//	int value;
//	struct Node *left;
//	struct Node*right;
//	struct Node *parent;
//};