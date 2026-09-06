#pragma once

#include <array>
#include <vector>
#include <string>
#include <iostream>

#include "chess/move.hpp"

class Board {
    private:
    std::array<std::array<int, 8>, 8> squares;
    std::array<std::array<bool, 2>, 2> castling_rights;
    std::array<int, 2> enpassant_rights;
    int side_to_move;
    std::vector<int> hashes_since_pushcap;

    public:
    Board() {
        // Sets the starting position
        hashes_since_pushcap = {};
        side_to_move = 1;
        enpassant_rights.fill(-1);
        castling_rights.at(0).fill(true);
        castling_rights.at(1).fill(true);

        squares[0][0] = 4;
        squares[1][0] = 2;
        squares[2][0] = 3;
        squares[3][0] = 5;
        squares[4][0] = 6;
        squares[5][0] = 3;
        squares[6][0] = 2;
        squares[7][0] = 4;
        for (int file = 0; file < 8; file++) {
            squares[file][1] = 1;
            squares[file][6] = -1;
            squares[file][7] = -squares.at(file).at(0);
            for (int rank = 2; rank <= 5; rank++) {
                squares[file][rank] = 0;
            }
        }
    }

    Board(std::string fen) {
        // TODO: Position from FEN
    }

    Board copy() {
    }

    Board apply_move() {
        Board new_board = copy();
        return new_board;
    }

    std::string to_fen() {
        // TODO
    }

    void print() {
        for (int rank = 7; rank >= 0; rank--) {
            for (int file = 0; file < 8; file++) {
                switch(squares[file][rank]) {
                    case 0:
                        std::cout << "  ";
                        break;
                    case 1:
                        std::cout << "♟ ";
                        break;
                    case 2:
                        std::cout << "♞ ";
                        break;
                    case 3:
                        std::cout << "♝ ";
                        break;
                    case 4:
                        std::cout << "♜ ";
                        break;
                    case 5:
                        std::cout << "♛ ";
                        break;
                    case 6:
                        std::cout << "♚ ";
                        break;
                    case -1:
                        std::cout << "♙ ";
                        break;
                    case -2:
                        std::cout << "♘ ";
                        break;
                    case -3:
                        std::cout << "♗ ";
                        break;
                    case -4:
                        std::cout << "♖ ";
                        break;
                    case -5:
                        std::cout << "♕ ";
                        break;
                    case -6:
                        std::cout << "♔ ";
                        break;
                    default:
                        std::cout << "! ";
                }
            }
            std::cout << std::endl;
        }
    }

    void print_move(Move& move) {
        // TODO
    }
};