#include <bits/stdc++.h>
using namespace std;
vector<int> insertion_sort(vector<int> a)
{
    int n = a.size();
    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
    return a;
}
void TestCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    a = insertion_sort(a);
    for (int x : a)
        cout << x << " ";
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        TestCase();
    return 0;
}