// balance brackets
// {[12*12(1-3)]}
#include<iostream>
#include<stack>
using namespace std;
bool problem(stack<int>&s,string st){
    int n=st.size();
    for(int i=0;i<n;i++){
        char m=st[i];
        if(m=='{'||m=='('||m=='['){
            s.push(m);
        }
        else if(m=='}'||m==')'||m==']')
        if(s.empty()){
            return false;
        }
        else{
            s.pop();
        }
    }
    if(s.empty()) return true;
    else return false;
}
int main(){
    stack<int>s;
    string st;
    cout<<"enter the expresion\n";
    cin>>st;
    bool a=problem(s,st);
    if(a){
        cout<<"balanced ";
    }else{
        cout<<"not balanced ";
    }
    return 0;
}