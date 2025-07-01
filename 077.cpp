// 77. 이진 변환 반복하기 (bitset, string)
// https://school.programmers.co.kr/learn/courses/30/lessons/70129
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    int eraseZeroCnt = 0;
    int toBinaryCnt = 0;
    int remainLength = 0;
    
    while(s != "1"){
            if(c == '0'){
                eraseZeroCnt++;
            }
            else{
                remainLength++;
            }
        }
        bitset<18> bits(remainLength);
        s = bits.to_string();
        s = s.substr(s.find('1'));
        toBinaryCnt++;
        remainLength=0;
    }
    return {toBinaryCnt, eraseZeroCnt};
}