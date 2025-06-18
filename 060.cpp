// 60. 기사단원의 무기, 약수 구하기(Sieve Like)
// https://school.programmers.co.kr/learn/courses/30/lessons/136798
#include <string>
#include <vector>

using namespace std;

/* 단일 수에 대한 약수개수 반환 */
int countDivisors(int n){   // O(sqrt(n))
    int cnt = 0;
    for(int i=1; i*i <= n; ++i){
        if(n % i == 0){
            cnt+=2;         // 약수는 짝으로 더해줌
            if(i*i == n){   // 제곱근의 경우 1개로 계산
                --cnt;
            }
        }
    }
}

/* Sieve Like 방식 약수 구하기 */
int solution(int number, int limit, int power) {
    // 약수의 개수 미리 저장해두기
    vector<int> divisors(number+1, 0);
    for(int i=1; i<=number; ++i){       // O(n)
        for(int j=i; j<=number; j+=i){  // O(n / i) => O(n log n)
            ++divisors[j];              // i의 배수에 약수의 개수 +1
        }
    }
    
    int sum = 0;
    for(int i=1; i<=number; ++i){
        sum += (divisors[i] > limit) ? power : divisors[i];
    }
    return sum;
}