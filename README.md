<br/>
<p align="center">
    <img src="https://github.com/rkrocha/42cursus/blob/main/badges/ft_printfe.png" alt="Logo" width="150" height="150">

  <h3 align="center">ft_printf</h3>

  <p align="center">
    Because putnbr and putstr aren't enough
    <br/>
    <br/>
  </p>
</p>



## About The Project

This project is pretty straight forward: it's about recoding printf. It mainly teaches how to use variadic arguments in C.

## Built With

* C

### Prerequisites

* A Shell terminal
* gcc compiler
* My [libft](https://github.com/rkrocha/libft/)

### Installation

1. Clone the repo
```sh
git clone git@github.com:rkrocha/ft_printf.git
```

2. Then inside ft_printf folder, clone libft:
```sh
git clone git@github.com:rkrocha/libft.git
```

3. Still inside ft_print folder, compile the library:
```sh
make
```

## Usage

1. Include the header in your program:
```c
#include "ft_printf.h"
```

2. Compile your program with the necessary flags indicating the path to ft_printf files and link the library:
```sh
gcc your_program.c -I~/path/to/ft_printf -L~/path/to/ft_printf -lftprintf
```
