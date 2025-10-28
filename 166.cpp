// 166. 모두 0으로 만들기(dfs) / re, 앞으로 dfs용 변수는 전역 선언을 해버려야겠다
// https://school.programmers.co.kr/learn/courses/30/lessons/76503
#include <string>
#include <vector>
#include <numeric>

using namespace std;

long long ans;
vector<bool> visited;

long long dfs(int cur, int parent, vector<vector<int>>& graph, vector<long long>& treeValue){ 
    // 트리이기 때문에 visited 대신 parent만 확인해도 무한루프 방지됨 (사이클 없음)
    for(int next : graph[cur]){
        if(next == parent)  continue;
        long long childValue = dfs(next, cur, graph, treeValue);
        treeValue[cur] += childValue;
        ans += abs(childValue); // 이동횟수 = |value|
    }
    
    // visited 버전 (트리 아닌 경우) -> 약간 더 느릴 수 있음
    // visited[cur] = true;
    // for(int next : graph[cur]){
    //     if(!visited[next]){
    //         long long childValue = dfs(next, parent, graph, treeValue);
    //         treeValue[cur] += childValue;
    //         ans += abs(childValue);
    //     }
    // }
    
    return treeValue[cur];
}


long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = a.size();
    vector<long long> treeValue(a.begin(), a.end());
    vector<vector<int>> graph(n);
    visited.assign(n, false);
    
    if(accumulate(treeValue.begin(), treeValue.end(), 0LL) != 0){
        return -1;
    }
    
    for(const auto& e : edges){
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
    }
    
    ans = 0;
    dfs(0, -1, graph, treeValue);
    
    return ans;
}