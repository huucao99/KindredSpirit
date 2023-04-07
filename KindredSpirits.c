
// HUU NGOC CHINH CAO
// 4529434
// COP 3502C 00308
// FALL SEMESTER 2018


#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

int countNodes(node *root);
node *cloneTree(node *root);
node *reflect(node *root);
node *forestFire(node *root);
void swap(node **left, node **right);
void preO(node *root, int *arr, int *i);
void postO(node *root, int *arr, int *i);

//A function to determine whether the trees rooted at a and b are reflections of one another 
int isReflection(node *a, node *b)
{
	// Both trees are NULL or it has gone through both trees without any offsets
	if(a == NULL && b == NULL)
		return 1;
	// If one is NULL when the other is not the they cannot be reflections of eachother
	if(a == NULL || b == NULL)
		return 0;
	// If the data in the supposedly reflected nodes are not equal then they cannot be reflections of eachother
	if(a->data != b->data)
		return 0;
	// Recursively goes through both trees
	return (isReflection(a->left, b->right) && isReflection(a->right, b->left));
}

//A function that creates a new tree, which is a reflection of the tree rooted at root
node *makeReflection(node *root)
{
	//return the reflected clone tree
	return reflect(cloneTree(root));
}

//A function that determines whether the trees rooted at a and b are kindred spirits
int kindredSpirits(node *a, node *b)
{
	int n;
	int i = 0;
	int x = 1;
	int y = 1;
	int *preOa = NULL, *postOa = NULL, *preOb = NULL, *postOb = NULL;
	
	//Case both emty tree -> they are kindred spirits
	if (a == NULL && b == NULL)
		return 1;
	
	//Case both tree's nodes are not equal
	if (countNodes(a) != countNodes(b))
		return 0;
	
	//Case both tree's nodes are equal
	n = countNodes(a);
	
	//preOa is an array of nodes rooted at a in preorder
	preOa = malloc(n * sizeof(int));
	//postOa is an array of nodes rooted at a in postorder
	postOa = malloc(n * sizeof(int));
	//preOb is an array of nodes rooted at b in preorder
	preOb = malloc(n * sizeof(int));
	//postOb is an array of nodes rooted at b in postorder
	postOb = malloc(n * sizeof(int));
	
	//Malloc fail check
	if (preOa == NULL || postOa == NULL || preOb == NULL || postOb == NULL)
		return 0;
	
	preO(a, preOa, &i);
	//Recover i
	i = 0;
	postO(a, postOa, &i);
	//Recover i
	i = 0;
	
	preO(b, preOb, &i);
	//Recover i
	i = 0;
	postO(b, postOb, &i);
	
	//Check if a and b are kindred spirits by go through the arrays
	for (i = 0; i < n; i++)
	{
		if (preOa[i] != postOb[i])
			x = 0;
		
		if (postOa[i] != preOb[i])
			y = 0;
	}

	//Return 1 if x or y is 1
	return (x || y);
}

//Difficult rating for this assignment
double difficultyRating(void)
{
	return 2.5;
}

//Time that I spent for this assignment
double hoursSpent(void)
{
	return 6.0;
}

//Helper functions
//This is Dr.Szumlanski's function from class for counting nodes in tree
int countNodes(node *root)
{
	if (root == NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
}

//This is Dr.Szumlanski's function to free the tree
node *forestFire(node *root)
{
	if (root == NULL)
		return NULL;

	forestFire(root->left);
	forestFire(root->right);
	free(root);

	return NULL;
}

//This function clone original tree and return root of clone tree
node *cloneTree(node *root)
{
	node *newRoot = NULL;
	
	//Case the original tree is empty
	if (root == NULL)
		return newRoot;
	
	//If the original is not empty, then malloc
	newRoot = malloc(sizeof(node));
	
	//Malloc fail check
	if (newRoot == NULL)
		return NULL;
	
	//Cloning data
	newRoot->data = root->data;
	
	//Clone left and right child
	newRoot->left = cloneTree(root->left);
	newRoot->right = cloneTree(root->right);
	
	return newRoot;
}

//This function reflect the tree and return root of reflected tree
node *reflect(node *root)
{
	//Case root is NULL
	if (root == NULL)
		return root;

	//Recursive through the end of the tree
	reflect(root->left);
	reflect(root->right);
	
	//Swap left and right child
	swap(&root->left, &root->right);
	
	return root;
}

//This function swap left child and right child
void swap(node **left, node **right)
{
	node *temp;
	
	//Case both left and right child are NULL
	if (*left == NULL && *right == NULL)
		return;
	
	//Case only left child empty
	if (*left == NULL)
	{
		*left = *right;
		forestFire(*right);
		return;
	}
	
	//Case only right child empty
	if (*right == NULL)
	{
		*right = *left;
		forestFire(*left);
		return;
	}
	
	//Both right and left are not empty
	temp = *left;
	*left = *right;
	*right = temp;
}

//Store nodes rooted at root to array in preorder
void preO(node *root, int *arr, int *i)
{
	//Case no root or end of tree
	if (root == NULL)
		return;
	
	arr[(*i)++] = root->data;
	
	preO(root->left, arr, i);
	preO(root->right, arr, i);
}

//Store nodes rooted at root to array in postorder
void postO(node *root, int *arr, int *i)
{
	//Case no root or end of tree
	if (root == NULL)
		return;
	
	postO(root->left, arr, i);
	postO(root->right, arr, i);
	
	arr[(*i)++] = root->data;

}