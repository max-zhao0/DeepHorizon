#include <windows.h>

#include "chess/board.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Board start_board;
    start_board.print();
}