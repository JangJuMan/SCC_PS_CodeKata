// 118. 거리두기 확인하기(탐색) / re (2트 완료 - 1시간)
// https://school.programmers.co.kr/learn/courses/30/lessons/81302
// 모범답안은 4방향 탐색만 진행하고, 탐색중 O(빈 테이블)을 2번 이상 만나면 false 해버리는 것...
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <algorihtm>

using namespace std;

/* 2트 */
struct Node{
    int r, c, dist;
};

constexpr int dr[] = {1, -1, 0, 0};
constexpr int dc[] = {0, 0, -1, 1};
constexpr int maxDist = 2;
constexpr int n = 5;

array<array<bool, n>, n> visitedDFS = {false};

bool isKeepDistanceDFS(const vector<string>& graph, int r, int c, int depth){
    if(depth > 0 && graph[r][c] == 'P') return false;
    if(depth == 2) return true;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
        if(visitedDFS[nr][nc]) continue;
        if(graph[nr][nc] == 'X') continue;

        visitedDFS[nr][nc] = true;
        if(!isKeepDistanceDFS(graph, nr, nc, depth+1)) return false;
        visitedDFS[nr][nc] = false;     // 다른 방향 방문을 위해 체크해제=
    }
    return true;
}

bool isKeepDistanceBFS(const vector<string>& graph, int r, int c){
    // vector<vector<bool> visited(n, vector<bool>(n, false));
    array<array<bool, n>, n> visited = {false};  // 이 문제처럼 고정된 배열은 array가 더 빠름
    queue<Node> q;

    visited[r][c] = true;
    q.push({r, c, 0});

    while(!q.empty()){
        Node now = q.front();
        q.pop();

        if(now.dist >= maxDist) continue;   // 현재 노드 거리가 이미 최대라면 다음 칸은 확인할 필요 X

        for(int i=0; i<4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            int nd = now.dist + 1;

            if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
            if(visited[nr][nc]) continue;
            if(graph[nr][nc] == 'X') continue;
            if(graph[nr][nc] == 'P') return false;  // 다른 사람 발견 시 거리유지 실패
            
            visited[nr][nc] = true;
            q.push({nr, nc, nd});
        }
    }
    return true;
}

int checkPlace(const vector<string>& place){
    for(int i=0; i<place.size(); i++){
        for(int j=0; j<place[0].size(); j++){
            if(place[i][j] == 'P'){
                fill(visitedDFS.begin(), visitedDFS.end(), array<bool, n>{false});
                visitedDFS[i][j] = true;
                if(!isKeepDistanceDFS(place, i, j, 0)){
                    return 0;
                }
                // if(!isKeepDistanceBFS(place, i, j)){
                //     return 0;
                // }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places){
    vector<int> ans;
    for(const auto& p : places){
        ans.emplace_back(checkPlace(p));
    }
    return ans;
}




/* 1트 */
// constexpr int dr[] = {1, -1, 0, 0};
// constexpr int dc[] = {0, 0, 1, -1};

// bool isInside(int row, int col, int size){
//     return (0 <= row && row < size && 0 <= col && col < size);
// }

// // /* ----------------DFS------------------ */
// bool dfs(const vector<string>& place, int r, int c, int depth, vector<vector<bool>>& visited){
//     if(depth > 2) return true;
//     if(depth > 0 && place[r][c] == 'P') return false;
//     visited[r][c] = true;
//     for(int i=0; i<4; i++){
//         int nr = r + dr[i];
//         int nc = c + dc[i];
//         if(!isInside(nr, nc, 5)) continue;
//         if(visited[nr][nc]) continue;
//         if(place[nr][nc] == 'X') continue;
//         if(!dfs(place, nr, nc, depth+1, visited)) return false;
//     }
//     return true;
// }

// /* ---------- BFS ----------- */
// struct State{
//     int row, col, depth;
// };

// bool bfs(const vector<string>& place, int r, int c){
//     queue<State> q;
//     q.push({r, c, 0});
//     int n = place.size();
//     vector<vector<bool>> visited(n, vector<bool>(n, false));
//     visited[r][c] = true;
    
//     while(!q.empty()){
//         auto [r, c, d] = q.front(); q.pop();
//         if(d >= 1 && place[r][c] == 'P') return false;
//         if(d == 2) continue;
//         for(int i=0; i<4; i++){
//             int nr = r + dr[i];
//             int nc = c + dc[i];
//             if(!isInside(nr, nc, n)) continue;
//             if(visited[nr][nc]) continue;
//             if(place[nr][nc] == 'X') continue;
//             visited[nr][nc] = true;
//             q.push({nr, nc, d+1});
//         }
//     }
//     return true;
// }

// vector<int> solution(vector<vector<string>> places) {
//     vector<int> ans;
//     int n = places.size();
//     for(const auto& place : places){
//         bool check = true;
//         for(int r=0; r<n && check; r++){
//             for(int c=0; c<n && check; c++){
//                 if(place[r][c] == 'P'){
//                     vector<vector<bool>> visited(n, vector<bool>(n, false));
//                     // if(!dfs(place, r, c, 0, visited)){   // DFS
//                     if(!bfs(place, r, c)){      // BFS
//                         check = false;
//                     }
//                 }
//             }
//         }
//         ans.emplace_back(check ? 1 : 0);
//     }
//     return ans;
// }

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