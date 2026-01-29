// 111. 무인도 여행 (전형적인 BFS, DFS 탐색) / re (2트 완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/154540
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/* 2트 */
constexpr int dr[] = {1, -1, 0, 0};
constexpr int dc[] = {0, 0, 1, -1};

int n, m;

int bfs(vector<string>& maps, vector<vector<bool>>& visited, int r, int c){
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        
        sum += maps[now.first][now.second] - '0';
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(visited[nr][nc]) continue;
            if(maps[nr][nc] == 'X') continue;
            
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
    return sum;
}

int dfs(vector<string>& maps, vector<vector<bool>>& visited, int r, int c){
    visited[r][c] = true;
    int sum = maps[r][c] - '0';
    
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(visited[nr][nc]) continue;
        if(maps[nr][nc] == 'X') continue;
        
        sum += dfs(maps, visited, nr, nc);
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    vector<int> ans;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                // ans.emplace_back(bfs(maps, visited, i, j));
                ans.emplace_back(dfs(maps, visited, i, j));
            }
        }
    }
    
    if(ans.empty()){
        return {-1};
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}




/* 1트 */
// int dr[] = {0, 0, -1, 1};
// int dc[] = {1, -1, 0, 0};

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
// vector<int> solution(vector<string> maps){
//     int n = maps.size();
//     int m = maps[0].size();
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     vector<int> ans;
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(!visited[i][j] && maps[i][j] != 'X'){
//                 int sum =0;
//                 queue<pair<int, int>> q;
//                 q.push({i, j});
//                 visited[i][j] = true;
//                 sum += maps[i][j] - '0';
                
//                 while(!q.empty()){
//                     auto [r, c] = q.front();
//                     q.pop();
                    
//                     for(int d=0; d<4; d++){
//                         int nr = r + dr[d];
//                         int nc = c + dc[d];
//                         if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
//                         if(visited[nr][nc] || maps[nr][nc] == 'X') continue;
//                         visited[nr][nc] = true;
//                         sum += maps[nr][nc] - '0';
//                         q.push({nr, nc});
//                     }
//                 }
//                 ans.emplace_back(sum);
//             }
//         }
//     }
//     if(ans.empty()) return {-1};
//     sort(ans.begin(), ans.end());
//     return ans;
// }