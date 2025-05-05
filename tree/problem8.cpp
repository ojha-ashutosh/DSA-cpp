#include <iostream>
#include <queue>
#include <map>
#include <limits.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// complexsity time ->0(logn)
node *INSERT_INTO_BST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (root->data < data)
    {
        root->right = INSERT_INTO_BST(root->right, data);
    }
    if (root->data > data)
    {
        root->left = INSERT_INTO_BST(root->left, data);
    }

    return root;
}
void takeinput(node *&root)
{
    int data;
    cout << "Enter data to from BST: " << endl;
    cin >> data;
    while (data != -1)
    {
        root = INSERT_INTO_BST(root, data);
        cin >> data;
    }
}
class two_sum_bst{
    public:
    void inorder(node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    bool solve(node* root,int target){
        vector<int>v;
        inorder(root,v);
        int i=0;
        int j=v.size();
        while(i<j){
            int sum=v[i]+v[j];
            if(sum==target){
                return true;
            }
            else if(sum>target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};
class bst_to_sorted_LL
{
    public:
    void inorder(node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    node* solve(node* root){
        vector<int>v;
        inorder(root,v);
        node* newnode=new node(v[0]);
        node* curr=newnode;
        for(int i=1;i<v.size();i++){
            node* temp=new node(v[i]);
            curr->left=NULL;
            curr->right=temp;
            curr=temp;
        }

        // last node
        curr->left=NULL;
        curr->right=NULL;

        return newnode;
    }    

};
class normal_BST_to_balanedBST
{
    public:
    void inorder(node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    node* solve(vector<int>&v,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        node* newroot=new node(v[mid]);
        newroot->left=solve(v,start,mid-1);
        newroot->right=solve(v,mid+1,end);
        return newroot;
    }
    node* BST_to_balanedBST(node* root){
        vector<int>v;
        inorder(root,v);
        return solve(v,0,v.size()-1);
    }
};
class preorder_to_BST{
    public:
    // first aproch normalyy do it bt takeinput and createBST fn
    // 2nd by you have preorder ....sort it and get inorder ...after that we know to make tree by preorder and inorder
    // 3rd neche h
    node* solve(vector<int>&preorder,int mini,int maxi,int &i){
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]>maxi || preorder[i]<mini){
            return NULL;
        }
        node* root=new node(preorder[i]);
        i++;
        root->left=solve(preorder,mini,root->data,i);
        root->right=solve(preorder,root->data,maxi,i);
        return root;

    }
    node* preTObst(vector<int>&postorder){
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(postorder,mini,maxi,i); 
    } 
};
void levelordertreversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// 7  4 2 1 3 5 9 10 8 -1
//        7
//      /   \
//     4     9
//    / \   / \
//   2   5 8  10
//  / \
// 1   3
int main(){
    node* root=NULL;
    takeinput(root);
    two_sum_bst obj1;
    cout<<obj1.solve(root,17)<<endl;
    bst_to_sorted_LL obj2;
    node* ll=obj2.solve(root);
    while (ll->right!=NULL)
    {
        cout<<ll->data<<" ";
        ll=ll->right;
    }cout<<endl;
    levelordertreversal(root);
    cout<<"normal_BST_to_balanedBST"<<endl;
    normal_BST_to_balanedBST obj3;
    root=obj3.BST_to_balanedBST(root);
    levelordertreversal(root);
    cout<<endl;
    vector<int>v={5,2,1,3,4,8,7,9,10};
    preorder_to_BST obj4;
    node* r=obj4.preTObst(v);
    cout<<"preorder_to_BST"<<endl;
    levelordertreversal(r);
}

