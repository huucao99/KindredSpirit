// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase11.c
// ============================
// A test of kindredSpirits(), based on the test cases released with the
// assignment PDF.


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

int main(void)
{
	int success;
	node *node1, *node2, *node3, *root5, *root6;

	// Let's establish some trees with just a single element.
	node1 = zCreateNode(15);
	node2 = zCreateNode(15);
	node3 = zCreateNode(14);

	// These are the trees from Figure 9 in the assignment PDF, used for testing
	// the kindredSpirits function.
	root5 = zCreateNode(23);
	root5->left = zCreateNode(12);
	root5->left->left = zCreateNode(5);
	root5->left->right = zCreateNode(18);
	root5->right = zCreateNode(71);
	root5->right->right = zCreateNode(56);

	root6 = zCreateNode(56);
	root6->left = zCreateNode(23);
	root6->right = zCreateNode(71);
	root6->right->left = zCreateNode(5);
	root6->right->left->right = zCreateNode(12);
	root6->right->right = zCreateNode(18);

	success =
		kindredSpirits(root5, root6) &&
		kindredSpirits(root6, root5) &&
		!kindredSpirits(root5, root5) &&
		kindredSpirits(NULL, NULL) &&
		kindredSpirits(node1, node2) &&
		!kindredSpirits(node2, node3);

	printf("%s\n", success ? "Hooray!" : "Fail whale. :(");

	return 0;
}
