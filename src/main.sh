# ./main.sh [minModulusLength plainText]

minModulusLength=$1
plainText=$2

# minModulusLength=32 # 0s cryptanalysis
# plainText=0123

minModulusLength=46 # 8s cryptanalysis
plainText=four6

# minModulusLength=64 # 1h cryptanalysis
# plainText=01234567

############################################################

# clear
# reset
make subsystem
make
./cry.out $minModulusLength $plainText
# make clean
