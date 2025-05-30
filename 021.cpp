// https://school.programmers.co.kr/learn/courses/30/lessons/12947
// 21. 하샤드 수
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(int x) {
    int digit = x;
    int digitSum = 0;
    
    while(digit){
        digitSum += digit%10;
        digit /= 10;
    }
    
    return x % digitSum == 0;
}