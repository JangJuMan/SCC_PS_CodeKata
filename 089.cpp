// 89. 할인행사(슬라이딩 윈도우) / re(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/131127#
#include <string>
#include <vector>
#include <map>

using namespace std;

// const 가 붙으면 map의 [] 작동 박식떄문에 문제 생김. 내부적으로 값을 조회 뿐만 아니라 삽입하는 부가기능도 들어있기 때문에 const로하면 막힘!
bool checkIsComplete(map<string, int>& shopping, const vector<string>& want, const vector<int>& number){
    for(int i=0; i<want.size(); i++){
        if(shopping[want[i]] < number[i]){
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> shopping;
        
    int ans = 0;
    for(int i=0; i<discount.size(); i++){
        shopping[discount[i]]++;
        if(i - 10 >= 0){
            shopping[discount[i-10]]--;
        }
        
        if(checkIsComplete(shopping, want, number)){
            ans++;
        }
    }
    return ans;
}