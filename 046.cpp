// 46. 숫자 문자열과 영단어(영단어/숫자 복합 -> 숫자 치환) O(n)
// https://school.programmers.co.kr/learn/courses/30/lessons/81301
// 성능상 이점은 없지만, regex로 푸는 방법도 있더라
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, char> dict = {
        {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'},
        {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'},
        {"eight", '8'}, {"nine", '9'}};
    
    string op = "", result = "";
    for(char& c : s){
        if(isdigit(c)){
            result += c;
        }
        else{
            op += c;
            if(dict.count(op)){
                result += dict[op];
                op.clear();
            }
        }
    }
    return stoi(result);
}