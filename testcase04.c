// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase04.c
// ============================
// A short test to ensure that makeReflection(NULL) returns NULL, since the
// reflection of an empty tree is just an empty tree. Also verifies that
// makeReflection() is not always just returning NULL no matter what.


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

	// The reflection of an empty tree is an empty tree.
	success1 = (makeReflection(NULL) == NULL);
	printf("%s\n", success1 ? "Hooray!" : "Fail whale. :(");

	root1 = zCreateNode(50);
	root2 = makeReflection(root1);

	success2 = (root2 != NULL && root2 != root1);
	printf("%s\n", success2 ? "Hooray!" : "Fail whale. :(");

	return 0;
}
