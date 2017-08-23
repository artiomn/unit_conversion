#!/bin/bash
E_SQ="q w e r t y u i o p a s d f g h j k l z x c v b n m"
R_SQ="й ц у к к е н г ш щ з х ъ ф ы в а п р о л д ж э я ч с м и т ь б ю"
SQ="$E_SQ"
if [ $# -gt "0" ]; then
	if [ "$1" == "-e" ];
		then SQ="$E_SQ";
		elif [ "$1" == "-r" ]; then SQ="$R_SQ";
	fi
fi

for i in $SQ ;do
	for j in $SQ; do
		echo -n "$i$j "
	done
	echo -ne "\n"
done
