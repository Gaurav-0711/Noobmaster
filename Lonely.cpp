#include<iostream>
using namespace std;

int main()
{
    int n,m,r;
    int u,v;
    cin>>n>>m>>r;
    
    int adj[100][100]={0},prob[100]={0};
    for(int i =0;i<m;i++)
    {
        cin>>u;
        cin>>v;
        adj[u-1][v-1] = 1;
        
    }
    for(int i=0;i<n;i++)
    {
        if(adj[r-1][i]==1)
        prob[i] = 1;
    }
    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(prob[i]>0&&adj[i][j]==1)
        prob[j]++;
    }
    int max =0;

    for(int i =0;i<n;i++)
    if(prob[i]>prob[max])
    max = i;

    max++;
    cout<<max;
}
