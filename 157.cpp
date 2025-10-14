// 157. 부대복귀(단순 반복 + bfs) / 품. 그러나 re / O(N*M) -> O(N+M)으로 줄일 수 있음
// https://school.programmers.co.kr/learn/courses/30/lessons/132266
#include <string>
#include <vector>
#include <queue>

using namespace std;

// destination 부터 시작하면 불필요한 반복을 줄일 수 있음
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> graph(n+1);
    for(const auto& r : roads){
        graph[r[0]].emplace_back(r[1]);
        graph[r[1]].emplace_back(r[0]);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    q.emplace(destination);
    dist[destination] = 0;
    
    while(!q.empty()){  // bfs는 한 번만 실행함 (역순으로)
        int cur = q.front();    q.pop();
        for(int next : graph[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.emplace(next);
            }
        }
    }
    
    vector<int> ans;
    for(int s : sources){
        ans.emplace_back(dist[s]);
    }
    
    return ans;
}

/* 내가 푼 불필요한 반복 버전 */
// int bfs(int n, int start, int destination, const vector<vector<int>>& graph){
//     vector<int> visited(n+1, 0);
//     queue<int> q;
    
//     q.emplace(start);
//     visited[start] = 0;
//     while(!q.empty()){
//         int cur = q.front();    q.pop();
//         if(cur == destination){
//             return visited[cur];
//         }
        
//         for(const int& next : graph[cur]){
//             if(!visited[next]){
//                 visited[next] = visited[cur] + 1;
//                 q.emplace(next);
//             }
//         }
//     }
//     return -1;
// }

// vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
//     vector<int> ans;
//     vector<vector<int>> graph(n+1);
    
//     for(const vector<int>& in : roads){
//         graph[in[0]].emplace_back(in[1]);
//         graph[in[1]].emplace_back(in[0]);
//     }
    
//     for(const int& source : sources){
//         int res = bfs(n, source, destination, graph);
//         ans.emplace_back(res);
//     }
    
//     return ans;
// }