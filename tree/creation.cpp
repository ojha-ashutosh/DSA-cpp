#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildtree(node* root){
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter the data in the left of node "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter the data in the right of node "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}
void levelordertreversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inordertreversal(node* root){
    if(root){
        inordertreversal(root->left);
        cout<<root->data<<" ";
        inordertreversal(root->right);
    }
}
void preordertreversal(node* root){
    if(root){
        cout<<root->data<<" ";
        preordertreversal(root->left);
        preordertreversal(root->right);
    }
}
void postordertreversal(node* root){
    if(root){
        postordertreversal(root->left);
        postordertreversal(root->right);
        cout<<root->data<<" ";
    };
}
void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//      1
//    /   \
//   3     5
//  / \   /
// 7  11 15
int main(){
    node* root=NULL;
    root=buildtree(root);
    levelordertreversal(root);
    inordertreversal(root);
    cout<<endl;
    preordertreversal(root);
    cout<<endl;
    postordertreversal(root);
    cout<<endl;
}