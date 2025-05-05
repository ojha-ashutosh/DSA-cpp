#include<iostream>
#include<vector>
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
// count leaf node
void cntleafnode(node* root,int &count){
    if(root){
        cntleafnode(root->left,count);
        if(root->left==NULL && root->right==NULL) count++;
        cntleafnode(root->right,count);
    }
}
// height of tree
int heightoftree(node* root){
    if(root==NULL){
        return 0;
    }
    int leftheight=heightoftree(root->left);
    int rightheight=heightoftree(root->right);
    int height=max(leftheight,rightheight)+1;
    return height;
}
// diameter(width) of binary tree.....longest path between two endding node
// 0(n^2)
int diameter(node* root){
    if(root==NULL) return 0;
    int leftdiameter=diameter(root->left);
    int rightdiameter=diameter(root->right);
    int combinediameterLeftRight=heightoftree(root->left)+heightoftree(root->right)+1;//+1 for root node
    return max(max(leftdiameter,rightdiameter),combinediameterLeftRight);
}
// optimize diameter 
// 0(n)
pair<int,int> optimizediameter(node* root){
    // first int diameter & 2nd int height
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>leftpair=optimizediameter(root->left);
    pair<int,int>rightpair=optimizediameter(root->right);

    int leftdiameter=leftpair.first;
    int rightdiameter=rightpair.first;
    int combinediameterLeftRight=leftpair.second+rightpair.second+1;
    pair<int,int>ans;
    ans.first=max(max(leftdiameter,rightdiameter),combinediameterLeftRight);
    ans.second=max(leftpair.second,rightpair.second)+1;
    return ans;
}
// all node should be balanced...that means diff btw left child and right child of all node is <=1;
// 0(n^2)
bool checkforbalancetree(node* root){
    if(root==NULL)
     return true;
    bool left=checkforbalancetree(root->left);
    bool right=checkforbalancetree(root->right);

    bool diff=abs(heightoftree(root->left)-heightoftree(root->right))<=1;
    if(left&&right&&diff){
        return true;
    }
    else{
        return false;
    }
}
// optimized 0(n)
pair<bool,int> OPTIMIZEcheckforbalancetree(node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    pair<bool,int> left=OPTIMIZEcheckforbalancetree(root->left);
    pair<bool,int> right=OPTIMIZEcheckforbalancetree(root->right);

    bool leftans=left.first;
    bool rightans=right.first;
    bool diff = abs (left.second - right.second ) <=1;
    
    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    if(leftans&&rightans&&diff){
        ans.first=true;
    }else{
        ans.first=false;
    }
}
// identical or not 
// 0(n)
bool isIdentical(node* root1,node* root2){
    if (root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL) return false;
    if(root2==NULL && root1!=NULL) return false;
    bool left=isIdentical(root1->left,root2->left);
    bool right=isIdentical(root1->right,root2->right);
    bool value=root1->data==root2->data;

    if(left&&right&&value){
        return true;
    }else{
        return false;
    }
}
// if all the node have data equal to sum of left and right sub treee
pair<bool,int> issumtree(node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int>left=issumtree(root->left);
    pair<bool,int>right=issumtree(root->right);

    bool leftans=left.first;
    bool rightans=right.first;
    bool sum=root->data==left.second+right.second;

    pair<bool,int>ans;
    if(leftans&&rightans&&sum){
        ans.first=true;
        ans.second=root->data+left.second+right.second;
    }else{
        ans.first=false;
        ans.second=root->data+left.second+right.second;
    }
     return ans;
}


//  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//      1
//    /   \
//   3     5
//  / \   /
// 7  11 15
// 1 3 7 -1 -1 11 -1 -1 5 1 -1 -1 -1
int main(){
    node* root=NULL;
    // node* root1=NULL;
    root=buildtree(root);
    // root1=buildtree(root1);
    int count=0;
    cntleafnode(root,count);
    cout<<"total leaf node is ";
    cout<<count<<endl;
    int height=heightoftree(root);
    cout<<"height of tree is "<<height<<endl;
    // int d=diameter(root);
    pair<int,int>a=optimizediameter(root);
    cout<<"Diameter of tree is "<<a.first<<endl;
    // bool m=checkforbalancetree(root);
    pair<bool,int> m=OPTIMIZEcheckforbalancetree(root);
    if(m.first){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
    // bool iden=isIdentical(root,root1);
    //         if(iden){
    //         cout<<"identical"<<endl;
    //     }else{
    //         cout<<"Not identical"<<endl;
    //     }
    pair<int,bool> sumtree=issumtree(root);
    if(sumtree.first){
        cout<<"sum tree"<<endl;
    }
    else{
        cout<<"not sum tree"<<endl;
    }
} 