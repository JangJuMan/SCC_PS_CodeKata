// 165. 등산 코스 정하기 (Multi Source Dijkstra) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/118669
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int node, intensity;
    // NOTE. comparator를 구조체에 넣으면 느려진다 + 의미상 분리
    // bool operator()(const Edge& a, const Edge& b){  
    //     if(a.intensity == b.intensity){
    //         return a.node > b.node;
    //     }
    //     return a.intensity > b.intensity;
    // }
};

struct CompareEdge{
    bool operator()(const Edge& a, const Edge& b) const{
        if(a.intensity == b.intensity){
            return a.node > b.node;
        }
        return a.intensity > b.intensity;
    }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<Edge>> graph(n+1);
    for(const auto& p : paths){
        graph[p[0]].push_back({p[1], p[2]});
        graph[p[1]].push_back({p[0], p[2]});
    }
    
    vector<bool> isGate(n+1, false), isSummit(n+1, false);
    for(const int& g : gates) isGate[g] = true;
    for(const int& s : summits) isSummit[s] = true;
    
    vector<int> minIntensity(n+1, 1e7+1);
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    
    for(const int& g : gates){  // 모든 게이트를 시작 지점으로 설정
        minIntensity[g] = 0;
        pq.push({g, 0});
    }
    
    while(!pq.empty()){
        Edge cur = pq.top();
        pq.pop();
        
        if(cur.intensity > minIntensity[cur.node])  continue;
        if(isSummit[cur.node])  continue;
        
        for(const auto& next : graph[cur.node]){
            if(isGate[next.node])    continue;
            int newIntensity = max(cur.intensity, next.intensity);
            if(newIntensity < minIntensity[next.node]){
                minIntensity[next.node] = newIntensity;
                pq.push({next.node, newIntensity});
            }
        }
    }
    
    int bestSummit = -1, bestIntensity = 1e7 + 1;
    for(const int& s : summits){
        if(minIntensity[s] < bestIntensity){
            bestSummit = s;
            bestIntensity = minIntensity[s];
        }
        else if(minIntensity[s] == bestIntensity){
            bestSummit = min(s, bestSummit);
        }
    }
    return {bestSummit, bestIntensity};
}