// 172. 금과 은 운반하기 (binary search) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/86053
#include <string>
#include <vector>

using namespace std;

bool canDeliver(long long time, int a, int b, 
                const vector<int>& g, const vector<int>& s,
                const vector<int>& w, const vector<int>& t){
    int n = t.size();
    long goldSum = 0, silverSum = 0, totalSum = 0;  // time 내에 운반 가능한 총량
    for(int i=0; i<n; i++){
        long long travelTime = t[i] * 2;    // 왕복시간
        long long maxWeight = w[i];         // 트럭 용량
        long long curGold = g[i];           // 현재 도시 금 보유량
        long long curSilver = s[i];         // 현재 도시 은 보유량
        
        long long travelCnt = time / travelTime;    // 왕복 횟수
        if(time % travelTime >= t[i]){
            travelCnt++;    // 마지막 편도 운행 가능한 경우
        }
        
        long long maxCapacity = travelCnt * maxWeight;  // 운반 가능한 최대 광물 양
        goldSum += min(maxCapacity, curGold);
        silverSum += min(maxCapacity, curSilver);
        totalSum += min(maxCapacity, curGold + curSilver);
        
        if(goldSum >= a && silverSum >= b && totalSum >= a+b){
            return true;
        }
    }
    return (goldSum >= a && silverSum >= b && totalSum >= a+b);
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long left = 0, right = 4e14;   // 상한 : 2(왕복) * 10^5 * 2(금&은) * 10^9 = 4e14
    while(left < right){
        long long mid = (left + right) / 2;
        if(canDeliver(mid, a, b, g, s, w, t))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}