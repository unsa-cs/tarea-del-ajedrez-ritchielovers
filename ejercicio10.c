#include "chess.h"
#include "figures.h"

void display() {
  // 0 = tablero, vacio
  // 1 = peon, -1 = peon negro
  // 2 = caballo, -2  = caballo negro
  // 3 = alfil, -3 = alfil negro
  // 4 = torre, -4 = torre negro
  // 5 = reina, -5 = reina negro
  // 6 = rey, -6 = rey negro
  int table[8][8] = {{0, 0, 0, 0, 0, 0, 0, 6},  {0, 0, 0, 0, -6, -1, 0, -1},
                     {0, 0, 4, 0, 0, 0, -1, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 1, 0, 0, 0, 0, 0, 0},  {0, -4, 3, 0, 0, 0, 0, 0}};
  char **fichas[6] = {pawn, knight, bishop, rook, queen, king};
  char **square;
  char **row;
  char **chess_table;
  char **ficha;

  for (int i = 0; i < 8; ++i) {
    if (i % 2 == 0) {
      square = reverse(whiteSquare);
    } else {
      square = whiteSquare;
    }
    for (int j = 0; j < 8; ++j) {
      if (j % 2 == 0) {
        ficha = square;
      } else {
        ficha = reverse(square);
      }

      if (table[i][j] < 0) {
        ficha = superImpose(reverse(fichas[(table[i][j] * -1) - 1]), ficha);
      } else {
        ficha = superImpose(fichas[table[i][j] - 1], ficha);
      }

      if (j == 0) {
        row = ficha;
      } else {
        row = join(row, ficha);
      }
    }
    if (i == 0) {
      chess_table = row;
    } else {
      chess_table = up(chess_table, row);
    }
  }

  interpreter(chess_table);
}
