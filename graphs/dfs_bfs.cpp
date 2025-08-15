
#include <bits/stdc++.h>
using namespace std;

void print_graph(unordered_map<int,vector<int>> graph){
    for(auto i:graph){
        cout<<i.first<<"-->";
        for(int node:i.second){
            cout<<node<<" ";
        }
        cout<<endl;
    }

}
void bfs(int source,unordered_map<int,vector<int>>graph,int n){
    queue<int>q;
    vector<int>visited(n);
    
    q.push(source);
    visited[source]=1;
    
    while(!q.empty()){
        int f=q.front();
        q.pop();
        cout<<f<<" ";
        for(int num:graph[f]){
            if(!visited[num]){
                q.push(num);
                visited[f]=1;
            }
        }
    }
}

void dfs(int source,unordered_map<int,vector<int>>graph,int n,vector<int>&visited){
    cout<<source<<" ";
    visited[source]=1;
    for(int nbr:graph[source]){
        if(!visited[nbr]){
            dfs(nbr,graph,n,visited);
        }
    }
}

int main(){
    vector<vector<int>> edgeList={
        {0,1},{1,4},{1,2},{2,3}
    };
    
    unordered_map<int,vector<int>> graph;

    for(int i=0;i<edgeList.size();i++){
        //undirected graph
        int a=edgeList[i][0];
        int b=edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int n=graph.size();
    cout<<"\n";
    print_graph(graph);
    
    cout<<"\nbfs: ";
    bfs(0,graph,n);
    
    cout<<"\ndfs: ";
    vector<int>visited(n,0);
    dfs(0,graph,n,visited);

    
}
