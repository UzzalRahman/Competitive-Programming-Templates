*** Factorial Digit At any base ***
#include<bits/stdc++.h>
using namespace std;
int factorial_digit(int num,int base)
{
    double digit=0.00;
        for(int i=num; i>0; i--)
        {
            digit=digit+log(i);
        }
        digit=digit/log(base);
        return floor(digit)+1;
}
int main()
{
    int a,b,c,x,y,z,num,base;
    while(cin>>num>>base)
    {
        int digit=factorial_digit(num,base);
        cout<<digit<<endl;
    }
    return 0;
}
//Input: 5 10 Output: 3
