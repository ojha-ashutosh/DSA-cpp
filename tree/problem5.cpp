#include <iostream>
#include <queue>
#include<map>
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
class min_time_TO_burn_A_tree
{
    public:
    node* mapping_child_parents(node* root,map<node*,node*>&nodeTOparent,int target){
        node* targetnode=NULL;
        queue<node*>q;
        q.push(root);
        nodeTOparent[root]=NULL;
        while(!q.empty()){
            node* frontnode=q.front();
            q.pop();
            if(frontnode->data==target){
                targetnode=frontnode;
            }
            if(frontnode->left){
                nodeTOparent[frontnode->left]=frontnode;
                q.push(frontnode->left);
            }
            if(frontnode->right){
                nodeTOparent[frontnode->right]=frontnode;
                q.push(frontnode->right);
            }
        }
        return targetnode;
    }
    int burntree(node* targetnode,map<node*,node*>nodetoparents){
        int ans=0;
        map<node*,bool> visited;
        queue<node*>q;
        q.push(targetnode);
        visited[targetnode]=true;
        while(!q.empty()){
            bool flag=false;
            int size=q.size();
            for(int i=0;i<size;i++){
                node* front=q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag=true;
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right]){
                    flag=true;
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(nodetoparents[front] && !visited[nodetoparents[front]]){
                    flag=true;
                    q.push(nodetoparents[front]);
                    visited[nodetoparents[front]]=true;
                }
            }
            if(flag==true){
                ans++;
            }
        }
        return ans;
    }
    int mdt(node* root,int target){
        // step1->create node to parants mapping
        // step2->find target node
        // step3->burn tree in min time

        map<node*,node*> nodeTOparent;
        node* targetnode=mapping_child_parents(root,nodeTOparent,target);
        return burntree(targetnode,nodeTOparent);

    }
};
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//      1
//    /   \
//   3     5
//  / \   /
// 7  11 17
int main(){
    node* root=nullptr;
    root=buildtree(root);
    min_time_TO_burn_A_tree obj;
    cout<<obj.mdt(root,17);
}
