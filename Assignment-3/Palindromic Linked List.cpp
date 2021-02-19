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
int LLlength(Node* head)
{
    int length=0;
    while(head!=NULL){
        length++;
        head=head->next;
    }
    return length;
}

Node* findMiddle(Node* head)
{
    Node* slow=head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseList(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;
        
    Node* end = reverseList(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return end;
}

bool isPalindromeEven(Node* head)
{
    Node* mid = findMiddle(head);
    
    Node* rev = reverseList(mid);
    
    cout<<endl;
    while(rev!=NULL)
    {
        if(head->data !=rev->data)
            return false;
            
        head=head->next;
        rev=rev->next;
    }
    
    return true;
    
}

bool isPalindromeOdd(Node* head)
{
    Node* mid = findMiddle(head);
    
    Node* etcmid = new Node(mid->data);
    etcmid->next = mid->next;
    mid->next = etcmid;
    
    return isPalindromeEven(head);
}


int main()
{
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(4);
    
    
    printLinkedList(head);
    cout<<endl;
    
    int len = LLlength(head);
    bool flag=false;
    if(len%2==1)
        flag = isPalindromeOdd(head);
    else
        flag = isPalindromeEven(head);
        
    
    if(flag)
        cout<<"plaindrome";
    else
        cout<<"Not Palindrome";
    
    cout<<endl;
}
