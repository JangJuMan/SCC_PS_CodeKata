// 112. 행렬 테두리 회전하기 / 풀었지만 re?
// https://school.programmers.co.kr/learn/courses/30/lessons/77485
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries){
    vector<vector<int>> board(rows, vector<int>(columns));
    int num = 1;
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            board[i][j] = num++;

    vector<int> ans;
    for(auto& q : queries){ // vector<int>
        int r1 = q[0]-1, c1 = q[1]-1, r2 = q[2]-1, c2 = q[3]-1;
        int prev = board[r1][c1];
        int mn = prev;

        for(int r = r1; r <r2; r++){    // 왼쪽 위 → 왼쪽 아래
            board[r][c1] = board[r+1][c1];
            mn = min(mn, board[r][c1]);
        }
        for(int c = c1; c < c2; c++){   // 왼쪽 아래 → 오른쪽 아래
            board[r2][c] = board[r2][c+1];
            mn = min(mn, board[r2][c]);
        }
        for(int r = r2; r > r1; r--){   // 오른쪽 아래 → 오른쪽 위
            board[r][c2] = board[r-1][c2];
            mn = min(mn, board[r][c2]);
        }
        for(int c = c2; c > c1+1; c--){ // 오른쪽 위 → 왼쪽 위
            board[r1][c] = board[r1][c-1];
            mn = min(mn, board[r1][c]);
        }
        board[r1][c1+1] = prev;
        ans.emplace_back(mn);
    }
    return ans;
}