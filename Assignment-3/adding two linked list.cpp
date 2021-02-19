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

int getLength(Node* head)
{
    int length=0;
    Node* curr = head;
    while(curr!=NULL)
    {
        length++;
        curr=curr->next;
    }
    return length;
}

Node* sumHelper(Node* head1, Node* head2, int diff)
{
    if(head1==NULL)
        return NULL;
        
    Node* result = NULL;
    if(diff==0)
    {
        result = new Node(head1->data + head2->data);
    }
    else
    {
        result = new Node(head1->data);
    }
    
    Node* next_sum=NULL;
    
    if(diff==0)
    {
        next_sum = sumHelper(head1->next, head2->next, diff); 
    }
    else
    {
        next_sum = sumHelper(head1->next, head2, diff-1);
    }
        
    
   
    
    if(next_sum!=NULL && next_sum->data>9)
    {
        next_sum->data = next_sum->data %10;
        
        result->data = result->data+1;
    }
    
    result->next = next_sum;
    return result;
}




Node* sum(Node* head1, Node* head2)
{
    if(head1==NULL)
    {
        return NULL;
    }
    
    int len_head1 = getLength(head1);
    int len_head2 = getLength(head2);
    
    Node* res = NULL;
    
    if(len_head1>len_head2)
    {
        int diff = len_head1 - len_head2;
        res = sumHelper(head1, head2, diff);
        
    }
    else
    {
        int diff = len_head2 - len_head1;
        res = sumHelper(head2, head1, diff);
    }
    
    
    
    Node* temp=new Node(1);
    
    if(res->data>9)
    {
        res->data = res->data%10;
        temp->next=res;
        res = temp;
    }
    return res;
}


int main()
{
    Node* head1 = new Node(9);
    head1->next = new Node(9);
    Node* head2 = new Node(9);
    head2->next = new Node(9);
    head2->next->next = new Node(9);
    
    
    Node* result_sum = sum(head1, head2);
    
    


    printLinkedList(result_sum);
}
