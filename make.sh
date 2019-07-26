gcc -c buffer.c -o buffer.o
gcc -c bwt.c -o bwt.o
gcc bwt.o buffer.o -o bwt
./bwt <<end
to be or not to be
end
