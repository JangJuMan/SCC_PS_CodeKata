// 59. 덧칠하기, Greedy
// https://school.programmers.co.kr/learn/courses/30/lessons/161989
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int paintCnt = 0, current = -1;
    for(int i=0; i<section.size(); ++i){
        if(current < section[i]){
            ++paintCnt;
            current = section[i] + m - 1;
            if(current >= n){
                break;
            }
        }
    }
    return paintCnt;
}