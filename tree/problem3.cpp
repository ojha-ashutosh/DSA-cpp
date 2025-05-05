#include <iostream>
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
class SumOfNodesONlongestPath
{
public:
    void solve(node *root, int sum, int &maxsum, int length, int &maxlenght)
    {
        if (root == NULL)
        {
            if (maxlenght < length)
            {
                maxlenght = length;
                maxsum = sum;
            }
            else if (maxlenght == length)
            {
                maxsum = (maxsum, sum);
            }
            return;
        }
        sum = sum + root->data;
        solve(root->left, sum, maxsum, length + 1, maxlenght);
        solve(root->right, sum, maxsum, length + 1, maxlenght);
    }
    int SONOLP(node *root)
    {
        int sum = 0;
        int maxsum = -1;
        int length = 0;
        int maxlength = 0;
        solve(root, sum, maxsum, length, maxlength);
        return maxsum;
    }
};
class LowestCommanAncestor
{
public:
    node *LCA(node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        node *leftans = LCA(root->left, n1, n2);
        node *rightans = LCA(root->right, n1, n2);
        if (leftans != NULL && rightans != NULL)
        {
            return root;
        }
        else if (leftans == NULL && rightans != NULL)
        {
            return rightans;
        }
        else if (leftans != NULL && rightans == NULL)
        {
            return leftans;
        }
        else
        {
            return NULL;
        }
    }
};
class KsumPath
{
    // in this we find the total no of path whoes sum is equal to given value
public:
    void solve(node *root, vector<int> path, int k, int &count)
    {
        if (root == NULL)
            return;

        path.push_back(root->data);
        solve(root->left, path, k, count);
        solve(root->right, path, k, count);

        int size = path.size();
        int sum = 0;
        // we use loop from last bec we want to check from the node last inserted that it make the sum or not
        // if it make count++
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
        path.pop_back();
    }
    int KSP(node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, path, k, count);
        return count;
    }
};
class kthANCESTOR
{
public:
    node *solve(node *root, int &k, int value)
    {
        // base case
        if (root == NULL)
            return NULL;
        
        if (root->data == value)
        {
            return root;
        }

        node *leftAns = solve(root->left, k, value);
        node *rightAns = solve(root->right, k, value);

        // wapas
        if (leftAns != NULL && rightAns == NULL)
        {
            k--;
            if (k <= 0)
            {
                // answer lock
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }

        if (leftAns == NULL && rightAns != NULL)
        {
            k--;
            if (k <= 0)
            {
                // answer lock
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        return NULL;
    }
    int kthAncestor(node *root, int k, int value)
    {
        node *ans = solve(root, k, value);
        // root->data==node----->>>if the node is itself root node then it does not have any ancestor
        if (ans == NULL || ans->data == value)
            return -1;
        else
            return ans->data;
    }
};
class maxSumOfNON_Abjacent{
    public:
    // pair<int,int> 1st int have sum including node ----2nd int have sum excluding node 
    pair<int,int> solve(node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> leftans=solve(root->left);
        pair<int,int> rightans=solve(root->right);

        pair<int,int> res;

        res.first=root->data+leftans.second+rightans.second;
        res.second=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);

        return res;
    }
    int getmexsum(node* root){
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//      1
//    /   \
//   3     5
//  / \   /
// 7  11 15


int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelordertreversal(root);
    SumOfNodesONlongestPath obj1;
    cout << obj1.SONOLP(root) << endl;
    LowestCommanAncestor obj2;
    node *LCA = obj2.LCA(root, 7, 11);
    cout << LCA->data << endl;
    KsumPath obj3;
    cout << obj3.KSP(root, 6) << endl;
    kthANCESTOR obj4;
    cout << obj4.kthAncestor(root, 1, 17) << endl;
    maxSumOfNON_Abjacent obj5;
    cout<<obj5.getmexsum(root);
}