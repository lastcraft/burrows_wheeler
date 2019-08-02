rm bwt
gcc -c buffer.c -o buffer.o
gcc -c ring.c -o ring.o
gcc -c bwt.c -o bwt.o
gcc -c main.c -o main.o
gcc main.o bwt.o buffer.o ring.o -o bwt
./bwt <<end
to be or not to be
end
