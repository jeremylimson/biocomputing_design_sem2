# 2-15-2022
# jeremy limson
# description : makefile for vector and stats machine codes and executables

CC=g++

vector_op.o: limsonj_vectors_ops.cpp limsonj_vectors_ops.hpp
	$(CC) -c $^

stats_op.o: limsonj_stats.cpp limsonj_stats.hpp
	$(CC) -c $^

vect_op_exe: limsonj_vectors_ops.o #limsonj_vectors_ops_test.o
	$(CC) -o $@ $^

all: stats_op.o vect_op_exe
	
clean:
	rm -f *.o
	rm -f *.gch