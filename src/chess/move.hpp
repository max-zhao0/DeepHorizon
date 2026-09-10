#pragma once

struct Move {
    int start_file;
    int start_rank;
    int end_file;
    int end_rank;
    int promotion_piece;

    Move(int in_start_file, int in_start_rank, int in_end_file, int in_end_rank, int in_promotion_piece = 0) {
        start_file = in_start_file;
        start_rank = in_start_rank;
        end_file = in_end_file;
        end_rank = in_end_rank;
        promotion_piece = in_promotion_piece;
    }
};