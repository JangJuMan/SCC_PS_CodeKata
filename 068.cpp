// 68. 햄버거 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/133502
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> vec;
    int ans = 0;
    
    for(const int& i : ingredient){
        vec.push_back(i);
        
        if(vec.size() >= 4 &&
            vec[vec.size() - 4] == 1 &&
            vec[vec.size() - 3] == 2 &&
            vec[vec.size() - 2] == 3 &&
            vec[vec.size() - 1] == 1){
            vec.resize(vec.size() - 4);
            ans++;
        }
    }
    return ans;
}