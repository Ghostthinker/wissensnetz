#!/bin/bash
FILES=samples/*
for f in $FILES
do
  echo "Processing $f file..."

	filename=$(basename "$f")
	extension="${filename##*.}"
	filename="${filename%.*}"
  echo $filename
  echo $extension
  echo "========================================"

  # take action on each file. $f store current file name
  curl --form file=@$f  http://video17.edubreak.de/convert/jpg > out/$extension.jpg
done

