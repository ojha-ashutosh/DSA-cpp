#include<iostream>
using namespace std;

void towerOFhanoi(int n,char source,char destination,char helper){
    if(n==1) {
        cout<<source<<"->"<<destination<<endl;
        return ;
    }
    towerOFhanoi(n-1,source,helper,destination);
    cout<<source<<"->"<<destination<<endl;
    towerOFhanoi(n-1,helper,destination,source);
}
int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;
    
    towerOFhanoi(n, 'A', 'C', 'B'); // A: source, C: destination, B: helper

    return 0;
}
