#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int wt, vector<vector<int>> &dp, vector<int> &values, vector<int> &weights)
{
    if (ind == 0)
    {
        if (wt >= weights[0])
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][wt] != -1)
        return dp[ind][wt];

    int notTake = solve(ind - 1, wt, dp, values, weights);
    int take = 0;
    if (wt - weights[ind] >= 0)
    {
        take = values[ind] + solve(ind - 1, wt - weights[ind], dp, values, weights);
    }
    return dp[ind][wt] = max(notTake, take);
}

int main()
{
    int n, wt;
    cin >> n >> wt;
    vector<vector<int>> dp(n, vector<int>(wt + 1, -1));
    vector<int> values(n), weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
    }
    cout << solve(n - 1, wt, dp, values, weights);
    return 0;
}