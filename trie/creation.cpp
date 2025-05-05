#include<iostream>
#include<algorithm>
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
    void deleteutil(trienode* root,string word){
        if(word.length()==0){
           root->isTERMINAL=false;
           return;
        }
        int index=word[0]-'A';
        trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            // not found
            return;
        }
        // baki recursion dekh lega
        deleteutil(child,word.substr(1));
    }
    // for deleting the node you should mark the last node as not a terminal node
    void deleteword(string word){
        deleteutil(root,word);
        return ;
    }
    bool prifixUTIL(trienode* root,string prifix){
        if(prifix.length()==0){
            return true;
            // it is not checking whole string just checking prifix
        }
        int index=prifix[0]-'A';
        trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        // baki recursion dekh lega
        return prifixUTIL(child,prifix.substr(1));

    }
    bool serchPREFIX(string prefix){
        return prifixUTIL(root,prefix);
    }
};
int main(){
    trie t;
    t.insert_word("ABCD");
    t.insert_word("ANT");
    t.insert_word("RAM");
    cout<<t.SearchWord("ABCD")<<endl;
    t.deleteword("ABCD");
    cout<<t.SearchWord("ABCD");
    cout<<endl<<t.serchPREFIX("RA");
    return 0;
}
