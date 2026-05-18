#include <gtk/gtk.h>
#include "game.h"
#include"globals.h"
void pawn_moves_black(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;

    // First move: can move two spaces forward
    if (x == 6) {
        if (strcmp(h[x-1][y], "") == 0) {
            possible_moves[num_possible_moves][0] = x-1;
            possible_moves[num_possible_moves][1] = y;
            num_possible_moves++;
            if (strcmp(h[x-2][y], "") == 0) {
                possible_moves[num_possible_moves][0] = x-2;
                possible_moves[num_possible_moves][1] = y;
                num_possible_moves++;
            }
        }
    }
    // Regular move: one space forward
    if (x > 0 && strcmp(h[x-1][y], "") == 0) {
        possible_moves[num_possible_moves][0] = x-1;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
    }
    // Capturing moves
    if (x > 0 && y > 0 && (strcmp(h[x-1][y-1], "") != 0 && h[x-1][y-1][0] >= 'a' && h[x-1][y-1][0] <= 'z')) {
        possible_moves[num_possible_moves][0] = x-1;
        possible_moves[num_possible_moves][1] = y-1;
        num_possible_moves++;
    }
    if (x > 0 && y < 7 && (strcmp(h[x-1][y+1], "") != 0 && h[x-1][y+1][0] >= 'a' && h[x-1][y+1][0] <= 'z')) {
        possible_moves[num_possible_moves][0] = x-1;
        possible_moves[num_possible_moves][1] = y+1;
        num_possible_moves++;
    }
}
void pawn_moves_white(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;

    // First move: can move two spaces forward
    if (x == 1) {
        if (strcmp(h[x+1][y], "") == 0) {
            possible_moves[num_possible_moves][0] = x+1;
            possible_moves[num_possible_moves][1] = y;
            num_possible_moves++;
            if (strcmp(h[x+2][y], "") == 0) {
                possible_moves[num_possible_moves][0] = x+2;
                possible_moves[num_possible_moves][1] = y;
                num_possible_moves++;
            }
        }
    }
    // Regular move: one space forward
    if (x < 7 && strcmp(h[x+1][y], "") == 0) {
        possible_moves[num_possible_moves][0] = x+1;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
    }
    // Capturing moves
    if (x < 7 && y > 0 && (strcmp(h[x+1][y-1], "") != 0 && h[x+1][y-1][0] >= 'A' && h[x+1][y-1][0] <= 'Z')) {
        possible_moves[num_possible_moves][0] = x+1;
        possible_moves[num_possible_moves][1] = y-1;
        num_possible_moves++;
    }
    if (x < 7 && y < 7 && (strcmp(h[x+1][y+1], "") != 0 && h[x+1][y+1][0] >= 'A' && h[x+1][y+1][0] <= 'Z')) {
        possible_moves[num_possible_moves][0] = x+1;
        possible_moves[num_possible_moves][1] = y+1;
        num_possible_moves++;
    }
}
void rook_moves_white(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;
        
    // Down
    for (int i = x + 1; i < 8; i++) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'a' && h[i][y][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
    // Up
    for (int i = x - 1; i >= 0; i--) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'a' && h[i][y][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
    // Right
    for (int i = y + 1; i < 8; i++) {
        if (strcmp(h[x][i], "") != 0 && (h[x][i][0] >= 'a' && h[x][i][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = i;
        num_possible_moves++;
        if (h[x][i][0] >= 'A' && h[x][i][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
    // Left
    for (int i = y - 1; i >= 0; i--) {
        if (strcmp(h[x][i], "") != 0 && (h[x][i][0] >= 'a' && h[x][i][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = i;
        num_possible_moves++;
        if (h[x][i][0] >= 'A' && h[x][i][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
}
void rook_moves_black(int x, int y, char* h[8][8]) {
    num_possible_moves = 0; // Reset possible moves count

    // Down
    for (int i = x + 1; i < 8; i++) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'a' && h[i][y][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Up
    for (int i = x - 1; i >= 0; i--) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'a' && h[i][y][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Right
    for (int i = y + 1; i < 8; i++) {
        if (strcmp(h[x][i], "") != 0 && (h[x][i][0] >= 'A' && h[x][i][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = i;
        num_possible_moves++;
        if (h[x][i][0] >= 'a' && h[x][i][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Left
    for (int i = y - 1; i >= 0; i--) {
        if (strcmp(h[x][i], "") != 0 && (h[x][i][0] >= 'A' && h[x][i][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = i;
        num_possible_moves++;
        if (h[x][i][0] >= 'a' && h[x][i][0] <= 'z') break; // Stop if capturing an opponent piece
    }
}
void king_moves_black(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;
    
    // Up
    if (x > 0) {
        if (strcmp(h[x-1][y],"") == 0 || (h[x-1][y][0] >= 'a' && h[x-1][y][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x - 1;
            possible_moves[num_possible_moves][1] = y;
            num_possible_moves++;
        }
    }
    // Down
    if (x < 7) {
        if (strcmp(h[x+1][y],"") == 0 || (h[x+1][y][0] >= 'a' && h[x+1][y][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x + 1;
            possible_moves[num_possible_moves][1] = y;
            num_possible_moves++;
        }
    }
    // Right
    if (y < 7) {
        if (strcmp(h[x][y+1],"") == 0 || (h[x][y+1][0] >= 'a' && h[x][y+1][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x;
            possible_moves[num_possible_moves][1] = y + 1;
            num_possible_moves++;
        }
    }
    // Left
    if (y > 0) {
        if (strcmp(h[x][y-1],"") == 0 || (h[x][y-1][0] >= 'a' && h[x][y-1][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x;
            possible_moves[num_possible_moves][1] = y - 1;
            num_possible_moves++;
        }
    }
    // Up-left diagonal
    if (x > 0 && y > 0) {
        if (strcmp(h[x-1][y-1],"") == 0 || (h[x-1][y-1][0] >= 'a' && h[x-1][y-1][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x - 1;
            possible_moves[num_possible_moves][1] = y - 1;
            num_possible_moves++;
        }
    }
    // Down-left diagonal
    if (x < 7 && y > 0) {
        if (strcmp(h[x+1][y-1],"") == 0 || (h[x+1][y-1][0] >= 'a' && h[x+1][y-1][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x + 1;
            possible_moves[num_possible_moves][1] = y - 1;
            num_possible_moves++;
        }
    }
    // Up-right diagonal
    if (x > 0 && y < 7) {
        if (strcmp(h[x-1][y+1],"") == 0 || (h[x-1][y+1][0] >= 'a' && h[x-1][y+1][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x - 1;
            possible_moves[num_possible_moves][1] = y + 1;
            num_possible_moves++;
        }
    }
    // Down-right diagonal
    if (x < 7 && y < 7) {
        if (strcmp(h[x+1][y+1],"") == 0 || (h[x+1][y+1][0] >= 'a' && h[x+1][y+1][0] <= 'z')) {
            possible_moves[num_possible_moves][0] = x + 1;
            possible_moves[num_possible_moves][1] = y + 1;
            num_possible_moves++;
        }
    }
}
void king_moves_white(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;
    
    // Up
    if (x > 0) {
        if (strcmp(h[x-1][y],"") == 0 || (h[x-1][y][0] >= 'A' && h[x-1][y][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x - 1;
            possible_moves[num_possible_moves][1] = y;
            num_possible_moves++;
        }
    }
    // Down
    if (x < 7) {
        if (strcmp(h[x+1][y],"") == 0 || (h[x+1][y][0] >= 'A' && h[x+1][y][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x + 1;
            possible_moves[num_possible_moves][1] = y;
            num_possible_moves++;
        }
    }
    // Right
    if (y < 7) {
        if (strcmp(h[x][y+1],"") == 0 || (h[x][y+1][0] >= 'A' && h[x][y+1][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x;
            possible_moves[num_possible_moves][1] = y + 1;
            num_possible_moves++;
        }
    }
    // Left
    if (y > 0) {
        if (strcmp(h[x][y-1],"") == 0 || (h[x][y-1][0] >= 'A' && h[x][y-1][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x;
            possible_moves[num_possible_moves][1] = y - 1;
            num_possible_moves++;
        }
    }
    // Up-left diagonal
    if (x > 0 && y > 0) {
        if (strcmp(h[x-1][y-1],"") == 0 || (h[x-1][y-1][0] >= 'A' && h[x-1][y-1][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x - 1;
            possible_moves[num_possible_moves][1] = y - 1;
            num_possible_moves++;
        }
    }
    // Down-left diagonal
    if (x < 7 && y > 0) {
        if (strcmp(h[x+1][y-1],"") == 0 || (h[x+1][y-1][0] >= 'A' && h[x+1][y-1][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x + 1;
            possible_moves[num_possible_moves][1] = y - 1;
            num_possible_moves++;
        }
    }
    // Up-right diagonal
    if (x > 0 && y < 7) {
        if (strcmp(h[x-1][y+1],"") == 0 || (h[x-1][y+1][0] >= 'A' && h[x-1][y+1][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x - 1;
            possible_moves[num_possible_moves][1] = y + 1;
            num_possible_moves++;
        }
    }
    // Down-right diagonal
    if (x < 7 && y < 7) {
        if (strcmp(h[x+1][y+1],"") == 0 || (h[x+1][y+1][0] >= 'A' && h[x+1][y+1][0] <= 'Z')) {
            possible_moves[num_possible_moves][0] = x + 1;
            possible_moves[num_possible_moves][1] = y + 1;
            num_possible_moves++;
        }
    }
}
void knight_moves_black(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;

    // Move options for a knight (L-shaped moves)

    // Up 2, Right 1
    if (x - 2 >= 0 && y + 1 < 8 && (strcmp(h[x-2][y+1],"") == 0 || (h[x-2][y+1][0] >= 'a' && h[x-2][y+1][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x - 2;
        possible_moves[num_possible_moves][1] = y + 1;
        num_possible_moves++;
    }
    // Up 2, Left 1
    if (x - 2 >= 0 && y - 1 >= 0 && (strcmp(h[x-2][y-1],"") == 0 || (h[x-2][y-1][0] >= 'a' && h[x-2][y-1][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x - 2;
        possible_moves[num_possible_moves][1] = y - 1;
        num_possible_moves++;
    }
    // Up 1, Right 2
    if (x - 1 >= 0 && y + 2 < 8 && (strcmp(h[x-1][y+2],"") == 0 || (h[x-1][y+2][0] >= 'a' && h[x-1][y+2][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x - 1;
        possible_moves[num_possible_moves][1] = y + 2;
        num_possible_moves++;
    }
    // Up 1, Left 2
    if (x - 1 >= 0 && y - 2 >= 0 && (strcmp(h[x-1][y-2],"") == 0 || (h[x-1][y-2][0] >= 'a' && h[x-1][y-2][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x - 1;
        possible_moves[num_possible_moves][1] = y - 2;
        num_possible_moves++;
    }
    // Down 2, Right 1
    if (x + 2 < 8 && y + 1 < 8 && (strcmp(h[x+2][y+1],"") == 0 || (h[x+2][y+1][0] >= 'a' && h[x+2][y+1][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x + 2;
        possible_moves[num_possible_moves][1] = y + 1;
        num_possible_moves++;
    }
    // Down 2, Left 1
    if (x + 2 < 8 && y - 1 >= 0 && (strcmp(h[x+2][y-1],"") == 0 || (h[x+2][y-1][0] >= 'a' && h[x+2][y-1][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x + 2;
        possible_moves[num_possible_moves][1] = y - 1;
        num_possible_moves++;
    }
    // Down 1, Right 2
    if (x + 1 < 8 && y + 2 < 8 && (strcmp(h[x+1][y+2],"") == 0 || (h[x+1][y+2][0] >= 'a' && h[x+1][y+2][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x + 1;
        possible_moves[num_possible_moves][1] = y + 2;
        num_possible_moves++;
    }
    // Down 1, Left 2
    if (x + 1 < 8 && y - 2 >= 0 && (strcmp(h[x+1][y-2],"") == 0 || (h[x+1][y-2][0] >= 'a' && h[x+1][y-2][0] <= 'z'))) {
        possible_moves[num_possible_moves][0] = x + 1;
        possible_moves[num_possible_moves][1] = y - 2;
        num_possible_moves++;
    }
}
void knight_moves_white(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;
    
    // Up 2, Right 1
    if (x - 2 >= 0 && y + 1 < 8 && (strcmp(h[x-2][y+1],"") == 0 || (h[x-2][y+1][0] >= 'A' && h[x-2][y+1][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x - 2;
        possible_moves[num_possible_moves][1] = y + 1;
        num_possible_moves++;
    }
    // Up 2, Left 1
    if (x - 2 >= 0 && y - 1 >= 0 && (strcmp(h[x-2][y-1],"") == 0 || (h[x-2][y-1][0] >= 'A' && h[x-2][y-1][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x - 2;
        possible_moves[num_possible_moves][1] = y - 1;
        num_possible_moves++;
    }
    // Up 1, Right 2
    if (x - 1 >= 0 && y + 2 < 8 && (strcmp(h[x-1][y+2],"") == 0 || (h[x-1][y+2][0] >= 'A' && h[x-1][y+2][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x - 1;
        possible_moves[num_possible_moves][1] = y + 2;
        num_possible_moves++;
    }
    // Up 1, Left 2
    if (x - 1 >= 0 && y - 2 >= 0 && (strcmp(h[x-1][y-2],"") == 0 || (h[x-1][y-2][0] >= 'A' && h[x-1][y-2][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x - 1;
        possible_moves[num_possible_moves][1] = y - 2;
        num_possible_moves++;
    }
    // Down 2, Right 1
    if (x + 2 < 8 && y + 1 < 8 && (strcmp(h[x+2][y+1],"") == 0 || (h[x+2][y+1][0] >= 'A' && h[x+2][y+1][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x + 2;
        possible_moves[num_possible_moves][1] = y + 1;
        num_possible_moves++;
    }
    // Down 2, Left 1
    if (x + 2 < 8 && y - 1 >= 0 && (strcmp(h[x+2][y-1],"") == 0 || (h[x+2][y-1][0] >= 'A' && h[x+2][y-1][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x + 2;
        possible_moves[num_possible_moves][1] = y - 1;
        num_possible_moves++;
    }
    // Down 1, Right 2
    if (x + 1 < 8 && y + 2 < 8 && (strcmp(h[x+1][y+2],"") == 0 || (h[x+1][y+2][0] >= 'A' && h[x+1][y+2][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x + 1;
        possible_moves[num_possible_moves][1] = y + 2;
        num_possible_moves++;
    }
    // Down 1, Left 2
    if (x + 1 < 8 && y - 2 >= 0 && (strcmp(h[x+1][y-2],"") == 0 || (h[x+1][y-2][0] >= 'A' && h[x+1][y-2][0] <= 'Z'))) {
        possible_moves[num_possible_moves][0] = x + 1;
        possible_moves[num_possible_moves][1] = y - 2;
        num_possible_moves++;
    }
}
void bishop_moves_black(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;

    // Down-right
    for (int i = x + 1, j = y + 1; i <= 7 && j <= 7; i++, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Down-left
    for (int i = x + 1, j = y - 1; i <= 7 && j >= 0; i++, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Up-right
    for (int i = x - 1, j = y + 1; i >= 0 && j <= 7; i--, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Up-left
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
}
void bishop_moves_white(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;

    // Down-right
    for (int i = x + 1, j = y + 1; i <= 7 && j <= 7; i++, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
    // Down-left
    for (int i = x + 1, j = y - 1; i <= 7 && j >= 0; i++, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
    // Up-right
    for (int i = x - 1, j = y + 1; i >= 0 && j <= 7; i--, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
    // Up-left
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break; // Stop if capturing an opponent piece
    }
}
void queen_moves_white(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;
    
    // Diagonal moves
    
    // Down-right
    for (int i = x + 1, j = y + 1; i <= 7 && j <= 7; i++, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break; 
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break;
    }
    // Down-left
    for (int i = x + 1, j = y - 1; i <= 7 && j >= 0; i++, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break;
    }
    // Up-right
    for (int i = x - 1, j = y + 1; i >= 0 && j <= 7; i--, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break;
    }
    // Up-left
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'a' && h[i][j][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z') break;
    }

    // Straight-line moves

    // Down
    for (int i = x + 1; i <= 7; i++) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'a' && h[i][y][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z') break;
    }
    // Up
    for (int i = x - 1; i >= 0; i--) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'a' && h[i][y][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z') break;
    }
    // Right
    for (int j = y + 1; j <= 7; j++) {
        if (strcmp(h[x][j], "") != 0 && (h[x][j][0] >= 'a' && h[x][j][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[x][j][0] >= 'A' && h[x][j][0] <= 'Z') break;
    }
    // Left
    for (int j = y - 1; j >= 0; j--) {
        if (strcmp(h[x][j], "") != 0 && (h[x][j][0] >= 'a' && h[x][j][0] <= 'z')) break;
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[x][j][0] >= 'A' && h[x][j][0] <= 'Z') break;
    }
}
void queen_moves_black(int x, int y, char* h[8][8]) {
    num_possible_moves = 0;
    
    // Diagonal moves
    
    // Down-right
    for (int i = x + 1, j = y + 1; i <= 7 && j <= 7; i++, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Down-left
    for (int i = x + 1, j = y - 1; i <= 7 && j >= 0; i++, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Up-right
    for (int i = x - 1, j = y + 1; i >= 0 && j <= 7; i--, j++) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Up-left
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (strcmp(h[i][j], "") != 0 && (h[i][j][0] >= 'A' && h[i][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[i][j][0] >= 'a' && h[i][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }

    // Straight-line moves

    // Down
    for (int i = x + 1; i <= 7; i++) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'a' && h[i][y][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Up
    for (int i = x - 1; i >= 0; i--) {
        if (strcmp(h[i][y], "") != 0 && (h[i][y][0] >= 'A' && h[i][y][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = i;
        possible_moves[num_possible_moves][1] = y;
        num_possible_moves++;
        if (h[i][y][0] >= 'a' && h[i][y][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Right
    for (int j = y + 1; j <= 7; j++) {
        if (strcmp(h[x][j], "") != 0 && (h[x][j][0] >= 'A' && h[x][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[x][j][0] >= 'a' && h[x][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
    // Left
    for (int j = y - 1; j >= 0; j--) {
        if (strcmp(h[x][j], "") != 0 && (h[x][j][0] >= 'A' && h[x][j][0] <= 'Z')) break; // Stop if own piece
        possible_moves[num_possible_moves][0] = x;
        possible_moves[num_possible_moves][1] = j;
        num_possible_moves++;
        if (h[x][j][0] >= 'a' && h[x][j][0] <= 'z') break; // Stop if capturing an opponent piece
    }
}
void filter_invalid_moves_black(int x,int y,char* h[8][8]){
    int num_valid_moves=0,valid_moves[100][2];
    char* temp[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                temp[i][j] = h[i][j];
            }
        }
    char* n="";
    int temp_num_possible_moves=num_possible_moves,temp_possible_moves[100][2];
    for(int i=0;i<temp_num_possible_moves;i++){
        temp_possible_moves[i][0]=possible_moves[i][0];
        temp_possible_moves[i][1]=possible_moves[i][1];
    }
    for(int i=0;i<temp_num_possible_moves;i++){
        char* t=temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]];
        temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]]=temp[x][y];
        temp[x][y]=n;
        printf("testing\n");
        if(check_black(temp)==1){
            valid_moves[num_valid_moves][0]=temp_possible_moves[i][0];
            valid_moves[num_valid_moves][1]=temp_possible_moves[i][1];
            num_valid_moves++;
            printf("valid moves updated");
        }
        temp[x][y] = temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]];
        temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]] = t;
        printf("testing done\n");
    }
    num_possible_moves=num_valid_moves;
    for(int i=0;i<num_valid_moves;i++){
        possible_moves[i][0]=valid_moves[i][0];
        possible_moves[i][1]=valid_moves[i][1];
    }
}
void filter_invalid_moves_white(int x,int y,char* h[8][8]){
    int num_valid_moves=0,valid_moves[100][2];
    char* temp[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                temp[i][j] = h[i][j];
            }
        }
    int temp_num_possible_moves=num_possible_moves,temp_possible_moves[100][2];
    for(int i=0;i<temp_num_possible_moves;i++){
        temp_possible_moves[i][0]=possible_moves[i][0];
        temp_possible_moves[i][1]=possible_moves[i][1];
    }
    for(int i=0;i<temp_num_possible_moves;i++){
        char* t=temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]];
        temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]]=temp[x][y];
        temp[x][y]="";
        printf("testing\n");
        if(check_white(temp)==1){
            valid_moves[num_valid_moves][0]=temp_possible_moves[i][0];
            valid_moves[num_valid_moves][1]=temp_possible_moves[i][1];
            num_valid_moves++;
            printf("valid moves updated");
        }
        temp[x][y] = temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]];
        temp[temp_possible_moves[i][0]][temp_possible_moves[i][1]] = t;
        printf("testing done\n");
    }
    num_possible_moves=num_valid_moves;
    for(int i=0;i<num_valid_moves;i++){
        possible_moves[i][0]=valid_moves[i][0];
        possible_moves[i][1]=valid_moves[i][1];
    }
}
int check_black(char*h[8][8]){
    int Ex , Ey;
    for(int i = 0 ; i<8 ; i++){
        for(int j = 0 ; j<8 ; j++){
            if(h[i][j][0] == 'E'){
                Ex = i ; 
                Ey = j;
                break;
            }
        }
    }
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(h[i][j][0] == 'b'){
                knight_moves_white(i,j,h);
                for(int k = 0;k<num_possible_moves;k++){
                    if(possible_moves[k][0] == Ex && possible_moves[k][1] == Ey){
                        return 0;
                    }
                }
           }
            if(h[i][j][0] == 'c'){
                bishop_moves_white(i,j,h);
                for(int k = 0;k<num_possible_moves;k++){
                    if(possible_moves[k][0] == Ex && possible_moves[k][1] == Ey){
                        return 0;
                    }
                }
           }
            if(h[i][j][0] == 'd'){
                queen_moves_white(i,j,h);
                for(int k = 0;k<num_possible_moves;k++){
                    if(possible_moves[k][0] == Ex && possible_moves[k][1] == Ey){
                        return 0;
                    }
                }
           }
            if(h[i][j][0] == 'a'){
                rook_moves_white(i,j,h);
                for(int k = 0;k<num_possible_moves;k++){
                    if(possible_moves[k][0] == Ex && possible_moves[k][1] == Ey){
                        return 0;
                    }
                }
           }
            if(h[i][j][0] == 'p'){
                pawn_moves_white(i,j,h);
                for(int k = 0;k<num_possible_moves;k++){
                    if(possible_moves[k][0] == Ex && possible_moves[k][1] == Ey){
                        return 0;
                    }
                }
           }
            if(h[i][j][0] == 'e'){
                king_moves_white(i,j,h);
                for(int k = 0;k<num_possible_moves;k++){
                    if(possible_moves[k][0] == Ex && possible_moves[k][1] == Ey){
                        return 0;
                    }
                }
           }
        
        }
    }
    return 1;
}
int check_white(char *h[8][8]) {
    int Ex, Ey;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (h[i][j][0] == 'e') {
                Ex = i;
                Ey = j;
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (h[i][j][0] == 'B') {
                knight_moves_black(i, j, h);
                for (int k = 0; k < num_possible_moves; k++) {
                    if (possible_moves[k][0] == Ex && possible_moves[k][1] == Ey) {
                        return 0;
                    }
                }
            } 
            else if (h[i][j][0] == 'C') {
                bishop_moves_black(i, j, h);
                for (int k = 0; k < num_possible_moves; k++) {
                    if (possible_moves[k][0] == Ex && possible_moves[k][1] == Ey) {
                        return 0;
                    }
                }
            }
            else if (h[i][j][0] == 'D') {
                queen_moves_black(i, j, h);
                for (int k = 0; k < num_possible_moves; k++) {
                    if (possible_moves[k][0] == Ex && possible_moves[k][1] == Ey) {
                        return 0;
                    }
                }
            } 
            else if (h[i][j][0] == 'A') {
                rook_moves_black(i, j, h);
                for (int k = 0; k < num_possible_moves; k++) {
                    if (possible_moves[k][0] == Ex && possible_moves[k][1] == Ey) {
                        return 0;
                    }
                }
            } 
            else if (h[i][j][0] == 'P') {
                pawn_moves_black(i, j, h);
                for (int k = 0; k < num_possible_moves; k++) {
                    if (possible_moves[k][0] == Ex && possible_moves[k][1] == Ey) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}
void random_move(int k, int s[][2]) {
    if (k > 0) {
        int randomR = rand() % k;
        bot_move_random[0] = s[randomR][0]; // Row of the new position
        bot_move_random[1] = s[randomR][1]; // Column of the new position
    }
}
void ai_random(char* h[8][8]) {
    int grid[2][2]={{-1,-1},{-1,-1}};
    int knight_grid[2][2]={{-1, -1}, {-1, -1}};
    int bishop_grid[2][2]={{-1, -1},{-1,-1}};
    int rook_grid[2][2]={{-1,-1},{-1,-1}};
    int pawn_grid[8][2]={{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
    int enemy_grid[16][2]={{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2},{-2,-2}};
    int p=0,r=0,b=0,k=0,piece_found = 0;
    int ep=0,er=0,eb=0,ek=0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(h[i][j][0]=='e'){enemy_grid[0][0]=i;enemy_grid[0][1]=j;}
            else if(h[i][j][0]=='d'){enemy_grid[1][0]=i;enemy_grid[1][1]=j;}
            else if(h[i][j][0]=='a'){enemy_grid[2+er][0]=i;enemy_grid[2+er][1]=j;er++;}
            else if(h[i][j][0]=='b'){enemy_grid[4+ek][0]=i;enemy_grid[4+ek][1]=j;ek++;}
            else if(h[i][j][0]=='c'){enemy_grid[6+eb][0]=i;enemy_grid[6+eb][1]=j;eb++;}
            else if(h[i][j][0]=='p'){enemy_grid[8+ep][0]=i;enemy_grid[8+ep][1]=j;ep++;}
            }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            random=1;
            if(h[i][j][0]=='P') {
                pawn_moves_black(i,j,h);
                filter_invalid_moves_black(i,j,h);
                for(int m=0;m<16;m++){
                    for(int n=0;n<num_possible_moves;n++){
                        if(enemy_grid[m][0]==possible_moves[n][0]&&enemy_grid[m][1]==possible_moves[n][1]){
                            bot_move_random[0]=possible_moves[n][0];x=i;
                            bot_move_random[1]=possible_moves[n][1];y=j;
                            random=0;
                            return;
                        }
                    }
                }
                if(num_possible_moves>0){
                    pawn_grid[p][0] = i;
                    pawn_grid[p][1] = j;
                    piece_found++;
                    p++;
                }
            }
            else if(h[i][j][0]=='A') {
                rook_moves_black(i,j,h);
                filter_invalid_moves_black(i,j,h);
                for(int m=0;m<16;m++){
                    for(int n=0;n<num_possible_moves;n++){
                        if(enemy_grid[m][0]==possible_moves[n][0]&&enemy_grid[m][1]==possible_moves[n][1]){
                            bot_move_random[0]=possible_moves[n][0];x=i;
                            bot_move_random[1]=possible_moves[n][1];y=j;
                            random=0;
                            return;
                        }
                    }
                }
                if(num_possible_moves>0){
                    rook_grid[r][0] = i;
                    rook_grid[r][1] = j;
                    piece_found++;
                    r++;
                }
            } 
            else if(h[i][j][0]=='B') {
                knight_moves_black(i,j,h);
                filter_invalid_moves_black(i,j,h);
                for(int m=0;m<16;m++){
                    for(int n=0;n<num_possible_moves;n++){
                        if(enemy_grid[m][0]==possible_moves[n][0]&&enemy_grid[m][1]==possible_moves[n][1]){
                            bot_move_random[0]=possible_moves[n][0];x=i;
                            bot_move_random[1]=possible_moves[n][1];y=j;
                            random=0;
                            return;
                        }
                    }
                }
                if(num_possible_moves>0){
                    knight_grid[k][0] = i;
                    knight_grid[k][1] = j;
                    piece_found++;
                    k++;
                }
            } 
            else if(h[i][j][0]=='C') {
                bishop_moves_black(i,j,h);
                filter_invalid_moves_black(i,j,h);
                for(int m=0;m<16;m++){
                    for(int n=0;n<num_possible_moves;n++){
                        if(enemy_grid[m][0]==possible_moves[n][0]&&enemy_grid[m][1]==possible_moves[n][1]){
                            bot_move_random[0]=possible_moves[n][0];x=grid[1][0];
                            bot_move_random[1]=possible_moves[n][1];y=grid[1][1];
                            random=0;
                            return;
                        }
                    }
                }
                if(num_possible_moves>0){
                    bishop_grid[b][0] = i;
                    bishop_grid[b][1] = j;
                    piece_found++;
                    b++;
                }
            } 
            else if(h[i][j][0]=='D') {
                queen_moves_black(i,j,h);
                filter_invalid_moves_black(i,j,h);
                for(int m=0;m<16;m++){
                    for(int n=0;n<num_possible_moves;n++){
                        if(enemy_grid[m][0]==possible_moves[n][0]&&enemy_grid[m][1]==possible_moves[n][1]){
                            bot_move_random[0]=possible_moves[n][0];x=i;
                            bot_move_random[1]=possible_moves[n][1];y=j;
                            random=0;
                            return;
                        }
                    }
                }
                if(num_possible_moves>0){
                    grid[3][0] = i;
                    grid[3][1] = j;
                    piece_found++;
                }
            } 
            else if(h[i][j][0]=='E') {
                king_moves_black(i,j,h);
                filter_invalid_moves_black(i,j,h);
                for(int m=0;m<16;m++){
                    for(int n=0;n<num_possible_moves;n++){
                        if(enemy_grid[m][0]==possible_moves[n][0]&&enemy_grid[m][1]==possible_moves[n][1]){
                            bot_move_random[0]=possible_moves[n][0];x=i;
                            bot_move_random[1]=possible_moves[n][1];y=j;
                            random=0;
                            return;
                        }
                    }
                }
                if(num_possible_moves>0){
                    grid[4][0] = i;
                    grid[4][1] = j;
                    piece_found++;
                }
            }
        }
    }
    if (piece_found > 0) {
        srand(time(NULL));       
            int count = rand()%16,c=0;
            switch (count) {
                case 0:
                    if (grid[1][0] != -1 && grid[1][1] != -1) {
                        x = grid[1][0];
                        y = grid[1][1];
                        return;
                    }
                case 1:
                    if (pawn_grid[1][0] != -1 && pawn_grid[1][1] != -1) {
                        x = pawn_grid[1][0];
                        y = pawn_grid[1][1];
                        return;
                    }
                case 2:
                    if (pawn_grid[2][0] != -1 && pawn_grid[2][1] != -1) {
                        x = pawn_grid[2][0];
                        y = pawn_grid[2][1];
                        return;
                    }
                case 3:
                    if (pawn_grid[3][0] != -1 && pawn_grid[3][1] != -1) {
                        x = pawn_grid[3][0];
                        y = pawn_grid[3][1];
                        return;
                    }
                case 4:
                    if (pawn_grid[4][0] != -1 && pawn_grid[4][1] != -1) {
                        x = pawn_grid[4][0];
                        y = pawn_grid[4][1];
                        return;
                    }
                case 5:
                    if (pawn_grid[5][0] != -1 && pawn_grid[5][1] != -1) {
                        x = pawn_grid[5][0];
                        y = pawn_grid[5][1];
                        return;
                    }
                case 6:
                    if (pawn_grid[6][0] != -1 && pawn_grid[6][1] != -1) {
                        x = pawn_grid[6][0];
                        y = pawn_grid[6][1];
                        return;
                    }
                case 7:
                    if (pawn_grid[7][0] != -1 && pawn_grid[7][1] != -1) {
                        x = pawn_grid[7][0];
                        y = pawn_grid[7][1];
                        return;
                    }
                case 8:
                    if (rook_grid[0][0] != -1 && rook_grid[0][1] != -1) {
                        x = rook_grid[0][0];
                        y = rook_grid[0][1];
                        return;
                    }
                case 9:
                    if (rook_grid[1][0] != -1 && rook_grid[1][1] != -1) {
                        x = rook_grid[1][0];
                        y = rook_grid[1][1];
                        return;
                    }
                case 10:
                    if (bishop_grid[0][0] != -1 && bishop_grid[0][1] != -1) {
                        x = bishop_grid[0][0];
                        y = bishop_grid[0][1];
                        return;
                    }
                case 11:
                    if (bishop_grid[1][0] != -1 && bishop_grid[1][1] != -1) {
                        x = bishop_grid[1][0];
                        y = bishop_grid[1][1];
                        return;
                    }
                case 12:
                    if (knight_grid[0][0] != -1 && knight_grid[0][1] != -1) {
                        x = knight_grid[0][0];
                        y = knight_grid[0][1];
                        return;
                    }
                case 13:
                    if (knight_grid[1][0] != -1 && knight_grid[1][1] != -1) {
                        x = knight_grid[1][0];
                        y = knight_grid[1][1];
                        return;
                    }
                case 14:
                    if (grid[0][0] != -1 && grid[0][1] != -1) {
                        x = grid[0][0];
                        y = grid[0][1];
                        return;
                    }
                case 15:
                    if (pawn_grid[0][0] != -1 && pawn_grid[0][1] != -1) {
                        x = pawn_grid[0][0];
                        y = pawn_grid[0][1];
                        return;
                    }
                default:
                    if (pawn_grid[1][0] != -1 && pawn_grid[1][1] != -1) {
                        x = pawn_grid[1][0];
                        y = pawn_grid[1][1];
                        return;
                    }
                    else if (pawn_grid[2][0] != -1 && pawn_grid[2][1] != -1) {
                        x = pawn_grid[2][0];
                        y = pawn_grid[2][1];
                        return;
                    }
                    else if (pawn_grid[3][0] != -1 && pawn_grid[3][1] != -1) {
                        x = pawn_grid[3][0];
                        y = pawn_grid[3][1];
                        return;
                    }
                    else if (pawn_grid[4][0] != -1 && pawn_grid[4][1] != -1) {
                        x = pawn_grid[4][0];
                        y = pawn_grid[4][1];
                        return;
                    }
                    else if (pawn_grid[5][0] != -1 && pawn_grid[5][1] != -1) {
                        x = pawn_grid[5][0];
                        y = pawn_grid[5][1];
                        return;
                    }
                    else if (pawn_grid[6][0] != -1 && pawn_grid[6][1] != -1) {
                        x = pawn_grid[6][0];
                        y = pawn_grid[6][1];
                        return;
                    }
                    else if (pawn_grid[7][0] != -1 && pawn_grid[7][1] != -1) {
                        x = pawn_grid[7][0];
                        y = pawn_grid[7][1];
                        return;
                    }
                    else if (rook_grid[0][0] != -1 && rook_grid[0][1] != -1) {
                        x = rook_grid[0][0];
                        y = rook_grid[0][1];
                        return;
                    }
                    else if (rook_grid[1][0] != -1 && rook_grid[1][1] != -1) {
                        x = rook_grid[1][0];
                        y = rook_grid[1][1];
                        return;
                    }
                    else if (bishop_grid[0][0] != -1 && bishop_grid[0][1] != -1) {
                        x = bishop_grid[0][0];
                        y = bishop_grid[0][1];
                        return;
                    }
                    else if (bishop_grid[1][0] != -1 && bishop_grid[1][1] != -1) {
                        x = bishop_grid[1][0];
                        y = bishop_grid[1][1];
                        return;
                    }
                    else if (knight_grid[0][0] != -1 && knight_grid[0][1] != -1) {
                        x = knight_grid[0][0];
                        y = knight_grid[0][1];
                        return;
                    }
                    else if (knight_grid[1][0] != -1 && knight_grid[1][1] != -1) {
                        x = knight_grid[1][0];
                        y = knight_grid[1][1];
                        return;
                    }
                    else if (grid[0][0] != -1 && grid[0][1] != -1) {
                        x = grid[0][0];
                        y = grid[0][1];
                        return;
                    }
                    else if (pawn_grid[0][0] != -1 && pawn_grid[0][1] != -1) {
                        x = pawn_grid[0][0];
                        y = pawn_grid[0][1];
                        return;
                    }
                    else if (grid[1][0] != -1 && grid[1][1] != -1) {
                        x = grid[1][0];
                        y = grid[1][1];
                        return;
                    }
            }
    }
}
int checkmate_black(char* h[8][8]){
    int total_moves_black=0;
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            if(h[x][y][0]=='P'){
                pawn_moves_black(x,y, chess_pieces);
                filter_invalid_moves_black(x,y,chess_pieces);
                total_moves_black+=num_possible_moves;}
            if(h[x][y][0]=='A'){
                rook_moves_black(x,y, chess_pieces);
                filter_invalid_moves_black(x,y,chess_pieces);
                total_moves_black+=num_possible_moves;}
            if(h[x][y][0]=='B'){
                knight_moves_black(x,y, chess_pieces);
                filter_invalid_moves_black(x,y,chess_pieces);    
                total_moves_black+=num_possible_moves;}
            if(h[x][y][0]=='C'){
                bishop_moves_black(x,y, chess_pieces);
                filter_invalid_moves_black(x,y,chess_pieces);
                total_moves_black+=num_possible_moves;}
            if(h[x][y][0]=='D'){
                queen_moves_black(x,y, chess_pieces);
                filter_invalid_moves_black(x,y,chess_pieces);
                total_moves_black+=num_possible_moves;}
            if(h[x][y][0]=='E'){
                king_moves_black(x,y, chess_pieces);
                filter_invalid_moves_black(x,y,chess_pieces);
                total_moves_black+=num_possible_moves;}
        }
    }
    
    if(total_moves_black==0) return 1;
    else return 0;
}
int checkmate_white(char* h[8][8]){
    int total_moves_white=0;
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            if(h[x][y][0]=='p'){
                pawn_moves_white(x,y, chess_pieces);
                filter_invalid_moves_white(x,y,chess_pieces);
                total_moves_white+=num_possible_moves;}
            if(h[x][y][0]=='a'){
                rook_moves_white(x,y,chess_pieces);
                filter_invalid_moves_white(x,y,chess_pieces);
                total_moves_white+=num_possible_moves;}
            if(h[x][y][0]=='b'){
                knight_moves_white(x,y,chess_pieces);
                filter_invalid_moves_white(x,y,chess_pieces);
                total_moves_white+=num_possible_moves;}
            if(h[x][y][0]=='c'){
                bishop_moves_white(x,y, chess_pieces);
                filter_invalid_moves_white(x,y,chess_pieces);
                total_moves_white+=num_possible_moves;}
            if(h[x][y][0]=='d'){
                queen_moves_white(x,y, chess_pieces);
                filter_invalid_moves_white(x,y,chess_pieces);
                total_moves_white+=num_possible_moves;}
            if(h[x][y][0]=='e'){
                king_moves_white(x,y,chess_pieces);
                filter_invalid_moves_white(x,y,chess_pieces);
                total_moves_white+=num_possible_moves;}
        }
    }
    
    if(total_moves_white==0) return 1;
    else return 0;
}
