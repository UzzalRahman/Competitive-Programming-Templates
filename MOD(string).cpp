//*** Big Int Mod ***
//Time Complexity: length of number
#include<iostream>
using namespace std;
int mod(string num, int M)
{
    int res = 0;
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         {
             res = (res*10 + (int)num[i] - '0') %M;
         }
    return res;
}
int main()
{
    string num = "12316767678678";
    cout << mod(num, 10); //Output: 8
    return 0;
}
