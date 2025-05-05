// prefix
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int cal(int a,int b,char op){
    if(op=='^'){
        return pow(a,b);
    }
    else if(op=='/'){
        return a/b;
    }
    else if (op=='*'){
        return a*b;
    }
    else if(op=='+'){
        return a+b;
    }else{
        return a-b;
    }
}
int prefix(string s){
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            int ans=cal(a,b,s[i]);
            st.push(ans);
        }
    }
    return st.top();
}
int main(){
    string s="-9+*132";
    cout<<prefix(s);
    return 0;
}