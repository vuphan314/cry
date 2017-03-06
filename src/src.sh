cc_files=" cryptosystem/rsa_cryptosystem.cc party/party.cc src.cc"
out_file=/tmp/cry.out

# clear
# reset
g++ -o $out_file -lgmpxx -lgmp $cc_files
$out_file
