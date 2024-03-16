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

mkdir -p "$CAMPAIGN_NAME/output"

afl-fuzz -M $CAMPAIGN_NAME -t $TIMEOUT $QEMU_MODE -i $INPUT_FOLDER -o "$CAMPAIGN_NAME/output" $FUZZ_TARGET @@ 

