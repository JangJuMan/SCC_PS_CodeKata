// 80. 예상 대진표(일반화)
// https://school.programmers.co.kr/learn/courses/30/lessons/12985
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int round = 0;
    while(a != b){
        a = (a+1)/2;
        b = (b+1)/2;
        round++;
    }
    return round;
}