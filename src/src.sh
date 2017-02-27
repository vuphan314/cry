cc_files="cryptosystem/cryptosystem.cc cryptosystem/rsa.cc party/party.cc src.cc"
out_file=/tmp/cry.out

# clear
# reset
g++ -o $out_file -lgmpxx -lgmp $cc_files
$out_file
