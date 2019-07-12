#include"Token.h"
#include<iostream>
#include<cstring>

using namespace std;
Tokenizer::Tokenizer(char *myChar) {
  myStream = myChar;
}

void Tokenizer::PrintContent() {
  cout << myStream << endl;
}

void Tokenizer::ParseToken() {
  SkipWhiteSpace();
  unsigned int length = myStream.length();
  if (length > 0x000000007fffffff) {
    // TODO should to trans pos to uint.
  }
  while (pos < (static_cast<int>(length) - 1)) {
    NextToken().Print();
  }
}

void Tokenizer::SkipWhiteSpace() {
  char destC[myStream.length()];
  for (int i =0; myStream[i] != '\0'; i++) {
    if (myStream[i] == ' ') {
      continue;
    }
    destC[++pos] = myStream[i];
  }
  destC[++pos] = '\0';
  myStream = destC;
  pos = -1;
}

Token Tokenizer::NextToken() {
  ++pos;
  if (myStream[pos] > '0' && myStream[pos] < '9') {
    return Token(TOKENTYPE::Integer, &myStream, pos, 1);
  }
}

Token::Token(TOKENTYPE tokenType, string *s, int begin, int length) {
  type = tokenType;
  value = s->substr(begin,length);
}

void Token::Print() {
  cout << "[" << type << "," << value << "]" << endl;
}
