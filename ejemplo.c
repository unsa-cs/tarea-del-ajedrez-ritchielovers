#include "chess.h"
#include "figures.h"

void display() {
  
  char **_spwhite = whiteSquare; //un casillero en blanco
  char **_spblack = reverse(_spwhite); //un casillero en negro
  char **two_block = join(_spwhite, _spblack); //se cambio de lugar para que ahora empieze con el casillero negro
  char **fila = reverse(repeatH(two_block,4)); //se multiplica por 4 para que sean 8 casilleros

  interpreter(fila);
}
