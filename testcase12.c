// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase12.c
// ============================
// A few test cases for kindredSpirits().


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
	node *root1, *root2;


	// These trees are identical, but are not kindred spirits.
	root1 = zCreateNode(20);
	root1->right = zCreateNode(31);
	root1->right->right = zCreateNode(41);
	root1->right->right->left = zCreateNode(18);
	root1->right->right->right = zCreateNode(21);

	root2 = zCreateNode(20);
	root2->right = zCreateNode(31);
	root2->right->right = zCreateNode(41);
	root2->right->right->left = zCreateNode(18);
	root2->right->right->right = zCreateNode(21);

	printf("%s\n", (success = !kindredSpirits(root1, root2)) ? "Hooray!" : "Fail whale. :(");

	zTreeDestroyer(root1);
	zTreeDestroyer(root2);

	
	// These trees are identical, and they're also kindred spirits.
	root1 = zCreateNode(20);
	root1->right = zCreateNode(31);
	root1->right->right = zCreateNode(31);
	root1->right->right->right = zCreateNode(20);

	root2 = zCreateNode(20);
	root2->right = zCreateNode(31);
	root2->right->right = zCreateNode(31);
	root2->right->right->right = zCreateNode(20);

	printf("%s\n", (success = kindredSpirits(root1, root2)) ? "Hooray!" : "Fail whale. :(");


	// That means this tree is a kindred spirit of itself, which is beautiful.
	printf("%s\n", (success = kindredSpirits(root1, root1)) ? "Hooray!" : "Fail whale. :(");
	
	zTreeDestroyer(root1);
	zTreeDestroyer(root2);
	
	
	// These identical trees are also also kindred spirits.
	root1 = zCreateNode(15);
	root1->left = zCreateNode(15);
	root1->right = zCreateNode(15);
	root1->right->left = zCreateNode(15);
	root1->right->left->left = zCreateNode(15);
	root1->right->left->right = zCreateNode(15);
			
	root2 = zCreateNode(15);
	root2->left = zCreateNode(15);
	root2->right = zCreateNode(15);
	root2->right->left = zCreateNode(15);
	root2->right->left->left = zCreateNode(15);
	root2->right->left->right = zCreateNode(15);
	
	printf("%s\n", (success = kindredSpirits(root1, root2)) ? "Hooray!" : "Fail whale. :(");
	
	zTreeDestroyer(root1);
	zTreeDestroyer(root2);
	

	// These trees are not identical, but they are kindred spirits.
	root1 = zCreateNode(15);
	root1->left = zCreateNode(15);
	root1->right = zCreateNode(15);
	
	root2 = zCreateNode(15);
	root2->left = zCreateNode(15);
	root2->left->right = zCreateNode(15);

	printf("%s\n", (success = kindredSpirits(root1, root2)) ? "Hooray!" : "Fail whale. :(");
	
	zTreeDestroyer(root1);
	zTreeDestroyer(root2);

	return 0;
}
