// 99. 롤 케이크 자르기(unordered_set/map) 
// https://school.programmers.co.kr/learn/courses/30/lessons/132265
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    unordered_set<int> l;
    unordered_map<int, int> r;
    for(int i : topping){
        r[i]++;
    }
    
    int ans = 0;
    for(int i=0; i<topping.size()-1; i++){
        l.insert(topping[i]);
        if(--r[topping[i]] == 0){
            r.erase(topping[i]);
        }
        if(l.size() == r.size()){
            ans++;
        }
    }
    return ans;
}