// 13. 자릿수 더하기
#include <iostream>

using namespace std;
int solution(int n)
{
    int sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}