*** BFS ***
// Time complexity O(N+M)
#define rng 100000
queue<int>Q;
vector<int> edge[rng];
int vis[rng],lvl[rng];
int bfs(int u)
{
    for(int x=0;x<rng;x++)
    vis[x]=0;
    vis[u]=1;
    lvl[u]=0;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        int len=edge[u].size();
        for(int i=0;i<len;i++)
        {
            int v=edge[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                lvl[v]=lvl[u]+1;
                Q.push(v);
            }
        }
    }
}

