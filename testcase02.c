// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase02.c
// ============================
// A small test of makeReflection(). This test case also verifies that
// makeReflection() is not simply returning the root that it receives as an
// argument.


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

int main(void)
{
	int success;
	node *root1, *root2;

	// Let's build a tree! This is a super hacky and terrible way of making the
	// left binary tree from Figure 1 in the assignment PDF. Please don't ever
	// do anything this terrible, hacky, and inelegant in your code.
	root1 = zCreateNode(10);
	root1->left = zCreateNode(20);
	root1->right = zCreateNode(30);
	root1->right->left = zCreateNode(40);
	root1->right->right = zCreateNode(1);

	// Construct the reflection of the tree, and ensure that that the
	// isReflection() function works.
	success = isReflection(root1, root2 = makeReflection(root1));

	// Make sure isReflection() isn't just returning the root of the tree it
	// received. (SO CHEEKY!)
	success = success && (root1 != root2);

	printf("%s\n", success ? "Hooray!" : "Fail whale. :(");

	return 0;
}
