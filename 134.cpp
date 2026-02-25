// 134. 혼자하는 틱텍토(구현) / re (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/160585#
#include <string>
#include <vector>

using namespace std;

/* 2트(실패) */
bool winCheck(const vector<string>& board, char c){
    for(int i=0; i<3; i++){
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c)    // 세로
        // NOTE. 이건 순차적으로 비교하기때문에 비교 의미가 달라짐
        // board[i][0] == board[i][1] == board[i][2] == c 
            return true;
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c)    // 가로
            return true;
    }
    
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    int cntO = 0, cntX = 0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'O') cntO++;
            else if(board[i][j] == 'X') cntX++;
        }
    }
    
    if(!(cntO == cntX + 1 || cntO == cntX)) return 0;
    
    bool winO = winCheck(board, 'O');
    bool winX = winCheck(board, 'X');
    if(winO && winX) return 0;
    if(winO && cntO != cntX+1) return 0;
    if(winX && cntX != cntO) return 0;
    
    return 1;
}

/* 1트 */
bool win_check(const vector<string>& board, char c){
    for(int i=0; i<board.size(); i++){
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
    }
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
    return false;
}

int solution(vector<string> board) {
    int count_o = 0, count_x = 0;
    for(int i = 0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'O') count_o++;
            else if(board[i][j] == 'X') count_x++;
        }
    }
    
    if(!(count_o == count_x || count_o == count_x + 1)) return 0;
    
    bool is_win_o = win_check(board, 'O');
    bool is_win_x = win_check(board, 'X');
    
    if(is_win_o && is_win_x) return 0;
    if(is_win_o && count_o != count_x + 1) return 0;
    if(is_win_x && count_o != count_x) return 0;
    return 1;
}