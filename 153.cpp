// 153. 연속 펄스 부분 수열의 합(kadane's algorithm) / 품(간단)
// https://school.programmers.co.kr/learn/courses/30/lessons/161988
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

long long solution(vector<int> sequence) {
    long long ans = 0;
    long long cur1 = 0, cur2 = 0;
    
    for(int i=0; i<sequence.size(); i++){
        int x = sequence[i];
        int p1 = (i&1) == 0 ? x : -x;
        int p2 = (i&1) == 0 ? -x : x;
        
        cur1 = max((long long)p1, cur1 + p1);
        cur2 = max((long long)p2, cur2 + p2);
        
        ans = max({ans, cur1, cur2});   // max가 리스트로 받는게 있구나(algorithm)
    }
    return ans;
}