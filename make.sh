gcc -c buffer.c -o buffer.o
gcc -c ring.c -o ring.o
gcc -c bwt.c -o bwt.o
gcc bwt.o buffer.o ring.o -o bwt
./bwt <<end
to be or not to be
end
