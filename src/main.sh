# ./main.sh [minModulusLength plainText]

minModulusLength=$1
plainText=$2

# minModulusLength=32 # 0s cryptanalysis
# plainText=0123

# minModulusLength=46 # 10s cryptanalysis
# plainText=four6

# minModulusLength=64 # 1h cryptanalysis
# plainText=01234567

minModulusLength=128 # 506-millennium cryptanalysis
plainText='cry\nbaby\n'

############################################################

# clear
# reset
make subsystem
make
./cry.out $minModulusLength $plainText
# make clean
