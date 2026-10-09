# Notes

## C

in most expressions `my_arr` behaves like pointer to its first element
`my_arr[2]` is like `*(my_arr + 2)` is like `*(my_arr + (2 * sizeof(int)))`
pointer arithmetic uses the pointee type - the compiler knows how big the pointees are so treats + accordingly

`char *names[3] = {"one", "two", "a-longer-string"}`
`names[i]` is a char *
`names[i][j]` is a char


## TODO

LSP support?

## System calls

https://www.cs.virginia.edu/~cr4bd/4414/S2021/xv6.html
system call handling

    syscall.h, syscall.c — system call handling/dispatch code
    sysproc.c — process-related system call implementations
    sysfile.c — file-related system call implementations
    kshutdown.c,
