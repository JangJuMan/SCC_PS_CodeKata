// 174. 숫자 타자 대회 (dp) / rererere(4시간)
// https://school.programmers.co.kr/learn/courses/30/lessons/136797
#include <string>
#include <vector>
#include <array>

using namespace std;

struct Pos{
    int row, col;
};

const array<Pos, 10> keyPos = {{
    {3, 1}, // 0
    {0, 0}, {0, 1}, {0, 2}, // 1 2 3
    {1, 0}, {1, 1}, {1, 2}, // 4 5 6
    {2, 0}, {2, 1}, {2, 2}  // 7 8 9
}};

int calcCost(int start, int end){
    if(start == end)    return 1;
    
    Pos p1 = keyPos[start];
    Pos p2 = keyPos[end];
    
    int dr = abs(p1.row - p2.row);
    int dc = abs(p1.col - p2.col);
    
    int diagnal = min(dr, dc);      // 대각선 우선
    int straight = abs(dr - dc);    // 대각선 이동 후 잔여
    
    return (diagnal * 3) + (straight * 2);
}


int solution(string numbers) {
    int n = numbers.size();
    
    array<array<int, 10>, 10> costs;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            costs[i][j] = calcCost(i, j);
    
    constexpr int INF = 2147483647;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(10, vector<int>(10, INF))); // dp[n+1][10][10];
    
    dp[0][4][6] = 0;    // 시작위치 (왼손4, 오른손 6)
    for(int i=0; i<n; i++){
        int target = numbers[i] - '0';
        for(int l=0; l<=9; l++){        // 이전 왼손 위치
            for(int r=0; r<=9; r++){    // 이전 오른손 위치
                if(dp[i][l][r] == INF)  continue;   // 도달할 수 없는 이전 상태는 건너뜀
                
                if(target == l || target == r){     // 현재손 위치에 타겟이 있을 때(제자리)
                    dp[i+1][l][r] = min(dp[i+1][l][r], dp[i][l][r] + 1);
                    continue;
                }
                
                int costL = costs[l][target];   // 왼손 -> target으로 이동 비용
                dp[i+1][target][r] = min(dp[i+1][target][r], dp[i][l][r] + costL);
                
                int costR = costs[r][target];   // 오른손 -> target으로 이동 비용
                dp[i+1][l][target] = min(dp[i+1][l][target], dp[i][l][r] + costR);
            }
        }
    }
    
    int ans = INF;
    for(int l=0; l<=9; l++){
        for(int r=0; r<=9; r++){
            ans = min(ans, dp[n][l][r]);
        }
    }
    return ans;
}


/* 1. 재귀를 활용한 방식 (stack overflow 위험성 O) */
// int costs[10][10] = {
//     {1, 7, 6, 7, 5, 4, 5, 3, 2, 3}, // 0에서 출발할 때.
//     {7, 1, 2, 4, 2, 3, 5, 4, 5, 6}, // 1에서 출발할 때.
//     {6, 2, 1, 2, 3, 2, 3, 5, 4, 5}, // 2에서 출발할 때.
//     {7, 4, 2, 1, 5, 3, 2, 6, 5, 4}, // 3에서 출발할 때.
//     {5, 2, 3, 5, 1, 2, 4, 2, 3, 5}, // 4에서 출발할 때.
//     {4, 3, 2, 3, 2, 1, 2, 3, 2, 3}, // 5에서 출발할 때.
//     {5, 5, 3, 2, 4, 2, 1, 5, 3, 2}, // 6에서 출발할 때.
//     {3, 4, 5, 6, 2, 3, 5, 1, 2, 4}, // 7에서 출발할 때.
//     {2, 5, 4, 5, 3, 2, 3, 2, 1, 2}, // 8에서 출발할 때.
//     {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}, // 9에서 출발할 때.
// };

// static int dp[100001][11][11];
// string inputNum;

// int dfs(int l, int r, int now){
//     if(now >= inputNum.size())  return 0;
//     if(dp[now][l][r] != -1) return dp[now][l][r];
    
//     int target = inputNum[now] - '0';
//     if(target == l || target == r) 
//         return dp[now][l][r] = 1 + dfs(l, r, now+1);
    
//     return dp[now][l][r] = min(costs[l][target] + dfs(target, r, now+1), costs[r][target] + dfs(l, target, now+1));
// }

// int solution(string numbers) {
//     inputNum = numbers;
//     memset(dp, -1, sizeof(dp));
//     return dfs(4, 6, 0);
}