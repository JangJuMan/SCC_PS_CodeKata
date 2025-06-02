// 25. 나누어 떨어지는 숫자 배열
// https://school.programmers.co.kr/learn/courses/30/lessons/12910
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> ans;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] % divisor == 0){
            ans.emplace_back(arr[i]);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return (ans.empty()) ? vector(1, -1) : ans;
}