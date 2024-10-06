#include "chess.h"
#include "figures.h"

void display() {
  char **_spwhite = whiteSquare;       // un casillero en blanco
  char **_spblack = reverse(_spwhite); // un casillero en negro
  char **two_block = join(_spwhite, _spblack);
  char **fila = reverse(repeatH(two_block, 4));

  char **row_figures = rook;
   
  //se concatenan las imagenes por separado en la variable row_figures
  row_figures = join(row_figures, knight);
  row_figures = join(row_figures, bishop);
  row_figures = join(row_figures, queen);
  row_figures = join(row_figures, king);
  row_figures = join(row_figures, bishop);
  row_figures = join(row_figures, knight);
  row_figures = join(row_figures, rook);
  
  //se invierte los colores de las figuras en row_figures
  row_figures = reverse(row_figures);

  //se superpone las figuras a los casilleros 
  char**result = superImpose(row_figures, fila);

  interpreter(result);
}
