#include <iostream>
#include <unordered_map>
#include <limits.h>
#include <vector>
using namespace std;
int max_frequency(vector<int> v)
{
    int ans = -1;
    int max_freq = INT_MIN;
    unordered_map<int, int> count;
    for (int i = 0; i < v.size(); i++)
    {
        count[v[i]]++;
        if (max_freq < count[v[i]])
        {
            max_freq = count[v[i]];
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (max_freq == count[v[i]]){
            ans = v[i];
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 3, 2, 3, 1, 1, 1, 2, 4, 5, 6, 7, 7,7,7,7,7,8,9,7,9};
    cout << max_frequency(v) << endl;
}