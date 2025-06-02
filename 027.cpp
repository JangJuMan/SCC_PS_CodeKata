// 27. 핸드폰 번호 가리기
// https://school.programmers.co.kr/learn/courses/30/lessons/12948
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    // fill 버전
    // fill(phone_number.begin(), phone_number.end()-4, '*');

    // iter 버전
    for(auto it = phone_number.begin(); it<phone_number.end()-4; it++){
        *it = '*';
    }
    return phone_number;
}