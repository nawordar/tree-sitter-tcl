fn main() {
    let root_dir = std::path::Path::new(".");
    let tcl_dir = root_dir.join("tcl").join("src");
    let tclsh_dir = root_dir.join("tclsh").join("src");

    let mut c_config = cc::Build::new();
    c_config.include(&tcl_dir);
    c_config
        .flag_if_supported("-Wno-unused-parameter")
        .flag_if_supported("-Wno-unused-but-set-variable")
        .flag_if_supported("-Wno-trigraphs");

    let sources = [
        tcl_dir.join("parser.c"),
        tcl_dir.join("scanner.c"),
        tclsh_dir.join("parser.c"),
        tclsh_dir.join("scanner.c"),
    ];

    for source in &sources {
        c_config.file(source);
        println!("cargo:rerun-if-changed={}", source.to_str().unwrap());
    }

    c_config.compile("parser");
}
