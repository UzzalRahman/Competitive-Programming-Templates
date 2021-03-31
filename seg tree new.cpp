//*** Segment Tree ***
//Time Complexity: QlogN
#include<bits/stdc++.h>
using namespace std;
#define N 100200
int tree[N*4], arr[N], lazy[N*4];
int new_value,L,R;
int choice;
void build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    int left=nod*2;
    int right=nod*2+1;
    build(left,l,mid);
    build(right,mid+1,r);
    tree[nod]=tree[left]+tree[right];
}
int qu(int nod,int l,int r)
{
    if(r<L||l>R)
        return 0;
    if(l>=L&&r<=R)
    {
        return tree[nod];
    }
    int mid=(l+r)/2;
    int left=nod*2;
    int right=nod*2+1;
    int q1=qu(left,l,mid);
    int q2=qu(right,mid+1,r);
    return q1+q2;
}
void up(int nod,int l,int r)
{
    if(r<L||l>R)
        return;
    if(l>=L&&r<=R)
    {
        tree[nod]=tree[nod]+new_value;
        return;
    }
    int mid=(l+r)/2;
    int left=nod*2;
    int right=nod*2+1;
    up(left,l,mid);
    up(right,mid+1,r);
    tree[nod]=tree[left]+tree[right];
}
int main()
{
    int a,i,j,b,c,d,e,f,x,y,z,t,n,q,cas=0;
    cin>>t;
    while(t>0)
    {
        cin>>n>>q;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",++cas);
        for(i=1; i<=q; i++)
        {

            scanf("%d",&choice);
            if(choice==1)
            {
                scanf("%d%d",&a,&b);
                new_value=b;
                L=a,R=a;
                up(1,1,n);
            }
            else
            {
                scanf("%d%d",&a,&b);
                L=a,R=b;
                printf("%d\n",qu(1,1,n));

            }
        }

        t--;
    }

    return 0;
}
/*Input:
    1
    5 3
    1 2 3 4 5
    3 1 5
    1 5 1
    3 1 5
Output:
    Case 1:
    15
    16
  */
