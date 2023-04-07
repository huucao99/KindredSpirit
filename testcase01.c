// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase01.c
// ============================
// A small test of isReflection(). The function should return false because the
// two trees it receives are not reflections of one another.


#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

// A pretty standard createNode() function. Creates a new binary tree node,
// initializes its members, and returns a pointer to the new node. I've renamed
// this so that it won't cause conflicts if someone else has defined a
// createNode() function in their program submission.
node *zCreateNode(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->left = n->right = NULL;

	return n;
}

// This function is included to ensure that your isReflection has to return
// both 1 and 0, in order to ensure that it's not just always returning one
// value or the other in hopes of receiving some credit without actually
// doing anything useful. Returns 1 if both test cases are successful, zero
// otherwise.
int OneZeroCheck(void)
{
	int success1, success2;
	node *root1, *root2, *root3;

	// Manually build a binary tree.
	root1 = zCreateNode(15);
	root1->left = zCreateNode(1);
	root1->right = zCreateNode(2);

	// Create a copy of the tree above. This tree is not a reflection of itself.
	root2 = zCreateNode(15);
	root2->left = zCreateNode(1);
	root2->right = zCreateNode(2);

	// Create a reflection of the tree above.
	root3 = zCreateNode(15);
	root3->left = zCreateNode(2);
	root3->right = zCreateNode(1);

	success1 = !isReflection(root1, root2);
	success2 = isReflection(root2, root3);

	printf("%s\n", success1 ? "Hooray!" : "Fail whale. :(");
	printf("%s\n", success2 ? "Hooray!" : "Fail whale. :(");

	return success1 && success2;
}

int main(void)
{
	OneZeroCheck();
	return 0;
}
