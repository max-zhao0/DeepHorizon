#include <windows.h>

#include "chess/board.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Board start_board;
    start_board.print();

    Move e4(4, 1, 4, 3);
    start_board.print_move(e4);
}