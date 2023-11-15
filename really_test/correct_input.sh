#!/usr/bin/bash

# test_one_case() {
#     eval "$2" < "$1" | eval $3
# }



cmd1="cat"
cmd2="awk '{print \$0}'"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat"
cmd2="head -n 2"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat"
cmd2="wc -l"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat"
cmd2="sort"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat"
cmd2="ping google.com -c 1"
test_many_cases "$cmd1" "$cmd2"



# cmds
# ls, echo, cat, grep, wc, pwd, sed, awk, sed, ping, sort, cut, uniq, head, tail, tr, xargs, expr, curl/wget,
# infile /dev/urandom and /dev/stdin
