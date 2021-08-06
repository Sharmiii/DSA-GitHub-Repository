//Program to get intersection point of two linked list
#include <bits/stdc++.h>
using namespace std;
 
/* Singly linked list */
class Node 
{
public:
    int data;
    Node* next;
};
 
/*To get the counts of node in a linked list */
int getCount(Node* head);
 
/*To get the intersection point of two linked lists */
int _getIntesectionNode(int d, Node* head1, Node* head2);

int getIntesectionNode(Node* head1, Node* head2)
{
 
    // Count the number of nodes in a linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
 
    if (c1 > c2)
    {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else
    {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}
 

int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;
 
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
 
    /* Move both pointers of both list till they intersect with each other */
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
 
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
 
    return -1;
}
 
/* Takes head pointer of the linked list and
returns the count of nodes in the list */
int getCount(Node* head)
{
    Node* current = head;
 
    int count = 0;
 
    while (current != NULL) {
 
        count++;
 
        // Move the Node ahead
        current = current->next;
    }
 
    return count;
}
 
// Main
int main()
{
    
    Node* newNode;
 
    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 6;
 
    Node* head2 = new Node();
    head2->data = 1;
 
    newNode = new Node();
    newNode->data = 2;
    head2->next = newNode;
 
    newNode = new Node();
    newNode->data = 5;
    head2->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 7;
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 4;
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
 
    cout << "The node of intersection is " << getIntesectionNode(head1, head2);
}