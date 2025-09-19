// 148. 섬 연결하기 (MST, Kruskal or Prim) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/42861
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* Kruskal 알고리즘 */
struct Edge{
    int from, to, cost;
};

int findParent(int x, vector<int>& parent){
    if(parent[x] == x)  return x;
    return parent[x] = findParent(parent[x], parent);
}

bool unionNodes(int a, int b, vector<int>& parent){
    a = findParent(a, parent);
    b = findParent(b, parent);
    if(a == b) return false;    // 이미 같은 부모이면 false
    parent[b] = a;              // 부모 합치기
    return true;
}

int solution(int n, vector<vector<int>> costs){
    vector<Edge> edges;
    for(const auto& c : costs){
        edges.push_back({c[0], c[1], c[2]});
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.cost < b.cost;
    });     // cost 낮은 순으로 정렬
    
    vector<int> parent(n);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    
    int ans = 0;
    int cnt = 0;
    
    for(const auto& e : edges){
        if(unionNodes(e.from, e.to, parent)){
            ans += e.cost;
            cnt++;
            if(cnt == n-1) break;   // MST 완성
        }
    }
    return ans;
}

/* Prim 알고리즘 */
// struct Edge{
//     int to, cost;
// };

// struct Compare{
//     bool operator()(const Edge& a, const Edge& b){
//         return a.cost > b.cost;     // minHeap 구성
//     }
// };

// int solution(int n, vector<vector<int>> costs) {
//     vector<vector<Edge>> graph(n);
    
//     for(const auto& c : costs){
//         int from = c[0], to = c[1], cost = c[2];
//         graph[from].push_back({to, cost});
//         graph[to].push_back({from, cost});
//     }
    
//     vector<bool> visited(n, false);
//     priority_queue<Edge, vector<Edge>, Compare> pq;
    
//     visited[0] = true;
//     for(auto& e : graph[0]){
//         pq.push(e);
//     }
    
//     int ans = 0;
//     int connected = 1;
    
//     while(!pq.empty() && connected < n){
//         Edge curr = pq.top();
//         pq.pop();
        
//         if(visited[curr.to])    continue;   // 이미 방문한 노드면 스킵
        
//         visited[curr.to] = true;
//         ans += curr.cost;
//         connected++;
        
//         for(const auto& next : graph[curr.to]){
//             if(!visited[next.to]){
//                 pq.push(next);
//             }
//         }
//     }
//     return ans;
// }