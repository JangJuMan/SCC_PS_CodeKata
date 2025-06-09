// 39. 최대공약수와 최소공배수
// https://school.programmers.co.kr/learn/courses/30/lessons/12940
#include <string>
#include <vector>

using namespace std;

// Greatest Common Divisor - Euclidean Algorithm O(log n)
// GCD(a, b) = GCD(b, r),  a = b * q + r 일 때,
// a, b 대소비교 필요없음(자동 자리바꿈)
int getGCD(int a, int b){
    while(b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// Least Common Multiple : a * b / GCD;
int getLCM(int a, int b, int gcd){
    return (a * b) / gcd;
}

vector<int> solution(int n, int m) {
    int gcd = getGCD(n, m);
    int lcm = getLCM(n, m, gcd);
    return {gcd, lcm};
}