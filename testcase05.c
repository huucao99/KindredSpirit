// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase05.c
// ============================
// A short test to ensure that isReflection(NULL, NULL) returns 1, since an
// empty is a reflection of itself. Also verifies that isReflection() is not
// always just returning 1 no matter what.


#include <stdio.h>
#include <stdlib.h>
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
	int success1, success2;
	node *root1, *root2;

	// The empty tree is considered a reflection of itself.
	success1 = isReflection(NULL, NULL);
	printf("%s\n", success1 ? "Hooray!" : "Fail whale. :(");

	root1 = zCreateNode(50);
	root1->left = zCreateNode(40);
	root1->right = zCreateNode(60);
	root1->left->right = zCreateNode(45);

	root2 = zCreateNode(50);
	root2->left = zCreateNode(40);
	root2->right = zCreateNode(60);
	root2->left->right = zCreateNode(45);

	success2 = isReflection(root1, root2);
	printf("%s\n", !success2 ? "Hooray!" : "Fail whale. :(");

	return 0;
}
