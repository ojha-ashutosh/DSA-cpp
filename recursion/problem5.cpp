// palindrom
#include<iostream>
using namespace std;
bool palindrome(string s,int first,int last){
    if(first>last) return true;

    if(s[first]!=s[last]) return false;
    return palindrome(s,first+1,last-1);
}
int main() {
    string s = "madam";
    if (palindrome(s, 0, s.length() - 1)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}