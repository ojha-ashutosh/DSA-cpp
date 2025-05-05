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
class approach
{
public:
    void inorder(node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    vector<int> marge (vector<int> &v1, vector<int> &v2)
    {
        vector<int> marge(v1.size() + v2.size());
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                marge[k++] = v1[i];
                i++;
            }
            else
            {
                marge[k++] = v2[j];
                j++;
            }
        }
        while (i < v1.size())
        {
            marge[k++] = v1[i++];
        }
        while (j < v2.size())
        {
            marge[k++] = v2[j++];
        }
        return marge;
    }
    node *solve(vector<int> &v, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int mid = (start + end) / 2;
        node *newroot = new node(v[mid]);
        newroot->left = solve(v, start, mid - 1);
        newroot->right = solve(v, mid + 1, end);
        return newroot;
    }
    node *marge_two_BST(node *root1, node *root2)
    {
        vector<int> inorder_for_root1;
        vector<int> inorder_for_root2;
        inorder(root1, inorder_for_root1);
        inorder(root2, inorder_for_root2);
        // marge then into single soarted array(inorder of the tree)
        vector<int> marge_vector = marge(inorder_for_root1, inorder_for_root2);
        return solve(marge_vector, 0, marge_vector.size()-1);
    }
};
// 10 5 15 3 7 12 18 -1
// 20 8 25 15 30 -1
int main()
{
    node *root1 = NULL;
    takeinput(root1);
    node *root2 = NULL;
    takeinput(root2);
    approach obj1;
    node *root = obj1.marge_two_BST(root1, root2);
    levelordertreversal(root);
}