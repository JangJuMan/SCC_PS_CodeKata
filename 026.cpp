// 26. 음양 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/76501
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int sum = 0;
    for(int i=0; i<absolutes.size(); i++){
        sum += (signs[i]) ? absolutes[i] : -absolutes[i];
    }
    return sum;
}