// 16. x 만큼 간격이 있는 n개의 숫자
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n, x);
    for(int i=1; i<n; i++){
        answer[i] = answer[i-1] + x;
    }
    return answer;
}