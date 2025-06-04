// 28. 없는 숫자 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/86051
#include <string>
#include <vector>
#include <numeric>  // accumulate()

using namespace std;

int solution(vector<int> numbers) {
    int totalSum = 45;
    int numberSum = accumulate(numbers.begin(), numbers.end(), 0/*sum 초기값*/);    
    return totalSum - numberSum;
}