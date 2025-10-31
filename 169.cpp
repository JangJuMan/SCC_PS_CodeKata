// 169. 2차원 동전 뒤집기 (완전탐색) / re - 백트래킹 아닌 모든 경우의수 완전탐색
// https://school.programmers.co.kr/learn/courses/30/lessons/131703
// 비트마스크를 통한 최적화가 가능하긴 한데, 가독성도 너무 떨어지고 어렵다
#include <string>
#include <vector>

using namespace std;

int n, m;

void flipRow(vector<vector<int>>& board, int row){
    for(int i=0; i<m; i++){
        board[row][i] ^= 1; // board[i][j] xor 1 (1은 0되고, 0은 1이 됨)
    }
}

void flipCol(vector<vector<int>>& board, int col){
    for(int i=0; i<n; i++){
        board[i][col] ^= 1; // board[i][j] xor 1 (1은 0되고, 0은 1이 됨)
    }
}

bool isSame(vector<vector<int>>& board, vector<vector<int>>& target){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != target[i][j]){
                return false;
            }
        }
    }
    return true;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    n = beginning.size();
    m = beginning[0].size();
    int ans = 1e9;
    
    for(int mask = 0; mask < (1 << n); mask++){ // 1~2^n 의 모든 경우의 수 확인
        vector<vector<int>> board = beginning;
        int cnt = 0;
        
        // 행 뒤집기
        for(int i=0; i<n; i++){
            if(mask & (1 << i)){    // mask가 9(=1001)이면 0, 3번 행 뒤집기
                flipRow(board, i);
                cnt++;
            }
        }
        
        // 열 뒤집기
        for(int j=0; j<m; j++){
            if(board[0][j] != target[0][j]){
                flipCol(board, j);
                cnt++;
            }
        }
        
        if(isSame(board, target)){
            ans = min(ans, cnt);
        }
    }
    
    if(ans != 1e9){
        return ans;
    }
    return -1;
}