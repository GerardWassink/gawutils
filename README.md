# gawutils

Oh well, I suppose lots of people have had a go at this, 
these are my versions of elementary Linux commands.
To be extended when I feel like it... ;-)

## filters
The programs in this category van be used as filters in pipe constructions

### upper
upper is a filter program that:
- reads characters from stdin
- looks for lower case letters
- converts those to upper case
- writes everything thru to stdout

### lower
lower is a filter program that:
- reads characters from stdin
- looks for upper case letters
- converts those to lower case
- writes everything thru to stdout

### cat
cat is a concatenation utility
- looks at commandline arguments, assumes they are filenames
- when arguments present, files are read and copied to stdout
- when no arguments present, stdin is read and copied to stdout
