// 87. n^2 배열 자르기(일반화) : O(n)
// https://school.programmers.co.kr/learn/courses/30/lessons/87390
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    ans.reserve(right - left + 1);
    
    for(long long i = left; i<=right; ++i){
        ans.emplace_back(max(i/n, i%n) + 1);
    }
    
    return ans;
}