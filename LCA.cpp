// LCA (Lowest Common Ancestor)
//Time complexity: NlogN
#include<bits/stdc++.h>
using namespace std;
#define rng 100
map<int,vector<int > > mp,Edge;
// Distance between a and b when LCA(a,b)=L
//dist(root,a)+dist(root,b)-2*dist(root,L)
int vis[rng],lvl[rng],dep,parent[rng],table[rng][10];
void DFS(int u)
{
    vis[u]=1;
    int len=Edge[u].size();
    for(int i=0;i<len;i++)
    {
        int v=Edge[u][i];
        if(vis[v]==0)
            {
                lvl[v]=lvl[u]+1;
                parent[v]=u;
                DFS(v);
            }
    }

}
void sparse_table(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;(1<<j)<n;j++)
            table[i][j]=-1;
    }
    for(int i=0;i<n;i++)
        table[i][0]=parent[i];
    for(int j=1;(1<<j)<n;j++)//(1<<j)<n mean 2^j<n
    {
        for(int i=0;i<n;i++)
        {
            if(table[i][j-1]!=-1)
                table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}
int LCA(int p,int q)
{
    if(lvl[p]<lvl[q])
        swap(p,q);
        int temp=1;
        int log=1;
    while(temp<=p)
    {
        temp=temp*2;
        log++;
    }
    for(int i=log;i>=0;i--)
    {
        if(lvl[p]-(1<<i)>=lvl[q])
            p=table[p][i];
    }
    if(p==q)
        return p;
    for(int i=log;i>=0;i--)
    {
        if(table[p][i]!=-1&&table[p][i]!=table[q][i])
        {
            p=table[p][i];
            q=table[q][i];
        }
    }
    return parent[p];
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        Edge[a].push_back(b);
    }
    lvl[0]=0;
    parent[0]=-1;
    DFS(0);
    sparse_table(n);
    cout<<LCA(8,2)<<endl;
    return 0;
}

