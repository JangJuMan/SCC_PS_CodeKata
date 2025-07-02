// 83. 귤 고르기(빈도 정렬)
// https://school.programmers.co.kr/learn/courses/30/lessons/138476
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* unordered_map 버전. 귤의 종류가 적을 때 유리 */
int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> count;
    for(int i : tangerine){
        count[i]++;
    }
    
    vector<int> freq;
    freq.reserve(count.size());
    for(auto& p : count){
        freq.push_back(p.second);
    }
    
    sort(freq.rbegin(), freq.rend());   // 내림차순 정렬
    
    int ans = 0;
    for(int i=0; i<freq.size() && k > 0; ++i){
        k -= freq[i];
        ++ans;
    }
    return ans;
}

/* vector 버전. 귤의 종류가 연속적이고, 귤의 최대값이 크지 않을때 유리 */
// int solution(int k, vector<int> tangerine) {
//     int m = *max_element(tangerine.begin(), tangerine.end());
//     vector<int> count(m+1, 0);
    
//     for(int i=0; i<tangerine.size(); i++){
//         ++count[tangerine[i]];
//     }
//     sort(count.begin(), count.end(), greater());
//     int ans=0;
//     for(int i=0; i<count.size() && k > 0; i++){
//         k -= count[i];
//         ++ans;
//     }
//     return ans;
// }
// array는 메모리 초과의 위험성이 있다.(보통 1천만개까지는 가능하다는데..)
// vector로 힙메모리를 먹는게 나은가?