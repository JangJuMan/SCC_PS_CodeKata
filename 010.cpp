// 10. 배열의 평균값
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    int sum = 0;
    for(int i=0; i<numbers.size(); i++){
        sum += numbers[i];
    }
    return (double)sum / numbers.size();
}