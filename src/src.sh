cc_file=src.cc
out_file=/tmp/cry.out

# clear
g++ -o $out_file -lgmpxx -lgmp $cc_file
$out_file
