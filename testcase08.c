// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase08.c
// ============================
// A test of makeReflection() and isReflection() on tall, randomly generated
// trees.


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

// Makes a tree of height (n - 1) with n nodes. The node values are randomly
// generated on the range [-100, 100]. A node may have a left or right child,
// but not both. (And of course, there's one leaf node with exactly zero
// children.)
void makeRandomSticks(node **root1, node **root2, int n)
{
	int i, rval;
	node *leaf1 = NULL, *leaf2 = NULL;

	if (n == 0)
	{
		*root1 = *root2 = NULL;
		return;
	}

	// Initialize. This is kind of dangerous, beacuse it could create a memory
	// leak if we pass in pointers to trees that are non-empty. So, be careful
	// with that.
	*root1 = *root2 = NULL;

	for (i = 0; i < n; i++)
	{
		rval = rand() % 201 - 100;

		if (*root1 == NULL)
		{
			// We can assume that if root1 is NULL, so is root2.
			*root1 = leaf1 = zCreateNode(rval);
			*root2 = leaf2 = zCreateNode(rval);
		}
		else if (rand() % 2)
		{
			// Go left in first tree, right in second tree.
			leaf1->left = zCreateNode(rval);
			leaf1 = leaf1->left;

			leaf2->right = zCreateNode(rval);
			leaf2 = leaf2->right;
		}
		else
		{
			// Go right in first tree, left in second tree.
			leaf1->right = zCreateNode(rval);
			leaf1 = leaf1->right;

			leaf2->left = zCreateNode(rval);
			leaf2 = leaf2->left;
		}
	}
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

int main(void)
{
	int i, success = 1;
	node *root1 = NULL, *root2 = NULL, *root3 = NULL;

	srand(time(NULL));

	// Let's generate 10 random trees (and their reflections) just to be sure we
	// get a decent sample. This has a gross memory leak, but the test case
	// shouldn't be problematic unless your code is slow and busted.
	for (i = 0; i < 10; i++)
	{
		makeRandomSticks(&root1, &root2, 100);
		root3 = makeReflection(root1);

		success = success &&
			      (root1 != root3) &&
			      isReflection(root1, root2) &&
			      isReflection(root1, root3) &&
			      zCompareTrees(root2, root3);
	}

	printf("%s\n", success ? "Hooray!" : "Fail whale. :(");

	return 0;
}
