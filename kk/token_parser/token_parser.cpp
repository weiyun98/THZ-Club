#include"Token.h"

int main(){
  char tmpc[] = "1 ++ 2 - 3";
  Tokenizer *tker = new Tokenizer(tmpc);
  tker->ParseToken();
  tker->PrintContent();
  delete(tker);
}
