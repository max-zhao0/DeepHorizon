#pragma once

#include <array>

struct Board {
    std::array<std::array<int, 8>, 8> squares;
    std::array<std::array<bool, 2>, 2> castling_rights;
    std::array<int, 2> enpassant_rights;
    int side_to_move;

    Board(
        std::array<std::array<int, 8>, 8>& in_squares,
        std::array<std::array<bool, 2>, 2>& in_castling_rights,
        std::array<int, 2>& in_enpassant_rights,
        int in_side_to_move
    ) {
        squares = in_squares;
        castling_rights = in_castling_rights;
        enpassant_rights = in_enpassant_rights;
        side_to_move = in_side_to_move;
    }

    Board() {};
};