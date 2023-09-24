#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

TreeNode n1 = { 4, NULL, NULL, 1 };
TreeNode n2 = { 5, NULL, NULL, 1 };
TreeNode n3 = { 3, &n1, &n2, 0 };
TreeNode n4 = { 6, NULL, NULL, 1 };
TreeNode n5 = { 2, &n3, &n4, 0 };
TreeNode n6 = { 8, NULL, NULL, 1 };
TreeNode n7 = { 10, NULL, NULL, 1 };
TreeNode n8 = { 11, NULL, NULL, 0 };
TreeNode n9 = { 9, &n7, &n8, 0 };
TreeNode n10 = { 7, &n6, &n9, 0};
TreeNode n11 = { 1, &n5, &n10, 0 };
TreeNode* exp = &n11;

char* getNodeName(TreeNode* node) {
	// 각 노드에 대한 이름을 반환하는 함수
	if (node == &n1) return "n1";
	if (node == &n2) return "n2";
	if (node == &n3) return "n3";
	if (node == &n4) return "n4";
	if (node == &n5) return "n5";
	if (node == &n6) return "n6";
	if (node == &n7) return "n7";
	if (node == &n8) return "n8";
	if (node == &n9) return "n9";
	if (node == &n10) return "n10";
	if (node == &n11) return "n11";
	return "Unknown";
}

TreeNode* parent(TreeNode* child, TreeNode* root) {
	// 기저 사례: 루트 노드가 NULL이거나 자식 노드와 일치할 때
	if (root == NULL) {
		return -1; // 또는 다른 적절한 값으로 부모가 없음을 나타냄
	}

	if (root->left == child || root->right == child) {
		return root;
	}

	// 왼쪽 서브트리와 오른쪽 서브트리에서 찾지 못한 경우 재귀 호출
	int leftParent = parent(child, root->left);
	if (leftParent != -1) {
		return root;
	}

	int rightParent = parent(child, root->right);
	return root;
}

TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;

	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q;

	q = t;
	while (q->left) q = q->left;
	printf("1. 중위순회 결과\n");
	do {
		
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q);
}

int main(void) {
	n1.right = &n3;
	n2.right = &n4;
	n4.right = &n11;
	n6.right = &n10;
	n7.right = &n9;

	thread_inorder(exp);
	printf("\n");

	TreeNode* parentValue = parent(&n4, exp);
	printf("n4 노드의 부모 노드 이름: %s\n", getNodeName(parentValue));
	TreeNode* parentValue2 = parent(&n5, exp);
	printf("n5 노드의 부모 노드 이름: %s\n", getNodeName(parentValue2));

	return 0;
}
