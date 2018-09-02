#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
public:
    int N;
    vector<vector<int>>adj;
    vector<bool>visited;
    Graph():N(0){}
    Graph(int n):N(n){
        adj.resize(N);
        visited.resize(N);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void sortList(){
        for(int i = 0 ; i < N ; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
    }
    int dfs(){
        int totalElement = 0;
        fill(visited.begin(),visited.end(), false);
        for(int i = 1 ; i < N ; i++){
            if(!visited[i]){
                dfs(i);
                totalElement++;
            }
        }
        return totalElement;
    }
private:
    void dfs(int curr){
        visited[curr] = true;
        for(int next : adj[curr]){
            if(!visited[next])
                dfs(next);
        }
    }
};

int main(){
    int n, m = 0;
    cin >> n >> m;
    Graph g(n+1);
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        g.addEdge(x,y);
    }
    g.sortList();
    cout << g.dfs() << endl;
}