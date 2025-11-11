// 176. 사라지는 발판 (dfs) / rere
// https://school.programmers.co.kr/learn/courses/30/lessons/92345
#include <string>
#include <vector>

using namespace std;

constexpr int dr[4] = {-1, 1, 0, 0};
constexpr int dc[4] = {0, 0, -1, 1};

struct Result{
    bool canWin;     // 현재 플레이어가 이길 수 있는지
    int moveCnt;     // 총 이동 횟수
};

int n, m;

Result dfs(vector<vector<int>>& board, int r1, int c1, int r2, int c2, bool isTurnA){
    int cr = isTurnA ? r1 : r2;
    int cc = isTurnA ? c1 : c2;
    
    if(board[cr][cc] == 0) return {false, 0};   // 현재 위치에 발판이 없으면 패배 (이전에 밟았던 곳이 사라졌음)
    
    bool canMove = false;
    Result best = {false, 0};
    
    for(int i=0; i<4; i++){
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        if(nr<0 || n<=nr || nc<0 || m<=nc) continue;
        if(board[nr][nc] == 0) continue;
        
        canMove = true;
        board[cr][cc] = 0;  // 현재 발판을 제거
        
        Result next;
        if(isTurnA)
            next = dfs(board, nr, nc, r2, c2, false);
        else
            next = dfs(board, r1, c1, nr, nc, true);
        
        board[cr][cc] = 1;  // 현재 발판 복구 (백트래킹)
        
        if(next.canWin){    // 상대가 승리한다면, 현재 플레이어는 패배
            if(!best.canWin)   // 승리할 수 있는 방법이 없는 경우, 패배 경로를 선택 (승리 > 패배)
                best.moveCnt = max(best.moveCnt, next.moveCnt + 1);
        }
        else{               // 상대가 패배한다면 현재 플레이어는 승리
            if(!best.canWin || best.moveCnt > next.moveCnt+1)
                best = {true, next.moveCnt + 1};
        }
    }
    if(!canMove) 
        return {false, 0};  // 이동불가 → 패배
    return best;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();        // 정사각형이라 상관은 없지만, 명시적으로 표시
    
    Result ans = dfs(board, aloc[0], aloc[1], bloc[0], bloc[1], true);
    return ans.moveCnt;
}