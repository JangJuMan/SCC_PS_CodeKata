// 110. 두 큐 합 같게 만들기(투포인터) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/118667
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2){
    long long sum1 = 0, sum2 = 0;
    for(int i : queue1) sum1 += i;
    for(int i : queue2) sum2 += i;

    long long total = sum1 + sum2;
    if(total & 1) return -1;

    vector<int> q1 = queue1;
    q1.insert(q1.end(), queue2.begin(), queue2.end());
    
    long long target = total / 2;
    int n = queue1.size();
    int limit = n * 3, ans = 0, idx1 = 0, idx2 = n;

    while(ans <= limit && idx1 < q1.size() && idx2 < q1.size()){
        if(sum1 == target){
            return ans;
        }
        else if(sum1 > target){
            sum1 -= q1[idx1++];
        }
        else if(sum1 < target){
            sum1 += q1[idx2++];
        }
        // else if(sum1 > target){
        //     queue2.emplace_back(queue1[idx1]);
        //     sum1 -= queue1[idx1++];
        // }
        // else if(sum1 < target){
        //     queue1.emplace_back(queue2[idx2]);
        //     sum1 += queue2[idx2++];
        // }
        ans++;
    }
    return -1;
}