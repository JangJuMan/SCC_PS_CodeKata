// 156. 순위 (플루이드 워셜을 쓸 바엔 bfs/dfs로 푸는게 나은거 같은데) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/49191
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int bfs(int start, vector<vector<int>>& graph, int n){
    vector<int> visited(n+1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int cnt = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int next : graph[cur]){
            if(!visited[next]){
                visited[next] = 1;
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int dfs_iter(int start, vector<vector<int>>& graph, int n){
    vector<int> visited(n+1, 0);
    stack<int> st;
    st.push(start);
    visited[start] = 1;
    int cnt = 0;
    
    while(!st.empty()){
        int cur = st.top(); st.pop();
        for(int next : graph[cur]){
            if(!visited[next]){
                visited[next] = 1;
                cnt++;
                st.push(next);
            }
        }
    }
    return cnt;
}

int dfs(int start, vector<vector<int>>& graph, vector<int>& visited){
    int cnt = 0;
    visited[start] = 1;
    
    for(int next : graph[start]){
        if(!visited[next]){
            visited[next] = 1;
            cnt += 1 + dfs(next, graph, visited);
        }
    }
    return cnt;
}

/* dfs, bfs */
int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> winGraph(n+1);
    vector<vector<int>> loseGraph(n+1);
    
    for(auto& res : results){
        int winner = res[0], loser = res[1];
        winGraph[winner].emplace_back(loser);
        loseGraph[loser].emplace_back(winner);
    }
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        vector<int> visited1(n+1, 0), visited2(n+1);    // 초기화해서 쓰는것보다 메모리 더 쓰는게 빠를 듯
        int winCnt = bfs(i, winGraph, n);   // dfs_iter(i, winGraph, n);   // dfs(i, winGraph, visited1);
        int loseCnt = bfs(i, loseGraph, n); // dfs_iter(i, loseGraph, n);  //dfs(i, loseGraph, visited2);
        if(winCnt + loseCnt == n-1) ans++;
    }
    return ans;
}

/* 플루이드 워셜 */
// int solution(int n, vector<vector<int>> results) {
//     vector<vector<int>> graph(n, vector<int>(n, 0));
    
//     // 결과 기록
//     for (auto &r : results) {
//         int a = r[0] - 1, b = r[1] - 1;
//         graph[a][b] = 1;   // a 이김
//         graph[b][a] = -1;  // b 짐
//     }

//     // 플로이드-워셜
//     for (int k = 0; k < n; k++) {
//         for (int i = 0; i < n; i++) {
//             if (graph[i][k] != 1) continue; // i가 k 이길 때만 확인
//             for (int j = 0; j < n; j++) {
//                 if (graph[k][j] == 1) {
//                     graph[i][j] = 1;   // i가 j를 이김
//                     graph[j][i] = -1;  // j는 i한테 짐
//                 }
//             }
//         }
//     }

//     // 순위가 확정된 선수 세기
//     int answer = 0;
//     for (int i = 0; i < n; i++) {
//         int known = 0;
//         for (int j = 0; j < n; j++) {
//             if (graph[i][j] != 0) known++;
//         }
//         if (known == n-1) answer++;
//     }
//     return answer;
// }
