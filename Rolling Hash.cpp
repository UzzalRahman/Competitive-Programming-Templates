#include<bits/stdc++.h>
using namespace std;
const int mod1=100000123;
const int mod2=100033111;
const int base=33;
const int rng=250003;
long long int  Base1[rng+2],Base2[rng+2];
int suff1[rng+2],pre1[rng+2],suff2[rng+2],pre2[rng+2];
void pre_calculation()
{
    Base1[0]=1,Base2[0]=1;
    for(int i=1; i<rng; i++)
    {
        Base1[i]=(Base1[i-1]*(long long int)base)%mod1;
        Base2[i]=(Base2[i-1]*(long long int)base)%mod2;
    }
}
int Calculate_Hash(string str,int needle_length,int mod,int base)
{
    long long int value=0;
    for(int i=0; i<needle_length; i++)
    {
        value*=base;
        value+=str[i]-'a'+1;
        value%=mod;
    }
    return value;

}
void CalculatePrefix(int *pre,string str,int base,int mod)
{
    long long int value=0;
    pre[0]=0;
    for(int i=0; i<str.size(); i++)
    {
        value*=base;
        value+=str[i]-'a'+1;
        value%=mod;
        pre[i+1]=value;
    }
}
void CalculateSuffix(int *suff,string str,int base,int mod)
{
    long long int value=0;
    suff[0]=0;
    int j=1;
    for(int i=str.size()-1; i>=0; i--)
    {
        value*=base;
        value+=str[i]-'a'+1;
        value%=mod;
        suff[j++]=value;
    }
}
bool Query(int str,int left,int right)
{
    // 1-based index of suff and pre array
    left++;
    right++;
    int length=(right-left)+1;

    //Calculate prefix value using mod1 and mod2
    long long int pre_value1=(pre1[right]-(pre1[left-1]*Base1[length]))%mod1;
    pre_value1=(pre_value1+mod1)%mod1;
    long long int pre_value2=(pre2[right]-(pre2[left-1]*Base2[length]))%mod2;
    pre_value2=(pre_value2+mod2)%mod2;

    // calculate suffix value using mod1 and mod2
    right=str-left+1;
    left=right-length+1;
    long long int suff_value1=(suff1[right]-(suff1[left-1]*Base1[length]))%mod1;
    suff_value1=(suff_value1+mod1)%mod1;
    long long int suff_value2=(suff2[right]-(suff2[left-1]*Base2[length]))%mod2;
    suff_value2=(suff_value2+mod2)%mod2;
    //cout<<pre_value1<<" "<<suff_value1<<endl;
    if(pre_value1==suff_value1&&pre_value2==suff_value2)
        return true;
    return false;

}
bool Check(string str,int mid)
{
    int len=str.size();
    if(mid>len)
        return false;
    bool flag=false;
    for(int i=0; i<=len-mid; i++)
    {
        flag|=Query(len,i,i+mid-1);
    }
    return flag;
}
int solve(string str)
{
    int n=str.size();
    CalculateSuffix(suff1,str,base,mod1);
    CalculateSuffix(suff2,str,base,mod2);
    CalculatePrefix(pre1,str,base,mod1);
    CalculatePrefix(pre2,str,base,mod2);
    int lo=1,hi=n;
    int mid=(lo+hi)/2;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        bool flag1=Check(str,mid);
        bool flag2=Check(str,mid+1);
        if(flag1==true)
        {
            lo=mid+1;
        }
        else if( flag2==true)
        {
            lo=mid+2;
        }
        else
            hi=mid-1;
    }
    while(Check(str,lo)==false)
        lo--;
    return lo;
}
int main()
{
    pre_calculation();
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<solve(str)<<endl;
    return 0;
}
