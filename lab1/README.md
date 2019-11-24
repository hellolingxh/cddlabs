# Lab1:The Toolchain

## Description
The purpose of this lab is to introduce you to the Unix (GNU Linux) command
line tools. We will specifically use:
1. Git for document versioning and management (C++ files in our case)
2. Emacs for editing
3. g++ for compiling
4. gdb for debugging
5. Make for managing code projects
6. Doxygen for documenting code

## Execution
There are 4 Makefiles(Makefile1, Makefile2, Makefile3, Makefile4) we can use to compile the c++ source code within exercises.
If you would compile the c++ source code with Makefile1, you can do like this:
```
$ mv Makefile1 Makefile
```
and then you can use the **make** command within linux
```
$ make
```
Of course, you can also try the other makefiles such as Makefile, Makefile2, Makefile3 and Makefile.

## Debugger
There is a dugger command within linux.
- gdb commands
	- list [number]: list the source code arround the specific number line.
	- list <function>: list the source code of the specific function.
	
	- run: to run the executable file with debug mode
	
	- break <function>: add the breakpoint at the specific function name
	- break [number]: add the breakpoint at the specific number line.

	- next: execute the next line code.

	- step: if the code line is function, then enter the function.

## License
The MIT License
```
/* * Copyright (c) 2019 Xiaohui Ling
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */
```
