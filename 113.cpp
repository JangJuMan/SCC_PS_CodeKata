// 113. 전력망 둘로 나누기(완전탐색, BFS, DFS) / 풀었지만... re? (re. 더 최적화 할 수 있었음)
// https://school.programmers.co.kr/learn/courses/30/lessons/86971
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/* 2트 (최적화) */
int minDiff, N;

int getSubtreeSize(vector<vector<int>>& graph, int now, int parent){
    int nowSize = 1;

    for(const auto& next : graph[now]){
        if(next != parent){
            int subtreeSize = getSubtreeSize(graph, next, now);
            int diff = abs(N - 2 * subtreeSize);    // diff = | subtreeSize - (n-subtreeSize) |
            minDiff = min(minDiff, diff);
            nowSize += subtreeSize;
        }
    }
    return nowSize;
}

int solution(int n, vector<vector<int>> wires){
    N = n;
    minDiff = n+1;
    vector<vector<int>> graph(n+1);
    for(const auto& w : wires){
        int from=w[0], to=w[1];
        graph[from].emplace_back(to);
        graph[to].emplace_back(from);
    }

    getSubtreeSize(graph, 1, 0);        // 1번 노드부터 시작하며 subtree 개수 세기
    return minDiff;
}


// /* 1트 (최적화 X) */
// void init(vector<bool>& visited){
//     fill(visited.begin(), visited.end(), false);
// }

// int dfs(int start, const vector<vector<int>>& graph, vector<bool>& visited){
//     visited[start] = true;
    
//     int cnt = 1;
//     for(int node : graph[start]){
//         if(!visited[node]){
//             cnt += dfs(node, graph, visited);
//         }
//     }
//     return cnt;
// }

// int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
//     int cnt=1;
//     queue<int> q;
//     q.push(start);
//     visited[start] = true;
    
//     while(!q.empty()){
//         int cur = q.front(); 
//         q.pop();
        
//         for(int next : graph[cur]){
//             if(!visited[next]){
//                 visited[next] = true;
//                 q.push(next);
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// int solution(int n, vector<vector<int>> wires) {
//     vector<vector<int>> graph(n+1);
//     for(int i=0; i<wires.size(); i++){
//         graph[wires[i][0]].emplace_back(wires[i][1]);
//         graph[wires[i][1]].emplace_back(wires[i][0]);
//     }
    
//     int ans = n+1;
//     vector<bool> visited(n+1, false);
//     for(int i=0; i<wires.size(); i++){
//         init(visited);    
//         visited[wires[i][1]] = true;    // wires[i][0]과 연결을 끊기 위함
//         // int res1 = dfs(wires[i][0], graph, visited);
//         int res1 = bfs(wires[i][0], graph, visited);
//         int res2 = n - res1;            // wires[i][1]과 연결된 노드 수 = 총 노드수 - wires[i][0]과 연결된 노드 수
//         ans = min(ans, abs(res1 - res2));
//     }
    
//     return ans;
// }