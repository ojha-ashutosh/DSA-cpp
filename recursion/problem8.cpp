// permutation of string
#include<iostream>
#include<vector>
using namespace std;
class P
{
    private:
    void soln(string s,vector<string>&ans,int index){
        if(index>=s.size()){
            ans.push_back(s);
            return;
        }
        for(int j=index;j<s.size();j++){
            swap(s[index],s[j]);
            soln(s,ans,index+1);
            // back track
            swap(s[index],s[j]);
        }
    }
    public:
    vector<string> prob(string s){
        vector<string>ans;
        if(s.size()==0){
            return ans;
        }
        soln(s,ans,0);
        return ans;
    }
};
int main() {
    P p;
    string s;
    cin >> s;
    vector<string> result = p.prob(s);
    for (string str : result) {
        cout << str << " ";
    }
    return 0;
}
