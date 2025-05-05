#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class trienode
{
    public:
       char data;
       trienode* children[26];
       bool isTERMINAL;

       trienode(char ch){
          this->data=ch;
          for(int i=0;i<26;i++){
            children[i]=NULL;
          }
          isTERMINAL=false;
       }
};
class trie
{
    public:
    trienode* root;
    trie(){
        root=new trienode('\0');
    }
    
    void insertUtil(trienode* root,string word){
        if(word.length()==0){
            root->isTERMINAL=true;
            return;
        }
        //(asume word is in caps)
        // index
        int index=word[0]-'A';
        trienode* child;
        if(root->children[index]!=NULL){
            // present
            child=root->children[index];
        }else{
            // not present
            child=new trienode(word[0]);
            root->children[index]=child;
        }
        // recursion dekh lega baki.....()
        insertUtil(child,word.substr(1));//substr->1st word ko chor ke baki pass hoga
    }
    void insert_word(string word){
        insertUtil(root,word);
    }
};
class phone_directory
{
    public:
    void printsuggestion(trienode* curr,vector<string>&temp,string prefix){
        if(curr->isTERMINAL){
            temp.push_back(prefix);
        }
        for(char ch='A';ch<='Z';ch++){
            trienode* next=curr->children[ch-'A'];
            if(next != NULL){
                prefix.push_back(ch);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getsuggestion(trienode* root,string search_word){
        vector<vector<string>> output;
        string prefix="";
        trienode* prev=root;
        for(int i=0;i<search_word.size();i++){
            char lastcharecter=search_word[i];
            
            prefix.push_back(lastcharecter);

            trienode* curr=root->children[lastcharecter-'A'];
            if(curr == NULL){
                break;
            }
            
            vector<string> temp;
            printsuggestion(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
    vector<vector<string>> solve(vector<string>contract_name,string search_word){
        trie t;
        for(int i=0;i<contract_name.size();i++){
            t.insert_word(contract_name[i]);
        }
        return getsuggestion(t.root,search_word);
    } 
};
int main(){
    vector<string>contract_name={"ABCD","ABCM","AXYZ","MNO"};
    phone_directory obj;
    vector<vector<string>>ans=obj.solve(contract_name,"AB");
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<endl;
        }
    }

}