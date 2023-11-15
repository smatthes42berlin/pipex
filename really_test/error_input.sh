#!/usr/bin/bash

cmd1="cat -b -A"
cmd2="grep1 e"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat -WrongArg -b -A"
cmd2="echo e"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat1 -b -A"
cmd2="grep e"
test_many_cases "$cmd1" "$cmd2"

cmd1="cat1 -b -A"
cmd2="grep1 e"
test_many_cases "$cmd1" "$cmd2"
