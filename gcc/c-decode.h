/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L ANSI-C -F ', 0, 0' -p -i 1 -g -o -t -N decode_option c-decode.gperf  */
/* Computed positions: -k'2,7,9,$' */

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

#line 1 "c-decode.gperf"

enum command_line_option
{
    FLAG_ALLOW_SINGLE_PRECISION,
    FLAG_ASM,
    FLAG_BUILTIN,
    FLAG_C90,
    FLAG_C99,
    FLAG_COND_MISMATCH,
    FLAG_CONST_STRINGS,
    FLAG_FREESTANDING,
    FLAG_GNU90,
    FLAG_GNU99,
    FLAG_IDENT,
    FLAG_SHORT_DOUBLE,
    FLAG_SHORT_ENUMS,
    FLAG_SIGNED_BITFIELDS,
    FLAG_TRADITIONAL,
    FLAG_W_ALL,
    FLAG_W_BAD_FUNC_CAST,
    FLAG_W_CAST_QUAL,
    FLAG_W_CHAR_SUBSCRIPTS,
    FLAG_W_CONVERSION,
    FLAG_W_IMPLICIT,
    FLAG_W_IMPLICIT_FUNC,
    FLAG_W_IMPLICIT_INT,
    FLAG_W_LONG_LONG,
    FLAG_W_MISSING_BRACES,
    FLAG_W_MISSING_DECLARATIONS,
    FLAG_W_MISSING_NORETURN,
    FLAG_W_MISSING_PROTOTYPES,
    FLAG_W_MULTICHAR,
    FLAG_W_NESTED_EXTERNS,
    FLAG_W_PARENTHESES,
    FLAG_W_POINTER_ARITH,
    FLAG_W_REDUNDANT_DECLS,
    FLAG_W_RETURN_TYPE,
    FLAG_W_SIGN_COMPARE,
    FLAG_W_STRICT_PROTOTYPES,
    FLAG_W_TRADITIONAL
};
#line 43 "c-decode.gperf"
struct option
{
    const char *name;
    int type;
    int val;
};

