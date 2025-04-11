# **🚀 pipex**

Welcome to **pipex**! 🎉  
This project is all about recreating the power of the **pipe** command in **bash**! In simple terms, **pipex** allows you to simulate the piping functionality (`|`) used in bash to chain commands together. It's a fun and challenging way to dive into **process management**, **pipes**, and **system-level programming** in C.

## 🎯 **Project Overview**

**pipex** aims to mimic the behavior of the pipe command in **bash**. The goal is to read the output of one command and send it as input to another, all while using **system calls** like `fork()`, `execve()`, and `pipe()` to replicate the behavior from scratch.

### **Key Functions Allowed:**
- `open()`
- `malloc()`
- `free()`
- `dup2()`
- `exit()`
- `fork()`
- `pipe()`
- `execve()`
- `access()`
- `wait()`

This is an awesome exercise to understand **process management**, **I/O redirection**, and how commands interact in the terminal. 💻✨

## 🛠️ Usage
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

