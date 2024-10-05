#include "chess.h"
#include "figures.h"

void display() {
  char **_knight = knight;
  char **_black_knight = reverse(_knight);
  char **two_knight = join(_knight, _knight);
  char **two_black_knight = join(_black_knight, _black_knight);
  char **four_knight = join(two_knight, two_black_knight);
  interpreter(four_knight);
}
