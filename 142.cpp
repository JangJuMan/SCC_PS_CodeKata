// 142. 빛의 경로 사이클 / re (dfs는 스택오버플로 가능, 전방위 탐색이 필요없는 경우)
// https://school.programmers.co.kr/learn/courses/30/lessons/86052
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    vector<vector<vector<bool>>> visited(rowSize, vector<vector<bool>>(colSize, vector<bool>(4, false)));
    vector<int> ans;
    
    for(int r=0; r<rowSize; r++){
        for(int c=0; c<colSize; c++){
            for(int d=0; d<4; d++){
                if(visited[r][c][d]) continue;
                
                int cnt = 0;
                int currR = r, currC = c, currD = d;
                
                while(!visited[currR][currC][currD]){
                    visited[currR][currC][currD] = true;
                    cnt++;
                    
                    char ch = grid[currR][currC];
                    if(ch == 'L') 
                        currD = (currD + 3) % 4;      // 왼쪽 회전
                    else if(ch == 'R') 
                        currD = (currD + 1) % 4;   // 오른쪽 회전
                    
                    currR = (currR + dr[currD] + rowSize) % rowSize;    // currR + dr[currD]가 음수(0 - 1)가 될 수 있기에 +rowSize를 함
                    currC = (currC + dc[currD] + colSize) % colSize;
                }
                
                if(cnt > 0) ans.emplace_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}