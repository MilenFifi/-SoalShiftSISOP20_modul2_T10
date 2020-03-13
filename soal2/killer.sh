#!/bin/bash
for i in $*
do
  if [[ $i == "-a" ]]; then
    ps aux | grep s3 | awk '$7 ~/?/ { printf "%s", $2; }' | (read msg; kill -9 $msg;);
  elif [[ $i == "-b" ]]; then
    ps aux | grep s3 | awk '$7 ~/?/ { printf "%s", $2; }' | (read msg; kill -2 $msg;);
exit 0
fi
