//Muhtasim
//03.08.25


#include <bits/stdc++.h>
using namespace std;

#define sz 200005

//Don't worry,you can copy ;)
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

//CR7 is the real GOAT
//"If you don’t believe you are the best, then you will never achieve all that you are capable of."
// — CR7 (a mindset both in football and coding)
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
