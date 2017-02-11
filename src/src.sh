cpp_file=src.cpp
out_file=/tmp/cpp.out

clear
g++ $cpp_file -o $out_file -lgmpxx -lgmp
$out_file
