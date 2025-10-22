// 162. 표현 가능한 이진트리(bitset, divide ans conquer) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/150367
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bool isValid(const string& s, int left, int right){
    if(left == right) return true;  // 리프 노드
    
    int mid = (left + right) / 2;   // 루트 노드 idx
    char root = s[mid];
    
    bool isLeftValid = isValid(s, left, mid-1);
    bool isRightValid = isValid(s, mid+1, right);
    
    int leftChild = (left + mid - 1) / 2;
    int rightChild = (mid + 1 + right) / 2;
    if(root == '0' &&   // 루트가 0인데, 자식 노드가 존재하면 불가능
      (s[leftChild] == '1' || s[rightChild] == '1')){
        return false;
    }
    return isLeftValid && isRightValid;    
}

vector<int> solution(vector<long long> numbers) {
    vector<int> ans;
    
    for(const long long& num : numbers){
        string bin = bitset<64>(num).to_string();
        bin = bin.substr(bin.find('1'));    // 앞의 0 모두 제거
        
        // 포화 이진트리 크기 찾기 (1, 3, 7, 15 ,,,)
        int binSize = bin.size();
        int fullSize = 1;
        while(fullSize < binSize) 
            fullSize = fullSize * 2 + 1;
        
        // 앞쪽에 더미(0) 추가하여 포화 이진트리 완성
        bin = string(fullSize - binSize, '0') + bin;
        
        ans.emplace_back(isValid(bin, 0, fullSize-1) ? 1 : 0);
    }
    return ans;
}