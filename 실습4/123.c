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
TreeNode n7 = { 10, NULL, NULL, 0 };
TreeNode n8 = { 11, NULL, NULL, 0 };
TreeNode n9 = { 9, &n7, &n8, 0 };
TreeNode n10 = { 7, &n6, &n9, 0 };
TreeNode n11 = { 1, &n5, &n10, 0 };
TreeNode* exp = &n11;

TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q;

	q = t;
	while (q->left) q = q->left;
	do {
		printf("%c ->", q->data);
		q = find_successor(q);
	} while (q);
}

int min(void) {
	n1.right = &n3;
	n2.right = &n4;
	n4.right = &n11;
	n6.right = &n10;
	n10.right = &n9;

	thread_inorder(exp);
	printf("\n");
	return 0;
}
