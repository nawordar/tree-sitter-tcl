import Parser from 'tree-sitter'
import treeSitterTcl from './index.js'
const { tcl, tclsh } = treeSitterTcl

const sourceCode = `
set x "Hello world!"
puts x
`

const tclParser = new Parser()
tclParser.setLanguage(tcl)
tclParser.parse(sourceCode)

const tclshParser = new Parser()
tclshParser.setLanguage(tclsh)
tclshParser.parse(sourceCode)

console.log("Node bindings test successful")
