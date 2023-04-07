// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase13.c
// ============================
// A large test case for kindredSpirits().


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "KindredSpirits.h"

node *zCreateNode(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->left = n->right = NULL;

	return n;
}

void mpreorder(node *root)
{
	if (root == NULL) return;
	
	printf("%d ", root->data);
	mpreorder(root->left);
	mpreorder(root->right);
}

void mpostorder(node *root)
{
	if (root == NULL) return;
	
	mpostorder(root->left);
	mpostorder(root->right);
	printf("%d ", root->data);
}

node *zTreeDestroyer(node *root)
{
	if (root == NULL)
		return NULL;
		
	zTreeDestroyer(root->left);
	zTreeDestroyer(root->right);
	free(root);
	return NULL;
}

int main(void)
{
	int success;
	node *root1, *root2;
	
	// The preorder traversal of this tree is:
	// 15 93 92 105 82 83 92 1 59 235 105 120 39 510 23 5 1 90 1 9 50 1 34 51 9 3 4
	root1 = zCreateNode(15);
	root1->left = zCreateNode(93);
	root1->left->right = zCreateNode(92);
	root1->left->right->left = zCreateNode(105);
	root1->left->right->left->left = zCreateNode(82);
	root1->left->right->left->right = zCreateNode(83);
	root1->left->right->left->right->right = zCreateNode(92);
	root1->left->right->left->right->right->left = zCreateNode(1);
	root1->left->right->left->right->right->right = zCreateNode(59);
	root1->left->right->right = zCreateNode(235);
	root1->left->right->right->left = zCreateNode(105);
	root1->left->right->right->left->right = zCreateNode(120);
	root1->left->right->right->left->right->left = zCreateNode(39);
	root1->left->right->right->right = zCreateNode(510);
	root1->left->right->right->right->right = zCreateNode(23);
	root1->right = zCreateNode(5);
	root1->right->left = zCreateNode(1);
	root1->right->right = zCreateNode(90);
	root1->right->right->left = zCreateNode(1);
	root1->right->right->left->left = zCreateNode(9);
	root1->right->right->left->left->left = zCreateNode(50);
	root1->right->right->left->left->right = zCreateNode(1);
	root1->right->right->left->left->right->right = zCreateNode(34);
	root1->right->right->right = zCreateNode(51);
	root1->right->right->right->right = zCreateNode(9);
	root1->right->right->right->right->left = zCreateNode(3);
	root1->right->right->right->right->right = zCreateNode(4);
	
	mpreorder(root1);
	printf("\n");
	
	// The postorder traversal of this tree is:
	// 15 93 92 105 82 83 92 1 59 235 105 120 39 510 23 5 1 90 1 9 50 1 34 51 9 3 4
	root2 = zCreateNode(4);
	root2->right = zCreateNode(3);
	root2->right->left = zCreateNode(9);
	root2->right->left->right = zCreateNode(51);
	root2->right->left->right->left = zCreateNode(34);
	root2->right->left->right->left->left = zCreateNode(1);
	root2->right->left->right->left->left->right = zCreateNode(50);
	root2->right->left->right->left->left->left = zCreateNode(9);
	root2->right->left->left = zCreateNode(1);
	root2->right->left->left->right = zCreateNode(90);
	root2->right->left->left->right->right = zCreateNode(1);
	root2->right->left->left->right->left = zCreateNode(5);
	root2->right->left->left->right->left->left = zCreateNode(23);
	root2->right->left->left->right->left->left->right = zCreateNode(510);
	root2->right->left->left->right->left->left->right->right = zCreateNode(39);
	root2->right->left->left->right->left->left->right->left = zCreateNode(120);
	root2->right->left->left->right->left->left->left = zCreateNode(105);
	root2->right->left->left->right->left->left->left->left = zCreateNode(235);
	root2->right->left->left->right->left->left->left->left->right = zCreateNode(59);
	root2->right->left->left->right->left->left->left->left->right->right = zCreateNode(1);
	root2->right->left->left->right->left->left->left->left->right->right->left = zCreateNode(92);
	root2->right->left->left->right->left->left->left->left->right->right->left->right = zCreateNode(83);
	root2->right->left->left->right->left->left->left->left->right->right->left->right->left = zCreateNode(82);
	root2->right->left->left->right->left->left->left->left->right->right->left->left = zCreateNode(105);
	root2->right->left->left->right->left->left->left->left->right->right->left->left->left = zCreateNode(92);
	root2->right->left->left->right->left->left->left->left->right->right->left->left->left->right = zCreateNode(93);
	root2->right->left->left->right->left->left->left->left->right->right->left->left->left->left = zCreateNode(15);

	mpostorder(root2);
	printf("\n");

	// The two trees are kindred spirits.
	printf("%s\n", (success = kindredSpirits(root1, root2)) ? "Hooray!" : "Fail whale. :(");

	// That means they're kindred spirits when passing them in the reverse order too, of course.
	printf("%s\n", (success = kindredSpirits(root2, root1)) ? "Hooray!" : "Fail whale. :(");

	// But neither tree is a kindred spirit of itself.
	printf("%s\n", (success = !kindredSpirits(root1, root1)) ? "Hooray!" : "Fail whale. :(");

	printf("%s\n", (success = !kindredSpirits(root2, root2)) ? "Hooray!" : "Fail whale. :(");
	
	zTreeDestroyer(root1);
	zTreeDestroyer(root2);
	
	return 0;
}
