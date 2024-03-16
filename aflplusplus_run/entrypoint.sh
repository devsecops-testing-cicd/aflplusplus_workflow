#!/usr/bin/env sh

set -eu

ROOT_DIR="afl"

CAMPAIGN_NAME=$1
FUZZ_TARGET=$2
INPUT_FOLDER=$3
TIMEOUT=$4
TIME=$5
QEMU_MODE=$6

if [ "$QEMU_MODE" = true ]; then
	QFLAG="-Q"
else
	QFLAG=""
fi

# Print out the AFL++ fuzzing command before executing it
echo "Running AFL++ fuzzing command:"
echo "afl-fuzz -M \"$CAMPAIGN_NAME\" -t \"$TIMEOUT\" \"$QFLAG\" -i \"$INPUT_FOLDER\" -o \"$CAMPAIGN_NAME/output\" -- \"$FUZZ_TARGET\" @@"

# Run AFL++ fuzzing command

afl-fuzz -M $CAMPAIGN_NAME -t $TIMEOUT $QFLAG -i $INPUT_FOLDER -o "$CAMPAIGN_NAME/output" -- $FUZZ_TARGET @@ 

