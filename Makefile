default:
	-gcc -o vplanet *.c -lm

debug:
	-gcc -g -o vplanet *.c -lm -Wno-div-by-zero
