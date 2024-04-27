# pipex
pipex is a project that aims to recreate the command pipe in bash.

This project is made in C for 42School.

Allowed functions are ```open()```, ```malloc()```, ```free()```. ```dup2()```, ```exit()```, ```fork()```, ```pipe()```, ```execve()```, ```access()``` & ```wait()```

## Usage
**1. Clone the repository**
```
git clone https://github.com/alones-dev/pipex.git
```
**2. Compile the project**
```
make
```
**3. Enjoy**
```
./pipex Makefile "cat -e" "wc -l" out.txt
```
is same like
```
< Makefile "cat -e" | "wc -l" > out.txt
```

