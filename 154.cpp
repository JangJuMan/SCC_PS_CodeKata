// 154. 풍선 터뜨리기 / 1트 solve
// https://school.programmers.co.kr/learn/courses/30/lessons/68646#
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    vector<int> leftMin(n, numeric_limits<int>::max());
    vector<int> rightMin(n, numeric_limits<int>::max());
    
    for(int i=1; i<n; i++){
        leftMin[i] = min(leftMin[i-1], a[i-1]);
    }
    for(int i=n-2; i>=0; i--){
        rightMin[i] = min(rightMin[i+1], a[i+1]);
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] < leftMin[i] || a[i] < rightMin[i]){
            ans++;
        }
    }
    return ans;
}