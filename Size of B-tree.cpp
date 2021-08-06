//C++ program to calculate the size of the B-tree
#include <bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node* left;
    node* right;
};
 
//To allocates a new node with the given data and NULL left and right pointers.
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
         
    return(Node);
}
 
/* Computes the number of nodes in a tree. */
int size(node* node)
{
    if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}
 
//Main 
int main()
{
    node *root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(9);
    root->left->left = newNode(1);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(11);
     
    cout << "Size of the tree is " << size(root);
    return 0;
}
 
