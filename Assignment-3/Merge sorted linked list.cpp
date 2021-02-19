#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data = data;
        next=NULL;
    }
};

void printLinkedList(Node* head)
{
    if(head == NULL)
        return;
        
    cout<<head->data<<"->";
    
    return printLinkedList(head->next);
}

Node* mergesort(Node* head1, Node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
        
    
    if(head1->data < head2->data)
    {
        head1->next = mergesort(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergesort(head1, head2->next);
        return head2;
    }
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    
    printLinkedList(head1);
    cout<<endl;
    
    printLinkedList(head2);
    cout<<endl;
    
    Node* updated = mergesort(head1, head2);
    
    printLinkedList(updated);
    
}

