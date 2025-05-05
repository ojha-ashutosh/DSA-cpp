#include<iostream>
using namespace std;
// Function to count distinct ways to climb stairs
int countdistintWAYtoCLIMBstairs(int stair ){
    if(stair<0) return 0;
    if(stair==0) return 1;
    return countdistintWAYtoCLIMBstairs(stair-1)+countdistintWAYtoCLIMBstairs(stair-2);
}
int main() {
    int stairs;
    cout << "Enter number of stairs: ";
    cin >> stairs;
    int result = countdistintWAYtoCLIMBstairs(stairs);

    if (result == -1) {
        cout << "Invalid input! Number of stairs cannot be negative." << endl;
    } else {
        cout << "Number of distinct ways to climb " << stairs << " stairs is: " << result << endl;
    }
    return 0;
}