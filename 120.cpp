// 120. 멀쩡한 사각형(gcd, 공식?) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/62048
#include <numeric>

using namespace std;

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