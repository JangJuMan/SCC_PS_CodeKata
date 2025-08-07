// 118. 거리두기 확인하기(탐색) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/81302
// 모범답안은 4방향 탐색만 진행하고, 탐색중 O(빈 테이블)을 2번 이상 만나면 false 해버리는 것...
#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int dr[] = {1, -1, 0, 0};
constexpr int dc[] = {0, 0, 1, -1};

bool isInside(int row, int col, int size){
    return (0 <= row && row < size && 0 <= col && col < size);
}

// /* ----------------DFS------------------ */
bool dfs(const vector<string>& place, int r, int c, int depth, vector<vector<bool>>& visited){
    if(depth > 2) return true;
    if(depth > 0 && place[r][c] == 'P') return false;
    visited[r][c] = true;
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(!isInside(nr, nc, 5)) continue;
        if(visited[nr][nc]) continue;
        if(place[nr][nc] == 'X') continue;
        if(!dfs(place, nr, nc, depth+1, visited)) return false;
    }
    return true;
}

/* ---------- BFS ----------- */
struct State{
    int row, col, depth;
};

bool bfs(const vector<string>& place, int r, int c){
    queue<State> q;
    q.push({r, c, 0});
    int n = place.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[r][c] = true;
    
    while(!q.empty()){
        auto [r, c, d] = q.front(); q.pop();
        if(d >= 1 && place[r][c] == 'P') return false;
        if(d == 2) continue;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!isInside(nr, nc, n)) continue;
            if(visited[nr][nc]) continue;
            if(place[nr][nc] == 'X') continue;
            visited[nr][nc] = true;
            q.push({nr, nc, d+1});
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> ans;
    int n = places.size();
    for(const auto& place : places){
        bool check = true;
        for(int r=0; r<n && check; r++){
            for(int c=0; c<n && check; c++){
                if(place[r][c] == 'P'){
                    vector<vector<bool>> visited(n, vector<bool>(n, false));
                    // if(!dfs(place, r, c, 0, visited)){   // DFS
                    if(!bfs(place, r, c)){      // BFS
                        check = false;
                    }
                }
            }
        }
        ans.emplace_back(check ? 1 : 0);
    }
    return ans;
}

// /* -----------------하드코딩----------------- */
// constexpr int diag_dr[] = {1, 1, -1, -1};
// constexpr int diag_dc[] = {1, -1, 1, -1};

// bool check(const vector<string>& place){
//     int n = place.size(); // 5
//     for(int r=0; r<n; r++){
//         for(int c=0; c<n; c++){
//             if(place[r][c] != 'P') continue;
            
//             // 1칸 내 P 존재 확인
//             for(int i=0; i<4; i++){
//                 int nr = r + dr[i], nc = c + dc[i];
//                 if(!isInside(nr, nc, n)) continue;    // 초과 범위는 제외 
//                 if(place[nr][nc] == 'P') return false;
//             }
            
//             // 직선 2칸거리 P 존재 확인
//             for(int i=0; i<4; i++){
//                 int nr = r + dr[i]*2, nc = c + dc[i]*2;
//                 if(!isInside(nr, nc, n)) continue;
//                 if(place[nr][nc] == 'P' && place[r + dr[i]][c + dc[i]] != 'X')
//                     return false;
//             }
            
//             // 대각 2칸거리 P 존재확인
//             for(int i=0; i<4; i++){
//                 int nr = r + diag_dr[i];
//                 int nc = c + diag_dc[i];
//                 if(!isInside(nr, nc, n)) continue;
//                 if(place[nr][nc] == 'P'){
//                     if(!(place[r + diag_dr[i]][c] == 'X' && place[r][c + diag_dc[i]]))
//                         return false;
//                 }
//             }
//         }
//     }
//     return true;
// }

// vector<int> solution(vector<vector<string>> places) {
//     vector<int> ans;
//     for(const auto& place : places){
//         ans.emplace_back(check(place) ? 1 : 0);
//     }
//     return ans;
// }