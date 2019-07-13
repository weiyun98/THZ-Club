#include"interpreter.h"

Interpreter::Interpreter(AST t) {
  tree = t;
}

bool Interpreter::run() {
  return visit(tree);
}
