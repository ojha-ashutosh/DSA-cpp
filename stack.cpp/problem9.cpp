// how many breckets we have to add to make a breaket sq balance
#include<iostream>
#include<stack>
using namespace std;

int problem(string st){
    int count = 0;
    stack<char> s; // Changed stack<int> to stack<char> for characters

    for(int i = 0; i < st.size(); i++){
        char m = st[i];
        if(m == '{' || m == '(' || m == '['){
            s.push(m);
        }
        else if(m == '}' || m == ')' || m == ']'){
            if(!s.empty()){
                char top = s.top();
                s.pop();
                // Check if the current closing bracket matches the top of the stack
                if((m == '}' && top != '{') || 
                   (m == ')' && top != '(') || 
                   (m == ']' && top != '[')){
                    count++; // Mismatched bracket found
                }
            }
            else{
                count++; // No matching opening bracket found
            }
        }
        else{
             // Any other character encountered (non-bracket)
             // Increase the count for additional brackets needed
             count++;
        }
    }

    // After processing all characters, count any remaining unmatched opening brackets
    while(!s.empty()){
        count++;
        s.pop();
    }

    return count; // Return the number of additional brackets needed
}

int main(){
    string a = "({{}{{{}}})";
    cout << problem(a) << endl; // Output the result of the problem function
    return 0;
}
