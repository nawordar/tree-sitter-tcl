{
  "targets": [
    {
      "target_name": "tree_sitter_tcl_binding",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "tcl/src",
      ],
      "sources": [
        "bindings/node/binding.cc",
        "tcl/src/parser.c",
        "tcl/src/scanner.c",
        "tclsh/src/parser.c",
        "tclsh/src/scanner.c",
      ],
      "cflags_c": [
        "-std=c99",
      ]
    }
  ]
}
