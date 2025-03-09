#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        int idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
                idx = j;
        }
        swap(a[i], a[idx]);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    a = selection_sort(a);
    for (int x : a)
        cout << x << " ";
}