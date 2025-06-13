// 52. 콜라문제
// https://school.programmers.co.kr/learn/courses/30/lessons/132267
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int totalCoke = 0;

    while(n >= a){
        int exchange = (n / a) * b;
        totalCoke += exchange;
        n = exchange + (n % a);
    }
    return totalCoke;
}