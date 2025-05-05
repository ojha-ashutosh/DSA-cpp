#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data in the left of node " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter the data in the right of node " << data << endl;
    root->right = buildtree(root->right);

    return root;
}
class kth_smalest_element
{
public:
    int solve(int arr[], int size, int k)
    {
        // max heap
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        // for rest element
        for (int i = k; i < size; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        // kth smalest element will be on top
        return pq.top();
    }
};
class is_binary_heap
{
public:
    int count_node(node *root)
    {
        if (root == NULL)
            return 0;
        return (count_node(root->left) + count_node(root->right) + 1);
    }
    bool is_CBT(node *root, int i, int count)
    {
        if (root == NULL)
        {
            return true;
        }
        if (i >= count)
        { // 0 based indexing matlab equal to bhi lagega
            return false;
        }
        else
        {
            bool left = is_CBT(root->left, 2 * i + 1, count);
            bool right = is_CBT(root->right, 2 * i + 2, count);
            return (left && right);
        }
    }
    bool is_max_order(node *root)
    {
        if (root->left == nullptr && root->right == NULL)
        {
            return true;
        }
        // aager yaha tk aa gye ho matlab CBT tho hai
        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left = is_max_order(root->left);
            bool right = is_max_order(root->right);
            return (left && right && ((root->data > root->left->data) && (root->data > root->right->data)));
        }
    }
    bool is_heap(node *root)
    {
        int count = count_node(root);
        int i = 0;
        if (is_CBT(root, i, count) && is_max_order(root))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
void heapify(vector<int> &ans, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && ans[left] > ans[largest])
    {
        largest = left;
    }
    if (right < size && ans[right] > ans[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(ans[i], ans[largest]);
        heapify(ans, size, largest);
    }
}
void heapify_first(vector<int> &ans, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(ans, size, i);
    }
}
class marge_two_binary_heap
{
public:
    vector<int> marge(vector<int> h1, vector<int> h2, int n1, int n2)
    {
        // marge both array
        vector<int> m;
        for (auto i : h1)
        {
            m.push_back(i);
        }
        for (auto i : h2)
        {
            m.push_back(i);
        }
        // make max heap of ans
        int size = m.size();
        heapify_first(m, size);

        return m;
    }
};
class min_cost_of_rope
{
    // There are given N ropes of different lengths, 
    // we need to connect these ropes into one rope. 
    // The cost to connect two ropes is equal to sum of their lengths.
    //  The task is to connect the ropes with minimum cost
public:
    int solve(int arr[])
    {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int size = sizeof(arr);
        for (int i = 0; i < size; i++)
        {
            minheap.push(arr[i]);
        }
        int cost = 0;
        while (minheap.size() != 1)
        {
            int i = minheap.top();
            minheap.pop();
            int j = minheap.top();
            minheap.pop();
            minheap.push(i + j);
            cost += i + j;
        }
        return cost;
    }
};
// 10 9 7 3 -1 -1 2 -1 -1 6 -1 -1 8 5 -1 -1 4 -1 -1
// max heap
// 1 9 7 3 -1 -1 2 -1 -1 6 -1 -1 8 5 -1 -1 4 -1 -1
// not a max heap

int main()
{
    int arr[] = {12, 2, 34, 5, 6};
    kth_smalest_element obj;
    cout << obj.solve(arr, 5, 1) << endl;
    is_binary_heap obj1;
    // node* root=NULL;
    // root=buildtree(root);
    // cout<<obj1.is_heap(root);
    vector<int> h1 = {23, 45, 6, 7, 24, 8};
    heapify_first(h1, h1.size());
    vector<int> h2 = {12, 34, 56, 76, 9};
    heapify_first(h2, h2.size());
    marge_two_binary_heap obj2;

    vector<int> margeheap = obj2.marge(h1, h2, h1.size(), h2.size());
    for (auto i : margeheap)
    {
        cout << i << " ";
    }
    cout << endl;
    int a[] = {4, 3, 2, 6};
    // 2+3=5
    // {5,4,6}
    // 5+4=9
    // {9,6}
    // (9+6)=15
    // {15}
    // total cost=5+9+15=29
    min_cost_of_rope obj3;
    cout << obj3.solve(a);
}