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
    Node * head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    
    printLinkedList(head1);
    cout<<endl;
    Node * head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = head1->next->next;
    
    printLinkedList(head2);
    cout<<endl;
    
    int sum_head1 = getSum(head1);
    int sum_head2 = getSum(head2);
    
    //cout<<sum_head1<<" "<<sum_head2;
    
    
    int intersection = FindIntersection(head1, head2, sum_head1, sum_head2);
    
    if(intersection==-1)
        cout<<"No intersection point found !!";
    else
        cout<<"intersection point found at point : "<<intersection;
    return 0;
}

