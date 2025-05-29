// 12. 평균 구하기 : O(n)
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int avg = 0;
    for(int i=0; i<arr.size(); i++){
        avg += arr[i];
    }
    return (double)avg / arr.size();
}