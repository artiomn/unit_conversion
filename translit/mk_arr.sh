# !/bin/sh
if [ $# != "1" ]; then
	echo "Syntax: $0 <filename>" >&2
	exit 1
fi

cat "$1"|awk '
		BEGIN {FS = " - "; ORS = ", "}
		{
			print("{" "\"" $1 "\"" ", " "\"" $2 "\"" "}");
		}
	'

echo
