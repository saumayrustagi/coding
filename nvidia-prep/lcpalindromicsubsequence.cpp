#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2){
    int n,m;
    n = s1.size();
    m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int i,j;
    for(i = 1; i<=n; ++i){
        for(j = 1; j<=m; ++j){
            if(s1[i]==s2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int lcpalindromesubsequence(string s1){
    string s2;
    for(int i=s1.size()-1; i>=0; --i){
        s2 += s1[i];
    }
    return lcs(s1, s2);
}

int main()
{
    string s = "bbabcbcab";

    cout << lcpalindromesubsequence(s) << '\n';
}