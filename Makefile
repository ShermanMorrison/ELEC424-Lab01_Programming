ORDER= ASC
CC = gcc
CFLAGS= "-D$(ORDER)=1 -I"
	
sort : sort.c read_data.a
	$(CC) -g -o $@ sort.c read_data.a $(CFLAGS)

clean:
	rm -f sort.o sort 
