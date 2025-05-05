#include <iostream>
#include <vector>
using namespace std;
int space_optimize(vector<int> v)
{
    int n = v.size();

    int prev2 = 0;
    int prev1 = v[0];
    for (int i = 1; i < n; i++)
    {
        int include = prev2 + v[i];
        int exclude = prev1 + 0;
        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int HouseRobberyProblem(vector<int> houseitem)
{
    // house in circular mannior
    // cant robbery 2 abjusnet house
    // first and last are neighbour so if include 1st cant include last and vise varsa
    int n = houseitem.size();
    if (n == 1)
        return houseitem[n];
    vector<int> excluding_last;
    vector<int> excluding_first;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            excluding_last.push_back(houseitem[i]);
        }
        else if (i == n - 1)
        {
            excluding_first.push_back(houseitem[i]);
        }
        else
        {
            excluding_last.push_back(houseitem[i]);
            excluding_first.push_back(houseitem[i]);
        }
    }
    int a = space_optimize(excluding_first);
    int b = space_optimize(excluding_last);
    return max(a, b);
}
int main()
{
    vector<int> houseitem = {2, 3, 2};
    cout << "Maximum amount that can be robbed: " << HouseRobberyProblem(houseitem) << endl;

    vector<int> houseitem2 = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: " << HouseRobberyProblem(houseitem2) << endl;

    return 0;
}