minModulusLength= # argc == 1
plainText=

# minModulusLength=32
# plainText=0123

# minModulusLength=64 # 1h cryptanalysis
# plainText=01234567

############################################################

# clear
# reset
make
./cry.out $minModulusLength $plainText
# make clean
