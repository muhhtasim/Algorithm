//Author: Muhtasim (20.7.25)
//coin change - count minimum number of coins & maximum number of ways for targeted_amount

#include <bits/stdc++.h>
using namespace std;

#define mx 1000
int dp[mx][mx];

int minCoins(int coins[], int n, int target_amount)
{
    if (target_amount == 0) return 0; // sum already made
    if (target_amount < 0 || n == 0) return 1e9; // impossible

    if (dp[n][target_amount] == -1)
        dp[n][target_amount] = min(
            minCoins(coins, n, target_amount - coins[n - 1]) + 1,
            minCoins(coins, n - 1, target_amount)
        );

    return dp[n][target_amount];
}

int countWays(int coins[], int n, int target_amount)
{
    if (target_amount == 0) return 1;  // one way (no coins)
    if (target_amount < 0 || n == 0) return 0;  // no way

    if (dp[n][target_amount] != -1)
        return dp[n][target_amount];

    dp[n][target_amount] = countWays(coins, n, target_amount - coins[n - 1]) +
                           countWays(coins, n - 1, target_amount);

    return dp[n][target_amount];
}

int main()
{
    int n;
    cout << "Enter the number of coins: " << endl;
    cin >> n;
    int coin[n];
    cout << "Enter those coins: " << endl;
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int target_amount;
    cout << "Enter the amount: " << endl;
    cin >> target_amount;

    // Minimum coins
    memset(dp, -1, sizeof(dp));
    int result = minCoins(coin, n, target_amount);
    if (result >= 1e9)
        cout << "It is not possible to make the amount with given coins." << endl;
    else
        cout << "Minimum number of coins: " << result << endl;

    // Number of ways
    memset(dp, -1, sizeof(dp));
    cout << "Number of ways to make the amount: " << countWays(coin, n, target_amount) << endl;

    return 0;
}

