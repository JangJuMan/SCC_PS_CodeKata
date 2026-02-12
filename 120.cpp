// 120. 멀쩡한 사각형(gcd, 공식?) / re(2트 완료, 캐스팅 주의)
// https://school.programmers.co.kr/learn/courses/30/lessons/62048
#include <numeric>

using namespace std;

/* 2트 */
long long solution(int w, int h){
    long long W = (long long)w;
    long long H = (long long)h;
    long long total = W*H;
    long long unusable = W + H - gcd(W, H);
    return total - unusable;
}

/* 1트 */
int getGCD(int a, int b){   // gcd(a, b) = gcd(b, r) / 복습용
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long long W = w, H = h;
    return (W*H) - (W + H - gcd(w,h));
}