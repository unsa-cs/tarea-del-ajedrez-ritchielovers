#include "chess.h"
#include "figures.h"

void display(){
  int table[8][8] = {{0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0}, 
                            {0,0,0,0,0,0,0,0}};
  char** fichas[6]={pawn,knight,bishop,rook,queen,king};
  char** square;
  char** row;
  char** chess_table;
  char** ficha;

  for(int i = 0 ; i < 8 ; ++i){
    if(i%2==0){
      square=reverse(whiteSquare);
    }else{
      square=whiteSquare;
    }
    for(int j = 0 ;  j < 8 ; ++j){
        
      if(j%2==0){
        ficha=square;
      }else{
        ficha=reverse(square);
      }

      if(j==0){
        row=ficha;
      }else{
        row=join(row,ficha);
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
