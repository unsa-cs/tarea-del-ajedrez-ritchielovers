#include "chess.h"
#include "figures.h"

void display() {
  char **_spwhite = whiteSquare;       // un casillero en blanco
  char **_spblack = reverse(_spwhite); // un casillero en negro
  char **two_block = join(_spwhite, _spblack);
  char **fila_start_white = repeatH(two_block, 4);
  char **fila_start_black = reverse(fila_start_white); 

  char **row_figures = rook;
   
  //se concatenan las figuras por separado en la variable row_figures
  row_figures = join(row_figures, knight);
  row_figures = join(row_figures, bishop);
  row_figures = join(row_figures, queen);
  row_figures = join(row_figures, king);
  row_figures = join(row_figures, bishop);
  row_figures = join(row_figures, knight);
  row_figures = join(row_figures, rook);

  char **row_peones_blancos = repeatH(pawn,8);
  
  row_peones_blancos = superImpose(row_peones_blancos,fila_start_white);
  char **row_peones_negros = reverse(row_peones_blancos);

  char **row_whites = superImpose(row_figures, fila_start_black);
  char **row_blacks = reverse(row_whites);
  
  char **conjunto_negras = up(row_peones_negros, row_blacks);
  char **conjunto_blancas = up(row_whites, row_peones_blancos);
  char **four_rows = repeatV(up(fila_start_black, fila_start_white), 2);
  char **chess_table = up(up(conjunto_blancas, four_rows), conjunto_negras);

  interpreter(chess_table);
}
