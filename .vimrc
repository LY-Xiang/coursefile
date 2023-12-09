syntax on
set nocompatible
set number
set ruler
set hls
set backspace=indent,eol,start
set whichwrap=b,s,<,>,[,]
set sw=4
set ts=4
set lbr
set fo+=mB
set sm
set ai
nmap <C-b> <esc>:w<cr>:!g++ % -g -o %< -fsanitize=undefined -Wall -Wextra -O2 -std=c++14
nmap <C-r> :!\time -f "\%M \%U" ./%<
