//*** Topological Sort ***
//Time Complexity: V*V
#include<bits/stdc++.h>
using namespace std;
#define M 55
vector<int> ans, depends[M];
int visited[M], cycle = 0;
vector<int> edge[M];
int taken[M];

// depends[i] contains all the items that item i is depending on
// when taken[i] = 1, that means it's already taken

void take( int p ) {
    if( !taken[ p ] ) {
        // i am taking all the items that i should take before p
        for(int i=0; i<depends[p].size(); i++)
            take( depends[p][i] );
        ans.push_back( p ); // now i can take it
        taken[p] = 1;
    }
}

void visit( int p ) {
    if( visited[p] == 2 || cycle ) return;
    // we won't process anything if we already have found a cycle
    if( visited[p] == 1 ) {
        cycle = 1; // found cycle
        return;
    }

    visited[p] = 1;
    for(int i=0; i<edge[p].size(); i++) visit( edge[p][i] );
    visited[p] = 2;
}
int main() {
    int n,m,i,j,k,x,y,z;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        depends[x].push_back(y);
    }
    for(int i=1; i<=n; i++) take( i );
    for(int i=0; i<n; i++) printf("%d ", ans[i] );

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
    1 3 2 0 4 5
*/
