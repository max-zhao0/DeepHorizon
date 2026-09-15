#include <windows.h>

#include "chess/SmartBoard.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    SmartBoard start_board;
    start_board.print();

    Move e4(4, 1, 4, 3);
    e4.print(start_board.get_board());
}