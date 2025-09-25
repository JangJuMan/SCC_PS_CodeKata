// 151. 입국심사 (이분탐색) / re (이런 방법이... ㄷㄷ)
// https://school.programmers.co.kr/learn/courses/30/lessons/43238
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1, right = (long long)*min_element(times.begin(), times.end()) * n;
    long long ans = right;
    
    while(left <= right){
        long long mid = (left + right) / 2;
        
        long long people = 0;
        for(int t : times){
            people += mid / t;
            if(people >= n) break;  // 불필요한 반복 제거
        }
        
        if(people >= n){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}