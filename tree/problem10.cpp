#include <iostream>
#include <vector>
#include <queue>
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
node *buildtree(node *root)
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data in the left of node " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter the data in the right of node " << data << endl;
    root->right = buildtree(root->right);

    return root;
}
class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};
class max_size_BST
{
public:
    info solve(node *root, int &ans)
    {
        if (root == NULL)
        {
            // we initilized mini with max ans maxi with minimum value /
            // bec when we mave to find currnode.mini = min(root->data, left.mini)
            // currnode.maxi = max(root->data, right.maxi) we can get correct value
            return {INT_MAX, INT_MIN, true, 0};
        }
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info currnode;
        currnode.size=left.size+right.size+1;
        currnode.mini = min(root->data, left.mini);
        currnode.maxi = max(root->data, right.maxi);

        if (left.isBST && right.isBST && (left.maxi < root->data && right.mini > root->data))
        {
            currnode.isBST = true;
        }
        else
        {
            currnode.isBST = false;
        }

        if(currnode.isBST){
            ans=max(ans,currnode.size);
        }
        return currnode;
    }
    int max_node_BST(node *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
// 10 7 3 -1 -1 9 -1 -1 5 17 -1 -1 -1
//      10
//    /   \
//   7     5
//  / \   /
// 3  9  17
int main()
{
    node *root = NULL;
    root = buildtree(root);
    max_size_BST obj;
    cout<<"ans is "<<obj.max_node_BST(root);

}