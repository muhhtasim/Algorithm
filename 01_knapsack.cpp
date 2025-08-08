//Author: Muhtasim (20.7.25)
// 0,1 knapsack using dp.

#include<bits/stdc++.h>
using namespace std;

int dp[101][1001];

int knapsack_01(int n, int w, int profit[], int wt[])
{
    if(n == 0 || w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    if(wt[n-1] > w)
        return dp[n][w] = knapsack_01(n-1, w, profit, wt);
    else
        return dp[n][w] = max(knapsack_01(n-1, w, profit, wt),
                              profit[n-1] + knapsack_01(n-1, w - wt[n-1], profit, wt));
}

int main()
{
    int n, w;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> w;

    int profit[n], wt[n];

    cout << "Enter profit and weight of each item:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Item " << i+1 << " - Profit: ";
        cin >> profit[i];
        cout << "Item " << i+1 << " - Weight: ";
        cin >> wt[i];
    }

    memset(dp, -1, sizeof(dp));
    int maxProfit = knapsack_01(n, w, profit, wt);
    cout << "\nMaximum Profit: " << maxProfit << endl;

    // Backtrack to find selected items
    int i = n, j = w;
    cout << "Selected items (0-based index):" << endl;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            cout << "Item " << i-1 << " (Profit: " << profit[i-1] << ", Weight: " << wt[i-1] << ")" << endl;
            j -= wt[i-1];
        }
        i--;
    }

    return 0;
}
