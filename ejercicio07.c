#include "chess.h"
#include "figures.h"

void display() {
  char **_spwhite = whiteSquare;
  char **knight_ = superImpose(knight, reverse(_spwhite));
  char **_spblack = reverse(_spwhite);
  char **two_block = join(_spwhite, _spblack);
  char **fila = repeatH(two_block, 4);
  //Creacion de la fila con los caballos a sus extremos
  char **two_fila = up(reverse(fila), fila);
  char **knight_beside_spwhite = join(knight_, _spwhite);
  char **left_mid = join(knight_beside_spwhite, reverse(two_block));
  char **spblack_beside_knight = join(_spblack, rotateL(reverse(knight_)));
  char **right_mid = join(reverse(two_block), spblack_beside_knight);
  char **first_row_with_knight = join(left_mid, right_mid);
  //Creacion de la mitad superior e inferior del tablero
  char **first_two_rows = up(first_row_with_knight, fila);
  char **upper_mid_table = up(first_two_rows, two_fila);
  char **lower_mid_table = rotateR(rotateR(upper_mid_table));
  //Combinacion de las mitades creadas anteriormente
  char **solution = up(upper_mid_table, lower_mid_table);
  interpreter(solution);
}
