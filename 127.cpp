// 127. 리코쳇 로봇 (최단거리는 역시 BFS) / 풀었지만 한번 더?
// https://school.programmers.co.kr/learn/courses/30/lessons/169199
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

struct Pos{
    int row, col;
    
    bool operator ==(const Pos& other) const{
        return (row == other.row) && (col == other.col);
    }
};

bool isOutside(int r, int c, int maxR, int maxC){
    return r < 0 || r >= maxR || c < 0 || c >= maxC;
}

int bfs(const vector<string>& board, const Pos& start, const Pos& end){
    int maxRow = board.size();
    int maxCol = board[0].size();
    
    vector<vector<int>> visited(maxRow, vector<int>(maxCol, -1));
    queue<Pos> q;
    
    q.emplace(start);
    visited[start.row][start.col] = 0;
    
    while(!q.empty()){
        Pos curr = q.front();
        q.pop();
        
        if(curr == end){    // operator == 재정의로 비교
            return visited[curr.row][curr.col];
        }
        
        for(int i=0; i<4; i++){
            int nr = curr.row;
            int nc = curr.col;
            while(1){
                int tmpNr = nr + dr[i];
                int tmpNc = nc + dc[i];
                
                if(isOutside(tmpNr, tmpNc, maxRow, maxCol) || board[tmpNr][tmpNc] == 'D'){
                    break;
                }
                nr = tmpNr;
                nc = tmpNc;
            }
            
            if(visited[nr][nc] == -1){
                visited[nr][nc] = visited[curr.row][curr.col] + 1;
                q.push({nr, nc});
            }   
        }
    }
    
    
    return -1;
}

int solution(vector<string> board) {
    Pos start, end;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'R'){
                start.row = i;
                start.col = j;
            }
            else if(board[i][j] == 'G'){
                end.row = i;
                end.col = j;
            }
        }
    }
    
    return bfs(board, start, end);
}