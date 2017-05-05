# ./main.sh [minModulusLength plainText]

minModulusLength=$1
plainText=$2

# minModulusLength=32 # 0s cryptanalysis
# plainText=0123

# minModulusLength=46 # 10s cryptanalysis
# plainText=four6

# minModulusLength=64 # 1h cryptanalysis
# plainText=01234567

# minModulusLength=128 # 506-millennium cryptanalysis
# plainText="cry\nbaby"

############################################################

executable=./cry.out

receiver=pr
sender=ps
cryptosystem=rsa

keyGeneration="g $receiver $cryptosystem"
encryption="e $sender $receiver"
decryption="d $receiver $sender"
cryptanalysis="c $receiver $sender"

function run {
  $executable $keyGeneration
  # $executable $encryption
  # $executable $decryption
  # $executable $cryptanalysis
}

############################################################

# clear
# reset
make subsystem
make
# ./cry.out $minModulusLength $plainText
run
# make clean
