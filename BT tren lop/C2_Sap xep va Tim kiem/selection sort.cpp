#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] <= a[i])
                min = j;
        }
        swap(a[i], a[min]);
    }
    for (auto x : a)
        cout << x << " ";
}