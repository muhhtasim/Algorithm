//Muhtasim
//22.07.25

#include <bits/stdc++.h>
using namespace std;

void bfs(int start_node, vector<int> adj[], bool visit[], int node)
{
    queue<int>n;
    n.push(start_node);
    visit[start_node] = true;

    cout << "BFS result: " << endl;
    while(!n.empty())
    {
        int fr = n.front();
        n.pop();
        cout << fr << endl;
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit[adj[fr][i]])
            {
                visit[adj[fr][i]]=true;
                n.push(adj[fr][i]);
            }
        }
    }
}

//Don't worry,you can copy ;)
void dfs(int start_node, vector<int> adj[], bool visit[], int node)
{
    stack<int>l;
    l.push(start_node);
    visit[start_node] = true;

    cout << "DFS result: " << endl;
    while(!l.empty())
    {
        int fr = l.top();
        l.pop();
        cout << fr << endl;
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit[adj[fr][i]])
            {
                visit[adj[fr][i]]=true;
                l.push(adj[fr][i]);
            }
        }
    }
}

//CR7 is the real GOAT
//"If you don’t believe you are the best, then you will never achieve all that you are capable of."
// — CR7 (a mindset both in football and coding)

int main()
{
    int node, edge, start_node;
  //  cout>>"Life is a graph — connected, undirected, and full of cycles">>endl;
//     cout>>"copy-pasting parts of the code works,">>endl;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    vector<int> adj[node + 1];
    bool visit[node + 1];

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for (int i = 0; i <= node; i++)
        visit[i] = false;
    bfs(start_node, adj, visit, node);

    for (int i = 0; i <= node; i++)
        visit[i] = false;
    dfs(start_node, adj, visit, node);

    return 0;
}


/*

int visit_bfs[1000005];
int visit_dfs[1000005];

vector<int> bfs(int s_node, vector<int>adj[])
{
    queue<int>q;
    visit_bfs[s_node] = 1;
    q.push(s_node);
    // cout << "BFS Output: ";
    vector<int>bfs_output;
    while(!q.empty())
    {
        int fr = q.front();
        q.pop();
        //cout << fr << " ";
        bfs_output.push_back(fr);
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit_bfs[adj[fr][i]])
            {
                visit_bfs[adj[fr][i]] = 1;
                q.push(adj[fr][i]);
            }
        }
    }
    return bfs_output;
}

void dfs(int s_node, vector<int>adj[])
{
    stack<int>s;
    visit_dfs[s_node] = 1;
    s.push(s_node);
    cout << "DFS Output: ";
    while(!s.empty())
    {
        int fr = s.top();
        s.pop();
        cout << fr << " ";
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit_dfs[adj[fr][i]])
            {
                visit_dfs[adj[fr][i]] = 1;
                s.push(adj[fr][i]);
            }
        }
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    vector<int>b = bfs(s, adj);
    cout << "BFS Output: ";
    for(int i=0; i<b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    dfs(s, adj);

}
*/

/*

vector<int> bfs(int start_node, vector<int> adj[], bool visit[], int node)
{
    vector<int> result;
    queue<int> n;
    n.push(start_node);
    visit[start_node] = true;

    while (!n.empty())
    {
        int fr = n.front();
        n.pop();
        result.push_back(fr);

        for (int i = 0; i < adj[fr].size(); i++)
        {
            if (!visit[adj[fr][i]])
            {
                visit[adj[fr][i]] = true;
                n.push(adj[fr][i]);
            }
        }
    }
    return result;
}

vector<int> dfs(int start_node, vector<int> adj[], bool visit[], int node)
{
    vector<int> result;
    stack<int> l;
    l.push(start_node);
    visit[start_node] = true;

    while (!l.empty())
    {
        int fr = l.top();
        l.pop();
        result.push_back(fr);

        for (int i = 0; i < adj[fr].size(); i++)
        {
            if (!visit[adj[fr][i]])
            {
                visit[adj[fr][i]] = true;
                l.push(adj[fr][i]);
            }
        }
    }
    return result;
}

int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    vector<int> adj[node + 1];
    bool visit[node + 1];

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    fill(visit, visit + node + 1, false);
    vector<int> bfs_result = bfs(start_node, adj, visit, node);
    cout << "BFS result: ";
    for (int i : bfs_result)
        cout << i << " ";
    cout << endl;

    fill(visit, visit + node + 1, false);
    vector<int> dfs_result = dfs(start_node, adj, visit, node);
    cout << "DFS result: ";
    for (int i : dfs_result)
        cout << i << " ";
    cout << endl;

    return 0;
}

*/

