
#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> adj_mat){
    for(int i=1;i<=4;i++){
        cout<<i<<"-->";
        for(int j=1;j<=4;j++){
            if(adj_mat[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }

}

int main(){
    vector<vector<int>> edgeList={
        {1,2},{2,3},{3,4},{4,2},{1,3}
    };
    
    vector<vector<int>> adj_mat(5, vector<int>(5, 0));
    for(int i=0;i<edgeList.size();i++){
        //undirected graph
        int a=edgeList[i][0];
        int b=edgeList[i][1];
        adj_mat[a][b]=1;
        adj_mat[b][a]=1;
    }
    print_graph(adj_mat);

    
}