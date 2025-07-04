#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
#include <set>

using namespace std;

struct Move {
    int column;
    int rotation;
    int score;
};

vector<int> get_colors(vector<string> &board, int col) {
  vector<int> res;
  char prev_color = '.';  // Initialize with empty space
  for (int i = 0; i < 12; ++i) {
    if (board[i][col] != prev_color && board[i][col] != '.' && board[i][col] != '0') {
      res.push_back(board[i][col] - '0');  // Convert char to int
      prev_color = board[i][col];
    }
  }
  return res;
}


vector<string> place_peice(vector<string> board, char col, char rot, char colorA, char colorB) {
  vector<string> result = board;
  int column = col - '0';  // Convert char to int

  // Find the first empty position from bottom
  int empty_row = -1;
  for (int i = 11; i >= 0; --i) {
    if (board[i][column] == '.') {
      empty_row = i;
      break;
    }
  }

  // If no empty position found in the main column, the move is invalid
  if (empty_row == -1) {
    result[0][0] = 'x';
    return result;
  }

  // Place blocks based on rotation
  switch (rot) {
    case '0': {  // Horizontal placement, colorA at (x), colorB at (x+1)
      if (column >= 5 || board[empty_row][column+1] != '.') { result[0][0] = 'x'; return result; }
      result[empty_row][column] = colorA;
      result[empty_row][column+1] = colorB;
      break;
    }
    case '1': {  // Vertical placement, colorB on top of colorA at (x)
      if (empty_row < 1) { result[0][0] = 'x'; return result; }
      result[empty_row][column] = colorA;
      result[empty_row-1][column] = colorB;
      break;
    }
    case '2': {  // Horizontal placement, colorA at (x), colorB at (x-1)
      if (column <= 0 || board[empty_row][column-1] != '.') { result[0][0] = 'x'; return result; }
      result[empty_row][column] = colorA;
      result[empty_row][column-1] = colorB;
      break;
    }
    case '3': {  // Vertical placement, colorA on top of colorB at (x)
      if (empty_row < 1) { result[0][0] = 'x'; return result; }
      result[empty_row][column] = colorB;
      result[empty_row-1][column] = colorA;
      break;
    }
  }
  return result;
}


pair<vector<string>, int> eliminate(vector<string> board) {
    int rows = 12, cols = 6;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<bool>> to_remove(rows, vector<bool>(cols, false));
    vector<int> group_sizes;
    set<int> colors_cleared;
    int total_blocks_cleared = 0;
    int GB = 0; // Group Bonus
    int CB = 0; // Color Bonus
    int CP = 0; // Chain Power (handled in process, so 0 here)
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // Step 1: Find and mark colored block groups of 4+
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            char color = board[r][c];
            if (color >= '1' && color <= '5' && !visited[r][c]) {
                // BFS to find group
                vector<pair<int, int>> group;
                queue<pair<int, int>> q;
                q.push({r, c});
                visited[r][c] = true;
                while (!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    group.push_back({cr, cc});
                    for (int d = 0; d < 4; ++d) {
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] && board[nr][nc] == color) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                if (group.size() >= 4) {
                    // Mark for removal
                    for (auto [gr, gc] : group) {
                        to_remove[gr][gc] = true;
                    }
                    group_sizes.push_back(group.size());
                    colors_cleared.insert(color - '0');
                    total_blocks_cleared += group.size();
                }
            }
        }
    }

    // Step 2: Mark skulls adjacent to the exploding color groups
    vector<vector<bool>> initial_to_remove = to_remove; // Copy the initially marked blocks
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (initial_to_remove[r][c]) { // Check only blocks from the original color groups
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    // If a neighbor is a skull, mark it for removal
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == '0') {
                        to_remove[nr][nc] = true;
                    }
                }
            }
        }
    }


    // Step 3: Remove all marked blocks (colors and skulls)
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (to_remove[r][c]) {
                board[r][c] = '.';
            }
        }
    }

    // Step 4: Calculate score (based only on colored blocks, unchanged)
    for (int sz : group_sizes) {
        if (sz == 4) GB += 0;
        else if (sz == 5) GB += 1;
        else if (sz == 6) GB += 2;
        else if (sz == 7) GB += 3;
        else if (sz == 8) GB += 4;
        else if (sz == 9) GB += 5;
        else if (sz == 10) GB += 6;
        else if (sz >= 11) GB += 8;
    }

    // Color Bonus (CB)
    if (colors_cleared.size() == 1) CB = 0;
    else if (colors_cleared.size() == 2) CB = 2;
    else if (colors_cleared.size() == 3) CB = 4;
    else if (colors_cleared.size() == 4) CB = 8;
    else if (colors_cleared.size() == 5) CB = 16;

    int bonus = CP + CB + GB;
    if (bonus < 1) bonus = 1;
    if (bonus > 999) bonus = 999;
    int score = (10 * total_blocks_cleared) * bonus;

    return {board, score};
}

