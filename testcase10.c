// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase10.c
// ============================
// A test of makeReflection() on large, randomly generated BSTs (and their
// reflections).


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

// Returns 1 if the two trees are identical in structure and contents.
// Otherwise, returns 0.
int zCompareTrees(node *root1, node *root2)
{
	// Two empty trees are identical.
	if (root1 == NULL && root2 == NULL)
		return 1;

	// If one is NULL, but they aren't both NULL, they are not identical.
	if (root1 == NULL || root2 == NULL)
		return 0;

	// If the values at these nodes differ, the trees differ.
	if (root1->data != root2->data)
		return 0;

	// Otherwise, compare the subtrees.
	return zCompareTrees(root1->left, root2->left) &&
	       zCompareTrees(root1->right, root2->right);
}

// Basic BST insertion functions. Doesn't allow insertion of duplicates. Oddly
// named so it won't conflict with any function definitions in the code you
// submitted, just in case for some odd reason you have a BST_insert() function
// in there.
node *zBSTinsert(node *root, int data)
{
	if (root == NULL)
		return zCreateNode(data);
	else if (data < root->data)
		root->left = zBSTinsert(root->left, data);
	else if (data > root->data)
		root->right = zBSTinsert(root->right, data);
	return root;
}

// This inserts into a BST in reflected order (so, smaller nodes go right and
// larger nodes go left). Does not allow duplicates. This function name is the
// mirror image of zBSTinsert, and is super cheeky. Don't do stuff like this in
// the real world.
node *tresniTSBz(node *root, int data)
{
	if (root == NULL)
		return zCreateNode(data);
	else if (data < root->data)
		root->right = tresniTSBz(root->right, data);
	else if (data > root->data)
		root->left = tresniTSBz(root->left, data);
	return root;
}

int main(void)
{
	int i, j, rval, success = 1;
	node *root1 = NULL, *root2 = NULL, *root3 = NULL;

	srand(time(NULL));

	// Let's generate 10 random trees (and their reflections) just to be sure we
	// get a decent sample. This has a huge memory leak, but the test case
	// shouldn't be problematic unless your code is slow and busted.
	for (i = 0; i < 10; i++)
	{
		// Generates a BST and its reflection.
		for (j = 0; j < 500; j++)
		{
			rval = rand() % 20001 - 10000;  // range: [-10k, 10k]

			root1 = zBSTinsert(root1, rval);
			root2 = tresniTSBz(root2, rval);  // reflection of the above BST
		}

		// Make the reflection of root1 (which should be equivalent to root2).
		root3 = makeReflection(root1);
		success = success && (root1 != root3) && isReflection(root1, root3);
	}

	printf("%s\n", (success == 0) ? "Fail whale. :(" : "Hooray!");

	return 0;
}
