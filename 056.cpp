// 56. 과일장수, greedy, Counting sort O(N+K)
// https://school.programmers.co.kr/learn/courses/30/lessons/135808
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 최적화 버전(빠름)
int solution(int k, int m, vector<int> score) {
    vector<int> countingVec(k+1, 0);
    for(size_t i=0; i<score.size(); ++i){
        ++countingVec[score[i]];
    }
    
    int idx = k, res = 0, i=1;
    while(idx > 0){
        if(countingVec[idx] == 0){
            --idx;
            continue;
        }
        if(i % m == 0){
            res += (idx * m);
        }
        --countingVec[idx];
        ++i; 
    }
    
    return res;
}

/* 가독성 버전(느림) */
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// vector<int> countingSort(const vector<int>& vec, int maxElem){
//     vector<int> count(maxElem+1, 0);
//     for(const int& elem : vec){
//         ++count[elem];
//     }
//     // 내림차순으로 정렬된 결과 벡터 구성
//     vector<int> sorted;
//     for (int i = maxElem; i >= 1; --i) {
//         for (int j = 0; j < count[i]; ++j) {
//             sorted.emplace_back(i);
//         }
//     }
//     return sorted;
// }

// int solution(int k, int m, vector<int> score) {
//     vector<int> sorted = countingSort(score, k);    // O(N + K)
    
//     int totalProfit = 0;
//     int n = score.size();
//     int boxCnt = n / m;     // 만들 수 있는 상자의 수
    
//     for(int i=0; i<boxCnt; ++i){
//         int minScore = sorted[(i*m) + m - 1];
//         totalProfit += minScore * m;
//     }
//     return totalProfit;
// }