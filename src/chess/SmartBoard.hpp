#pragma once

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <bitset>

#include "chess/Board.hpp"
#include "chess/Move.hpp"
#include "chess/Zobrist.hpp"

class SmartBoard {
    private:
    Board board;
    std::vector<std::bitset<ZOBRIST_SIZE>> hashes_since_irrev;

    public:
    SmartBoard() {
        // Sets the starting position
        hashes_since_irrev = {};
        board.side_to_move = 1;
        board.enpassant_rights.fill(-1);
        board.castling_rights.at(0).fill(true);
        board.castling_rights.at(1).fill(true);

        board.squares[0][0] = 4;
        board.squares[1][0] = 2;
        board.squares[2][0] = 3;
        board.squares[3][0] = 5;
        board.squares[4][0] = 6;
        board.squares[5][0] = 3;
        board.squares[6][0] = 2;
        board.squares[7][0] = 4;
        for (int file = 0; file < 8; file++) {
            board.squares[file][1] = 1;
            board.squares[file][6] = -1;
            board.squares[file][7] = -board.squares.at(file).at(0);
            for (int rank = 2; rank <= 5; rank++) {
                board.squares[file][rank] = 0;
            }
        }
    }

    SmartBoard(std::string fen) {
        // TODO: Position from FEN
    }

    Board* get_board() {
        return &board;
    }

    void apply_move(const Move& move, bool trusting=true) {
        if (!trusting && !move.is_legal(board)) {
            throw std::invalid_argument("Illegal move");
        }
    }

    std::string to_fen() const {
        // TODO
    }

    void print() const {
        for (int rank = 7; rank >= 0; rank--) {
            for (int file = 0; file < 8; file++) {
                switch(board.squares[file][rank]) {
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
};