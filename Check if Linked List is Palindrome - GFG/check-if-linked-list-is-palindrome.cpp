//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
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
    Node *getMid(Node *head){
        Node *slow = head;
        Node *fast = head;
        Node *prev = NULL;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {   if(head == NULL || head->next == NULL){
         return true;
        }
        Node *mid = getMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        right = reverseLL(right);
        while(left != NULL && right != NULL){
            if(left -> data == right->data){
                left = left->next;
                right = right->next;
            }
            else
            {return false;}
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends