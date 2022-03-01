# 2-15-2022
# jeremy limson
# description : makefile for vector and stats machine codes and executables

CC=g++

vector_op.o: limsonj_vectors_ops.cpp limsonj_vectors_ops.hpp
	$(CC) -c $^

pre_processing.o: limsonj_vector_ops_pre_processing.cpp limsonj_vector_ops_pre_processing.hpp
	$(CC) -c $^

stats_op.o: limsonj_stats.cpp limsonj_stats.hpp
	$(CC) -c $^

vect_op_exe: limsonj_vectors_ops.o limsonj_vector_ops_pre_processing.o
	$(CC) -o $@ $^

cluster_op: limsonj_k_means.cpp limsonj_k_means.hpp limsonj_cluster.cpp
	$(CC) -c $^

cluster_op_exe: limsonj_k_means.o limsonj_stats.o limsonj_cluster.o
	$(CC) -o $@ $^

all: stats_op.o vect_op_exe cluster_op_exe
	
clean:
	rm -f *.o
	rm -f *.gch