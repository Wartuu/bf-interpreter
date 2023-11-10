# bf-interpreter



## usage:
```
bf <filename>
```

## brainfuck cheatsheet:
* '>' - increase pointer
* '<' - decrease pointer
* '+' - increase value
* '-' - decrease value
* '[' - start loop
* ']' - go to the start point (until value is 0)

## build:
```
g++ main.cpp --static -O3 -o bf
```
