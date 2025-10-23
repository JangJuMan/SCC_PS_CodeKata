// 163. 스타수열 (구현) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/70130
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
    int n = a.size();
    if(n < 2) return 0;
    
    vector<int> freq(n, 0);
    for(int& i : a) freq[i]++;
    
    int ans = 0;
    
    // 최적화
    vector<pair<int, int>> order(n);
    for(int i=0; i<n; i++){
        if(freq[i] > 0){
            order.emplace_back(freq[i], i);
        }
    }
    sort(order.rbegin(), order.rend());     // 빈도 순 내림차순 정렬
    
    for(auto [countX, x] : order){      // 빈도가 높은 것부터 차례로 확인
        if(countX * 2 <= ans) break;    // 만들 수 있는 최대 길이가 이미 작으면 스킵
        
        int pairs = 0;
        for(int i=0; i<n-1; ){
            int cur = a[i], nxt = a[i+1];
            
            if(cur != nxt && (cur == x || nxt == x)){
                ++pairs;
                i+=2;       // 쌍을 만들었으면 두 칸 전진
            }
            else{
                ++i;        // 쌍을 못만들었으면 한 칸 전진
            }
        }
        ans = max(ans, pairs*2);
    }
    return ans;
}