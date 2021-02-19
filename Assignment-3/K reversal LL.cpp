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

Node* kreversal(Node* head, int k)
{
    Node* curr = head;
    Node* prevfirst=NULL;
    
    bool firstpass=true;
    
    while(curr!=NULL)
    {
        Node* first = curr, *prev = NULL;
        int count=0;
        while(curr!=NULL && count<k)
        {
            Node * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
            count++;
        }
        if(firstpass)
        {
            head=prev;
            firstpass = false;
        }
        else
        {
            prevfirst->next = prev;
        }
        prevfirst = first;
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
    
    cout<<endl<<"Enter value of K :  ";
    int k;
    cin>>k;
    
    Node* updated = kreversal(head, k);
    
    printLinkedList(updated);
}
