rm bwt
gcc -c buffer.c -o buffer.o
gcc -c rotation.c -o rotation.o
gcc -c bwt.c -o bwt.o
gcc -c main.c -o main.o
gcc main.o bwt.o buffer.o rotation.o -o bwt
./bwt <<end
to be or not to be
end
