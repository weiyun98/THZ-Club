#include<iostream>
#include"Node.h"
#include"Token.h"
using namespace std;

int main() {
  cout << "Welcome to use kk." << endl;
  char input[] = "1 + 2 + 3 + 4";
  Tokenizer tkr(input);
  tkr.SkipWhiteSpace();
  tkr.PrintContent();
  Node node;
  node.NodeGenerate(&tkr);
}
