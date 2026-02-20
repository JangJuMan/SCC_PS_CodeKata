// 130. 두 원 사이의 정수 쌍 (수식, 구현) / re (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/181187
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 2트(1트 코드가 더 나은듯?) */
long long solution(int r1, int r2){
    int y_min = r1, y_max = r2;
    long long ans = 0;
    for(int x=1; x<=r2; x++){
        while((long long)x*x + (long long)y_max*y_max > (long long)r2*r2){
            y_max--;
        }
        
        if(x < r1){
            while(y_min > 0 && (long long)x*x + (long long)(y_min-1)*(y_min-1) >= (long long)r1*r1){
                y_min--;
            }
        }
        else{
            y_min = 0;
        }
        ans += y_max - y_min + 1;
    }
    return ans * 4;
}

/* 1트 */
long long solution(int r1, int r2) {
    long long ans = 0;
    for(int x=1; x<=r2; x++){
        int y_max = floor(sqrt((long long)r2*r2 - (long long)x*x)); // x^2 + y^2 = r^2 (원의 방정식)
        int y_min = 0;
        if(r1 >= x){
            y_min = ceil(sqrt((long long)r1*r1 - (long long)x*x));
        }
        ans += (y_max - y_min + 1);
    }
    return ans*4;
}