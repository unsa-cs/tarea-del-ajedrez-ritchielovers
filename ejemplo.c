#include "chess.h"
#include "figures.h"

void display() {
  char **blackQueen = reverse(queen);
  char **blackPaw = reverse(pawn);
  char **whitePaw = pawn;
  interpreter(blackQueen);
  repeatH(blackQueen,4);
}
