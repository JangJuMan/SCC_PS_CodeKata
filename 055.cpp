// 55. 카드뭉치, merge 비교
// https://school.programmers.co.kr/learn/courses/30/lessons/159994
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    for(size_t l=0, r=0, i=0; i<goal.size(); ++i){
        if(l < cards1.size() && cards1[l] == goal[i]){
            ++l;
        }
        else if(r < cards2.size() && cards2[r] == goal[i]){
            ++r;
        }
        else{
            return "No";
        }
    }
    return "Yes";
}