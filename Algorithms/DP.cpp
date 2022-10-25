#include <bits/stdc++.h>
using namespace std;

int NumberOfPath(int a, int b)
{
    // code here
    vector<vector<int>> dp(a, vector<int>(b, 1));
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[a - 1][b - 1];
}

// House Robbery /  Maximum sum of non-adjacent elements

int help(int n, vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notpick = dp[i - 1];

        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return help(nums.size(), nums, dp);
}

// O(1) Space method
int rob(vector<int> &nums)
{
    int prev2 = 0, prev = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notpick = prev;

        int curr = max(pick, notpick);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// If we encounter a circular array case, means first and last are adjacent
// Then we can use the same above function, but we have to give the input as two arrays
// 1st will do not have the last element and 2nd will not have the 1st element
// Hence the answer will be the max of the two solutions