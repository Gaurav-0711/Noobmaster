#include<bits/stdc++.h>
using namespace std; 

void dfs(long long s, vector<long long> adj[], vector<long long> &top,vector<long long> &vis)
{
	vis[s]=1;
	long long i;
	for(i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
   	    {
   	    	vis[adj[s][i]]=1;
            dfs(adj[s][i],adj,top,vis);
        }
    }
    top.push_back(s);
}

void solve()
{
    long long m,n,i,j;
    long double ma=-1;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n>>m;
    vector<long long>adj[n+1],top,vis(n+1,0);
    cout<<"Enter Edges\n";
    for(i=0;i<m;i++)
    {
        long long c,d;
        cin>>c>>d;
        adj[c].push_back(d);
    }
    dfs(1,adj,top,vis);
    for(i=0;i<top.size();i++)
    cout<<top[top.size()-i-1]<<" ";
}
    
int main() {
	
	solve();
    cout<<endl;
	return 0;
}