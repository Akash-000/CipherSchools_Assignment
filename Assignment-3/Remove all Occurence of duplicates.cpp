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
void removeRepeated(Node* head)
{
    
    if(head==NULL)
        return;
        
    Node* curr=head;
    Node* temphead = new Node(0);
    temphead->next = head;
    Node* prev = temphead;
    
    while(curr!=NULL)
    {
        while(curr->next!=NULL && prev->next->data==curr->next->data)
            curr=curr->next;
        
        
        if(prev->next==curr)
            prev=prev->next;
                
        else
        {
            prev->next=curr->next;
        }
        curr=curr->next;
    }
    head=temphead->next;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(5);
    
    printLinkedList(head);
    
    removeRepeated(head);
    cout<<endl;
    printLinkedList(head);
    cout<<endl;
    return 0;
}

