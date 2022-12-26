# Filter upper
upper    :   upper.o
	cc -o upper upper.o
upper.o  :   upper.c
	cc -c upper.c

# Filter lower
lower    :   lower.o
	cc -o lower lower.o
lower.o  :   lower.c
	cc -c lower.c

# All filters
filters	: upper lower

# All utilities
all	: upper lower
	
# clean up
clean :
	rm	upper    upper.o    \
		lower    lower.o	\
