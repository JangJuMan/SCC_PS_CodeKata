// 127. 리코쳇 로봇 (최단거리는 역시 BFS) / 풀었지만 한번 더? (2트도 성공)
// https://school.programmers.co.kr/learn/courses/30/lessons/169199
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/* 2트 */
constexpr int dr[] = {-1, 1, 0, 0};     // 상하좌우
constexpr int dc[] = {0, 0, -1, 1};

struct Search{
    int r, c, dist;
};

int bfs(const vector<string>& board, const pair<int, int>& start){
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Search> q;
    
    visited[start.first][start.second] = true;
    q.push({start.first, start.second, 0});
    
    while(!q.empty()){
        Search now = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nr = now.r;
            int nc = now.c;
            /* 방법 1*/
            // while(0<=nr+dr[i] && nr+dr[i]<n && 0<=nc+dc[i] && nc+dc[i]<m && board[nr+dr[i]][nc+dc[i]] != 'D'){
            //     nr += dr[i];
            //     nc += dc[i];
            // }
            /* 방법 2 */
            while(1){
                int tr = nr + dr[i];
                int tc = nc + dc[i];
                
                if(tr<0 || n<=tr || tc<0 || m<=tc || board[tr][tc] == 'D') break;
                
                nr = tr;
                nc = tc;
            }
            if(visited[nr][nc]) continue;
            if(board[nr][nc] == 'G') return now.dist + 1;
            
            visited[nr][nc] = true;
            q.push({nr, nc, now.dist+1});
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    pair<int, int> start, end;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'R'){
                start.first = i;
                start.second = j;
            }
        }
    }
    
    return bfs(board, start);
}

/* 1트 */
// int dr[] = {0, 0, 1, -1};
// int dc[] = {1, -1, 0, 0};

// struct Pos{
//     int row, col;
    
//     bool operator ==(const Pos& other) const{
//         return (row == other.row) && (col == other.col);
//     }
// };

// bool isOutside(int r, int c, int maxR, int maxC){
//     return r < 0 || r >= maxR || c < 0 || c >= maxC;
// }

// int bfs(const vector<string>& board, const Pos& start, const Pos& end){
//     int maxRow = board.size();
//     int maxCol = board[0].size();
    
//     vector<vector<int>> visited(maxRow, vector<int>(maxCol, -1));
//     queue<Pos> q;
    
//     q.emplace(start);
//     visited[start.row][start.col] = 0;
    
//     while(!q.empty()){
//         Pos curr = q.front();
//         q.pop();
        
//         if(curr == end){    // operator == 재정의로 비교
//             return visited[curr.row][curr.col];
//         }
        
//         for(int i=0; i<4; i++){
//             int nr = curr.row;
//             int nc = curr.col;
//             while(1){
//                 int tmpNr = nr + dr[i];
//                 int tmpNc = nc + dc[i];
                
//                 if(isOutside(tmpNr, tmpNc, maxRow, maxCol) || board[tmpNr][tmpNc] == 'D'){
//                     break;
//                 }
//                 nr = tmpNr;
//                 nc = tmpNc;
//             }
            
//             if(visited[nr][nc] == -1){
//                 visited[nr][nc] = visited[curr.row][curr.col] + 1;
//                 q.push({nr, nc});
//             }   
//         }
//     }
    
    
//     return -1;
// }

// int solution(vector<string> board) {
//     Pos start, end;
    
//     for(int i=0; i<board.size(); i++){
//         for(int j=0; j<board[i].size(); j++){
//             if(board[i][j] == 'R'){
//                 start.row = i;
//                 start.col = j;
//             }
//             else if(board[i][j] == 'G'){
//                 end.row = i;
//                 end.col = j;
//             }
//         }
//     }
    
//     return bfs(board, start, end);
// }