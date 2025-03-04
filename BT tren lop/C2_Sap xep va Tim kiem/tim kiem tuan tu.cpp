#include <bits/stdc++.h>
using namespace std;
void TestCase()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; ++i)
        if (a[i] == k)
        {
            cout << i + 1 << endl;
            return;
        }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        TestCase();
    return 0;
}