// 29. 제일 작은 수 제거하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12935
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1){
        return vector<int>(1, -1);
    }
    
    arr.erase(min_element(arr.begin(), arr.end()));
    
    return arr;
}