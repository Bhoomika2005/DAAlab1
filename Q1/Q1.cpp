#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // int n = sizeof(arr) / sizeof(arr[0]); By sorting the given array
        // sort(arr, arr + n);                    O(logn)
        // cout << arr[n - 2] + arr[n - 1];

        // But we can optimize it to O(n)
        ll first = max(arr[0], arr[1]);
        ll sec = min(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            if (arr[i] > first)
            {
                sec = first;
                first = arr[i];
            }
            else if (arr[i] > sec && arr[i] != first)
            {
                sec = arr[i];
            }
        }

        cout << first + sec << endl;
    }

    return 0;
}