#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int tree[4*100000][20];
int lazy[4*100000][20];
int kp[100050][20];
int s,u,v,n,m,tp;

void build(int nod,int l,int r,int no)
{
    if(l==r)
    {
        tree[nod][no]=kp[l][no];
        lazy[nod][no]=0;
        return ;
    }

    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;

    build(left,l,mid,no);
    build(right,mid+1,r,no);

    lazy[nod][no]=0;
    tree[nod][no]=tree[left][no]+tree[right][no];
}

void update(int nod,int l,int r,int no)
{
    if(r<u || v<l) return;

    if(u<=l && r<=v)
    {

        if(s==1)
        {
            //cout<<tree[nod][no]<<endl;

            tree[nod][no]=(r-l+1)-tree[nod][no];
            lazy[nod][no]+=s;
            if(lazy[nod][no]==2)
                lazy[nod][no]=0;
            //cout<<tree[nod][no]<<endl;
        }
        return ;
    }

    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;


    if(lazy[nod][no]>0)
    {
        tree[left][no]=(mid-l+1)-tree[left][no];
        lazy[left][no]=lazy[nod][no]+lazy[left][no];
        if(lazy[left][no]==2)
            lazy[left][no]=0;
        tree[right][no]=(r-mid)-tree[right][no];
        lazy[right][no]=lazy[nod][no]+lazy[right][no];
        if(lazy[right][no]==2)
            lazy[right][no]=0;

        lazy[nod][no]=0;
    }


    update(left,l,mid,no);
    update(right,mid+1,r,no);
    tree[nod][no]=tree[left][no]+tree[right][no];
}
void query(int nod,int l,int r,int no)
{
    if(r<u || v<l) return;

    if(u<=l && r<=v)
    {
        s+=tree[nod][no];
        return ;
    }

    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;



    if(lazy[nod][no]>0)
    {
        tree[left][no]=(mid-l+1)-tree[left][no];
        lazy[left][no]=lazy[nod][no]+lazy[left][no];
        if(lazy[left][no]==2)
            lazy[left][no]=0;
        tree[right][no]=(r-mid)-tree[right][no];
        lazy[right][no]=lazy[nod][no]+lazy[right][no];
        if(lazy[right][no]==2)
            lazy[right][no]=0;
        lazy[nod][no]=0;
    }


    query(left,l,mid,no);
    query(right,mid+1,r,no);

    tree[nod][no]=tree[left][no]+tree[right][no];
}
long long int convert(long long int no,long long int cnt)
{
    long long int temp=1;
    while(no>0)
    {
        temp*=2;
        no--;
    }
    return (temp*cnt);
}
#define FastIO {ios_base::sync_with_stdio(false); cin.tie(0);}
int main()
{
    FastIO;
    int c;
    cin>>n;
    string s1;
    for(int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        s1=bitset<20>(num).to_string();
        reverse(s1.begin(),s1.end());
        for(int j=0; j<20; j++)
            kp[i][j]=s1[j]-'0';
    }
    for(int i=0; i<20; i++)
        kp[0][i]=kp[1][i];
    for(int i=0; i<20; i++)
        build(1,1,n,i);
    cin>>m;
    while(m--)
    {
        cin>>tp;

        if(tp!=1) // type 1
        {
            cin>>u>>v>>s;
            s1=bitset<20>(s).to_string();
            reverse(s1.begin(),s1.end());
            for(int i=0; i<20; i++)
            {
                s=s1[i]-'0';
                update(1,1,n,i);
            }
        }
        else
        {
            long long int Ans=0;
            cin>>u>>v;
            s=0;
            for(int i=0; i<20; i++)
            {
                s=0;
                query(1,1,n,i);

                Ans+=convert(i,s);
            }
            cout<<Ans<<endl;
        }
    }

    return 0;
}
