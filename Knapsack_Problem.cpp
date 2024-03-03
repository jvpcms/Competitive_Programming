// by jvpcms

/* A collection of itens, each with varying "value" and "weight."
Find out the maximum value that can be obtained in a subset of itens,
such that the total weight does not surpass a given maximum.

Keywords: Dynamic programming, Knapsack problem. */

#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int weight[N], value[N];

int dp[N][N];

int main(){
  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int s, n; cin >> s >> n;

    for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];

    for (int i = 1; i <= n; i++) for (int w = 0; w <= s; w++)
    {
        dp[i][w] = dp[i - 1][w];
        if (w - weight[i] >= 0) dp[i][w] = max(dp[i][w], dp[i - 1][w - weight[i]] + value[i]);
    }

    cout << dp[n][s] << '\n';

    return 0;
}
