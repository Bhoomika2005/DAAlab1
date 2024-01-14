#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* A Naive recursive implementation of
 0-1 Knapsack problem */

// ll knapSack(ll W, ll wt[], ll val[], ll n)
// {

//      Base Case
//     if (n == 0 || W == 0)
//         return 0;

//     if (wt[n - 1] > W)
//         return knapSack(W, wt, val, n - 1);

//     else
//         return max(
//             val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
//             knapSack(W, wt, val, n - 1));
// }

// time complexity : O(2^N)
/*By using recursion we are computing same sub problems again and again so we can optimize this by using DP*/

// Using DP
ll knapSack(ll W, ll wt[], ll val[], ll n)
{
    // Making and initializing dp array
    ll dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (ll i = 1; i < n + 1; i++)
    {
        for (ll w = W; w >= 0; w--)
        {

            if (wt[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}
// time complexity : O(N*W)

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll values[n], weights[n];
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }

        int W;
        cin >> W;
        cout << knapSack(W, weights, values, n);
    }
    return 0;
}
