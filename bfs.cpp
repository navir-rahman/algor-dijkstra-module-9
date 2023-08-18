/*
input 
7
7
1 2
1 3
3 4
4 6
2 5
7 6
3 1
1 5

*/
#include <bits/stdc++.h>
using namespace std;
const int E=1e3+5;

vector<int> adj[E];
bool visited[E];
int level[E];
int parent[E]; //keep track of parent

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    parent[s]=-1;

    while (!q.empty())
    {

        int u =q.front();
        q.pop();
 
        for(auto v:adj[u])
        {
            if(visited[v]== true) continue;
            q.push(v);
            visited[v]=true;
            parent[v]=u;
            level[v]=level[u]+1;
        }
    }
    
}



int main(){

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

int s,d;
cin>>s>>d;
    bfs(s);

cout<<" Distence "<<level[d]<<endl;

vector<int>path;
int current=d;
while (current=! -1)
{
    path.push_back(current);
    current=parent[current];
}

reverse(path.begin(), path.end());

cout<<"Path ";
for(int node:path)
{
    cout<<node<<" ";
}


    // for (int i = 1; i <=n; i++)
    // {
    //     // cout<<"level of " <<i <<"  "<<level[i]<<endl;
    //     cout<<"parent of " <<i <<"  "<<parent[i]<<endl;

    // }
    
    
    return 0;
}