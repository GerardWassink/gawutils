upper    :   upper.o
	cc -o upper upper.o
upper.o  :   upper.c
	cc -c upper.c

lower    :   lower.o
	cc -o lower lower.o
lower.o  :   lower.c
	cc -c lower.c

all	: upper lower
	
clean :
	rm	upper    upper.o    \
		lower    lower.o	\
