#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class trienode
{
    public:
       char data;
       trienode* children[26];
       int count;
       bool isTERMINAL;

       trienode(char ch){
          this->data=ch;
          for(int i=0;i<26;i++){
            children[i]=NULL;
          }
          count=0;
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
            root->count++;
            root->children[index]=child;
        }
        // recursion dekh lega baki.....()
        insertUtil(child,word.substr(1));//substr->1st word ko chor ke baki pass hoga
    }
    void insert_word(string word){
        insertUtil(root,word);
    }


    bool searchUTIL(trienode* root,string word){
        if(word.length()==0){
            return root->isTERMINAL;
        }
        // index
        int index=word[0]-'A';
        trienode* child;
        if(root->children[index ]!= NULL){
            child=root->children[index];
        }else{
            return false;
        }

        //recursion
        return searchUTIL(child,word.substr(1)); 
    }
    bool SearchWord(string word){
        return searchUTIL(root,word);
    }
};
class longestCOMMANprifix_in_strings
{
    public:
    // space complexcity 0(1)
    // time complexsity 0(n*m) n=no of char in first string ....m=size of vector
    string approach1(vector<string>v){
       int n=v.size();
       string ans="";
       for(int i=0;i<v[0].length();i++){
          char ch=v[0][i];
          bool match=true;
          for(int j=1;j<n;j++){
            //  not match
            if(v[j].size()<i || ch!=v[j][i]){
                match=false;
                break;
            }
          }
          if(match == false){
            break;
          }else{
            ans.push_back(ch);
          }
       }
       return ans;
    } 
    void solve2(trienode* root,string first,string &ans){
        for(int i=0;i<first.length();i++){
            char ch=first[i];
            if(root->count==1){
                // count 1 means that word is comman in all;;;;
                ans.push_back(ch);
                int index=ch-'A';
                root=root->children[index];
            }else{
                break;
            }

            if(root->isTERMINAL==true){
                break;
            }

        }
    }
    // n=no of char in first string ....m=size of vector
    // time 0(n*m)    space =0(n*m)
    string approach2(vector<string>v){
        trie ob;
        for(int i=0;i<v.size();i++){
            ob.insert_word(v[i]);
        }
        string ans="";
        string first=v[0];
        solve2(ob.root,first,ans);
        return ans;
    }
};
int main(){
    vector<string>v={"RAMHJDHUS","RAMSKHJHS","RAMBDN","RAMJSJSJ"};
    longestCOMMANprifix_in_strings obj;
    cout<<obj.approach1(v)<<endl;
    cout<<endl<<obj.approach2(v);
}