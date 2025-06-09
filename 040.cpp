// 40. 3진법 뒤집기
// https://school.programmers.co.kr/learn/courses/30/lessons/68935
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> base3;
    
    while(n != 0){
        base3.push_back(n % 3);
        n /= 3;
    }
    
    int ans = 0;
    for(int i=0; i<base3.size(); i++){
        ans = ans * 3 + base3[i];
    }
    return ans;
}