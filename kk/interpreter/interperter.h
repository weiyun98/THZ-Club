#ifndef INTERPRETER_H_
#define INTERPRETER_H_

class Interpreter {
 public:
  Interpreter(AST t);
  bool run();
  AST tree;

}



#endif
