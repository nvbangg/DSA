#include <bits/stdc++.h>
using namespace std;
void BubbleSort1(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}
void BubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool flag = false;
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
void TestCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    BubbleSort(a);
    for (auto x : a)
        cout << x << ' ';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        TestCase();
    return 0;
}