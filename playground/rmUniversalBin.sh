#!/bin/zsh
execs=$(find $@ -type f -perm +0111 -print)
execs=${execs//' '/'\ '}
while read file; do
    sudo lipo -remove x86_64 $file -output $file 2>/dev/null
done <<<"$execs"
