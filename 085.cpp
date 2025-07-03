// 85. 연속 부분 수열 합의 개수(hash set, prefix)
// https://school.programmers.co.kr/learn/courses/30/lessons/131701
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> hashSet;
    
    int n = elements.size();
    for(int i=0; i<n; ++i){
        int sum = 0;
        for(int j=i; j<i+n; ++j){
            sum += elements[j%n];
            hashSet.insert(sum);
        }
    }
    return hashSet.size();
}