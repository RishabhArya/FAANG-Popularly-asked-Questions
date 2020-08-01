// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
void remove(Node *slow_ptr,Node *head);
void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *fast_ptr = head;
    Node *slow_ptr = head;
    while (fast_ptr != NULL && fast_ptr -> next != NULL){
        fast_ptr = fast_ptr -> next ->next;
        slow_ptr = slow_ptr ->next;
        if(slow_ptr == fast_ptr){
            remove(slow_ptr , head);
        }
        
    }
}
void remove(Node *slow_ptr,Node *head){
    Node *ptr_frst = slow_ptr;
    Node *ptr_scd = slow_ptr;
    int k=1;
    while(ptr_frst ->next !=ptr_scd){
        ptr_frst = ptr_frst ->next;
        k++;
    }
    ptr_frst = head;
    ptr_scd = head;
    for(int i=0;i < k; k++){
        ptr_scd = ptr_scd -> next;    
    }
    while (ptr_frst != ptr_scd){
        ptr_frst = ptr_frst ->next;
        ptr_scd = ptr_scd ->next;
    }
    while(ptr_scd ->next != ptr_frst){
        ptr_scd = ptr_scd ->next;
    }
    ptr_scd ->next = NULL;
}