// 159. 양대 늑대 / re (dfs, 방문가능 노드 업데이트)
// https://school.programmers.co.kr/learn/courses/30/lessons/92343
#include <string>
#include <vector>

using namespace std;

int ans = 0;
vector<vector<int>> graph;

void dfs(int cur, int sheep, int wolf, vector<int>& info, vector<int> next){
    if(info[cur] == 0) 
        sheep++;
    else
        wolf++;
    
    if(wolf >= sheep)
        return;
    
    ans = max(ans, sheep);
    
    for(int child : graph[cur]){
        next.emplace_back(child);
    }
    
    for(int i=0; i<next.size(); i++){
        if(next[i] == cur) continue;
        
        vector<int> newNext = next;
        newNext.erase(newNext.begin() + i);
        dfs(next[i], sheep, wolf, info, newNext);
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    graph.assign(n, {});
    
    for(const auto& e : edges){
        graph[e[0]].emplace_back(e[1]);
    }
    
    vector<int> next;
    dfs(0, 0, 0, info, next);
    
    return ans;
}