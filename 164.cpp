// 164. N으로 표현 (dp) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/42895
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<unordered_set<int>> dp(9);   // dp[1] ~ dp[8]
    
    for(int i=1; i<=8; i++){
        int repeated = 0;   // N을 i번 이어붙인 숫자 (5, 55, 555 ...)
        for(int j=0; j<i; j++){
            repeated = repeated * 10 + N;
        }
        dp[i].insert(repeated);
        
        for(int j=1; j<i; j++){
            for(int a : dp[j]){
                for(int b : dp[i-j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if(b != 0)  dp[i].insert(a / b);
                }
            }
        }
        if(dp[i].count(number)) return i;
    }
    return -1;
}