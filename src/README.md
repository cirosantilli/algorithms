# src

Files which are WIP will get the `.off` extension appended to their original names to prevent their compilation.

## Preferred program interface

The preferred program interface is:

- takes input from a data file give as a command line argument, e.g. `./program /path/to/data/0.in`
- outputs the output to stdout
- the exit status must be 0 on success

Although stdin input is more elegant as it does not require file IO, file input is more general as it allow for out-of-core considerations.

File output should also be supported some day.

## Alternative program interface

If you have just created a program, it may be faster to put the data and assertions into it directly, and only return its output via the exit status, with `0` for success and non-zero for failure.

But it has the following downsides:

- cannot share the data across languages
- you must recompile on data changes

So only use this if you are lazy and have only a single program that takes a given type of input.
