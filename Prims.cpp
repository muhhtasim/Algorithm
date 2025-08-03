//Muhtasim
//20.07.25

#include<bits/stdc++.h>
using namespace std;

#define sz 200005

vector<int>adj[sz],cost[sz];
int vis[sz];

//CR7 is the real GOAT
//"If you don’t believe you are the best, then you will never achieve all that you are capable of."
// — CR7 (a mindset both in football and coding)


priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

int prims(int st)
{
    for (int i = 0; i<adj[st].size(); i++)
        pq.push({cost[st][i], {st,adj[st][i]}});

    vector<pair<int,pair<int,int> > >ans;
    vis[st]=1;
    int c, u, v, tot=0;
    while(!pq.empty())
    {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();
        if(!vis[u] || !vis[v])
        {
            ans.push_back( {c, {u,v} } );
            tot+=c;
            if(vis[u]==1)
                u = v;
            else u = u;
            vis[u]=1;
            for (int i = 0; i<adj[u].size(); i++)
            {
                if(! vis[adj[u][i]])
                    pq.push({cost[u][i],{u,adj[u][i]}});
            }
        }
    }

    for (int i = 0; i<ans.size(); i++)
    {
        cout<<i<<":"<<ans[i].first<<" -> ("<<ans[i].second.first << "," <<ans[i].second.second << ")"<<endl;
    }
    return tot;
}
int main()
{
    cout<<"copy-pasting parts of the code works,"<<endl;
    int st,n,m,x,y,z;
    cin>>n>>m;
    for (int i = 0; i<m; i++)
    {
        cin>>x>>y>>z;
        adj[x].push_back(y);
        cost[x].push_back(z);
        adj[y].push_back(x);
        cost[y].push_back(z);
    }
    cin>>st;
    cout<<"Total Cost of MST = "<<prims(st)<<"\n";
    return 0;
}




/*

typedef pair<int, int> PII;

void prims(int n, vector<vector<PII>> &adj) {
    vector<bool> visited(n, false);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 0}); // {weight, node}

    int mst_cost = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;

        visited[u] = true;
        mst_cost += w;

        for (auto [v, weight] : adj[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << "Minimum Spanning Tree cost: " << mst_cost << endl;
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges
    vector<vector<PII>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    prims(n, adj);
    return 0;
}
*/
