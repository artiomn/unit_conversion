#!/bin/bash
E_SQ="q w e r t y u i o p a s d f g h j k l z x c v b n m"
R_SQ="Ê Ã Õ Ë Ë Å Î Ç Û Ý Ú È ß Æ Ù × Á Ð Ò Ï Ì Ä Ö Ü Ñ Þ Ó Í É Ô Ø Â À"
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
