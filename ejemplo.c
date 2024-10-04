#include "chess.h"
#include "figures.h"

void display() {
  char **blackKnight = reverse(queen);
  char **blackPaw = reverse(pawn);
  interpreter(blackKnight);
}
