#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
	int key;//데이터 값
	struct treeNode* left;//왼쪽 서브 트리 링크 
	struct treeNode* right;//오른쪽 서브 트리 링크 
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
	else printf("\n 이미 같은키가 있습니다! \n");

	return p;
}

void deleteNode(treeNode *root, element key)
{    //루트 노드부터 탐색하여 데이터 값과 같은 노드를 찾아 삭제하는 연산
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
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	//삭제할 노드가 터미널 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	//삭제할 노드가 한 개의 자식 노드를 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	//삭제할 노드가 두 개의 자식 노드를 가진 경우
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
{    //이진 탐색 트리를 중위 순회하면서 출력하는 연산
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


	root = insertNode(root, 7); //트리 만들기
	insertNode(root, 12);
	insertNode(root, 4);
	insertNode(root, 1);
	insertNode(root, 6);
	insertNode(root, 8);
	insertNode(root, 9);
	insertNode(root, 11);
	insertNode(root, 13);
	insertNode(root, 5);

	printf("노드 출력 \n\n");
	displayInorder(root); printf("\n\n");

	deleteNode(root, 6);
	deleteNode(root, 11);


	printf("노드 2개를 삭제한다음 출력 \n\n");
	displayInorder(root); printf("\n\n");

	insertNode(root, 2);
	insertNode(root, 3);
	insertNode(root, 10);
	insertNode(root, 14);
	insertNode(root, 16);

	deleteNode(root, 3);
	deleteNode(root, 8);


	printf("노드5개 추가한 후에 노드 2개를 삭제한 다음 출력함. \n\n");

	displayInorder(root); printf("\n\n");

	getchar();

}