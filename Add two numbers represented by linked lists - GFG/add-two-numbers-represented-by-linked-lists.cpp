//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node *reverseLL(struct Node *head){
        Node *curr = head;
        Node *temp = NULL;
        Node * prev = NULL;
        while (curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void insertAtTail(int digit,struct Node* &ansHead, struct Node* &ansTail){
        Node* temp = new Node(digit);
        if(ansHead == NULL){
            ansHead = temp;
            ansTail = temp;
        }
        else{
            ansTail->next = temp;
            ansTail = temp;
        }
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first = reverseLL(first);
       second = reverseLL(second);
       int carry = 0;
       Node* ansHead = NULL;
       Node* ansTail = NULL;
       while ( first != NULL && second != NULL){
           int sum = carry + first->data + second->data;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
           first = first->next;
           second = second->next;
       }
       while(first != NULL){
           int sum = carry + first->data;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
           first = first->next;
       }
       while(second != NULL){
           int sum = carry + second->data;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
           second = second->next;
       }
       while(carry != NULL){
           int sum = carry;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
       }
       ansHead = reverseLL(ansHead);
       return ansHead;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends