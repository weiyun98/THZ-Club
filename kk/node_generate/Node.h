#ifndef NODE_H_
#define NODE_H_
#include"Token.h"
class Node {
 protected:
  int nodeType;
 public:
  void NodeGenerate(Tokenizer *tkr);
  void SetType(int t) {
    nodeType = t;
  }

  int GetType() {
    return nodeType;
  }
};

typedef union{
bool z;
char b;
int i;
float f;
double d;
long l;
}kValue;

class ConstNode : public Node {
 public:
  kValue value;
  int constType;

  ConstNode(int type, kValue v);
  void print();
};

class OpNode : public Node {
 public:
  int opType;
  Node* left;
  Node* right;
  OpNode(int type, Node *l, Node *r) {
    SetType(1); // 1 for OpNode
    opType = type;
    left = l;
    right = r;
  }

  OpNode(int type, Node *r) {
    // TODO ensure type is plus or minus
    SetType(1); // 1 for OpNode
    opType = type;
    right = r;
    left = nullptr;
  }

  void print();
};
#endif
