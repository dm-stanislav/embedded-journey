# mycat

A minimal clone of the Unix `cat` utility, written in C.

## What it does

Reads the contents of a file and writes them to standard output.

```
./mycat file.txt      # print contents of file.txt
./mycat               # prints usage message to stderr, exits non-zero
./mycat missing.txt   # prints error to stderr, exits non-zero
```
