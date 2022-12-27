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

# Util wc
wc    :   wc.o
	cc -o wc wc.o
wc.o  :   wc.c
	cc -c wc.c

# All utils
utils	: cat wc


# All filters and utilities
all	: filters utils


# All filters and utilities
install	: all
	mv upper ~/bin
	mv lower ~/bin
	mv cat   ~/bin
	mv wc    ~/bin


# clean up
clean :
	rm	upper    upper.o    \
		lower    lower.o	\
		cat      cat.o	    \
		wc       wc.o	    \
