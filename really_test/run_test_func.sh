#!/usr/bin/bash

test_many_cases() {
    cmd1=$1
    cmd2=$2
    test_one_case "$infile0" "$cmd1" "$cmd2"
    test_one_case "$infile1" "$cmd1" "$cmd2"
    test_one_case "$infile2" "$cmd1" "$cmd2"
    test_one_case "$infile3" "$cmd1" "$cmd2"
    test_one_case "$infile4" "$cmd1" "$cmd2"
}

test_one_case() {

    outfile_bash="bash_out.txt"
    outfile_pipex="pipex_out.txt"
    outfile_leaks="leak_out.txt"
    outfile_leaks_check="leak_out_check.txt"
    diff_file=diff.txt
    infile=$1
    cmd1=$2
    cmd2=$3

    eval $cmd1 <$infile | eval $cmd2 2>&1 >$outfile_bash | awk '{for (i=4; i<NF; i++) printf $i " "} END{if ($NF > 0) print $NF}'
    echo -n ""
    ../pipex $infile "$cmd1" "$cmd2" $outfile_pipex
    diff $outfile_bash $outfile_pipex >$diff_file

    valgrind --leak-check=full ../pipex $infile "$cmd1" "$cmd2" $outfile_pipex 2>&1 | awk '{print $0}' >$outfile_leaks

    grep <$outfile_leaks '  definitely lost': | awk -F ':' '{print $2}' | awk '{print $1}' >$outfile_leaks_check
    grep <$outfile_leaks '  indirectly lost': | awk -F ':' '{print $2}' | awk '{print $1}' >>$outfile_leaks_check
    grep <$outfile_leaks '  possibly lost': | awk -F ':' '{print $2}' | awk '{print $1}' >>$outfile_leaks_check
    grep <$outfile_leaks '  still reachable': | awk -F ':' '{print $2}' | awk '{print $1}' >>$outfile_leaks_check
    grep <$outfile_leaks '  suppressed': | awk -F ':' '{print $2}' | awk '{print $1}' >>$outfile_leaks_check

    awk '{
  if ($0=="0") 
    printf "\033[32mCheck\033[0m"  
  else 
    printf "\033[31mError\033[0m"  
}' $outfile_leaks_check

    difference=$(wc <$diff_file -l)

    if [ $difference -eq 0 ]; then
        printf "\e[32mCHECK\e[0m\n"
    else
        printf "\e[31mERROR: DIFFERENT OUTPUT\e[0m\n"
    fi

}
