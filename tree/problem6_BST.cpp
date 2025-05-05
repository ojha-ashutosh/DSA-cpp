#include <iostream>
#include <queue>
#include <map>
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
void inordertreversal(node *root)
{
    if (root)
    {
        inordertreversal(root->left);
        cout << root->data << " ";
        inordertreversal(root->right);
    }
}
void preordertreversal(node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preordertreversal(root->left);
        preordertreversal(root->right);
    }
}
void postordertreversal(node *root)
{
    if (root)
    {
        postordertreversal(root->left);
        postordertreversal(root->right);
        cout << root->data << " ";
    };
}
class MIN_MAX_VALUE_OF_BST
{
public:
    node *min_OF_BST(node *root)
    {
        node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    node *max_OF_BST(node *root)
    {
        node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }
};
node *delete_from_tree(node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 2child
        if(root->right != NULL && root->left !=NULL){
            MIN_MAX_VALUE_OF_BST obj2;
            // one way->right ka minimum

            // int minright=obj2.min_OF_BST(root->right)->data;
            // root->data=minright;
            // root->right=delete_from_tree(root->right,minright);
            
            // 2nd way->left ka maximum

            int maxleft=obj2.max_OF_BST(root->left)->data;
            root->data=maxleft;
            root->left=delete_from_tree(root->left,maxleft);
        }
    }
    else if (root->data < target)
    {
        root->right = delete_from_tree(root->right, target);
        return root;
    }
    else
    {
        root->left = delete_from_tree(root->left, target);
        return root;
    }
}
class search_in_BST
{
public:
    bool search_recursive(node *root, int target)
    // time->0(n) space->0(n)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == target)
        {
            return true;
        }
        if (root->data < target)
        {
            return search_recursive(root->right, target);
        }
        if (root->data > target)
        {
            return search_recursive(root->left, target);
        }
        return false;
    }
    bool search_itterativly(node *root, int target)
    {
        // time->0(n) space->0(1)
        while (root != NULL)
        {
            if (root->data == target)
            {
                return true;
            }
            else if (root->data < target)
            {
                root = root->right;
            }
            else if (root->data > target)
            {
                root = root->left;
            }
        }
        return false;
    }
};

// 7 4 2 1 3 5 9 8 10 -1
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
    // inorder of bst is sorted
    inordertreversal(root);
    cout << endl;
    preordertreversal(root);
    cout << endl;
    postordertreversal(root);
    cout << endl;
    search_in_BST obj1;
    cout << obj1.search_recursive(root, 10) << endl;
    cout << obj1.search_itterativly(root, 11) << endl;
    MIN_MAX_VALUE_OF_BST obj2;
    node *min = obj2.min_OF_BST(root);
    cout << "min value is " << min->data << endl;
    node *max = obj2.max_OF_BST(root);
    cout << "max value is " << max->data << endl;
    root=delete_from_tree(root,7);
    inordertreversal(root);
    cout << endl;
}