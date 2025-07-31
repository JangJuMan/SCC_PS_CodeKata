// 113. 전력망 둘로 나누기(완전탐색, BFS, DFS) / 풀었지만... re?
// https://school.programmers.co.kr/learn/courses/30/lessons/86971
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void init(vector<bool>& visited){
    fill(visited.begin(), visited.end(), false);
}

int dfs(int start, const vector<vector<int>>& graph, vector<bool>& visited){
    visited[start] = true;
    
    int cnt = 1;
    for(int node : graph[start]){
        if(!visited[node]){
            cnt += dfs(node, graph, visited);
        }
    }
    return cnt;
}

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
    int cnt=1;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        
        for(int next : graph[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n+1);
    for(int i=0; i<wires.size(); i++){
        graph[wires[i][0]].emplace_back(wires[i][1]);
        graph[wires[i][1]].emplace_back(wires[i][0]);
    }
    
    int ans = n+1;
    vector<bool> visited(n+1, false);
    for(int i=0; i<wires.size(); i++){
        init(visited);    
        visited[wires[i][1]] = true;    // wires[i][0]과 연결을 끊기 위함
        // int res1 = dfs(wires[i][0], graph, visited);
        int res1 = bfs(wires[i][0], graph, visited);
        int res2 = n - res1;            // wires[i][1]과 연결된 노드 수 = 총 노드수 - wires[i][0]과 연결된 노드 수
        ans = min(ans, abs(res1 - res2));
    }
    
    return ans;
}