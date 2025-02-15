#include <bits/stdc++.h>
using namespace std;

int n, k, res = 0;
vector<int> b;

void Try(int index, int cnt, vector<int> &current)
{
    if (cnt == k)
    {
        res++;
        return;
    }
    for (int i = index; i < n; i++)
    {
        current.push_back(b[i]);
        Try(i + 1, cnt + 1, current);
        current.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    b.resize(n);
    for (int &x : b)
        cin >> x;

    vector<int> current;
    Try(0, 0, current);

    cout << res << endl;
}
