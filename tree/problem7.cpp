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
class validBST
{
public:
    bool solve(node *root, int minlimit, int maxlimit)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data > minlimit && root->data < maxlimit)
        {
            bool left = solve(root->left, minlimit, root->data);
            bool right = solve(root->right, root->data, maxlimit);
            return left && right;
        }
        else
        {
            return false;
        }
    }
    bool valid_BST(node *root)
    {
        int maxlimit = INT_MAX;
        int minlimit = INT_MIN;
        return solve(root, minlimit, maxlimit);
    }
};
class kth_smallest_node
{
public:
    int solve(node *root, int &i, int k)
    {
        if (root == NULL)
        {
            return -1;
        }
        //    left
        int left = solve(root->left, i, k);

        if (left != -1)
        {
            return left;
        }
        // node
        i++;
        if(i==k){
            return root->data;
        }
        // right
        return solve(root->right,i,k);
    }
    int kth_smallest(node *root, int k)
    {
        // kth largest ->(n-k)+1;
        int i = 0;
        return solve(root, i, k);
    }
};
class Predecessor_successor
// inorder Predecessor & successor
{
    public:
    pair<int,int> solve(node* root,int key){
        int pred=-1;
        int succ=-1;
        node* temp=root;
        while(temp!=NULL && temp->data!=key)
        {
            if(temp->data>key){
                succ=temp->data;
               temp=temp->left;
            }else{
               pred=temp->data;
               temp=temp->right;  
            }
        }
        if (temp == nullptr) {
        // Key not found in the tree
        return std::make_pair(pred, succ);
        }

        // predecessor ->will be the max node in left subtree
        node * lefttree=temp->left;
        while(lefttree!=nullptr){
            pred=lefttree->data;
            lefttree=lefttree->right;
        }

        // successor ->will be the min node in right sub tree
        node * righttree=temp->right;
        while(righttree!=nullptr){
            succ=righttree->data;
            righttree=righttree->left;
        }

        pair<int,int>ans=make_pair(pred,succ);
        return ans;
    }
};
class LowestCommanAncestor
{
public:
     node* find(node* root ,int key){
        while(root != NULL && root->data != key){
            if(root->data > key){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return root;
     }
     node* solve(node* root,int n1,int n2){
        node* node1=find(root,n1);
        node* node2=find(root,n2);
        
        node* temp=root;
        while(temp!=NULL){
            if(temp->data<n1 && temp->data <n2){
                temp=temp->right;
            }else if(temp->data >n1 && temp->data >n2){
                temp=temp->left;
            }else{
                return temp;
            }
        }
     }

};
// 7  4 2 1 3 5 9 8 10 -1
//        7
//      /   \
//     4     9
//    / \   / \
//   2   5 8  10
//  / \
// 1   3
int main()
{
    node *root = nullptr;
    takeinput(root);
    levelordertreversal(root);
    validBST obj1;
    cout << obj1.valid_BST(root)<<endl;
    kth_smallest_node obj2;
    cout<<obj2.kth_smallest(root,9)<<endl;
    Predecessor_successor obj3;
    pair<int,int> a=obj3.solve(root,9);
    cout<<"Predecessor is "<<a.first<<" successor is "<<a.second<<endl;
    LowestCommanAncestor obj4;
    cout<<obj4.solve(root,1,5)->data;
}