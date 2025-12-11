// 108. 삼각 달팽이(3방향 direction, 대입구현) / re(풀긴함..)
// https://school.programmers.co.kr/learn/courses/30/lessons/68645#
#include <string>
#include <vector>

using namespace std;

int dr[] = {1, 0, -1};
int dc[] = {0, 1, -1};

/* 2트 코드 정리 */
vector<int> solution(int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));
    int maxNum = n*(n+1)/2;
    int r=0, c=0, num=1, dir=0;
    
    while(num <= maxNum){
        graph[r][c] = num++;
        
        if(num > maxNum) break;
        
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n || graph[nr][nc] != 0){
            dir = (dir+1) % 3;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr;
        c = nc;
    }
    
    vector<int> ans;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=i; ++j){
            ans.emplace_back(graph[i][j]);
        }
    }
    return ans;
}

/* 2트 초안*/
// vector<int> solution(int n) {
//     vector<vector<int>> vec(n, vector<int>(n, 0));
//     int num=1, r=0, c=0, nr=0, nc=0, idx=2, last=n*(n+1)/2;
    
//     vec[0][0] = 1;
//     while(idx <= last){
//         for(int i=0; i<3; i++){
//             while(r+dr[i] < n && c+dc[i] < n && vec[r+dr[i]][c+dc[i]] == 0){
//                 nr = r + dr[i];
//                 nc = c + dc[i];
//                 vec[nr][nc] = idx++;
//                 r = nr;
//                 c = nc;
//             }
//         }
//     }
    
//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             ans.emplace_back(vec[i][j]);
//         }
//     }
    
//     return ans;
// }


/* 1트 */
// vector<int> solution(int n) {
//     vector<vector<int>> vec(n, vector<int>(n, 0));
    
//     int num = 1, row = -1, col = 0, direction = 0; // 0 : 아래 / 1 : 오른쪽 / 2: 왼쪽 대각
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n-i; j++){
//             if(direction == 0){
//                 row++;
//             }
//             else if(direction == 1){
//                 col++;
//             }
//             else if(direction == 2){
//                 row--;
//                 col--;
//             }
//             vec[row][col] = num++;
//         }
//         direction = (direction + 1) % 3;
//     }
    
//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             ans.emplace_back(vec[i][j]);
//         }
//     }
    
//     return ans;
// }