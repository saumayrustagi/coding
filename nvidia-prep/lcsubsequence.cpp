#include <bits/stdc++.h>

using namespace std;

int lcsRecursive(string s1, string s2, int n, int m)
{
    if (n < 0 || m < 0)
        return 0;

    if (s1[n] == s2[m])
        return 1 + lcsRecursive(s1, s2, n - 1, m - 1);
    else
        return max(lcsRecursive(s1, s2, n - 1, m), lcsRecursive(s1, s2, n, m - 1));
}

int lcsDP(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    return lcsDP(s1, s2, n, m);
}

int main()
{
    string s1 = "abcdb";
    string s2 = "bcacdhb";

    cout << lcs(s1, s2) << '\n';
}