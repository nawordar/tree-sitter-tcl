(quoted_word) @string

(set_command
  "set" @keyword
  name: (word) @variable)

(command
  name: (word) @function.call)
