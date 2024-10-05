#include "chess.h"
#include "figures.h"

void display() {
  
  
  char **_spwhite = whiteSquare; //un casillero en blanco
  char **_spblack = reverse(_spwhite); //un casillero en negro
  //char **two_block = join(_spwhite, _spblack); //dos casilleros, empezando con uno negro y luego otro blanco
  char **fila = join(join(join(_spwhite, _spblack),join(_spwhite, _spblack)),join(join(_spwhite,_spblack),join(_spwhite,_spblack)));

  interpreter(fila);
}
