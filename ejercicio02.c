#include "chess.h"
#include "figures.h"

void display() {

  char **_spwhite = whiteSquare;       // un casillero en blanco
  char **_spblack = reverse(_spwhite); // un casillero en negro
  char **two_block = join(_spwhite, _spblack);
  char **fila = reverse(repeatH(two_block, 4));

  interpreter(fila);
}
