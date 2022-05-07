#include "../../common/scanner.h"

void *tree_sitter_tcl_external_scanner_create() {
  return NULL;
}

void tree_sitter_tcl_external_scanner_destroy(void *p) {}

void tree_sitter_tcl_external_scanner_reset(void *p) {}

unsigned tree_sitter_tcl_external_scanner_serialize(void *p, char *buffer) {
  return 0;
}

void tree_sitter_tcl_external_scanner_deserialize(
    void *payload,
    const char *state,
    unsigned length
) {}

bool tree_sitter_tcl_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  return external_scanner_scan(payload, lexer, valid_symbols);
}
