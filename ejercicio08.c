#include "chess.h"
#include "figures.h"

void display(){
  int eight_queens[8][8] = {{0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,1,0,0},
                            {0,0,0,0,0,0,0,1},
                            {0,1,0,0,0,0,0,0},
                            {0,0,0,1,0,0,0,0},
                            {1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0}, 
                            {0,0,0,0,1,0,0,0}};
  char** square;
  char** row;
  char** chess_table;
  for(int i = 0 ; i < 8 ; ++i){
    if(i%2==0){
      square=reverse(whiteSquare);
    }else{
      square=whiteSquare;
    }
    for(int j = 0 ;  j < 8 ; ++j){
      if(j==0){
        row=square;
      } else{
        row=join(row,square);
      }
    }
    if(i==0){
      chess_table=row;
    }else{
      chess_table=up(chess_table,row);
    }
  }
  interpreter(chess_table);
}
