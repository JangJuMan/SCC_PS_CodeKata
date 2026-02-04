// 116. 점 찍기(수식계산) / re (2트 완료? 한번더..? 형변환에서 좀 애먹었음)
// https://school.programmers.co.kr/learn/courses/30/lessons/140107
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 2트 (부분정답 대부분은 형변환 문제) */
long long solution(int k, int d) {
    long long ans=0;
    long long dd = (long long)d*d;  // NOTE. 미리 형변환 해야 손실 없음
    for(int i=0; i<=d; i+=k){
        long long ii = (long long)i*i;
        long long res = sqrt(dd - ii) / k;
        ans += res + 1;
    }
    return ans;
}

/* 1트 */
long long solution(int k, int d) {
    // d*d >= a*a*k*k + b*b*k*k 를 만족하는 (a,b)의 개수
    long long ans = 0;
    for(int a=0; a <= d/k; a++){
        long long x = 1LL * a * k;
        // long long b = static_cast<long long>(sqrt((1LL*d*d) - (x*x))) / k;  // d*d >= x*x + y*y, x=ak, y=bk
        long long b = static_cast<long long>(sqrt((1LL * d*d)/(1LL*k*k) - (1LL*a*a)));  // sqrt 안의 수가 작아서 더 빠름
        ans += (b + 1);
    }
    return ans;
}