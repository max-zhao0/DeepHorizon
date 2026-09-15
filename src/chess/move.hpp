#pragma once

#include <string>
#include <iostream>

#include "chess/Board.hpp"

class Move {
    private:
    static constexpr std::string_view fileletters = "abcdefgh";
    static constexpr std::array<std::string_view, 7> piece_names = {"Blank", "Pawn", "Knight", "Bishop", "Rook", "Queen", "King"};

    int start_file;
    int start_rank;
    int end_file;
    int end_rank;
    int promotion_piece;

    public:
    Move(int in_start_file, int in_start_rank, int in_end_file, int in_end_rank, int in_promotion_piece = 0) {
        start_file = in_start_file;
        start_rank = in_start_rank;
        end_file = in_end_file;
        end_rank = in_end_rank;
        promotion_piece = in_promotion_piece;
    }

    bool is_legal(Board& board) const {
        throw std::invalid_argument("Legal move checking not implemented");
        return true;
    }

    bool is_legal(Board* board) const {
        return is_legal(*board);
    }

    void print(Board* board) const {
        int start_square = board->squares[start_file][start_rank];
        int end_square = board->squares[end_file][end_rank];

        // Castling expressed by king capturing own rook
        if ((start_square == 6 && end_square == 4) || (start_square == -6 && end_square == -4)) {
            if (end_file == 0) {
                std::cout << "Queenside castle" << std::endl;
            } else if (end_file == 7) {
                std::cout << "Kingside castle" << std::endl;
            } else {
                std::cout << "Invalid castle" << std::endl;
            }
        } else {
            std::cout << piece_names.at(std::abs(start_square));
            std::cout << " from " << fileletters.at(start_file) << start_rank + 1 << " to " << fileletters.at(end_file) << end_rank + 1;
            if (promotion_piece != 0) {
                std::cout << " promote to " << piece_names.at(std::abs(end_square));
            }
        }
    }
};