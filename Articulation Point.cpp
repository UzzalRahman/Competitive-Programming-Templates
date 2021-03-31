*** Articulation Point ***
// Time complexity O(V+E)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SZ 100
vector<int> Edge[SZ];
int vis[SZ],low[SZ],dis[SZ],par[SZ],Time,mark[SZ];
vector<ll> Ans;
ll AP(int u)
{
    vis[u]=1;
    Time++;
    low[u]=Time;
    dis[u]=Time;
    int child=0;
    int len=Edge[u].size();
    for(int i=0;i<len;i++)
    {
        int v;
        v=Edge[u][i];
        if(vis[v]==0)
        {
            child++;
            par[v]=u;
            AP(v);
            low[u]=min(low[u],low[v]);
            if(par[u]==0&&child>1)
            {
                mark[u]=1;
            }
            if(par[u]!=0&&low[v]>=dis[u])
                mark[u]=1;
        }
        else if(v!=par[u])
        {
            low[u]=min(low[u],dis[v]);
        }
    }
}
int main()
{
    ll n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }
    AP(1);
    for(int i=1;i<=n;i++)
        cout<<mark[i]<<" ";
    return 0;
}
/*Input:
7 7
1 2
1 3
3 4
3 7
4 5
4 6
6 7
output: 1 3 4
*/


