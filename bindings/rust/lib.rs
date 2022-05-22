//! This crate provides Tcl language support for the [tree-sitter][] parsing library.
//!
//! Typically, you will use the [language][language func] function to add this language to a
//! tree-sitter [Parser][], and then use the parser to parse some code:
//!
//! ```
//! let code = "";
//! let mut parser = tree_sitter::Parser::new();
//! parser
//!     .set_language(tree_sitter_tcl::language_tcl()) // or language_tclsh()
//!     .expect("Error loading Tcl grammar");
//! let tree = parser.parse(code, None).unwrap();
//! ```
//!
//! [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
//! [language func]: fn.language.html
//! [Parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter::Language;

extern "C" {
    fn tree_sitter_tcl() -> Language;
    fn tree_sitter_tclsh() -> Language;
}

/// Get the tree-sitter [Language][] for Tcl grammar.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language_tcl() -> Language {
    unsafe { tree_sitter_tcl() }
}

/// Get the tree-sitter [Language][] for Tclsh grammar.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language_tclsh() -> Language {
    unsafe { tree_sitter_tclsh() }
}

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const TCL_NODE_TYPES: &'static str = include_str!("../../tcl/src/node-types.json");

// Uncomment these to include any queries that this grammar contains

// pub const HIGHLIGHTS_QUERY: &'static str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &'static str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &'static str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &'static str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {
    #[test]
    fn test_can_load_tcl_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(super::language_tcl())
            .expect("Error loading Tcl language");
    }

    #[test]
    fn test_can_load_tclsh_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(super::language_tclsh())
            .expect("Error loading Tclsh language");
    }
}
