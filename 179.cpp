// 179. 아방가르드 타일링(DP) / rere
// https://school.programmers.co.kr/learn/courses/30/lessons/181186
#include <iostream>
#include <vector>

using namespace std;

constexpr long long mod = 1'000'000'007;
long long dp[100001] = {1, 1, 3, 10, };
long long sum[100001] = {1, 1, 3, 11, };          // i-3 계열의 누적 합(블록을 가로 3칸짜리 계속 이어붙일 수 있음)

int solution(int n) {
    for(int i=4; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-3]
                + (sum[i-2] * 2)
                + (sum[i-3] * 4)
                + (sum[i-4] * 2)) % mod;
        
        sum[i] = (sum[i-3] + dp[i]) % mod;
    }
    return dp[n];
}
