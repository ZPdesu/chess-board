#include <iostream>
using namespace std;
const int BOARD_SZ = 8;
static int tile = 1;
static int board[BOARD_SZ][BOARD_SZ] = {0};

void chess_board(int tr, int tc, int dr, int dc, int size) {
    if(size == 1)
        return;

    int t = tile++;
    int sz = size / 2;    //每次进行划分

    //覆盖左上角
    if(dr < tr+sz && dc < tc+sz)     //4种边界
        chess_board(tr, tc, dr, dc, sz);
    else{
        board[tr+sz-1][tc+sz-1] = t;
        chess_board(tr, tc, tr+sz-1, tc+sz-1, sz);
    }

    //覆盖右上角
    if(dr < tr+sz && dc >= tc+sz)
        chess_board(tr, tc+sz, dr, dc, sz);
    else{
        board[tr+sz-1][tc+sz] = t;
        chess_board(tr, tc+sz, tr+sz-1, tc+sz, sz);
    }

    //覆盖左下角
    if(dr >= tr+sz && dc < tc+sz)
        chess_board(tr+sz, tc, dr, dc, sz);
    else{
        board[tr+sz][tc+sz-1] = t;
        chess_board(tr+sz, tc, tr+sz, tc+sz-1, sz);
    }

    //覆盖右下角
    if(dr >= tr+sz && dc >= tc+sz)
        chess_board(tr+sz, tc+sz, dr, dc, sz);
    else{
        board[tr+sz][tc+sz] = t;
        chess_board(tr+sz, tc+sz, tr+sz, tc+sz, sz);
    }
}

void print_chess_board() {

    for(int i=0; i<BOARD_SZ; ++i){
        for(int j=0; j<BOARD_SZ; ++j){
            cout.width(3);
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

int main() {
    chess_board(0, 0, 2, 1, BOARD_SZ);
    print_chess_board();
    return 0;
}
