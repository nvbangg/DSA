#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void QuickSort(int l, int r)
{
    int i = l, j = r, chot = (l + r) / 2;
    do
    {
        while (a[i] < a[chot]) && i < r) ++i;
        while (a[j] > a[chot]) && j > l) --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }

    } while (i <= j);
    if (l < j)
        QuickSort(l, j);
    if (i < r)
        QuickSort(i, r);
}

void TestCase()
{
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a)
        cin >> x;
    QuickSort(0, n - 1);
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