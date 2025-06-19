// 61. 로또의 최고 순위와 최저 순위
// https://school.programmers.co.kr/learn/courses/30/lessons/77484
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> lottosVec(46, 0);
    for(int i=0; i<lottos.size(); ++i){
        ++lottosVec[lottos[i]];
        ++lottosVec[win_nums[i]];
    }
    
    int matchCnt = 0;
    for(int i=1; i<lottosVec.size(); ++i){
        if(lottosVec[i] == 2){
            ++matchCnt;
        }
    }
    
    int ranks[] = {6, 6, 5, 4, 3, 2, 1};
    return {ranks[matchCnt + lottosVec[0]], ranks[matchCnt]};
}