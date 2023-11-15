#!/usr/bin/bash


infile_special="/dev/urandom"
cmd1="cat"
cmd2="head -n 10"
test_one_case "$infile_special" "$cmd1" "$cmd2"

# cmds
# ls, echo, cat, grep, wc, pwd, sed, awk, sed, ping, sort, cut, uniq, head, tail, tr, xargs, expr, curl/wget,
# infile /dev/urandom and /dev/stdin

