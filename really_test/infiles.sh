#!/usr/bin/bash

infile0=infile0.txt
infile1=infile1.txt
infile2=infile2.txt
infile3=infile3.txt
infile4=infile4.txt
infile5=infile5.txt
infile6=infile6.txt
infile7=infile7.txt
infile8=infile8.txt
infile9=infile9.txt

(
    cat <<EOF
line1
line2
line3
line4
line5
line6
line7
line8
line9
line10
EOF
) | tee $infile0 >/dev/null

rm $infile1
touch $infile1

(
    cat <<EOF
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.
Lorem ipsum dolor sit amet consectetur adipisicing elit. Reprehenderit, distinctio.



EOF
) | tee $infile2 >/dev/null

(
    cat <<EOF




EOF
) | tee $infile3 >/dev/null

(
    cat <<EOF

\\\
///
##
gfgd
,.'.''.

EOF
) | tee $infile4 >/dev/null