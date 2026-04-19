# mycat

A minimal clone of the Unix `cat` utility, written in C.

## What it does

Reads the contents of one or more files and writes them to standard output.

## Build

```
gcc -Wall -Wextra -std=gnu11 -o mycat mycat.c
```

## Usage

```
./mycat file.txt                # print contents of file.txt
./mycat file1.txt file2.txt     # concatenate multiple files to stdout
./mycat -n file.txt             # number each line in the output
./mycat -n file1.txt file2.txt  # number lines continuously across files
./mycat                         # prints usage to stderr, exits non-zero
./mycat missing.txt             # prints error to stderr, exits non-zero
./mycat -x file.txt             # unknown option: prints usage, exits non-zero
```

## Options

| Flag | Description                                      |
|------|--------------------------------------------------|
| `-n` | Prefix each line of output with its line number. |
