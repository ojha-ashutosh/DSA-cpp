// keyboard problem
#include<iostream>
#include<vector>
using namespace std;
class keyboard
{
   public:
   void soln(string digit,vector<string>&ans,string output,int index,string mapping[]){
      if(index>=digit.size()){
        ans.push_back(output);
        return ;
      }
      char ch=digit[index]-'0';
      string s=mapping[ch];
      for(int i=0;i<s.size();i++){
        output.push_back(s[i]);
        soln(digit,ans,output,index+1,mapping);
        output.pop_back();
      }
   }
   vector<string> kp(string digit){
     vector<string>ans;
     if(digit.size()==0) return ans;
     string output;
     string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     int index=0;
     soln(digit,ans,output,index,mapping);
     return ans;
   }
};
int main() {
    keyboard kb;
    string digit;
    cin >> digit;
    vector<string> result = kb.kp(digit);
    for (string s : result) {
        cout << s << " ";
    }
    return 0;
}