***Trie Implementation***
#include<bits/stdc++.h>
using namespace std;

struct node *root, *curr;
struct node
{
    bool endmark;
    node* next[26+1];
    node()
    {
        endmark= false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
};
void insert(string s)
{
    curr=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=true;
}

bool search(string s)
{
    curr=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;

}
bool delete_node(string s)
{
    curr=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    curr->endmark=false;

}
int main()
{
    string s;
    int i;
    root=new node();
    while(true)
    {
        cin>>i;
        cin>>s;
        if(i==1)
        {
            insert(s);
        }
        else if(i==2)
        {
            delete_node(s);
        }
        else
        {
            if(search(s))
                cout<<"found"<<endl;
            else
                cout<<"huh"<<endl;
        }
    }
    return 0;
}
