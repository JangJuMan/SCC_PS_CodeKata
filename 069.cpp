// 69. 성격 유형 검사하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118666
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    vector<int> category(26, 0);
    
    for(int i=0; i<survey.size(); ++i){
        if(choices[i] < 4){
            category[survey[i][0] - 'A'] += (4 - choices[i]);
        }
        else if(choices[i] > 4){
            category[survey[i][1] - 'A'] += (choices[i] - 4);
        }
    }
    
    string ans;
    ans += (category['R'-'A'] >= category['T'-'A'] ? 'R' : 'T');
    ans += (category['C'-'A'] >= category['F'-'A'] ? 'C' : 'F');
    ans += (category['J'-'A'] >= category['M'-'A'] ? 'J' : 'M');
    ans += (category['A'-'A'] >= category['N'-'A'] ? 'A' : 'N');
    return ans;
}