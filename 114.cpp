// 114. 배달 (dijkstra) / re (2트 re)
// https://school.programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* 2트 (가독성 향상) */
struct Edge{
    int node, dist;
};

struct DistInfo{
    int node, totalDist;
    bool operator>(const DistInfo& other) const {    // const 함수로 안하면 컴파일 에러 발생
        return totalDist > other.totalDist;
    }
};

int solution(int N, vector<vector<int>> road, int K){
    vector<vector<Edge>> graph(N+1);
    for(const auto& r : road){
        int from=r[0], to=r[1], dist=r[2];
        graph[from].push_back({to, dist});
        graph[to].push_back({from, dist});
    }

    vector<int> minDist(N+1, 1e9);
    minDist[1] = 0;

    priority_queue<DistInfo, vector<DistInfo>, greater<DistInfo>> pq;   // minHeap
    pq.push({1, 0});
    while(!pq.empty()){
        DistInfo now = pq.top();
        pq.pop();

        if(now.totalDist > K) continue;
        if(now.totalDist > minDist[now.node]) continue;

        for(const Edge& next : graph[now.node]){
            int nextDist = now.totalDist + next.dist;
            if(minDist[next.node] > nextDist){
                minDist[next.node] = nextDist;
                pq.push({next.node, nextDist});
            }
        }
    }

    int ans = 0;
    for(const int& dist : minDist){
        if(dist <= K) ans++;
    }
    return ans;
}

/* 1트 */
// struct Edge{
//     int to, dist;
//     bool operator()(Edge a, Edge b){
//         return a.dist > b.dist;
//     }
// };

// int solution(int N, vector<vector<int> > road, int K) {
//     vector<vector<Edge>> graph(N+1);
//     for(const auto& r : road){
//         int from = r[0], to = r[1], dist = r[2];
//         graph[from].push_back({to, dist});
//         graph[to].push_back({from, dist});
//     }
    
//     vector<int> dist(N+1, 1e9); // 10^9
//     dist[1] = 0;
    
//     priority_queue<Edge, vector<Edge>, Edge> pq;
//     pq.push({1, 0});    // to, dist
    
//     while(!pq.empty()){
//         Edge now = pq.top();
//         pq.pop();
        
//         if(dist[now.to] < now.dist) continue;   // 이미 더 짧은 경로를 방문했다면 생략
        
//         for(const Edge& next : graph[now.to]){
//             int cost = now.dist + next.dist;
//             if(cost < dist[next.to]){
//                 dist[next.to] = cost;
//                 pq.push({next.to, cost});
//             }
//         }
//     }
    
//     int ans = 0;
//     for(int i=1; i<=N; i++){
//         if(dist[i] <= K)    
//             ans++;
//     }
//     return ans;
    
// }