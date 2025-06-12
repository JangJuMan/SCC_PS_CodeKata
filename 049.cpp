// 49. 두 개 뽑아서 더하기(set)
// https://school.programmers.co.kr/learn/courses/30/lessons/68644
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 1. 데이터 수가 적은 경우 (n < 1000), set
    // 트리 관리 비용이 비쌈
    // set<int> mySet;
    // for(size_t i=0; i<numbers.size(); ++i){
    //     for(size_t j=i+1; j<numbers.size(); ++j){
    //         mySet.insert(numbers[i] + numbers[j]);
    //     }
    // }
    // return vector<int>(mySet.begin(), mySet.end());
    
    // 2. 데이터 수가 많은 경우 (n > 1000), unordered_set + vector sort
    // 트리 유지비용 절약, 연속된 vector 메모리로 캐시 효율 향상
    unordered_set<int> hashSet;
    
    for(size_t i=0; i<numbers.size(); ++i){
        for(size_t j=i+1; j<numbers.size(); ++j){
            hashSet.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> vec(hashSet.begin(), hashSet.end());
    sort(vec.begin(), vec.end());
    return vec;
}