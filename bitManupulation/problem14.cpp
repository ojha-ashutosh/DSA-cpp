#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Two Numbers with Odd Occurrences
    -----------------------------------------
    Given an array of N elements in which exactly two elements appear an odd number of times 
    and all others appear an even number of times, return the two odd-occurring numbers 
    in descending order.

    Approach:
    1. XOR all elements → gives xor = x ^ y (where x and y are the two odd numbers)
    2. Find the rightmost set bit in xor → this bit is different between x and y.
    3. Split array into two groups based on this bit and XOR separately to get x and y.
*/

class Solution {
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int xorall = 0;
        for (long long int i = 0; i < N; i++) {
            xorall ^= Arr[i];
        }

        // Rightmost set bit
        long long int r = xorall & ~(xorall - 1);

        long long int x = 0, y = 0;
        for (long long int i = 0; i < N; i++) {
            if (Arr[i] & r)
                x ^= Arr[i];
            else
                y ^= Arr[i];
        }

        vector<long long int> ans;
        if (x > y) {
            ans.push_back(x);
            ans.push_back(y);
        } else {
            ans.push_back(y);
            ans.push_back(x);
        }

        return ans;
    }
};

// Sample main function to test the solution
int main() {
    Solution obj;
    long long int Arr[] = {1, 2, 3, 1, 2, 5};
    long long int N = sizeof(Arr) / sizeof(Arr[0]);

    vector<long long int> result = obj.twoOddNum(Arr, N);

    cout << "Two odd occurring numbers are: ";
    for (auto num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
