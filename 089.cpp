// 89. 할인행사(슬라이딩 윈도우) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/131127#
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> buyMap;
    for(int i=0; i<9; i++){
        buyMap[discount[i]]++;
    }
    
    int ans = 0;
    for(int i=9; i<discount.size(); i++){
        buyMap[discount[i]]++;
        
        bool canBuy = true;
        for(int j=0; j<want.size(); j++){
            if(buyMap[want[j]] != number[j]){
                canBuy = false;
            }
        }
        
        if(canBuy){
            ans++;
        }
        
        buyMap[discount[i-9]]--;
    }
    return ans;
}
