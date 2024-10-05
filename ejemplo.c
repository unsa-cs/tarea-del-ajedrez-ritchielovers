#include "chess.h"
#include "figures.h"

void display() {
  
  
  char **_spwhite = whiteSquare; //un casillero en blanco
  char **_spblack = reverse(_spwhite); //un casillero en negro
  char **two_block = join(_spwhite, _spblack); //dos casilleros, uno blanco y uno negro
  char **fila = repeatH(two_block,4); //fila de casilleros blancos y negros

  interpreter(fila);
}
