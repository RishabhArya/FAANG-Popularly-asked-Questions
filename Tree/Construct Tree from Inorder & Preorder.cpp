// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		
		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
static int pointer = 0;
int search(int in[], int val,int startInx,int endInx)
{
    for(int i = startInx; i <= endInx; i++)
    {
        if(val == in[i]){
            return i;
        }
    }
}
Node* buildCompleteTree(int in[],int pre[], int startInx,int endInx)
{
    
    if (startInx > endInx)
        return NULL;
    Node *root = new Node(pre[pointer++]);
    int temp = root->data;
    //cout<<temp<<endl;
    int ele = search(in, root->data,startInx,endInx);
    
    if (startInx == endInx)
        return root;
    root ->left = buildCompleteTree(in,pre, startInx,ele - 1);
    root ->right = buildCompleteTree(in,pre, ele + 1 ,endInx);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    //add code here.
    
    pointer = 0;
    return buildCompleteTree(in,pre,0,n-1);
    
}
