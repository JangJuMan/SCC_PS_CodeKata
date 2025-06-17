// 57. 수포자, O(n)
// https://school.programmers.co.kr/learn/courses/30/lessons/42840
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> supo1 = {1,2,3,4,5};
    vector<int> supo2 = {2,1,2,3,2,4,2,5};
    vector<int> supo3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> score(3, 0);
    
    for(int i=0; i<answers.size(); ++i){
        if(answers[i] == supo1[i%supo1.size()]){
            ++score[0];
        }
        if(answers[i] == supo2[i%supo2.size()]){
            ++score[1];
        }
        if(answers[i] == supo3[i%supo3.size()]){
            ++score[2];
        }
    }
    int maxScore = *max_element(score.begin(), score.end());
    
    vector<int> res;
    for(int i=0; i<score.size(); ++i){
        if(score[i] == maxScore){
            res.emplace_back(i+1);
        }
    }
    return res;
}