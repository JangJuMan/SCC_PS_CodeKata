// [W] 62. 옹알이2
// https://school.programmers.co.kr/learn/courses/30/lessons/133499
#include <string>
#include <vector>

using namespace std;

vector<string> canSpeak = {"aya", "ye", "woo", "ma"};

bool isValid(const string& target){
    int pos = 0;
    string prev = "";
    while(pos < target.length()){
        bool isMatch = false;
        
        for(const string& canWord : canSpeak){
            int len = canWord.length();
            if(target.substr(pos, len) == canWord && canWord != prev){
                isMatch = true;
                prev = canWord;
                pos += len;
                break;
            }
        }
        
        if(!isMatch){
            return false;
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int count = 0;
    for(const string& target : babbling){
        if(isValid(target)){
            ++count;
        }
    }
    return count;
}