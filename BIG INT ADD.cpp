***Big INT Add***
#include<bits/stdc++.h>
using namespace std;
// Complexity: max(number1 length ,number2 length)
string Add(string num1,string num2)
{
    string ans;
    int len1,len2,len3;
    len1=num1.length();
    len2=num2.length();
    len3=max(len1,len2);
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    for(int x=min(len1,len2);x<len3;x++)
    {
        if(x>=len1)
            num1+=48;
        if(x>=len2)
            num2+=48;
    }
    int carry=0;
    for(int i=0;i<len3;i++)
    {
        int n,m,sum;
        n=num1[i]-48;
        m=num2[i]-48;
        sum=n+m+carry;
        carry=0;
        if(sum>=10)
        {
            ans+=sum%10+48;
            sum=sum/10;
            carry=sum;
        }
        else
        {
            ans+=sum+48;
        }
    }
    if(carry>0)
        ans+=carry+48;
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string num1,num2,Ans;
    int n,x,y;
    cin>>num1>>num2;
    Ans=Add(num1,num2);
    cout<<Ans<<endl;

}
