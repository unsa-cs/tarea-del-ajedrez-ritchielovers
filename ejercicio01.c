#include "chess.h"
#include "figures.h"

void display() {
  char **_spwhite = whiteSquare;
  char **_spblack = reverse(_spwhite);
  char **two_block = join(_spwhite, _spblack);
  char **fila = repeatH(two_block, 4);
  interpreter(fila);
}
