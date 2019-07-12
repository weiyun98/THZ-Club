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
enum TOKENTYPE {Integer, OP};
class Token{
 private:
  TOKENTYPE type;
  std::string value;
 public:
  Token(TOKENTYPE tokenType, std::string *s, int begin, int length);
  void Print();
};
#endif