vector<string> fall(vector<string> board) {
    int rows = 12, cols = 6;
    for (int c = 0; c < cols; ++c) { // each column
        int write_row = rows - 1; // start at top row
        for (int r = rows - 1; r >= 0; --r) { // drop the block one row at a time
            if (board[r][c] != '.') { // colored block found
                board[write_row][c] = board[r][c]; // drop the block
                if (write_row != r) {
                    board[r][c] = '.';
                }
                --write_row;
            }
        }
        // Fill the rest with '.' if any
        for (int r = write_row; r >= 0; --r) {
            board[r][c] = '.';
        }
    }
    return board;
}


pair<vector<string>, int> process(vector<string> board) {
  int total_score = 0;
  int prev_score = -1;
  vector<string> ret_board = board;
  while (total_score != prev_score) {
    prev_score = total_score;
    auto [v, i] = eliminate(ret_board);
    total_score += i;
    ret_board = fall(v);
  }
  return {ret_board, total_score};
}

double estimate_chain_potential(const vector<string>& board) {
    int rows = 12, cols = 6;
    double potential = 0.0;
    // For each cell, look for clusters of 2 or 3 same-colored blocks with adjacent empty space
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            char color = board[r][c];
            if (color < '1' || color > '5') continue;
            // Count adjacent same-color blocks
            int same_adj = 0;
            int empty_adj = 0;
            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (board[nr][nc] == color) same_adj++;
                    if (board[nr][nc] == '.') empty_adj++;
                }
            }
            // Reward for being part of a pair or triplet with empty space nearby
            if (same_adj == 1 && empty_adj >= 1) potential += 1.0; // pair with space
            if (same_adj == 2 && empty_adj >= 1) potential += 2.5; // triplet with space
            if (same_adj == 3 && empty_adj >= 1) potential += 5.0; // almost a group of 4
        }
    }
    return potential;
}

double evaluate_board(const vector<string>& board) {
    double height_penalty = 0;
    double adjacency_bonus = 0;
    double hole_penalty = 0;
    int column_heights[6] = {0};

    // Calculate column heights and hole penalty
    for (int c = 0; c < 6; ++c) {
        bool block_found = false;
        for (int r = 0; r < 12; ++r) {
            if (board[r][c] != '.') {
                if (!block_found) {
                    column_heights[c] = 12 - r;
                    block_found = true;
                }
            } else {
                if (block_found) {
                    hole_penalty++;
                }
            }
        }
        height_penalty += column_heights[c] * column_heights[c]; // Square height for a harsher penalty on tall towers
    }

    // Calculate adjacency bonus for setting up future groups
    for (int r = 0; r < 12; ++r) {
        for (int c = 0; c < 6; ++c) {
            if (board[r][c] >= '1' && board[r][c] <= '5') {
                // Check right neighbor
                if (c + 1 < 6 && board[r][c] == board[r][c+1]) {
                    adjacency_bonus++;
                }
                // Check bottom neighbor
                if (r + 1 < 12 && board[r][c] == board[r+1][c]) {
                    adjacency_bonus++;
                }
            }
        }
    }

    double chain_potential = estimate_chain_potential(board);

    // New: stack bonus for vertical and horizontal stacks
    double stack_bonus = 0;
    for (int c = 0; c < 6; ++c) {
        for (int r = 0; r < 11; ++r) {
            if (board[r][c] >= '1' && board[r][c] <= '5' &&
                board[r+1][c] == board[r][c]) {
                stack_bonus += 3.0; // vertical stack
            }
        }
    }
    for (int r = 0; r < 12; ++r) {
        for (int c = 0; c < 5; ++c) {
            if (board[r][c] >= '1' && board[r][c] <= '5' &&
                board[r][c+1] == board[r][c]) {
                stack_bonus += 2.0; // horizontal stack
            }
        }
    }

    // Heuristic weights - AGGRESSIVE grouping
    const double W_ADJ = 10.0;
    const double W_HEIGHT = 2.0;
    const double W_HOLE = 10.0;
    const double W_CHAIN = 30.0;
    const double W_STACK = 20.0;

    return (adjacency_bonus * W_ADJ)
         - (height_penalty * W_HEIGHT)
         - (hole_penalty * W_HOLE)
         + (chain_potential * W_CHAIN)
         + (stack_bonus * W_STACK);
}

pair<vector<string>,int> simulate_move(vector<string> board, char col, char rot, char colorA, char colorB) {
  return process(place_peice(board, col, rot, colorA, colorB));
}

void print_board_debug(const vector<string>& board, const string& label = "DEBUG BOARD") {
    cerr << "==== " << label << " (TOP is row 0, BOTTOM is row 11) ====" << endl;
    for (int r = 0; r < 12; ++r) {
        cerr << "[" << r << "] " << board[r] << endl;
    }
    cerr << "==== END BOARD ====" << endl;
}

