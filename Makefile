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


# Util cat
cat    :   cat.o
	cc -o cat cat.o
cat.o  :   cat.c
	cc -c cat.c

# All utils
utils	: cat


# All filters and utilities
all	: cat upper lower
	
# clean up
clean :
	rm	upper    upper.o    \
		lower    lower.o	\
		cat      cat.o	    \
