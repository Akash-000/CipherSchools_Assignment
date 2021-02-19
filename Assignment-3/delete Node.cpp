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

Node* deleteNode(Node* head, int k)
{
    
    if(head==NULL)
        return NULL;
        
    if(head->data==k)
        return head->next;
    
    Node* curr=head;
    
    while(curr!=NULL)
    {
        if(curr->next->data == k)
        {
            curr->next = curr->next->next;
            break;
        }
        else
            curr=curr->next;
    }
    
    return head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    printLinkedList(head);
    
    cout<<endl;
    
    cout<<"data to be deleted : ";
    int k=0;
    cin>>k;
    
    Node* updated = deleteNode(head, k);
    
    printLinkedList(updated);
}
