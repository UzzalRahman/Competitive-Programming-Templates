*** BFS in 2D Grid ***
int dx4[] = { 0, 0, -1, 1 };
int dy4[] = { 1, -1, 0, 0 };

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

#define rng 10000
queue<pair<int,int> >Q;
int vis[rng][rng],lvl[rng][rng];
int bfs(int u,int v,int n,int m)
{
    for(int i=0; i<rng; i++)
        for(int j=0; j<rng; j++)
            vis[i][j]=0;
    vis[u][v]=1;
    lvl[u][v]=0;
    Q.push(make_pair(u,v));
    while(!Q.empty())
    {
        u=Q.front().first;
        v=Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int u1=u+dx4[i];
            int v1=v+dy4[i];
            if(u1>=0&&v1>=0&&u1<n&&v1<m)
            {
                if(vis[u1][v1]==0)
                {
                    Q.push(make_pair(u1,v1));
                    vis[u1][v1]=1;
                    lvl[u1][v1]=lvl[u][v]+1;
                }

            }
        }
    }
}
