// kadane's algo



// 53. Maximum Subarray
// Given an integer array nums, find the subarray
//  with the largest sum, and return its sum.
// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];

            maxi=max(maxi,sum);

            if(sum<0){
                sum=0;
            }
        }
        if(maxi<0){
            return 0;
        }
        return maxi;
    }
};
int main() {
    Solution sol; 

    
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

   
    int result = sol.maxSubArray(nums);

    
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
