#include"Node.h"
#include"Token.h"
ConstNode::ConstNode(int type, kValue v) {
  SetType(0); // 0 for ConstNode
  value = v;
  constType = type;
}
Token curToken;
void Node::NodeGenerate(Tokenizer *tkr) {
  curToken = tkr->NextToken();
  while (curToken.GetType() != TOKENTYPE::End) {
    curToken.Print();
    curToken = tkr->NextToken();
  }
}
