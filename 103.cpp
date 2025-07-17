// 103. 가장 큰 수(sort) / re
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
    
    // sort(num.begin(), num.end(), comp);
    sort(num.begin(), num.end(), [](const string& a, const string& b){
        return (a+b) > (b+a);
    });
    
    if(num[0] == "0") return "0";   // 00...0 인 경우, 0으로 예외처리
    
    string ans = "";
    for(string& s : num){
        ans += s;
    }
    
    return ans;
}