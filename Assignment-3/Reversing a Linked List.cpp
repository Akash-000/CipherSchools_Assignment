#include <iostream>

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

Node* reverseLinkedList(Node* head)
{
    
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    Node* end = reverseLinkedList(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return end;
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    
   
    
    printLinkedList(head);
    
    cout<<endl;
    ///////////////////////////////////////////////////////////////////////////    RECURSIVE APPROACH
    
    
    //Node* rev = reverseLinkedList(head);
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////     ITERATIVE APPROACH
    Node* curr = head;
    
    Node* prev = NULL;
    
    Node* next = curr;
    
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr=next; 
    }
    
    head = prev;
    
    printLinkedList(head);
    return 0;
}

