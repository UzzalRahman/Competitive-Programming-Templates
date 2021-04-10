///*** Articulation Bridge ***
/// Time complexity O(V+E)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SZ 100

int Time;
vector<int> adj[SZ];
int vis[SZ],low[SZ],dis[SZ];
vector< pair< int, int > > bridge;

void dfs(int u, int par) {
    vis[u]=1;
    low[u]=dis[u]=++Time;
    int child=0;
	for(int v : adj[u]) {
		if(!vis[v]) {
		    child++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
            if(low[v]>dis[u])bridge.push_back({u,v}); ///save bridges
		}else{
			if(v != par) low[u] = min(low[u], dis[v]);
		}
	}
}

int main(){

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(auto i: bridge){
        cout<<i.first<<' '<<i.second<<endl;
    }

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
output:
1 2
4 5
1 3
*/


