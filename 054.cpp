// 54. 2016년, 달력 요일찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/12901
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int monthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 4;  // 1월 1일 = 금요일 시작
    for(size_t i=0; i<a-1; ++i){
        totalDays += monthDays[i];
    }
    return days[(totalDays + b) % 7];    
}