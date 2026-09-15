#pragma once

#include <array>

class Zobrist {
    const static int size = 64;

    std::array<std::array<std::array<std::bitset<size>, 12>, 8>, 8> squares_hashes;
    std::array<std::array<std::bitset<size>, 2>, 2> castling_rights_hashes;
    std::array<std::array<std::bitset<size>, 8>, 2> enpassant_rights_hashes;
    std::bitset<size> white_to_move_hash;

    Zobrist() {

    }
};