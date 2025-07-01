// 78. 피보나치 수(dp, 변수 2개, 행렬)
// https://school.programmers.co.kr/learn/courses/30/lessons/12945
#include <string>
#include <vector>

using namespace std;

constexpr int MOD = 1234567;

/* 행렬 이용 : O(log N) */
class Matrix{
public:
    long long a, b, c, d;   // 2x2 행렬 |a b|
                            //          |c d|
    Matrix(long long a, long long b, long long c, long long d) : a(a), b(b), c(c), d(d){}

    // 행럴 곱셈(모듈러 연산 포함)
    Matrix operator*(const Matrix& m) const {
        return Matrix(
            (a * m.a + b * m.c) % MOD,
            (a * m.b + b * m.d) % MOD,
            (c * m.a + d * m.c) % MOD,
            (c * m.b + d * m.d) % MOD
        );
    }
};

Matrix power(Matrix m, int n){  // n^10 = n^5^2 = ((n^2^2)*n)^2 .. 이렇게 log n번만에 계산 가능
    Matrix res(1, 0, 0, 1);     // 단위행렬(곱셈의 항등원)
    while(n > 0){
        if(n & 1)               // n^9 = n * (n^8) = n * (n^4^2) ...
            res = res*m;        // 여기서 n을 res에 곱해둔다는 의미
        m = m*m;                // 매 단계마다 1, 2, 4, 8 제곱으로 커짐
        n /= 2;                 // log n번만 반복
    }
    return res;
}

int solution(int n){
    if(n == 0)
        return 0;
    Matrix base(1, 1, 1, 0);
    Matrix res = power(base, n-1);  // F(1) ~ F(n) => n-1 제곱
    return res.a;
}


/* 변수 2개 이용 : O(N) */
// int solution(int n) {
//     if(n == 0)  return 0;
//     if(n == 1)  return 1;
    
//     int prev = 0, curr = 1, next = 0;
//     for(int i=2; i<=n; i++){
//         next = (prev + curr) % MOD;
//         prev = curr;
//         curr = next;
//     }
//     return curr;
// }