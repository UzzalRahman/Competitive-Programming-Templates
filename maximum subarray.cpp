*** Maximum Subarray Sum ***
int main()
{
    int a,b[110],c,d,e,f,x,y,z;
    cin>>a;
    int ans=0;
    for(x=0;x<a;x++)
    {
        cin>>b[x];
    }
    int cur_sum=0,max_sum=0;
    for(x=0;x<a;x++)
    {
        cur_sum=max(b[x],cur_sum+b[x]);
        if(cur_sum>max_sum)
            max_sum=cur_sum;
    }
    cout<<max_sum<<endl;
    return 0;
}