#define TOTAL_KEYWORDS 81
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 37
#define MIN_HASH_VALUE 15
#define MAX_HASH_VALUE 216
/* maximum key range = 202, duplicates = 0 */

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
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217,  71, 217, 217,   1, 217,
      217, 217, 217, 217, 217, 217,  41,  16, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217,  21, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 101, 217,   1,
       76,  21,   6,  41,  26,   1, 217, 217,   1,  91,
        1,   6, 217, 217,  11,   1,   1,  96,  11,   1,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217, 217, 217, 217, 217,
      217, 217, 217, 217, 217, 217
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
      case 5:
      case 4:
      case 3:
      case 2:
        hval += asso_values[(unsigned char)str[1]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

struct option *
decode_option (register const char *str, register unsigned int len)
{
  static struct option wordlist[] =
    {
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 84 "c-decode.gperf"
      {"-fident", FLAG_IDENT, 1},
      {"", 0, 0}, {"", 0, 0},
#line 81 "c-decode.gperf"
      {"-fbuiltin", FLAG_BUILTIN, 1},
      {"", 0, 0}, {"", 0, 0},
#line 51 "c-decode.gperf"
      {"-traditional", FLAG_TRADITIONAL, 1},
#line 50 "c-decode.gperf"
      {"-ftraditional", FLAG_TRADITIONAL, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 61 "c-decode.gperf"
      {"-std=c90", FLAG_C90, 1},
#line 130 "c-decode.gperf"
      {"-Wall", FLAG_W_ALL, 1},
      {"", 0, 0},
#line 66 "c-decode.gperf"
      {"-std=gnu90", FLAG_GNU90, 1},
#line 72 "c-decode.gperf"
      {"-fno-signed-bitfields", FLAG_SIGNED_BITFIELDS, 0},
      {"", 0, 0},
#line 70 "c-decode.gperf"
      {"-fno-unsigned-bitfields", FLAG_SIGNED_BITFIELDS, 1},
#line 54 "c-decode.gperf"
      {"-fallow-single-precision", FLAG_ALLOW_SINGLE_PRECISION, 1},
#line 90 "c-decode.gperf"
      {"-Wimplicit", FLAG_W_IMPLICIT, 1},
      {"", 0, 0},
#line 59 "c-decode.gperf"
      {"-std=iso9899:1990", FLAG_C90, 1},
#line 114 "c-decode.gperf"
      {"-Wtraditional", FLAG_W_TRADITIONAL, 1},
#line 88 "c-decode.gperf"
      {"-Wimplicit-int", FLAG_W_IMPLICIT_INT, 1},
      {"", 0, 0}, {"", 0, 0},
#line 65 "c-decode.gperf"
      {"-std=c99", FLAG_C99, 1},
#line 73 "c-decode.gperf"
      {"-fshort-enums", FLAG_SHORT_ENUMS, 1},
#line 125 "c-decode.gperf"
      {"-Wno-missing-braces", FLAG_W_MISSING_BRACES, 0},
#line 68 "c-decode.gperf"
      {"-std=gnu99", FLAG_GNU99, 1},
#line 101 "c-decode.gperf"
      {"-Wno-missing-noreturn", FLAG_W_MISSING_NORETURN, 0},
#line 105 "c-decode.gperf"
      {"-Wno-strict-prototypes", FLAG_W_STRICT_PROTOTYPES, 0},
#line 107 "c-decode.gperf"
      {"-Wno-missing-prototypes", FLAG_W_MISSING_PROTOTYPES, 0},
#line 98 "c-decode.gperf"
      {"-Wbad-function-cast", FLAG_W_BAD_FUNC_CAST, 1},
#line 109 "c-decode.gperf"
      {"-Wno-missing-declarations", FLAG_W_MISSING_DECLARATIONS, 0},
      {"", 0, 0},
#line 64 "c-decode.gperf"
      {"-std=iso9899:1999", FLAG_C99, 1},
#line 95 "c-decode.gperf"
      {"-Wno-write-strings", FLAG_CONST_STRINGS, 0},
#line 63 "c-decode.gperf"
      {"-std=iso9899:199409", FLAG_C90, 1},
#line 119 "c-decode.gperf"
      {"-Wno-conversion", FLAG_W_CONVERSION, 0},
#line 86 "c-decode.gperf"
      {"-Wimplicit-function-declaration", FLAG_W_IMPLICIT_FUNC, 1},
#line 118 "c-decode.gperf"
      {"-Wconversion", FLAG_W_CONVERSION, 1},
      {"", 0, 0}, {"", 0, 0},
#line 94 "c-decode.gperf"
      {"-Wwrite-strings", FLAG_CONST_STRINGS, 1},
#line 74 "c-decode.gperf"
      {"-fno-short-enums",  FLAG_SHORT_ENUMS, 0},
#line 127 "c-decode.gperf"
      {"-Wno-sign-compare", FLAG_W_SIGN_COMPARE, 0},
#line 120 "c-decode.gperf"
      {"-Wparentheses", FLAG_W_PARENTHESES, 1},
#line 113 "c-decode.gperf"
      {"-Wno-nested-externs", FLAG_W_NESTED_EXTERNS, 0},
      {"", 0, 0}, {"", 0, 0},
#line 62 "c-decode.gperf"
      {"-std=c89", FLAG_C90, 1},
      {"", 0, 0}, {"", 0, 0},
#line 67 "c-decode.gperf"
      {"-std=gnu89", FLAG_GNU90, 1},
#line 128 "c-decode.gperf"
      {"-Wmultichar", FLAG_W_MULTICHAR, 1},
#line 85 "c-decode.gperf"
      {"-Werror-implicit-function-declaration", FLAG_W_IMPLICIT_FUNC, 2},
#line 103 "c-decode.gperf"
      {"-Wno-pointer-arith", FLAG_W_POINTER_ARITH, 0},
      {"", 0, 0},
#line 102 "c-decode.gperf"
      {"-Wpointer-arith", FLAG_W_POINTER_ARITH, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 117 "c-decode.gperf"
      {"-Wno-char-subscripts", FLAG_W_CHAR_SUBSCRIPTS, 0},
#line 124 "c-decode.gperf"
      {"-Wmissing-braces", FLAG_W_MISSING_BRACES, 1},
#line 78 "c-decode.gperf"
      {"-fno-short-double", FLAG_SHORT_DOUBLE, 0},
#line 100 "c-decode.gperf"
      {"-Wmissing-noreturn", FLAG_W_MISSING_NORETURN, 1},
      {"", 0, 0},
#line 106 "c-decode.gperf"
      {"-Wmissing-prototypes", FLAG_W_MISSING_PROTOTYPES, 1},
      {"", 0, 0},
#line 108 "c-decode.gperf"
      {"-Wmissing-declarations", FLAG_W_MISSING_DECLARATIONS, 1},
      {"", 0, 0}, {"", 0, 0},
#line 71 "c-decode.gperf"
      {"-funsigned-bitfields", FLAG_SIGNED_BITFIELDS, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 83 "c-decode.gperf"
      {"-fno-ident", FLAG_IDENT, 0},
      {"", 0, 0},
#line 56 "c-decode.gperf"
      {"-fno-freestanding", FLAG_FREESTANDING, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 57 "c-decode.gperf"
      {"-fno-hosted", FLAG_FREESTANDING, 1},
      {"", 0, 0},
#line 79 "c-decode.gperf"
      {"-fasm", FLAG_ASM, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 80 "c-decode.gperf"
      {"-fno-asm", FLAG_ASM, 0},
#line 60 "c-decode.gperf"
      {"-ansi", FLAG_C90, 1},
      {"", 0, 0}, {"", 0, 0},
#line 53 "c-decode.gperf"
      {"-fno-traditional", FLAG_TRADITIONAL, 0},
#line 55 "c-decode.gperf"
      {"-fhosted", FLAG_FREESTANDING, 0},
      {"", 0, 0},
#line 104 "c-decode.gperf"
      {"-Wstrict-prototypes", FLAG_W_STRICT_PROTOTYPES, 1},
      {"", 0, 0}, {"", 0, 0},
#line 82 "c-decode.gperf"
      {"-fno-builtin", FLAG_BUILTIN, 0},
#line 69 "c-decode.gperf"
      {"-fsigned-bitfields", FLAG_SIGNED_BITFIELDS, 1},
#line 77 "c-decode.gperf"
      {"-fshort-double",  FLAG_SHORT_DOUBLE, 1},
#line 75 "c-decode.gperf"
      {"-fcond-mismatch",  FLAG_COND_MISMATCH, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 93 "c-decode.gperf"
      {"-Wno-long-long", FLAG_W_LONG_LONG, 0},
#line 52 "c-decode.gperf"
      {"-fnotraditional", FLAG_TRADITIONAL, 0},
#line 115 "c-decode.gperf"
      {"-Wno-traditional", FLAG_W_TRADITIONAL, 0},
      {"", 0, 0},
#line 91 "c-decode.gperf"
      {"-Wno-implicit", FLAG_W_IMPLICIT, 0},
      {"", 0, 0}, {"", 0, 0},
#line 112 "c-decode.gperf"
      {"-Wnested-externs", FLAG_W_NESTED_EXTERNS, 1},
#line 89 "c-decode.gperf"
      {"-Wno-implicit-int", FLAG_W_IMPLICIT_INT, 0},
#line 76 "c-decode.gperf"
      {"-fno-cond-mismatch", FLAG_COND_MISMATCH, 0},
#line 126 "c-decode.gperf"
      {"-Wsign-compare", FLAG_W_SIGN_COMPARE, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 122 "c-decode.gperf"
      {"-Wreturn-type", FLAG_W_RETURN_TYPE, 1},
#line 97 "c-decode.gperf"
      {"-Wno-cast-qual", FLAG_W_CAST_QUAL, 0},
      {"", 0, 0}, {"", 0, 0},
#line 110 "c-decode.gperf"
      {"-Wredundant-decls", FLAG_W_REDUNDANT_DECLS, 1},
      {"", 0, 0},
#line 129 "c-decode.gperf"
      {"-Wno-multichar", FLAG_W_MULTICHAR, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 87 "c-decode.gperf"
      {"-Wno-implicit-function-declaration", FLAG_W_IMPLICIT_FUNC, 0},
      {"", 0, 0},
#line 92 "c-decode.gperf"
      {"-Wlong-long", FLAG_W_LONG_LONG, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 111 "c-decode.gperf"
      {"-Wno-redundant-decls", FLAG_W_REDUNDANT_DECLS, 0},
#line 121 "c-decode.gperf"
      {"-Wno-parentheses", FLAG_W_PARENTHESES, 0},
      {"", 0, 0}, {"", 0, 0},
#line 58 "c-decode.gperf"
      {"-ffreestanding", FLAG_FREESTANDING, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 123 "c-decode.gperf"
      {"-Wno-return-type", FLAG_W_RETURN_TYPE, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
#line 96 "c-decode.gperf"
      {"-Wcast-qual", FLAG_W_CAST_QUAL, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0},
#line 116 "c-decode.gperf"
      {"-Wchar-subscripts", FLAG_W_CHAR_SUBSCRIPTS, 1},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0},
      {"", 0, 0},
#line 99 "c-decode.gperf"
      {"-Wno-bad-function-cast", FLAG_W_BAD_FUNC_CAST, 0}
    };

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
