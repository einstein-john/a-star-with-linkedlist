/* Trees.h
 * Definitions of type and functions for
 * Tree implementations.*/

struct  node {
	int data;
    int cost;
	struct node * left;
	struct node * right;
};

struct node * newNode(int d, int c)
{
	struct node *temp;
	temp=(struct node *) malloc(sizeof(node));
	temp->data=d;
    temp->cost = c;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
