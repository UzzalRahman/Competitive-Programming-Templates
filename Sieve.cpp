*** Sieve ***
#define S 10000000
bool mark[S+6];
vector<int > prime;
void sieve()
{
    int i,j;
    for(i=0; i<S; i++)
        mark[i]=0;
    mark[0]=mark[1]=1;
    for(i=4; i<S; i=i+2)
        mark[i]=1;
    for(i=3; i*i<=S; i=i+2)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<=S; j=j+i+i)
                mark[j]=1;
        }
    }
    j=0;
    for(i=2; i<S; i++)
        if(mark[i]==0)
            prime.push_back(i);

}


