//Author: Muhtasim (20.7.25)
// LCS using recursion.


#include<bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0; //base case

    if (s1[m - 1] == s2[n - 1])
        return 1 + lcs(s1, s2, m - 1, n - 1);

    else
    {
        return max(lcs(s1, s2, m, n - 1),
                   lcs(s1, s2, m - 1, n));
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.size();
    int n = s2.size();

    cout << "Length of LCS: " << lcs(s1, s2, m, n);

    return 0;
}




/*

#include <bits/stdc++.h>
using namespace std;

string S1, S2;
int dp[1001][1001];

// Recursive function to get length of LCS
int lcs(int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (S1[m - 1] == S2[n - 1])
        return dp[m][n] = 1 + lcs(m - 1, n - 1);
    else
        return dp[m][n] = max(lcs(m - 1, n), lcs(m, n - 1));
}

// Function to reconstruct LCS string from memo table
string getLCS(int m, int n) {
    string lcsStr = "";
    while (m > 0 && n > 0) {
        if (S1[m - 1] == S2[n - 1]) {
            lcsStr += S1[m - 1];
            m--;
            n--;
        } else if (dp[m - 1][n] > dp[m][n - 1])
            m--;
        else
            n--;
    }
    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main() {
    cin >> S1 >> S2;
    int m = S1.size(), n = S2.size();

    memset(dp, -1, sizeof(dp));
    int length = lcs(m, n);
    string lcsString = getLCS(m, n);

    cout << "Length of LCS: " << length << endl;
    cout << "LCS: " << lcsString << endl;

    return 0;
}

*/










/*

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











#include <bits/stdc++.h>
using namespace std;

#define sz 200005

vector<int> adj[sz], cost[sz];
int vis[sz];
bool visited[sz]; // for BFS and DFS

// Prim’s Algorithm using priority queue
priority_queue<
pair<int, pair<int, int>>,
     vector<pair<int, pair<int, int>>>,
     greater<pair<int, pair<int, int>>>>
     pq;

int prims(int st)
{
    for (int i = 0; i < adj[st].size(); i++)
    {
        pq.push({cost[st][i], {st, adj[st][i]}});
    }

    vector<pair<int, pair<int, int>>> ans;
    vis[st] = 1;
    int c, u, v, tot = 0;

    while (!pq.empty())
    {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();

        if (!vis[u] || !vis[v])
        {
            ans.push_back({c, {u, v}});
            tot += c;

            if (vis[u] == 1)
                u = v;

            vis[u] = 1;

            for (int i = 0; i < adj[u].size(); i++)
            {
                if (!vis[adj[u][i]])
                    pq.push({cost[u][i], {u, adj[u][i]}});
            }
        }
    }

    cout << "MST Edges:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << ": " << ans[i].first << " -> (" << ans[i].second.first << "," << ans[i].second.second << ")" << endl;
    }

    return tot;
}

// BFS Traversal
void bfs(int start_node, vector<int> adj[], int node)
{
    queue<int> n;
    n.push(start_node);
    visited[start_node] = true;

    cout << "BFS Traversal: ";
    while (!n.empty())
    {
        int fr = n.front();
        n.pop();
        cout << fr << " ";

        for (int i = 0; i < adj[fr].size(); i++)
        {
            int next = adj[fr][i];
            if (!visited[next])
            {
                visited[next] = true;
                n.push(next);
            }
        }
    }
    cout << endl;
}

// DFS Traversal
void dfs(int start_node, vector<int> adj[], int node)
{
    stack<int> l;
    l.push(start_node);
    visited[start_node] = true;

    cout << "DFS Traversal: ";
    while (!l.empty())
    {
        int fr = l.top();
        l.pop();
        cout << fr << " ";

        for (int i = 0; i < adj[fr].size(); i++)
        {
            int next = adj[fr][i];
            if (!visited[next])
            {
                visited[next] = true;
                l.push(next);
            }
        }
    }
    cout << endl;
}


int main()
{
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter the edges (format: node1 node2 weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        cost[x].push_back(z);
        adj[y].push_back(x);
        cost[y].push_back(z);
    }

    int start_node;
    cout << "Enter the starting node: ";
    cin >> start_node;

    // Prim's Algorithm
    cout << "\nRunning Prim’s Algorithm..." << endl;
    memset(vis, 0, sizeof(vis));
    cout << "Total Cost of MST = " << prims(start_node) << "\n";

    // BFS
    cout << "\nRunning BFS..." << endl;
    memset(visited, 0, sizeof(visited));
    bfs(start_node, adj, n);

    // DFS
    cout << "\nRunning DFS..." << endl;
    memset(visited, 0, sizeof(visited));
    dfs(start_node, adj, n);

    return 0;
}


*/
