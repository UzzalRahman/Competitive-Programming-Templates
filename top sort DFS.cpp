//*** Topological Sort ***
//Time Complexity: V*E
#include<bits/stdc++.h>
using namespace std;
#define rng 10000
typedef long long int ll;
vector<int> Edge[rng+5];
int vis[rng+5];
stack<ll> St;
int init()
{
    for(int i=0; i<rng; i++)
        vis[i]=0;
}
ll DFS(ll x,ll y)
{
    vis[x]=1;
    ll len=Edge[x].size();
    for(int i=0; i<len; i++)
    {
        if(vis[Edge[x][i]]==0)
        {
            DFS(Edge[x][i],y+1);
        }
    }
    St.push(x);
}
ll printall()
{
    while(!St.empty())
    {
        ll a=St.top();
        St.pop();
        printf("%lld",a);
        if(St.size()!=0)
            printf(" ");
    }
    printf("\n");
}
int main()
{
    int n,m,i,j,k,x,y,z;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        Edge[x].push_back(y);
    }
    for(int i=0; i<n; i++)
    {
        if(vis[i]==0)
            DFS(i,0);
    }
    printall();

    return 0;
}
/*Input:
    6 6
    5 2
    5 0
    4 0
    4 1
    2 3
    3 1
Output:
    5 4 2 3 1 0
*/


