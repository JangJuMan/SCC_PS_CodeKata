// 144. 네트워크(DFS, BFS) / re.. 풀었지만 다시? 기본문제
// https://school.programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 정리된 답 */
int solution(int n, vector<vector<int>> computers){
    int ans = 0;
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        
        ans++;
        queue<int> q;
        q.emplace(i);
        visited[i] = true;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int j=0; j<n; j++){
                if(computers[curr][j] == 1 && !visited[j]){
                    visited[j] = true;
                    q.emplace(j);
                }
            }
        }
    }
    return ans;
}


/* 내 답 */
// int solution(int n, vector<vector<int>> computers) {
//     vector<vector<int>> com(n);
//     vector<bool> visited(n, false);
    
//     for(int i=0; i<computers.size(); i++){
//         for(int j=0; j<computers[i].size(); j++){
//             if(i==j) continue;
//             if(computers[i][j] == 1){
//                 com[i].emplace_back(j);
//             }
//         }
//     }
    
//     int ans = 0;
//     queue<int> q;
//     for(int i=0; i<n; i++){
//         if(visited[i]) continue;
        
//         q.emplace(i);
//         visited[i] = true;
//         ans++;
//         while(!q.empty()){
//             int now = q.front();
//             q.pop();
//             for(int j=0; j<com[now].size(); j++){
//                 if(!visited[com[now][j]]){
//                     visited[com[now][j]] = true;
//                     q.emplace(com[now][j]);
//                 }
//             }
//         }
//     }
//     return ans;
// }