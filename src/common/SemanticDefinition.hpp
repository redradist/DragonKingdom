#ifndef SEMANTIC_DEFINITION
#define SEMANTIC_DEFINITION

#include <string>
#include <unordered_set>
#include <regex>

enum class TokenId {
  SpecialSymbol, // < > + - = - > " '
  Keyword, // action function
  ContextKeyword, // in, is, not, as
  NewLine, // \r \n
  NumberConst, // 23, 27, 2.75, 2.75f, 2.75e-23f, 2.75d, 2.75e-23d
  TextConst, // 'Hello Denis Good Job', "Hello Denis Good Job"
  SymbolId, // Name of variables, name of classes, name of structs and so on
};

inline std::unordered_set<char> const kNewLines = {
   '\r',
   '\n',
};

inline std::unordered_set<char> const kIndentSymbols = {
   ' ',
   '\t',
};

inline std::regex_constants::syntax_option_type const kRegexOptions =
    std::regex_constants::ECMAScript |
    std::regex_constants::optimize;

inline std::regex const kRegexKeyword(
    R"(^()"
    R"(yield|)"
    R"(return|)"
    R"(enum|)"
    R"(struct|)"
    R"(class|)"
    R"(public|)"
    R"(protected|)"
    R"(private|)"
    R"(internal|)"
    R"(data|)"
    R"(interface|)"
    R"(import|)"
    R"(from|)"
    R"(void|)"
    R"(new|)"
    R"(delete|)"
    R"(extension|)"
    R"(extends|)"
    R"(inherits|)"
    R"(implements|)"
    R"(var|)"
    R"(auto|)"
    R"(char|)"
    R"(char8|)"
    R"(char16|)"
    R"(char32|)"
    R"(byte|)"
    R"(short|)"
    R"(int|)"
    R"(long|)"
    R"(ushort|)"
    R"(uint|)"
    R"(ulong|)"
    R"(float|)"
    R"(double|)"
    R"(decimal|)"
    R"(await|)"
    R"(async|)"
    R"(if|)"
    R"(else|)"
    R"(try|)"
    R"(catch|)"
    R"(atomic|)"
    R"(volatile|)"
    R"(inline)"
    R"()(\s|\W|$))", kRegexOptions);
inline std::regex const kRegexContextKeyword(
    R"(^()"
    R"(in|)"
    R"(is|)"
    R"(not|)"
    R"(as|)"
    R"(to)"
    R"()(\s|\W|$))", kRegexOptions);
inline std::regex const kRegexSpecialSymbol(
    R"(^([)"
    R"(\()"
    R"(\))"
    R"(\[)"
    R"(\])"
    R"(\$)"
    R"(\@)"
    R"(\!)"
    R"(\~)"
    R"(\^)"
    R"(\&)"
    R"(\*)"
    R"(\%)"
    R"(\?)"
    R"(\:)"
    R"(\;)"
    R"(\,)"
    R"(\.)"
    R"(\-)"
    R"(\+)"
    R"(\=)"
    R"(\>)"
    R"(\<)"
    R"(\+)"
    R"(\{)"
    R"(\})"
    R"(]))", kRegexOptions);
inline std::regex const kRegexNumberConst(R"(^([0-9]+([.][0-9]*)?|[.][0-9]+)[ifd]?(\s|\D|$))", kRegexOptions);
inline std::regex const kRegexString0Const(R"(^'(.*)')", kRegexOptions);
inline std::regex const kRegexString1Const(R"(^''(.*)'')", kRegexOptions);
inline std::regex const kRegexString2Const(R"(^'''(.*)''')", kRegexOptions);
inline std::regex const kRegexString3Const(R"(^\"(.*)\")", kRegexOptions);
inline std::regex const kRegexString4Const(R"(^\"\"(.*)\"\")", kRegexOptions);
inline std::regex const kRegexString5Const(R"(^\"\"\"(.*)\"\"\")", kRegexOptions);
inline std::regex const kRegexSymbolId(R"(^([_\w][_\w\d]*)(\s|:|$))", kRegexOptions);

#endif // SEMANTIC_DEFINITION
