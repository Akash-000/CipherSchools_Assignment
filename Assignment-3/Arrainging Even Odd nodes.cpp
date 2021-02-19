#include <iostream>

using namespace std;

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

int getSum(Node* head)
{
    int sum =0;
    Node* curr = head;
    while(curr!=NULL)
    {
        sum+=curr->data;
        curr=curr->next;
    }
    return sum;
}

int FindIntersection(Node* head1, Node* head2, int sum_head1, int sum_head2)
{
    Node* curr1 = head1;
    Node* curr2 = head2;
    
    if(head1==NULL || head2 == NULL)
        return -1;
        
    while(curr1!=NULL|| curr2!=NULL)
    {
        sum_head1-=curr1->data;
        sum_head2-=curr2->data;
        if(sum_head2==sum_head1)
            return curr1->next->data;
            
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}

int main()
{
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    
    cout<<"Before Arranging Even Odd Nodes :-"<<endl;
    printLinkedList(head);
    cout<<endl;
    cout<<"After Arranging Even Odd nodes :-"<<endl;
    
    Node* curr=head;
    Node* curr_next = curr->next;
    Node* curr_next_ptr = curr->next;
    
    while(curr_next->next!=NULL)
    {
        curr->next = curr_next->next;
        curr=curr->next;
        curr_next->next = curr->next;
        curr_next = curr_next->next;
    }
    
    curr->next = curr_next_ptr;
    
    printLinkedList(head);
    cout<<endl;
    //printLinkedList(curr_next_ptr);
    return 0;
}

