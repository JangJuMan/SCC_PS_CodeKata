// 131. N-Queen (backtracking) / 너무 유명한 문제... bool 로 체크하는 방법도 확인하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12952
#include <string>
#include <vector>

using namespace std;

// 새 방식 (canPlaceQueen 부분이 더 빠름 - 반복 없음 / n > 10일때 수 배 빠름)
int N;
int ans = 0;
vector<bool> colUsed;   // 열 사용 여부
vector<bool> diag1Used; // ↙ 대각선 (row + col)
vector<bool> diag2Used; // ↘ 대각선 (row - col + n), 음수가 되지 않도록 하기 위해 n 더함(보정)

void dfs(int row){
    if(row == N){
        ans++;
        return;
    }
    
    for(int col=0; col<N; col++){
        if(colUsed[col] || diag1Used[row+col] || diag2Used[row-col+N]) continue;
        
        colUsed[col] = diag1Used[row+col] = diag2Used[row-col+N] = true;
        dfs(row+1);
        colUsed[col] = diag1Used[row+col] = diag2Used[row-col+N] = false;
    }
}

int solution(int n){
    N = n;
    ans = 0;
    colUsed.assign(n, false);
    diag1Used.assign(2*n, false);
    diag2Used.assign(2*n, false);
    dfs(0);
    return ans;
}

// 기존 방식 (단순, 직관적)
// bool canPlaceQueen(int row, int col, const vector<int>& queenCol){
//     for(int i=0; i<row; i++){
//         if(queenCol[i] == col)  return false;   // Same Column
//         if(abs(i-row) == abs(queenCol[i] - col))    return false;   // Same Diagnal
//     }
//     return true;
// }

// int backtracking(int row, int n, vector<int>& queenCol){
//     if(row == n){
//         return 1;
//     }
    
//     int count = 0;
//     for(int i=0; i<n; i++){
//         if(!canPlaceQueen(row, i, queenCol)) continue;
        
//         queenCol[row] = i;
//         count += backtracking(row+1, n, queenCol);
//     }
//     return count;
// }

// int solution(int n) {
//     vector<int> queenCol(n, -1);
//     return backtracking(0, n, queenCol);
// }