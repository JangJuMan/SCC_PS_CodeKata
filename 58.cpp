// 58. 소수 만들기, dfs, 에라토스테네스의 체, dp, prime
// 미리 소수판별 벡터 만들어두기, 6k ± 1 패턴검사(모든 소수는 6k ± 1 형태로 존재함 : 에라토스테네스의 체)
// https://school.programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <iostream>
using namespace std;

constexpr int MAX_SUM = 3000; // 1000 + 1000 + 1000(최대 3개의 합)
int sum, res;
vector<bool> prime(MAX_SUM+1, true);

// 단일수 최적화 소수판별
bool isPrime(int n){
    if(n <= 1) return false;    // 0, 1은 소수 아님
    if(n <= 3) return true;     // 2, 3은 소수
    if(n%2 == 0 || n%3 == 0) return false;  // 짝수와 3의 배수는 소수 아님
    
    // 6k ± 1 소수 성질 활용(모든 소수는 6k ± 1에만 존재한다)
    for(int i=5; i*i <= n; i+=6){   // 약수 탐색은 sqrt(n)까지만 확인
        if(n % i == 0 || n % (i+2) == 0){
            return false;
        }
    }
    return true;
}

// 다수비교 유리(DP)
void generatePrimes(int limit){
    prime[0] = prime[1] = false;
    for(int i=2; i*i <= limit; ++i){
        if(prime[i]){
            for(int j=i*i; j<=limit; j+=i){
                prime[j] = false;   // i*i부터 i의 배수를 모두 소수아님 처리
            }
        }
    }
}

void dfs(int depth, int start, const vector<int>& nums){
    if(depth == 3){
        if(prime[sum]){
            ++res;
        }
        return;
    }
    
    for(int i=start; i<nums.size(); ++i){
        sum += nums[i];
        dfs(depth+1, i+1, nums);
        sum -= nums[i];
    }
}

int solution(vector<int> nums) {
    generatePrimes(MAX_SUM);
    dfs(0, 0, nums);
    return res;
}