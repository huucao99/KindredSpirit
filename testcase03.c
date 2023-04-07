// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase03.c
// ============================
// A more paranoid test of makeReflection(). Rather than relying on
// isReflection(), it manually checks that the new tree's structure and contents
// are as expected.


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

	// Make a reflection of this tree.
	root2 = makeReflection(root1);

	// This is a very direct and hacky-horrible way of checking the tree's
	// structure manually, just in case I don't trust your isReflection() code.
	success = (
		// Check root node
		root2->data == 10 &&
		root2->left != NULL &&
		root2->right != NULL &&

		// Check node 20
		root2->right->data == 20 &&
		root2->right->left == NULL &&
		root2->right->right == NULL &&

		// Check node 30
		root2->left->data == 30 &&
		root2->left->left != NULL &&
		root2->left->right != NULL &&

		// Check node 1
		root2->left->left->data == 1 &&
		root2->left->left->left == NULL &&
		root2->left->left->right == NULL &&

		// Check node 40
		root2->left->right->data == 40 &&
		root2->left->right->left == NULL &&
		root2->left->right->right == NULL
	);

	// Make sure isReflection() isn't just returning the root of the tree it
	// received. (SO CHEEKY!)
	success = success && (root1 != root2);

	printf("%s\n", success ? "Hooray!" : "Fail whale. :(");

	return 0;
}
