//in struct node data == heuristic value

#include <cstdlib>
#include <iostream>
#include "TreesA.h"


using namespace std;



void aStar(struct node *);

int main(int argc, char *argv[])
{
   


    struct node *tree = newNode(8,0);
    struct node *a = NULL;	
  
int A = 4;
int b = 4;
int c = 4;
int d = 5;
int g = 0;	
	

//create the branches of the  nodes
	 //s->a
   a = newNode(A,1);
    tree->left = a;
  //s->g
  a = newNode(g,12);
    tree->right = a;
    
    	 //s->a->c
    a = newNode(c,1);
    tree->left->left = a;
    	 //s->a->b
       a = newNode(b,3);
    tree->left->right = a;

   	 //s->a->c->g
   a = newNode(g,2);
    tree->left->left->left = a;
     	 //s->a->c->d
       a = newNode(d,1);
    tree->left->left->right = a;
   //s->a->b->d
   a = newNode(d,3);
    tree->left->right->right = a;
      
      	 //s->a->c->d->g
    a = newNode(d,1);
    tree->left->left->right->right = a;
   //s->a->b->d->g
   a = newNode(g,3);
    tree->left->right->right->right = a;


   //displayAllTree(tree, "tree");

	 aStar(tree);

	 

    system("PAUSE");
    return EXIT_SUCCESS;
}

void aStar(struct node *temp) {
 int a,b;
  if (temp == NULL) {
    return;
  }


  if (temp->left == NULL && temp->right == NULL) {
    cout << "End of tree \n";
    return;
  }
//ensuer you are not pointing to a null node
  if (temp->left == NULL) {
    a = temp->right->data + temp->right->cost;
  } else {
    a = temp->left->data + temp->left->cost;
  } 

  if (temp->right == NULL) {
    b = a;
  } else {
    b = temp->right->data + temp->right->cost;
  }

//compare sum of heuristic value and cost to node
  if (a < b) {
    cout << "L -> ";
    if(a == 0)
    return;
    if (temp->left != NULL) {
      aStar(temp->left);
    }
  } else {
    cout << "R -> ";
     if(b == 0)
    return;
    if (temp->right != NULL) {
      aStar(temp->right);
    }
  }
}
