// activity selection problem
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int max_meeting(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    int end_time = v[0].second;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if(v[i].first>end_time){
            count++;
            end_time=v[i].second;
        }
    }
    return count;
}
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    cout<<max_meeting(start,end,6);
}