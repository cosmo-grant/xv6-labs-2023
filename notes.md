# Notes

## C

in most expressions `my_arr` behaves like pointer to its first element
`my_arr[2]` is like `*(my_arr + 2)` is like `*(my_arr + (2 * sizeof(int)))`
pointer arithmetic uses the pointee type - the compiler knows how big the pointees are so treats + accordingly

`char *names[3] = {"one", "two", "a-longer-string"}`
`names[i]` is a char *
`names[i][j]` is a char


## TODO

Where to push my commits?
