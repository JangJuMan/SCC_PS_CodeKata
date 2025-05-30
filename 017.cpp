// 17. 자연수 뒤집어 배열로 만들기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    do{
        answer.push_back(n%10);
        n /= 10;
    }while(n);
    
    return answer;
}