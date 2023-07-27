//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverseLL(Node *head){
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
    Node* addOne(Node *head) 
    {
     Node *temp = reverseLL(head);
     Node * newHead = temp;
     int carry = 0;
     int sum = carry + 1 + temp->data;
     int digit = sum%10;
     temp->data = digit;
     carry = sum/10;
     while(carry != NULL && temp->next != NULL){
         temp = temp->next;
         int sum = carry + temp->data;
         int digit = sum%10;
         temp->data = digit;
         carry = sum/10;
     }
     if(carry != NULL){
         Node *last = new Node(carry);
        //  last->data = carry;
         last->next = NULL;
         temp->next = last;
         temp = last;
     }
      temp = newHead;
      temp = reverseLL(temp);
      return temp;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends