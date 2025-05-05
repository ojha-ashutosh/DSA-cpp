#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class kTH_largest_sum_of_subarray
{
public:
    int f1(vector<int> &v, int k)
    {
        int n = v.size();
        vector<int> push_sum;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += v[j];
                push_sum.push_back(sum);
            }
        }
        // sort the VECTOR
        sort(push_sum.begin(), push_sum.end());
        // finding kth largest sum;
        return push_sum[push_sum.size() - k];
    }
    // using heap
    int f2(vector<int> v, int k)
    {
        int n = v.size();
        priority_queue<int, vector<int>, greater<int>> mini;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += v[j];
                if (mini.size() < k)
                {
                    mini.push(sum);
                }
                else
                {
                    if (sum > mini.top())
                    {
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        // finding kth largest sum  ----->>> it will be on top of min heap
        return mini.top();
    }
};
class marge_k_sorted_arr
{
    public:
    class node
    {
        public:
        int data;
        int i;
        int j;
        node(int data, int row, int col)
        {
            this->data = data;
            i = row;
            j = col;
        }
    };
    class compare
    {
        // fixed way for writing
        public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
    };
    vector<int> solve(vector<vector<int>>v,int k){
        priority_queue<node*,vector<node*>,compare>mini;
        // ist element of all array (minimum ele of array bec it is sorted)
        for(int i=0;i<k;i++){
            node* t=new node(v[i][0],i,0);
            mini.push(t);
        }
        vector<int>ans;
        while(mini.size()>0){
            node* temp=mini.top();
            mini.pop();
            ans.push_back(temp->data);
            int i=temp->i;
            int j=temp->j;
            // insert next element of the array which is being poped if exit ....next minimum element of that array
            if(j+1<v[i].size()){
                node* t=new node(v[i][j+1],i,j+1);
                mini.push(t);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    kTH_largest_sum_of_subarray obj1;
    // cout << obj1.f1(v, 3);
    cout << obj1.f2(v, 3) << endl;

    vector<vector<int>> v2 = {{1,100}, {2}, {3}, {3, 5, 9}, {4}, {1, 2, 3, 8}};
    marge_k_sorted_arr obj2;
    vector<int> m=obj2.solve(v2,6);
    for(auto i:m){
       cout<<i<<" ";
    }cout<<endl;
}