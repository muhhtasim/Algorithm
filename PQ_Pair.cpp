#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair <int, int>, vector<pair <int, int> >, greater<pair <int, int> > >q;
    q.push({4,-4});
    q.push({10,-10});
    q.push({-2,2});
    q.push({1,-1});
    q.push({6,-6});
    q.push({3,-3});


    while(!q.empty())
    {
        cout << "(" << q.top().first << ", " << q.top().second << ") ";
        q.pop();

    }
    cout<<endl;

    pair <int, int>p;
    p.first=12;
    p.second=1.2;
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<int, float> >pp;
    pp.first=12;
    pp.second.first=-2;
    pp.second.second=-5;
    cout<<pp.first<<" "<<pp.second.first<<" "<<pp.second.second<<endl;

}

