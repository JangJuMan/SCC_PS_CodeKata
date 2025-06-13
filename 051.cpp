// 51. 푸드 파이트 대회. string, deque
// https://school.programmers.co.kr/learn/courses/30/lessons/134240
#include <string>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string left;
    for(size_t i = 1; i < food.size(); ++i){
        left += string(food[i]/2, '0' + i);
    }
    string right = left;
    reverse(right.begin(), right.end());
    return left + '0' + right;
    
    
    // deque를 써봄
//     deque<char> dq(1, '0');    
//     for(size_t i=food.size()-1; i>0; --i){
//         for(size_t j=0; j<food[i]/2; ++j){
//             dq.push_front('0'+i);
//             dq.push_back('0'+i);
//         }
//     }
//     string ans = "";
//     for(const char& c : dq){
//         ans += c;
//     }
//     return ans;
}