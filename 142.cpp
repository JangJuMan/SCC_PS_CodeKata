// 142. 빛의 경로 사이클 / re (dfs는 스택오버플로 가능, 전방위 탐색이 필요없는 경우) / 2트 실패
// https://school.programmers.co.kr/learn/courses/30/lessons/86052
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 2트(실패) */
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};   // 상, 좌, 하, 우

vector<int> solution(vector<string> grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<int> ans;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            for(int d=0; d<4; d++){     // 상(0), 좌(1), 하(2), 우(3)
                if(visited[r][c][d])    continue;
                
                int cnt = 0;
                int curR = r, curC = c, curD = d;
                while(!visited[curR][curC][curD]){
                    visited[curR][curC][curD] = true;
                    cnt++;
                    
                    char ch = grid[curR][curC];
                    if(ch == 'L')       curD = (curD + 3) % 4; 
                    else if(ch == 'R')  curD = (curD + 1) % 4;
                    
                    curR = (curR + dr[curD] + n) % n;   // 수학적으로는 +n 안해도 양수이지만, 코드에서는 안붙이면 음수나옴
                    curC = (curC + dc[curD] + m) % m;   // ex. -7 % 5 = -2
                }
                
                if(cnt > 0) ans.emplace_back(cnt);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

/* 1트 */
// vector<int> solution(vector<string> grid) {
//     int rowSize = grid.size();
//     int colSize = grid[0].size();
    
//     int dr[4] = {-1, 0, 1, 0};
//     int dc[4] = {0, 1, 0, -1};      // 상, 좌, 하, 우
    
//     vector<vector<vector<bool>>> visited(rowSize, vector<vector<bool>>(colSize, vector<bool>(4, false)));
//     vector<int> ans;
    
//     for(int r=0; r<rowSize; r++){
//         for(int c=0; c<colSize; c++){
//             for(int d=0; d<4; d++){     // 상(0), 좌(1), 하(2), 우(3)
//                 if(visited[r][c][d]) continue;
                
//                 int cnt = 0;
//                 int currR = r, currC = c, currD = d;
                
//                 while(!visited[currR][currC][currD]){
//                     visited[currR][currC][currD] = true;
//                     cnt++;
                    
//                     char ch = grid[currR][currC];
//                     if(ch == 'L') 
//                         currD = (currD + 3) % 4;   // 왼쪽 회전 (반시계방향 270도 회전)
//                     else if(ch == 'R') 
//                         currD = (currD + 1) % 4;   // 오른쪽 회전 (반시계방향 90도 회전)
                    
//                     currR = (currR + dr[currD] + rowSize) % rowSize;    // currR + dr[currD]가 음수(0 - 1)가 될 수 있기에 +rowSize를 함
//                     currC = (currC + dc[currD] + colSize) % colSize;    // 수학적으로는 +n 안해도 양수이지만, 코드에서는 안붙이면 음수나옴 (ex -7 % 5 == -2)
//                 }
                
//                 if(cnt > 0) ans.emplace_back(cnt);
//             }
//         }
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
// }