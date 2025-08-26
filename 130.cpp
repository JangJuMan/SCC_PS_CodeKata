// 130. 두 원 사이의 정수 쌍 (수식, 구현) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/181187
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long ans = 0;
    for(int i=1; i<=r2; i++){
        int y_max = floor(sqrt((long long)r2*r2 - (long long)i*i));
        int y_min = 0;
        if(r1 >= i){
            y_min = ceil(sqrt((long long)r1*r1 - (long long)i*i));
        }
        ans += (y_max - y_min + 1);
    }
    return ans*4;
}