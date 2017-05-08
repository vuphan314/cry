EXECUTABLE="./cry"

TESTING="$EXECUTABLE t"
KEY_GENERATING="$EXECUTABLE g"
ENCRYPTING="$EXECUTABLE e"
DECRYPTING="$EXECUTABLE d"
CRYPTANALYZING="$EXECUTABLE c"

SPECIFIC_SENDER="send"
SPECIFIC_RECEIVER="receive"

############################################################

function run_doAction {
  plainText="cry?"
  cryptosystem="rsa"

  $TESTING $plainText $cryptosystem $1 $2
  $KEY_GENERATING $SPECIFIC_RECEIVER $cryptosystem $1 $2
  $ENCRYPTING $SPECIFIC_SENDER $SPECIFIC_RECEIVER
  $DECRYPTING $SPECIFIC_RECEIVER $SPECIFIC_SENDER
  $CRYPTANALYZING $SPECIFIC_RECEIVER $SPECIFIC_SENDER
}

############################################################

function run_breakRsa {
  minModulusLength=$1
  plainText=$2

  # minModulusLength=32 # 0s cryptanalysis
  # plainText=0123

  # minModulusLength=44 # 2s cryptanalysis
  # plainText=01234

  # minModulusLength=64 # 1h cryptanalysis
  # plainText=01234567

  # minModulusLength=128 # 506-millennium cryptanalysis
  # plainText=crybabies

  $EXECUTABLE $minModulusLength $plainText $3
}

############################################################

make subsystem
make

$EXECUTABLE $1 $2 $3 $4 $5
# run_doAction $1 $2
# run_breakRsa $1 $2 $3
