#!/bin/bash
tecla=0
while [[ 1=1 ]]; do
	if [[ $tecla = 0 ]]; then
		read -p "Digite o nome ou indice do arquivo: " entrada
		arquivo=`find ${entrada%.c}*.c | cut -d . -f 1`
		tecla=1
	fi
	if [[ $tecla = q ]]; then
		break;
	fi
	echo "Executando" $arquivo".c:"
	echo "---------------------------------------------------"
	# i686-w64-mingw32-gcc -x c $arquivo.c -o $arquivo"_x86.exe"
	x86_64-w64-mingw32-gcc -x c $arquivo.c -o $arquivo"_x64.exe"
	gcc -x c $arquivo.c -o $arquivo.tmp && ./$arquivo.tmp
	find . -name "*.tmp" -exec rm -rf {} \;
	echo "---------------------------------------------------"
	echo "Tecle '0' para excolher outro arquivo."
	echo "Tecle 'q' para sair."
	read -p "Tecle qualquer outro caractere para executar novamente." -n1 -s tecla
	echo ""
done
# AWMO