Move find_best_move_2ply(
    const vector<string>& board,
    int colorA1, int colorB1, // first piece
    int colorA2, int colorB2  // second piece
) {
    double best_eval = -1e9; // Use double for evaluation
    Move best_move = {0, 0, 0};

    for (int col1 = 0; col1 < 6; ++col1) { // try each column
        for (int rot1 = 0; rot1 < 4; ++rot1) { // for each rotation
            // Skip impossible placements for horizontal pieces
            if ((rot1 == 0 && col1 == 5) || // rotation 0: can't place at col 5
                (rot1 == 2 && col1 == 0) || // rotation 2: can't place at col 0
                (rot1 == 1 && col1 >= 6) || // rotation 1: all columns valid, but keep for clarity
                (rot1 == 3 && col1 >= 6))   // rotation 3: all columns valid, but keep for clarity
                continue;
            if ((rot1 == 1 && col1 >= 5) || (rot1 == 3 && col1 <= 0)) continue; // existing checks
            // Simulate first move
            auto [board1, score1] = simulate_move(board, '0' + col1, '0' + rot1, '0' + colorA1, '0' + colorB1);

            if (board1[0][0] == 'x') {
                cerr << "Invalid move: col1=" << col1 << " rot1=" << rot1 << endl;
                continue;
            }

            // Now, for each possible second move
            double best_second_eval = -1e9;
            bool possible_second_move = false;
            for (int col2 = 0; col2 < 6; ++col2) {
                for (int rot2 = 0; rot2 < 4; ++rot2) {
                    // Skip impossible placements for horizontal pieces
                    if ((rot2 == 1 && col2 >= 5) || (rot2 == 3 && col2 <= 0)) continue;
                    auto [board2, score2] = simulate_move(board1, '0' + col2, '0' + rot2, '0' + colorA2, '0' + colorB2);

                    if (board2[0][0] == 'x') continue; // Skip invalid moves
                    possible_second_move = true;

                    const double W_SCORE = 20.0;
                    double board_eval = evaluate_board(board2);
                    double total_eval = (score1 * W_SCORE) + (score2 * W_SCORE) + board_eval;

                    if (total_eval > best_second_eval) {
                        best_second_eval = total_eval;
                    }
                }
            }

            double final_eval_for_move = 0;
            if (possible_second_move) {
                final_eval_for_move = best_second_eval;
            } else {
                // If no second move is possible, the first move leads to a loss. Penalize heavily.
                // We still evaluate the board state, as some losing states are better than others.
                const double W_SCORE = 20.0;
                final_eval_for_move = (score1 * W_SCORE) + evaluate_board(board1) - 1e7; // Huge penalty for losing
            }

            if (final_eval_for_move > best_eval) {
                best_eval = final_eval_for_move;
                best_move = {col1, rot1, (int)best_eval};
            }
        }
    }
    return best_move;
}




int main()
{
    vector<string> board(12);  // Initialize with 12 empty strings

    // game loop
    while (1) {
        // Read the next 8 pieces (4 for you, 4 for opponent)
        int my_colors[8][2];
        for (int i = 0; i < 8; i++) {
            int color_a; // color of the first block
            int color_b; // color of the attached block
            cin >> color_a >> color_b; cin.ignore();
            my_colors[i][0] = color_a;
            my_colors[i][1] = color_b;
        }
        int score_1;
        cin >> score_1; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row;
            cin >> row; cin.ignore();
            board[i] = row;
        }
        int score_2;
        cin >> score_2; cin.ignore();

        // Read opponent's board (12 rows)
        for (int i = 0; i < 12; i++) {
            string row;
            cin >> row; cin.ignore();
        }
        // Debug: print the board after reading
        for (int i = 0; i < 12; i++) {
            cerr << "board[" << i << "] = " << board[i] << endl;
        }

        // DEBUG: Print the board after simulating a single move (col=2, rot=0, with first piece)
       // auto [test_board, test_score] = simulate_move(board, '2', '0', '0' + my_colors[0][0], '0' + my_colors[0][1]);
       // print_board_debug(test_board, "After simulating move col=2 rot=0");

        // 2-ply lookahead: use the first two pieces for you
        int colorA1 = my_colors[0][0];
        int colorB1 = my_colors[0][1];
        int colorA2 = my_colors[1][0];
        int colorB2 = my_colors[1][1];
        Move best = find_best_move_2ply(board, colorA1, colorB1, colorA2, colorB2);
        // Debug: print the best move found
        cerr << "Best move: col=" << best.column << " rot=" << best.rotation << " score=" << best.score << endl;
        // Output the best move (column and rotation)
        cout << best.column << " " << best.rotation << endl;
    }
}