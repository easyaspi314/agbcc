/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L ANSI-C -F ', 0, 0' -p -j1 -i 1 -g -o -t -N is_reserved_word -k'1,3,$' -G c-parse.gperf  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


/* Command-line: gperf -L KR-C -F ', 0, 0' -p -j1 -i 1 -g -o -t -N is_reserved_word -k1,3,$ c-parse.gperf  */ 
struct resword { char *name; short token; enum rid rid; };

#define TOTAL_KEYWORDS 84
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 20
#define MIN_HASH_VALUE 12
#define MAX_HASH_VALUE 122
/* maximum key range = 111, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
  static unsigned char asso_values[] =
    {
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123,  19, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123,   1, 123,  12,  32,  17,
       22,  18,  66,  37,   5,  10, 123,   8,  35,  43,
       27,  40,  19, 123,   2,  20,   1,  41,  61,   7,
       11,   3,   2, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

static struct resword wordlist[] =
  {
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"__real__", REALPART, NORID},
    {"__typeof__", TYPEOF, NORID},
    {"__restrict", TYPE_QUAL, RID_RESTRICT},
    {"int", TYPESPEC, RID_INT},
    {"__restrict__", TYPE_QUAL, RID_RESTRICT},
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"__imag__", IMAGPART, NORID},
    {"__asm__", ASM_KEYWORD, NORID},
    {"__inline__", SCSPEC, RID_INLINE},
    {"__iterator", SCSPEC, RID_ITERATOR},
    {"__iterator__", SCSPEC, RID_ITERATOR},
    {"__alignof__", ALIGNOF, NORID},
    {"__const", TYPE_QUAL, RID_CONST},
    {"__attribute__", ATTRIBUTE, NORID},
    {"__const__", TYPE_QUAL, RID_CONST},
    {"struct", STRUCT, NORID},
    {"__complex__", TYPESPEC, RID_COMPLEX},
    {"restrict", TYPE_QUAL, RID_RESTRICT},
    {"__signed__", TYPESPEC, RID_SIGNED},
    {"__extension__", EXTENSION, NORID},
    {"id", OBJECTNAME, RID_ID},
    {"char", TYPESPEC, RID_CHAR},
    {"return", RETURN, NORID},
    {"__inline", SCSPEC, RID_INLINE},
    {"__complex", TYPESPEC, RID_COMPLEX},
    {"in", TYPE_QUAL, RID_IN},
    {"while", WHILE, NORID},
    {"switch", SWITCH, NORID},
    {"__attribute", ATTRIBUTE, NORID},
    {"", 0, 0},
    {"__real", REALPART, NORID},
    {"out", TYPE_QUAL, RID_OUT},
    {"__label__", LABEL, NORID},
    {"@private", PRIVATE, NORID},
    {"@selector", SELECTOR, NORID},
    {"register", SCSPEC, RID_REGISTER},
    {"const", TYPE_QUAL, RID_CONST},
    {"__signed", TYPESPEC, RID_SIGNED},
    {"extern", SCSPEC, RID_EXTERN},
    {"@protected", PROTECTED, NORID},
    {"__imag", IMAGPART, NORID},
    {"static", SCSPEC, RID_STATIC},
    {"inout", TYPE_QUAL, RID_INOUT},
    {"auto", SCSPEC, RID_AUTO},
    {"bycopy", TYPE_QUAL, RID_BYCOPY},
    {"case", CASE, NORID},
    {"else", ELSE, NORID},
    {"__asm", ASM_KEYWORD, NORID},
    {"@defs", DEFS, NORID},
    {"break", BREAK, NORID},
    {"do", DO, NORID},
    {"@protocol", PROTOCOL, NORID},
    {"short", TYPESPEC, RID_SHORT},
    {"oneway", TYPE_QUAL, RID_ONEWAY},
    {"", 0, 0},
    {"inline", SCSPEC, RID_INLINE},
    {"continue", CONTINUE, NORID},
    {"@encode", ENCODE, NORID},
    {"@end", END, NORID},
    {"for", FOR, NORID},
    {"@interface", INTERFACE, NORID},
    {"__volatile__", TYPE_QUAL, RID_VOLATILE},
    {"__typeof", TYPEOF, NORID},
    {"", 0, 0},
    {"if", IF, NORID},
    {"", 0, 0},
    {"@class", CLASS, NORID},
    {"_Bool", TYPESPEC, RID_BOOL},
    {"goto", GOTO, NORID},
    {"union", UNION, NORID},
    {"@public", PUBLIC, NORID},
    {"signed", TYPESPEC, RID_SIGNED},
    {"", 0, 0},
    {"double", TYPESPEC, RID_DOUBLE},
    {"__alignof", ALIGNOF, NORID},
    {"", 0, 0},
    {"__volatile", TYPE_QUAL, RID_VOLATILE},
    {"unsigned", TYPESPEC, RID_UNSIGNED},
    {"typeof", TYPEOF, NORID},
    {"typedef", SCSPEC, RID_TYPEDEF},
    {"sizeof", SIZEOF, NORID},
    {"", 0, 0},
    {"default", DEFAULT, NORID},
    {"void", TYPESPEC, RID_VOID},
    {"", 0, 0},
    {"@compatibility_alias", ALIAS, NORID},
    {"", 0, 0},
    {"asm", ASM_KEYWORD, NORID},
    {"", 0, 0},
    {"long", TYPESPEC, RID_LONG},
    {"@implementation", IMPLEMENTATION, NORID},
    {"byref", TYPE_QUAL, RID_BYREF},
    {"enum", ENUM, NORID},
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"", 0, 0},
    {"float", TYPESPEC, RID_FLOAT},
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
    {"", 0, 0},
  };

struct resword *
is_reserved_word (register const char *str, register unsigned int len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
