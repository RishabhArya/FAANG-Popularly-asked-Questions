// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
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
Node* buildCompleteTree(int in[],int post[], int startInx,int endInx)
{
    
    if (startInx > endInx)
        return NULL;
    Node *root = new Node(post[pointer--]);
    //int temp = root->data;
    //cout<<temp<<endl;
    int ele = search(in, root->data,startInx,endInx);
    
    if (startInx == endInx)
        return root;
    root ->right = buildCompleteTree(in,post, ele + 1,endInx);
    root ->left = buildCompleteTree(in,post, startInx,ele - 1);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    pointer = n-1;
    return buildCompleteTree(in,post,0,n-1);
}
