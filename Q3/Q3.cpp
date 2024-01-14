#include <bits/stdc++.h>
using namespace std;

const int n = 4;
const int MAX = 1000000;

int dist[n + 1][n + 1] = {
    {0, 0, 0, 0, 0},
    {0, 0, 20, 42, 35},
    {0, 20, 0, 30, 34},
    {0, 42, 30, 0, 12},
    {0, 35, 34, 12, 0},

};

int arr[n + 1][1 << (n + 1)];

int fun(int i, int m)
{
    if (m == ((1 << i) | 3))
        return dist[1][i];

    if (arr[i][m] != 0)
        return arr[i][m];

    int res = MAX;

    for (int j = 1; j <= n; j++)
        if ((m & (1 << j)) && j != i && j != 1)
            res = min(res, fun(j, m & (~(1 << i))) + dist[j][i]);

    return arr[i][m] = res;
}

int main()
{
    int ans = MAX;
    for (int i = 1; i <= n; i++)
        ans = min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);

    cout << ans;

    return 0;
}