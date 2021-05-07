#include<bits/stdc++.h>
using namespace std; 

void solve()
{
    long long m,n,i,j;
    long double ma=-1;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n>>m;
    vector<long long>adj[n+1], in(n+1),top;
    cout<<"Enter Edges\n";
    for(i=0;i<m;i++)
    {
        long long c,d;
        cin>>c>>d;
        adj[c].push_back(d);
        in[d]++;
    }
    queue<long long>q;
    for(i=1;i<=n;i++)
    if(in[i]==0)
    q.push(i);
    while(!q.empty())
    {
        long long temp=q.front();
        q.pop();
        top.push_back(temp);
        for(i=0;i<adj[temp].size();i++)
        {
            in[adj[temp][i]]--;
            if(in[adj[temp][i]]==0)
            {
                q.push(adj[temp][i]);
            }
        }
    }
    for(i=0;i<top.size();i++)
    cout<<top[i]<<" ";
}
    
int main() {
	
	solve();
    cout<<endl;
	
	return 0;
}