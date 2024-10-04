#include "chess.h"
#include "figures.h"

void display() {
  char **blackQueen = reverse(queen);
  char **blackPaw = reverse(pawn);
  char **whitePaw = pawn;
  char **queens = repeatV(blackQueen,8);
  interpreter(queens);
}
