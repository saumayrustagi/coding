#include <bits/stdc++.h>

using namespace std;

int knapSackDP(int capacity, vector<int> weight, vector<int> profit, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= capacity; ++j)
        {
            if (weight[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + profit[i - 1]);
        }
    }
    return dp[n][capacity];
}

int knapSackDP1Row(int W, vector<int> &wt, vector<int> &val)
{
    int N = wt.size();
    vector<int> dp(W + 1, 0);

    int i, j;
    for (i = 1; i <= N; ++i)
    {
        for (j = W; j >= 0; --j)
        {
            if (wt[i - 1] <= j)
            {
                dp[j] = max(dp[j], val[i - 1] + dp[j - (wt[i - 1])]);
            }
        }
    }

    return dp[W];
}

int main()
{
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;
    int n = profit.size();
    // Maximum profit
    int sol1 = knapSackDP(W, weight, profit, n);
    int sol2 = knapSackDP1Row(W, weight, profit);
    if (sol1 != sol2)
    {
        perror("ERROR!");
        return 1;
    }
    cout << sol1 << '\n';
    cout << sol2 << '\n';
    return 0;
}
