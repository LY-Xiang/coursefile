#!/usr/bin/env bash
echo "-->start git..." && typeset -i err=0
echo "~~>git pull..." && git pull && err=$err+$?
echo "~~>git add..." && git add . && err=$err+$?
echo "~~>git commit..." && git commit -m "Auto Commit:$(date)" && err=$err+$?
echo "~~>git push..." && git push && err=$err+$?
echo "-->exit..." && exit $err
