//***Kruskal***
// Time Complexity: O(ElogE) or O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define rng 1000
priority_queue<pair<int,pair<int,int> > > Edge;
vector<pair<int,int> > path;
long long int ans;
int arr[rng];
int find(int a)
{
    if(arr[a]==a)
        return a;
    else
        return arr[a]=find(arr[a]);
}
int Union(int a,int b)
{
    if(a>b)
        arr[find(a)]=find(b);
    else
        arr[find(b)]=find(a);
}
bool check(int a,int b)
{
    return find(a)==find(b);
}
int kruskal(int n)
{
    for(int i=0;i<=n;i++)
        arr[i]=i;
    int count=0;
    while(!Edge.empty())
    {
        int edge1=Edge.top().second.first;
        int edge2=Edge.top().second.second;
        int cost=Edge.top().first;
        cost=cost*-1;
        Edge.pop();
        if(check(edge1,edge2)==0)
        {
            Union(edge1,edge2);
            ans+=cost;
            path.push_back(make_pair(edge1,edge2));
            count++;
        }
        if (count == n - 1)
            break;
    }
}
int main()
{
    int nodes,edge,T,N,M,E,a,b,c,x,y,z,i,j,k;
    while(cin>>T)
    {
        for(i=1; i<=T; i++)
        {
            cin>>N>>M;
            for(j=0; j<M; j++)
            {
                cin>>a>>b>>c;
                c=c*-1;
                Edge.push(make_pair(c,make_pair(a,b)));
            }
            ans=0;
            kruskal(N);
            cout<<ans<<endl;
        }
    }

    return 0;
}
/*Input:
    1
    4 5
    0 1 10
    0 2 6
    0 3 5
    1 3 15
    2 3 4
Output:
    19
    */
