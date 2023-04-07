// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase06.c
// ============================
// A test of isReflection() that involves trees with a single node each (which
// happen to be very large and very small integers).


#include <limits.h>
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
	int success;

	// Two trees with single nodes.
	success =
		isReflection(zCreateNode(INT_MAX - 1), zCreateNode(INT_MAX - 1)) &&
		!isReflection(zCreateNode(INT_MAX - 1), zCreateNode(INT_MIN + 1));

	printf("%s\n", success ? "Hooray!" : "Fail whale. :(");

	return 0;
}
