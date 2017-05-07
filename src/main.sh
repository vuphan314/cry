EXECUTABLE="./cry"

KEY_GENERATION="generatekeys"
ENCRYPTION="encrypt"
DECRYPTION="decrypt"
CRYPTANALYSIS="cryptanalyze"

############################################################

function run_doAction {
  sender=sender
  receiver=receiver
  cryptosystem=rsa

  keyGeneration="$KEY_GENERATION"
  # keyGeneration="$KEY_GENERATION $receiver $cryptosystem"
  encryption="$ENCRYPTION $sender $receiver"
  decryption="$DECRYPTION $receiver $sender"
  cryptanalysis="$CRYPTANALYSIS $receiver $sender"

  $EXECUTABLE $keyGeneration
  # $EXECUTABLE $encryption
  # $EXECUTABLE $decryption
  # $EXECUTABLE $cryptanalysis
}

############################################################

function run_breakRsa {
  minModulusLength=$1
  plainText=$2

  # minModulusLength=32 # 0s cryptanalysis
  # plainText=0123

  # minModulusLength=46 # 8s cryptanalysis
  # plainText=four6

  # minModulusLength=64 # 1h cryptanalysis
  # plainText=01234567

  # minModulusLength=128 # 506-millennium cryptanalysis
  # plainText="crybabies"

  $EXECUTABLE $minModulusLength $plainText $3
}

############################################################

make subsystem
make

# $EXECUTABLE $1 $2 $3 $4 $5
run_doAction
# run_breakRsa $1 $2 $3
