*** Disjoint Set Union Implementation ***
#include<bits/stdc++.h>
using namespace std;
int arr[100];
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
int check(int a,int b)
{
    return find(a)==find(b);
}
int main()
{
    int x,a,b;
    for(x=0; x<100; x++)
        arr[x]=x;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        Union(a,b);
    }
    for(x=1; x<6; x++)
        cout<<x<<" = "<<arr[x]<<endl;
    return 0;
}
/*input:
1 2
2 3
4 5
3 4
0 0
output:
1 = 1
2 = 1
3 = 1
4 = 1
5 = 4
*/
