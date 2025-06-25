// 70. 바탕화면 정리 (min, max)
// https://school.programmers.co.kr/learn/courses/30/lessons/161990
#include <string>
#include <vector>

using namespace std;

constexpr int MAX=51;
constexpr int MIN=-1;

vector<int> solution(vector<string> wallpaper) {
    int lux=MAX, luy=MAX, rdx=MIN, rdy=MIN;
    for(int i=0; i<wallpaper.size(); ++i){
        for(int j=0; j<wallpaper[i].size(); ++j){
            if(wallpaper[i][j] == '#'){
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i+1);
                rdy = max(rdy, j+1);
            }   
        }
    }
    return {lux, luy, rdx, rdy};
}