#pragma once

#include <array>
#include <bitset>
#include <random>

#define ZOBRIST_SIZE 64

class Zobrist {
    private:
    std::mt19937 rng;

    std::array<std::array<std::array<std::bitset<ZOBRIST_SIZE>, 12>, 8>, 8> squares_hashes;
    std::array<std::array<std::bitset<ZOBRIST_SIZE>, 2>, 2> castling_rights_hashes;
    std::array<std::array<std::bitset<ZOBRIST_SIZE>, 8>, 2> enpassant_rights_hashes;
    std::bitset<ZOBRIST_SIZE> white_to_move_hash;

    std::bitset<ZOBRIST_SIZE> random_bitstring() {
        std::uniform_int_distribution<unsigned long long> dist64(0, 64);
    }

    public:
    Zobrist() {
        std::random_device dev;
        std::mt19937 new_rng(dev());
        rng = new_rng;
    }
};