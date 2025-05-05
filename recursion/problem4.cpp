// rev string
#include<iostream>
using namespace std;
void rev(string &s,int start,int end){
    if(start>end) return;
    swap(s[start],s[end]);
    rev(s,start+1,end-1);
}
int main() {
    string s = "hello";
    rev(s, 0, s.length() - 1); // Call reverse function
    cout << "Reversed string: " << s << endl; // Output the reversed string
    return 0;
}

