// 111. 무인도 여행 (전형적인 BFS, DFS 탐색) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/154540
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

// // DFS
// int dfs(vector<string>& maps, vector<vector<bool>>& visited, int r, int c){
//     int n = maps.size();
//     int m = maps[0].size();
//     visited[r][c] = true;
//     int sum = maps[r][c] - '0';
    
//     for(int i=0; i<4; i++){
//         int nr = r + dr[i];
//         int nc = c + dc[i];
        
//         if(0 <= nr && nr < n && 0 <= nc && nc < m){
//             if(!visited[nr][nc] && maps[nr][nc] != 'X'){
//                 sum += dfs(maps, visited, nr, nc);
//             }
//         }
//     }
//     return sum;
// }

// vector<int> solution(vector<string> maps){
//     int n = maps.size();
//     int m = maps[0].size();
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     vector<int> ans;
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(!visited[i][j] && maps[i][j] != 'X'){
//                 int res = dfs(maps, visited, i, j);
//                 ans.emplace_back(res);
//             }
//         }
//     }
    
//     if(ans.empty()) return {-1};
//     sort(ans.begin(), ans.end());
//     return ans;
    
// }

// BFS
vector<int> solution(vector<string> maps){
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                int sum =0;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                sum += maps[i][j] - '0';
                
                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();
                    
                    for(int d=0; d<4; d++){
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                        if(visited[nr][nc] || maps[nr][nc] == 'X') continue;
                        visited[nr][nc] = true;
                        sum += maps[nr][nc] - '0';
                        q.push({nr, nc});
                    }
                }
                ans.emplace_back(sum);
            }
        }
    }
    if(ans.empty()) return {-1};
    sort(ans.begin(), ans.end());
    return ans;
}