#include <iostream>
#include <queue>
#include<map>
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

class constract_a_tree_from_inoder_preorder
{
public:
    void findposition(int in[],map<int,int>&indexTOnode,int n){
        for(int i=0;i<n;i++){
            indexTOnode[in[i]]=i;
        }
    }
    node *solve(int in[], int pre[], int &PREindex, int INstartindex, int INendindex, int n,map<int,int>indexTOnode)
    {
        if (PREindex >= n|| INstartindex > INendindex)
        {
            return NULL;
        }
        int element = pre[PREindex];
        PREindex++;
        node *root = new node(element);
        int position =indexTOnode[element];
        
        // first left then right
        root->left=solve(in,pre,PREindex,INstartindex,position-1,n,indexTOnode);
        root->right=solve(in,pre,PREindex,position+1,INendindex,n,indexTOnode);

        return root;
    }
    node *constrution(int in[], int pre[], int n)
    {
        int PREstartindex = 0;
        int INstartindex = 0;
        int INendindex = n - 1;
        map<int,int>indexTOnode;
        findposition(in,indexTOnode,n);
        return solve(in, pre, PREstartindex, INstartindex, INendindex, n,indexTOnode);
    }
};
class constract_a_tree_from_inoder_postorder
{
public:
    void findposition(int in[],map<int,int>&indexTOnode,int n){
        for(int i=0;i<n;i++){
            indexTOnode[in[i]]=i;
        }
    }
    node *solve(int in[], int post[], int &POSTindex, int INstartindex, int INendindex, int n,map<int,int>indexTOnode)
    {
        if (POSTindex<0|| INstartindex > INendindex)
        {
            return NULL;
        }
        int element = post[POSTindex];
        POSTindex--;
        node *root = new node(element);
        int position =indexTOnode[element];

        // first right then left(bec of post order arrangement)
        root->right=solve(in,post,POSTindex,position+1,INendindex,n,indexTOnode);
        root->left=solve(in,post,POSTindex,INstartindex,position-1,n,indexTOnode);

        return root;
    }
    node *constrution(int in[], int post[], int n)
    {
        int postindex = n-1;//from last
        int INstartindex = 0;
        int INendindex = n-1;
        map<int,int>indexTOnode;
        findposition(in,indexTOnode,n);
        return solve(in, post, postindex, INstartindex, INendindex, n,indexTOnode);
    }
};
int main()
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int post[]={3,4,1,5,2,0};
    constract_a_tree_from_inoder_preorder obj1;
    node* root=obj1.constrution(in,pre,6);
    levelordertreversal(root);
    cout<<endl;
    constract_a_tree_from_inoder_postorder obj2;
    node* root1=obj2.constrution(in,post,6);
    levelordertreversal(root1);

}