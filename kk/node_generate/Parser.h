#include "Token.h"
class Parser {
 public:
  Token *currentToken;
  Tokenizer *tkr;
  Parser(Tokenizer *tokenizer) {
    tkr = tokenizer;
    currentToken = tokenizer->NextToken();
  }
}
