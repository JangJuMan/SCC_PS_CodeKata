// 147. 가장 먼 노드(bfs) / 풀었지만.. 음 re?
// https://school.programmers.co.kr/learn/courses/30/lessons/49189
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

/* 답안 정리 */
int solution(int n, vector<vector<int>> edge){
    vector<vector<int>> graph(n+1);
    for(const auto& e : edge){
        int from = e[0], to = e[1];
        graph[from].emplace_back(to);
        graph[to].emplace_back(from);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next : graph[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.emplace(next);
            }
        }
    }
    int maxDist = *max_element(dist.begin(), dist.end());    // O(n)
    int count = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] == maxDist) count++;
    }
    return count;
}

/* 내 풀이 */
// int solution(int n, vector<vector<int>> edge) {
//     vector<int> distFrom1(n+1, 0);
//     vector<vector<int>> edges(n+1);
//     vector<bool> visited(n+1, false);
//     for(int i=0; i<edge.size(); i++){
//         int from = edge[i][0];
//         int to = edge[i][1];
//         edges[from].push_back(to);
//         edges[to].push_back(from);
//     }
    
//     int maxDist = 0;
//     queue<pair<int, int>> q;
//     q.push({1, 0});
//     visited[1] = true;
//     while(!q.empty()){
//         const auto& [curNode, curDist] = q.front();
//         q.pop();
//         for(const int& nextNode : edges[curNode]){
//             if(!visited[nextNode]){
//                 visited[nextNode] = true;
//                 distFrom1[nextNode] = curDist + 1;
//                 q.push({nextNode, curDist + 1});
//                 maxDist = max(maxDist, curDist+1);
//             }
//         }
//     }
    
//     int ans = 0;
//     for(int i=1; i<=n; i++){
//         if(distFrom1[i] == maxDist){
//             ans++;
//         }
//     }
//     return ans;
// }