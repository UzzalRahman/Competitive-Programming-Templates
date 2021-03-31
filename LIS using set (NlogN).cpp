//*** LIS implementation Using Set ***
//Time Complexity: NlogN
#include<bits/stdc++.h>
using namespace std;
const int rng = 1000;
int input[ rng + 5];
void Lis(int n)
{
    //set<int> lis;////  duplicate value not allowed
    //set < int > :: iterator  it ;////  duplicate value not allowed
    multiset < int > lis ;//// duplicate value allowed
    multiset < int > :: iterator  it ;//// duplicate value allowed
    int num;
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&num);
        lis.insert( num);
        //it = lis.find( input[i]);////  duplicate value not allowed
        it = lis.upper_bound( num);//// duplicate value allowed
        if( it != lis.end()) lis.erase(it);
    }
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        int temp=*it;
        cout<<temp<<" ";
    }
    cout <<endl << lis.size() << endl ;
}
int main()
{
    int n,num;
    cin>>n;
    Lis(n);
}
/*Input:
    9
    2 5 3 7 11 8 10 13 6
Output:
    2 3 6 8 10 13
    6
    */
