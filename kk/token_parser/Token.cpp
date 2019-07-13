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
  if (pos >= static_cast<int>(myStream.length())) {
    return Token(TOKENTYPE::End); //TODO return an end Token
  }
  switch (myStream[pos]) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return Token(TOKENTYPE::Integer, &myStream, pos, 1);
      break;
    case '+':
      return Token(TOKENTYPE::PLUS, &myStream, pos, 1);
    case '-':
      return Token(TOKENTYPE::MINUS, &myStream, pos, 1);
    case '*':
      return Token(TOKENTYPE::MUL, &myStream, pos, 1);
    case '/':
      return Token(TOKENTYPE::DIV, &myStream, pos, 1);
      break;
    default :
      cout << "unexpected input.";
  }
}

Token::Token(TOKENTYPE tokenType, string *s, int begin, int length) {
  type = tokenType;
  value = s->substr(begin,length);
}

Token::Token(TOKENTYPE tokenType) {
  type = tokenType;
}

TOKENTYPE Token::GetType() {
  return type;
}

Token::Token() {}

void Token::Print() {
  cout << "[" << type << "," << value << "]" << endl;
}
