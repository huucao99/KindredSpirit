// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase17.c
// ============================
// A test of kindredSpirits(). Includes trees that have extreme values.


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
	node *root1, *root2, *root3;


	// A variation on the trees from Figure 9 in the PDF. These contain the same values,
	// but are not kindred spirits.
	root1 = zCreateNode(INT_MIN);
	root1->left = zCreateNode(0);
	root1->left->left = zCreateNode(-1);
	root1->left->right = zCreateNode(INT_MIN + 1);
	root1->right = zCreateNode(INT_MAX - 1);
	root1->right->right = zCreateNode(INT_MAX);

	root2 = zCreateNode(INT_MIN);
	root2->left = zCreateNode(INT_MAX);
	root2->right = zCreateNode(INT_MAX - 1);
	root2->right->left = zCreateNode(-1);
	root2->right->left->right = zCreateNode(0);
	root2->right->right = zCreateNode(INT_MIN + 1);

	printf("%s\n", (success = !kindredSpirits(root1, root2)) ? "Hooray!" : "Fail whale. :(");
	
	
	// Just a quick check to make sure the function identifies kindred
	// spirits and doesn't always just return zero.
	root3 = zCreateNode(INT_MAX);
	root3->left = zCreateNode(INT_MIN);
	root3->right = zCreateNode(INT_MAX - 1);
	root3->right->left = zCreateNode(-1);
	root3->right->left->right = zCreateNode(0);
	root3->right->right = zCreateNode(INT_MIN + 1);
	
	printf("%s\n", (success = kindredSpirits(root1, root3)) ? "Hooray!" : "Fail whale. :(");
	
	zTreeDestroyer(root1);
	zTreeDestroyer(root2);
	zTreeDestroyer(root3);

	return 0;
}
