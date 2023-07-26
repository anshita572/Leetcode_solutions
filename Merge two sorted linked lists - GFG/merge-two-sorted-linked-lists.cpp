//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
 Node* merge(Node* list1,Node* list2)
    {if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
     Node*ans =new Node(-1); //dummy node
     Node* temp = ans;
     while (list1 != NULL && list2 != NULL){
     if(list1->data < list2->data){
         temp->next = list1;
         temp = list1;
         list1 = list1->next;
     }
     else{
         temp->next = list2;
         temp = list2;
         list2 = list2->next;
     }
    }
    while(list1 != NULL){
        temp->next = list1;
        temp = list1;
        list1 = list1->next;
    }
    while(list2 != NULL){
      temp->next = list2;
      temp = list2;
      list2 = list2->next;  
    }
        ans = ans->next;
        return ans;
    }
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    return merge(head1, head2);
}  