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
Node* removeRepeated(Node* head)
{
    if(head==NULL)
        return NULL;
        
    Node* curr = head;
    Node* curr_next = head;
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            curr_next = curr->next->next;
            delete(curr->next);
            curr->next = curr_next;
        }
        else
            curr=curr->next;
        
    }
    return head;
}
int main()
{
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);
    
   
    printLinkedList(head);
    
    Node* updated = removeRepeated(head);
    cout<<endl;
    printLinkedList(updated);
    cout<<endl;
    return 0;
}

