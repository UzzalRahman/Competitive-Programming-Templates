*** Big Int Multiplication***
//Time complexity: length of number1* length of number2
#include<bits/stdc++.h>
using namespace std;

string mul(string num1,string num2)
{
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    int len=num1.size();
    int len1=num2.size();
    int len3=len+len1;
    int arr1[10000],arr2[10000],ans[30000];
    int j=0;
    while(j<len3+5)
    {
        ans[j]=0;
        j++;
    }
    for(int i=0; i<len; i++)
    {
        arr1[i]=num1[i]-48;
    }
    for(int i=0; i<len1; i++)
    {
        arr2[i]=num2[i]-48;
    }
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len1; j++)
        {

            ans[i+j]+=arr1[i]*arr2[j];
            ans[i+j+1]=ans[i+j+1]+ans[i+j]/10;
            ans[i+j]%=10;
        }
    }

    while(ans[len3]==0)
        len3--;
    string Ans="";
    for(int i=0; i<=len3; i++)
    {
        Ans+=ans[i]+48;
    }
    reverse(Ans.begin(),Ans.end());
    return Ans;

}
int main()
{
    string num1,num2,Ans;
    int n,x,y;
    cin>>num1>>num2;
    Ans=mul(num1,num2);
    cout<<Ans<<endl;

}


