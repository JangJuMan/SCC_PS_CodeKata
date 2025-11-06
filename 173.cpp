// 173. 등대(tree dp, dfs, 최소 vertex cover) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/133500
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int node){
    visited[node] = true;
    dp[node][0] = 0;    // 꺼짐
    dp[node][1] = 1;    // 켜짐
    
    for(const auto& child : graph[node]){
        if(!visited[child]){
            dfs(child);  // 리프노드부터 계산해서 올라오기
            dp[node][0] += dp[child][1];    // 내가 꺼졌다면, 자식은 무조건 켜져야 함
            dp[node][1] += min(dp[child][0], dp[child][1]); // 내가 켜졌다면, 자식은 최솟값 선택
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    graph.assign(n+1, {});
    dp.assign(n+1, vector<int>(2, 0));  // dp[i][0] : 등대를 끈 경우, dp[i][1] : 등대를 킨 경우
    visited.assign(n+1, false);
    
    for(const auto& edge : lighthouse){
        graph[edge[0]].emplace_back(edge[1]);
        graph[edge[1]].emplace_back(edge[0]);
    }
    
    dfs(1); // 트리라서 아무데서나 시작해도 됨 (임의의 루트에서 시작)
    return min(dp[1][0], dp[1][1]); // 루트 기준으로 최소값 리턴
}