# 42sh
Bash-like [shell](https://en.wikipedia.org/wiki/Unix_shell).
It's a command-line interpreter

# Features
  - Prompt with line edition
  - Builtins: `[`, `alias`, `bg`, `cd`, `echo`, `exit`, `export`, `fc`, `fg`, `hash`, `help`, `history`, `jobs`, `kill`, `set`, `source`, `test`, `type`, `unalias`, `unset`
  - Executing commands
  - Executing command in background `&`
  - Pipe `|`
  - Redirections: `>`, `>>`, `>&`, `&>`, `&>>`, `>|`,
  `<`, `<<<`, `<&`, `&<`
  - Heredoc: `<<`, `<<-`
  - Logical operands: `&&` and `||`
  - Separators: `;`, `&`
  - Inhibitors: `"` (double quote), `'` (simple quote) and `\`
  - Environment and local variables: `$VAR` or `${VAR}`
  - Control groups and sub-shells: `(CMD)`, `{CMD}`
  - Command substitution: `$(CMD)`
  - Dynamical autocompletion
  - History (saved in `~/.42sh.history`)
  - Tilde expansion and additional parameter formats:
    `~`, `${parameter:-word}`, `${parameter:=word}`, `${parameter:?word}`, `${parameter:+word}`, `${#parameter}`, `${parameter%}`, `${parameter%%}`, `${parameter#}`, `${parameter##}`
  - Arithmetic expansion: `$(())`
  - Contextual dynamic completion of commands, built-ins, files, internal and environment variables. Autocompletion for order/built-ins parameters
  - The two editing modes of the vi and emacs command line (`set -o vi` or `set -o emacs`)
  - Shell Script (`if`, `while`, `until`, `for`, `case` and function definition)
  - PS1/PS2 environment variable to custom shell prompt ([wiki](https://ss64.com/bash/syntax-prompt.html))
  
# Installation

Clone current repository into empty folder "42sh"
```
$>  cd 42sh && make
$>  ./42sh
```
## Rules make
  - `make` compilation of binary executable
  - `make clean` delete all `.o` files
  - `make fclean` delete all `.o` files and `./42sh`
  - `make re` do `fclean` then `make`

# Shell

## History 
Commands|Functions|
:-:|:--
`!!`|Last command in history
`!word`|Look for the last command starting by `word`
`![-]number`|Look for the command at index `number`, `-` define that the search starts from the end

## Alias
Commands|Functions|
:-:|:--
`alias`|List all the current aliases set
`alias [name[=value] ...]`|Sets an alias for `name` so it replaces as `value` internally 
`unalias [-a] name [name ...]`|Remove the `name` arguments of the alias table. `-a` removes all aliases

## Hash table
Commands|Functions|
:-:|:--
`hash`|List hash table contents
`hash -r`|Clear the hash table

## Job control
Commands|Functions|
:-:|:--
`jobs [n]`|List all the current running jobs, `n` specify the job you want (the form is in [job id form](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html#tag_03_204) or it can be a numerical value) 
`fg [n]`|Bring the specified job to foreground
`bg [n]`|Bring the specified job to background

A shell compliant with the [POSIX Standard](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/).

# Authors
Name|Mail|Github
:-:|:-:|:--
Aleksandr | ggwin-go@student.21-school.ru |https://github.com/ZaprAlex
Aleksey | dwisoky@student.21-school.ru |https://github.com/TinkiBain
Vladimir | gmelisan@student.21-school.ru |https://github.com/nefyodovve
Danila | jterry@student.21-school.ru |https://github.com/itynol
Kirill | wtalea@student.21-school.ru |https://github.com/wtalea
