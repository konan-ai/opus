#!/bin/sh
set -e
URL="https://opus-codec.org/static/examples/samples/speech_orig.wav"
INPUT="speech_orig.wav"
if [ ! -f "$INPUT" ]; then
  curl -L -o "$INPUT" "$URL"
fi
rates="48000 24000 16000 12000 8000"
for r in $rates; do
  rm -rf dumps tmp.opus out.pcm
  mkdir dumps
  export OPUS_DUMP_DIR="dumps"
  ./opus_demo voip $r 1 $r "$INPUT" tmp.opus > /dev/null
  ./opus_demo -d $r 1 tmp.opus out.pcm > /dev/null
  if [ -f dumps/enc_silk.bin ]; then
    cmp dumps/enc_silk.bin dumps/dec_silk.bin
  fi
  if [ -f dumps/enc_celt.bin ]; then
    cmp dumps/enc_celt.bin dumps/dec_celt.bin
  fi
  echo "Rate $r OK"
  unset OPUS_DUMP_DIR
done
