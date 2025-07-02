// 82. 멀리뛰기 (DP)
// https://school.programmers.co.kr/learn/courses/30/lessons/12914
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    constexpr int MOD = 1234567;
    int prev=0, curr=1, next;
    for(int i=1; i<=n; i++){
        next = (prev + curr) % MOD;
        prev = curr;
        curr = next;
    }
    return curr;
}