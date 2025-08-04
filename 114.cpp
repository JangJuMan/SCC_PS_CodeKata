// 114. 배달 (dijkstra) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int to, dist;
    bool operator()(Edge a, Edge b){
        return a.dist > b.dist;
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<Edge>> graph(N+1);
    for(const auto& r : road){
        int from = r[0], to = r[1], dist = r[2];
        graph[from].push_back({to, dist});
        graph[to].push_back({from, dist});
    }
    
    vector<int> dist(N+1, 1e9); // 10^9
    dist[1] = 0;
    
    priority_queue<Edge, vector<Edge>, Edge> pq;
    pq.push({1, 0});    // to, dist
    
    while(!pq.empty()){
        Edge now = pq.top();
        pq.pop();
        
        if(dist[now.to] < now.dist) continue;   // 이미 더 짧은 경로를 방문했다면 생략
        
        for(const Edge& next : graph[now.to]){
            int cost = now.dist + next.dist;
            if(cost < dist[next.to]){
                dist[next.to] = cost;
                pq.push({next.to, cost});
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(dist[i] <= K)    
            ans++;
    }
    return ans;
    
}