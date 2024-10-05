#include "chess.h"
#include "figures.h"

void display() {
  char **_knight = knight;
  char **_black_knight = reverse(_knight);
  char **two_knight = join(_knight, _black_knight);
  char **flipv_two_knight = flipV(two_knight);
  /*
  char **four_knight = join(two_knight, flipv_two_knight);
  char **fliph_four_knight = flipH(four_knight);
  char **eight_knight = join(four_knight, fliph_four_knight);
  char **sixteen_knight = up(eight_knight, eight_knight);
  char **thirtytwo_knight = up(sixteen_knight, reverse(sixteen_knight));
  char **sixtyfour_knight = up(thirtytwo_knight, thirtytwo_knight);
  char **rotatel_knight = rotateL(_knight);
  */
  char **flipv_rotater_two_knight = rotateR(flipv_two_knight);
  char **repeath_flipv_rotater_two_knight = repeatH(flipv_rotater_two_knight, 8);
  interpreter(repeath_flipv_rotater_two_knight);
}
