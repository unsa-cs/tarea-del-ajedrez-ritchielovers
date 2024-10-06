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

  char **row_peones = repeatH(pawn,8);
  row_peones = superImpose(row_peones,fila_start_white);

  char **row_whites = superImpose(row_figures, fila_start_black);
  
  char **result = up(row_whites, row_peones);  

  interpreter(result);
}
