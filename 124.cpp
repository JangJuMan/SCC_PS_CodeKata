// 124. 미로탈출 (구현, BFS) / 풀었는데, bfs 연습할거면 다시
// https://school.programmers.co.kr/learn/courses/30/lessons/159993

#include <string>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

struct Pos{
    int row, col;
};

bool isInside(int r, int c, int maxR, int maxC){
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

int bfs(const vector<string>& maps, const Pos& start, const Pos& end){
    int maxRow = maps.size();
    int maxCol = maps[0].size();
    
    queue<Pos> q;
    vector<vector<int>> visited(maxRow, vector<int>(maxCol, -1));
    
    q.push(start);
    visited[start.row][start.col] = 0;
    
    while(!q.empty()){
        Pos curr = q.front();   q.pop();
        for(int i=0; i<4; i++){
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];
            
            if(!isInside(nr, nc, maxRow, maxCol))   continue;
            if(maps[nr][nc] == 'X') continue;
            if(visited[nr][nc] != -1)   continue;
            if(nr == end.row && nc == end.col)  return visited[curr.row][curr.col] + 1;
            
            visited[nr][nc] = visited[curr.row][curr.col] + 1;
            q.push({nr, nc});
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    Pos start, lever, end;
    int maxRow = maps.size();
    int maxCol = maps[0].size();
    
    for(int i=0; i<maxRow; i++){
        for(int j=0; j<maxCol; j++){
            if(maps[i][j] == 'S')   start = {i, j};
            if(maps[i][j] == 'L')   lever = {i, j};
            if(maps[i][j] == 'E')   end = {i, j};
        }
    }
    
    int startToLever = bfs(maps, start, lever);
    if(startToLever == -1){
        return -1;
    }
    
    int leverToEnd = bfs(maps, lever, end);
    if(leverToEnd == -1){
        return -1;
    }
    
    return startToLever + leverToEnd;
}