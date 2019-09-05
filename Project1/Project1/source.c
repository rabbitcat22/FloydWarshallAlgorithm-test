#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	int key;//������ ��
	struct treeNode* left;//���� ���� Ʈ�� ��ũ 
	struct treeNode* right;//������ ���� Ʈ�� ��ũ 
} treeNode;

typedef int element;

treeNode* insertNode(treeNode *p, int x)
{
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n �̹� ����Ű�� �ֽ��ϴ�! \n");

	return p;
}

void deleteNode(treeNode *root, element key)
{    //��Ʈ ������ Ž���Ͽ� ������ ���� ���� ��带 ã�� �����ϴ� ����
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	//������ ��尡 �͹̳� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	//������ ��尡 �� ���� �ڽ� ��带 ���� ���
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	//������ ��尡 �� ���� �ڽ� ��带 ���� ���
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}


void displayInorder(treeNode* root)
{    //���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
	if (root) {
		displayInorder(root->left);
		printf("%d_", root->key);
		displayInorder(root->right);
	}
}


int main()
{
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;


	root = insertNode(root, 7); //Ʈ�� �����
	insertNode(root, 12);
	insertNode(root, 4);
	insertNode(root, 1);
	insertNode(root, 6);
	insertNode(root, 8);
	insertNode(root, 9);
	insertNode(root, 11);
	insertNode(root, 13);
	insertNode(root, 5);

	printf("��� ��� \n\n");
	displayInorder(root); printf("\n\n");

	deleteNode(root, 6);
	deleteNode(root, 11);


	printf("��� 2���� �����Ѵ��� ��� \n\n");
	displayInorder(root); printf("\n\n");

	insertNode(root, 2);
	insertNode(root, 3);
	insertNode(root, 10);
	insertNode(root, 14);
	insertNode(root, 16);

	deleteNode(root, 3);
	deleteNode(root, 8);


	printf("���5�� �߰��� �Ŀ� ��� 2���� ������ ���� �����. \n\n");

	displayInorder(root); printf("\n\n");

	getchar();

}