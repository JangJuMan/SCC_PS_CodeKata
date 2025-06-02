// 23. 콜라스 추측
// https://school.programmers.co.kr/learn/courses/30/lessons/12943
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    
    for(int i=0; i<500; i++){
        if(n == 1){
            return i;
        }
        n = (n & 1) ? (n*3 + 1) : (n/2);
    }
    return -1;
}