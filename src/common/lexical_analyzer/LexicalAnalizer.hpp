#ifndef LEXICAL_ANALYZER
#define LEXICAL_ANALYZER

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/optional.hpp>

#include "common/SemanticDefinition.hpp"
#include "InStreamRange.hpp"
#include "SearchResult.hpp"

namespace DragonLang::Common {

class LexicalAnalyzer {
 public:
  struct Token {
    TokenId id_;
    std::string item_;

    std::string toString() const {
      switch (id_) {
        case TokenId::SpecialSymbol: {
          return "<SpecialSymbol>";
        }
        case TokenId::Keyword: {
          return "<Keyword>";
        }
        case TokenId::ContextKeyword: {
          return "<ContextKeyword>";
        }
        case TokenId::NewLine: {
          return "<NewLine>";
        }
        case TokenId::NumberConst: {
          return "<NumberConst>";
        }
        case TokenId::TextConst: {
          return "<TextConst>";
        }
        case TokenId::SymbolId: {
          return "<SymbolId>";
        }
        default: {
          return "<UnknownToken>";
        }
      }
    }
  };

  using OptionalTokenId = boost::optional<TokenId>;
  using OptionalToken = boost::optional<Token>;

  LexicalAnalyzer(const std::string & _file);
  virtual ~LexicalAnalyzer() = default;

  OptionalToken getNextToken();
  std::vector<Token> getAllTokens();
  void printTokens(const std::vector<LexicalAnalyzer::Token> &_tokens) const;
  void printTokens();

 protected:
  virtual SearchResult isNextSymbolId() const;
  virtual SearchResult isNextTextConst() const;
  virtual SearchResult isNextNumber() const;
  virtual SearchResult isNextKeyword() const;
  virtual SearchResult isNextContextKeyword() const;
  virtual SearchResult isNextSpecialSymbol() const;
  virtual bool isWhiteSpace(char const &_rawStr) const;
  virtual bool isIndentSymbol(char const &_rawStr) const;
  virtual bool isNewLine(char const &_rawStr) const;

 private:
  OptionalTokenId prev_token_id_;
  std::unique_ptr<InStreamRange> stream_range_;
  std::string token_buffer_;
};

}

#endif // LEXICAL_ANALYZER