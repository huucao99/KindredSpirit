// Sean Szumlanski
// COP 3502, Fall 2018

// ============================
// KindredSpirits: testcase07.c
// ============================
// A test of isReflection() to ensure that positive and negative values are both
// handled well.


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
	int success = 1;

	// Just making sure negative values don't cause weird breakage. These test
	// cases are leaky as hell, by the way.
	success = success && !isReflection(zCreateNode(1), zCreateNode(-1));
	success = success && !isReflection(zCreateNode(-1), zCreateNode(1));
	success = success && isReflection(zCreateNode(-1), zCreateNode(-1));
	success = success && isReflection(zCreateNode(INT_MIN + 1), zCreateNode(INT_MIN + 1));

	printf("%s\n", success ? "Hooray!" : "Fail whale. :(");

	return 0;
}
