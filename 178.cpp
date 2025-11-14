// 178. 고고학 최고의 발견 (경우의 수) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/131702
// 첫 번째 row만 BrouteForce 돌면, 나머지 row는 선택권 없이 그에 따라가야 한다.
#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

constexpr int dr[] = {0, 0, 0, 1, -1};  // 자신 + 인접한 4개의 시계
constexpr int dc[] = {0, 1, -1, 0, 0};

// 시계를 90도 * turn_count 만큼 돌리는 함수
void rotate_clocks(vector<vector<int>>& board, int r, int c, int n, int turn_count){
    if(turn_count == 0) return;

    for(int i=0; i<5; i++){ // 자신+ 인접한시계를 모두 업데이트
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || n<=nr || nc<0 || n<=nc) continue;
        board[nr][nc] = (board[nr][nc] + turn_count) % 4;
    }
}

bool is_solved(const vector<vector<int>>& board, int n){
    // 마지막 행이 모두 12시인지만 확인하면 됨 (위로는 다 맞춰두었으니)
    for(int c=0; c<n; c++){
        if(board[n-1][c] != 0){
            return false;
        }
    }
    return true;
}

int solution(vector<vector<int>> clockHands) {
    int n = clockHands.size();
    int ans = INT_MAX;
    int max_mask = 1;  
    for(int i=0; i<n; ++i) max_mask *= 4;
    
    for(int mask=0; mask<max_mask; mask++){
        vector<vector<int>> cur_board = clockHands;
        int res = 0;
        int tmp_mask = mask;

        for(int c=0; c<n; c++){ // 첫 번째 row
            int turn_count = tmp_mask % 4;  // mask에서 c 위치에 해당하는 회전 횟수(0, 1, 2, 3) 추출
            tmp_mask /= 4;                  // 현재 c 위치

            if(turn_count > 0){
                rotate_clocks(cur_board, 0, c, n, turn_count);
                res += turn_count;
            }
        }

        for(int r=1; r<n; r++){ // 1~n 번째 row
            for(int c=0; c<n; c++){
                // 윗 행의 시계바늘을 12시로 맞춰야 함
                int cur_state = cur_board[r-1][c];
                if(cur_state != 0){
                    int turn_count = (4 - cur_state) % 4;
                    rotate_clocks(cur_board, r, c, n, turn_count);
                    res += turn_count;
                }
            }
        }

        if(is_solved(cur_board, n)){
            ans = min(ans, res);
        }
    }

    return ans;
}