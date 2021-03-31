*** Floyed Warshell ***
// Time complexity O(N*N*N)
#include<bits/stdc++.h>
#define X 110
using namespace std;
long long int mat[X][X],n,nxt[X][X];
long long int inf=INT_MAX;
void floyed_warshall()
{
    int i,j,k;
    for(k=1; k<101; k++)
    {
        for(i=1; i<101; i++)
        {
            for(j=1; j<101; j++)
            {
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                nxt[i][j]=nxt[i][k];
            }
        }
    }
}
void init()
{
    int i,j;
    for(i=0; i<101; i++)
    {
        for(j=0; j<101; j++)
        {
            mat[i][j]=inf;
            nxt[i][j]=j;
        }
    }
}
int main()
{
    int u,v;
    while(cin>>u>>v)
    {
        if(u==0&&v==0)
            break;
        mat[u][v]=1;
    }
    floyed_warshall();
    return 0;
}


