#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
public:
    int N; // 정점의 개수
    vector<vector<int>> adj; // 인접 리스트

    // 생성자
    Graph(): N(0){}
    Graph(int n): N(n){ adj.resize(N); }

    // 간선 추가 함수
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 모든 리스트의 인접한 정점 번호 정렬
    void sortList(){
        for(int i=0; i<N; i++)
            sort(adj[i].begin(), adj[i].end());
    }

    // 너비 우선 탐색
    int bfs(int f_p, int s_p){
        vector<bool> visited(N, false); // 방문 여부를 저장하는 배열
        queue<int> Q;
        Q.push(f_p);
        visited[f_p] = true;

        int level1 = 0;
        int level2 = 0;
        bool isLevel1Found = false;
        bool isLevel2Found = false;

        int count = 0;
        while(!Q.empty()){


            int qsize = Q.size();
            for(int i = 0 ; i < qsize ; i++){
                int curr = Q.front();
                Q.pop();

                if(curr == f_p){
                    level1 = count;
                    isLevel1Found = true;
                }

                else if(curr == s_p){
                    level2 = count;
                    isLevel2Found = true;
                }

                for(int next: adj[curr]){
                    if(!visited[next]){
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            }

            count++;
        }
        int result = -1;
        if(isLevel1Found){
            if(isLevel2Found){
               result = level2-level1;
            }
        }
        return result;
    }
};

int main(){
    int peopleNum;
    int fp, sp;
    int relNum;

    cin >> peopleNum;
    Graph g(peopleNum+1);
    cin >> fp >> sp;
    cin >> relNum;
    for(int i = 0 ; i < relNum ; i++){
        int tx, ty;
        cin >> tx >> ty;
        g.addEdge(tx,ty);
    }
    g.sortList();
    if(fp >= sp){
        int temp = fp;
        fp = sp;
        sp = temp;
    }
    cout << g.bfs(fp,sp) << endl;

}
