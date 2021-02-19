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


void detectLoopAndRemove(Node* head)
{
    if(head==NULL)
        return ;
        
    Node* curr=head;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow = slow->next;
        
        if(fast==slow)
        {
            slow =curr;
            break;
        }
    }
    
    while(fast->next!=slow->next)
    {
        fast = fast->next;
        slow=slow->next;
    }
    fast->next=NULL;
    return;
}



int main()
{
    Node* head =new Node(1);
    Node* second = new Node(2);
    head->next = second;
    
    Node* third = new Node(3);
    second->next = third;
    Node* fourth = new Node(4);\
    third->next = fourth;
    Node* fifth = new Node(5);
    fourth->next = fifth;
    Node* sixth = new Node(6);
    fifth->next = sixth;
    sixth->next = third;

    detectLoopAndRemove(head);
    
    
        
    printLinkedList(head);
}
