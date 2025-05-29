// 014. 약수의 합 : O(sqrt(N))
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            sum += i;
            if(i != n/i){
                sum += n/i;
            }
        }
    }
    return sum;
}