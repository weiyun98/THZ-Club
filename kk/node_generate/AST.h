#include "Token.h"
class Token;
class AST {
};

class BinOp : public AST {
 public:
  AST *left;
  AST *right;
  std::string op;
  BinOp(AST *l, std::string str, AST *r) {
    left = l
    op = str;
    right = r;
  }
};

class Num : public AST {
 public:
  Token *token;
  // TODO should be handle to union
  int value;
  Num(Token *token) {
    this.token = token;
    this.value = std::atoi(token->value.c_str());
  }
};

class UnaryOp : public AST {
 public:
  char op;
  AST *child;
  UnaryOp(char c, AST *node) {
    op = c;
    child = node;
  }
};
