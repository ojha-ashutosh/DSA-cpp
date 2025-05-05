// union of two array
#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    while (i < n && j < m) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
        } else if (b[j] > a[i]) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }
    while (i < n) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        ans.push_back(a[i]);
        i++;
    }
    while (j < m) {
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 4, 4, 5, 6};
    vector<int> result = findUnion(a, b);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
