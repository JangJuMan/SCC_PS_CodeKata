// 103. 가장 큰 수(sort) / re(re)
// https://school.programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string& a, const string& b){
    return (a+b) > (b+a);
}

string solution(vector<int> numbers) {
    vector<string> num;
    for(int n : numbers){
        num.emplace_back(to_string(n));
    }
    
    // sort(num.begin(), num.end(), comp);   // comp 함수로 판단해도 되고
    sort(num.begin(), num.end(), [](const string& a, const string& b){   // 람다함수로 정의해도 되고
        return (a+b) > (b+a);     // 문자열을 이어붙였을 때, 더 큰 값을 만들 수 있는 문자열을 앞으로 보냄
    });
    
    if(num[0] == "0") return "0";   // 00...0 인 경우, 0으로 예외처리
    
    string ans = "";
    for(string& s : num){
        ans += s;
    }
    
    return ans;
}