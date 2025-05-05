#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
// zig zag traversal
// in this we go in left to right in 0th level and right to left in 1st level and left to right in 2th level and so on
vector<int> zigzogtraversal(node *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    queue<node *> q;
    bool lefttoright = true;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();

            int index = lefttoright ? i : size - i - 1;
            ans[index] = frontnode->data;

            if (frontnode->left)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }
        // change direction
        lefttoright = !lefttoright;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}
class boundarytrevalsal
{
public:
    void lefttravelsal(node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        // dont pushback leave node
        if (root->left == NULL && root->right == NULL)
            return;

        ans.push_back(root->data);
        if (root->left)
        {
            lefttravelsal(root->left, ans);
        }
        else
        {
            // when there is no left node then root->right will be on boundary
            lefttravelsal(root->right, ans);
        }
    }
    void leaftraversal(node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        leaftraversal(root->left, ans);
        leaftraversal(root->right, ans);
    }
    void rightTraversalREVERSEorder(node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
            return;

        if (root->right)
        {
            rightTraversalREVERSEorder(root->right, ans);
        }
        else
        {
            // when there is no right node then root->left will be on boundary
            rightTraversalREVERSEorder(root->left, ans);
        }

        // vapas jayega call
        ans.push_back(root->data);
    }
    vector<int> boundary(node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        // push root ka data
        ans.push_back(root->data);
        // left travelsal
        lefttravelsal(root->left, ans);
        // leaf travelsal
        leaftraversal(root, ans);
        // right traversal but in reverse order
        rightTraversalREVERSEorder(root->right, ans);

        return ans;
    }
};
class verticalOrderTraversal
{
public:
    // map<int1,map<int2,vector<int>> int1->horizontal distance ,,,,int2->level.....vector<int>--nodes at given level
    // queue <pair<node*,pair<int(horizontal distance),int(level)>>>

    vector<int> vot(node *root)
    {
        map<int, map<int, vector<int>>> m;
        queue<pair<node*, pair<int, int>>> q;
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
           pair<node*, pair<int, int>> temp=q.front();
           q.pop();

           node* frontnode=temp.first;
           int hd=temp.second.first;
           int level=temp.second.second;

           m[hd][level].push_back(frontnode->data);
           if(frontnode->left){
              q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
           }
           if(frontnode->right)
                q.push(make_pair(frontnode->right, make_pair(hd+1, level+1)));
        }
        for(auto i:m)
        {
           for(auto j:i.second){
               for(auto k:j.second){
                 ans.push_back(k);
               }
           } 
        }
        return ans;
    }
};

class topview{
    public:
    // map<int(horizontal distance),int(node->data)>
    // queue<map<node*,int>>  int->horizontal distance
    vector<int> TV(node* root){
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int> m;
        queue<pair<node*,int > > q;
        q.push(make_pair(root,0));
        while(!q.empty()){
          pair<node*,int > temp=q.front();
          q.pop();

          node* topnode=temp.first;
          int hd=temp.second;

          if(m.find(hd)==m.end()){
            m[hd]=topnode->data;
          }  
          if(topnode->left){
            q.push(make_pair(topnode->left,hd-1));
          }
          if(topnode->right){
            q.push(make_pair(topnode->right,hd+1));
          }

        }
        for(auto i:m){
           ans.push_back(i.second);
        }
        return ans;
    }

};
class bottomview
{
    // map<int(horizontal distance),int(node->data)>
    // queue<map<node*,int>>  int->horizontal distance
    public:
    vector<int> BV(node* root){
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int> m;
        queue<pair<node*,int>>q;
        q.push(make_pair(root,0));
        while (!q.empty())
        {
            pair<node*,int> temp=q.front();
            q.pop();
            node* frontnode=temp.first;
            int hd=temp.second;

            m[hd]=frontnode->data;

           if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
          }
          if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
          }
        }
        for(auto i:m){
           ans.push_back(i.second);
        }
        return ans;
        
    }
};
class leftview
{
    public:
    void solve(node* root,vector<int>&ans,int level){
        if(root==NULL) return;
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    vector<int> LV(node* root){
       vector<int>ans;
       if(root==NULL) return ans;
       int level=0;
       solve(root,ans ,level);
       return ans;
    }
};
class rightview
{
    public:
    void solve(node* root,vector<int>&ans,int level){
        if(root==NULL) return;
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> RV(node* root){
       vector<int>ans;
       if(root==NULL) return ans;
       int level=0;
       solve(root,ans ,level);
       return ans;
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
    vector<int> v = zigzogtraversal(root);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    boundarytrevalsal obj;
    vector<int> ans = obj.boundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    verticalOrderTraversal obj1;
    vector<int> vot=obj1.vot(root);
    for (auto i : vot)
    {
        cout << i << " ";
    }
    cout<<endl;
    topview obj3;
    vector<int> tv=obj3.TV(root);
    for (auto i : tv)
    {
        cout << i << " ";
    }cout<<endl;
    bottomview obj4;
    vector<int> bv=obj4.BV(root);
    for (auto i : bv)
    {
        cout << i << " ";
    }cout<<endl;
    leftview obj5;
    vector<int> lv=obj5.LV(root);
    for (auto i : lv)
    {
        cout << i << " ";
    }cout<<endl;
    rightview obj6;
    vector<int> rv=obj6.RV(root);
    for (auto i : rv)
    {
        cout << i << " ";
    }cout<<endl;
}

