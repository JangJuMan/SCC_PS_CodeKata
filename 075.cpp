// 75. 최댓값과 최솟값(sstream)
// https://school.programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    int tmp, min_n=numeric_limits<int>::max(), max_n=numeric_limits<int>::min();
    while(ss >> tmp){
        min_n = min(min_n, tmp);
        max_n = max(max_n, tmp);
    }
    return to_string(min_n) + " " + to_string(max_n);
}