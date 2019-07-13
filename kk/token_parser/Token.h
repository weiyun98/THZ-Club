#ifndef TOKEN_H_
#define TOKEN_H_
#include<string>
class Token;
class Tokenizer{
 private:
  std::string myStream;
  int pos = -1;
 public:
  Tokenizer(char *);
  void PrintContent();
  void ParseToken();
  void SkipWhiteSpace();
  Token NextToken();
};
enum TOKENTYPE {Integer, PLUS, MINUS, MUL, DIV, End};
class Token{
 private:
  TOKENTYPE type;
  std::string value;
 public:
  Token(TOKENTYPE tokenType, std::string *s, int begin, int length);
  Token(TOKENTYPE tokenType);
  Token();
  TOKENTYPE GetType();
  void Print();
};
#endif
