// 119. 숫자 카드 나누기 (gcd) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/135807
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool divisorCheck(const vector<int>& vec, int divisor){
    for(int num : vec){
        if(num % divisor == 0){
            return false;
        }
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    // array A의 모든 공약수
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    for(int i=1; i<arrayA.size(); i++){
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    int ans = 0;
    if(divisorCheck(arrayA, gcdB)){
        ans = max(ans, gcdB);
    }
    if(divisorCheck(arrayB, gcdA)){
        ans = max(ans, gcdA);
    }
    return ans;
    
}