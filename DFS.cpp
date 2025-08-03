#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    bool visit[node+1];
    vector<int> adj[node+1];

    cout << "Enter the edges: " << endl;
    for(int i=0; i<edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for(int i=0; i<=node; i++)
        visit[i]=false;

    stack<int>st;
    st.push(start_node);
    visit[start_node] = true;

    cout << "DFS result: " << endl;
    while(!st.empty())
    {
        int fr = st.top(); // changed from front() to top()
        st.pop();
        cout << fr << endl;
        for(int i=adj[fr].size()-1; i>=0; i--) // reverse for DFS order
        {
            if(!visit[adj[fr][i]])
            {
                visit[adj[fr][i]]=true;
                st.push(adj[fr][i]);
            }
        }
    }
}
