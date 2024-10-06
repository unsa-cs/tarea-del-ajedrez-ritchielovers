#include "chess.h"
#include "figures.h"

void display() {
  // 0 = tablero, vacio
  // 1 = peon
  // 2 = caballo
  // 3 = alfil
  // 4 = torre
  // 5 = reina
  // 6 = rey
  int table[8][8] = {{4, 2, 3, 5, 6, 3, 2, 4}, {1, 1, 1, 1, 1, 1, 1, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 1, 1, 1, 1, 1}, {4, 2, 3, 5, 6, 3, 2, 4}};
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

      ficha = superImpose(fichas[table[i][j] - 1], ficha);

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
