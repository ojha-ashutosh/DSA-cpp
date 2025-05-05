// xor from l to r


/*
   xor of 1 to n(1^2^3^4..........^n)

   n=1 ===1    n=5 ===1     n=9 ===1    n%4==1 -> 1
   n=2 ===3    n=6 ===7     n=10===11   n%4==2 -> n+1
   n=3 ===0    n=7 ===0     n=11===0    n%4==3 -> 0
   n=4 ===4    n=8 ===8     n=12===12   n%4==0 -> n


   l=4 to r=7
   if we have to find xor of 4^5^6^7;
   we find 1^2^3 and 1^2^3^4^5^6^7;
   and then we xor boyh of the we get the desered result bec a^a =0 so get elemenated

*/
#include <iostream>
using namespace std;
class Solution {
   public:
     int fn(int n)
     {
         if(n%4==1) return 1;
         if(n%4==2) return n+1;
         if(n%4==3) return 0;
         if(n%4==0) return n;
     }
     int findXOR(int l, int r) {
         int ans1=fn(l-1);
         int ans2=fn(r);
         return ans1^ans2;
     }
 };
int main() {
   Solution sol;

   int l, r;
   cout << "Enter l and r: ";
   cin >> l >> r;

   int result = sol.findXOR(l, r);
   cout << "XOR from " << l << " to " << r << " is: " << result << endl;

   return 0;
}