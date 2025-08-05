// 116. 점 찍기(수식계산) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/140107
#include <string>
#include <vector>
#include <cmath>

using namespace std;

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