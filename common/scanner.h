#include <tree_sitter/parser.h>
#include <wctype.h>

enum TokenType {
    CONCAT,
};

static bool is_end_of_file_ahead(TSLexer *lexer) {
    return lexer->lookahead == 0;
}

static bool is_whitespace_ahead(TSLexer *lexer) {
    return iswspace(lexer->lookahead);
}

static bool is_character_ahead(TSLexer *lexer, char character) {
    return lexer->lookahead == character;
}


static bool is_concat_valid(TSLexer *lexer) {
    return !(
        is_end_of_file_ahead(lexer)
        || is_whitespace_ahead(lexer)
        || is_character_ahead(lexer, '}')
        || is_character_ahead(lexer, ']')
        || is_character_ahead(lexer, ';')
    );
}

static inline bool external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    if (valid_symbols[CONCAT] && is_concat_valid(lexer)) {
        lexer->result_symbol = CONCAT;
        return true;
    }

    return false;
}
