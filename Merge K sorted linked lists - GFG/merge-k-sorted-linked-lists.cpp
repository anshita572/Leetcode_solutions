//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
class compare{
 public:
    bool operator()(Node* a,Node* b)
     {return a->data > b->data;}
 };
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    { priority_queue<Node*,vector<Node*>,compare>pq;
        if(K==0)
        {return NULL;}
        //step 1 : push 1st element of all linked lists into min heap
        for(int i=0;i<K;i++)
        {if(arr[i]!=NULL)
        {pq.push(arr[i]);}
        }
        Node*head=NULL;
        Node*tail=NULL;
        while(!pq.empty())
        {Node*temp=pq.top();
         pq.pop();
         //temp(min among 1st element of all LL),when we pop top,we push 2nd element of that particular LL 
         if(temp->next != NULL)
         {pq.push(temp->next);}
         if(head == NULL)
         {//initially,when we pop for the 1st time then answer LL is empty
          head=temp;
         tail=temp;}
         else
         {// when we pop for 2nd,3rd....till while loop runs
           tail->next=temp;
           tail=tail->next;
         }
        }
        return head;
         
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends