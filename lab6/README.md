# Lab 6: Producer and Consumer

## Description
Create a program that has two parts. A producer and a consumer.
- Producer 
  - The producer generates random characters from ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). It adds these to a thread safe buffer that has a finite holding capacity of N characters. It generates a preset number of characters (determined at runtime) and when it has finished it add an ‘X’ character to the buffer and exits.

- Consumer 
  - The consumer takes these letters from the buffer at random time intervals (between 0 and 1 second in length) and records how many of each letter it consumes. Once it sees an ‘X’ in the buffer it adds its character count to a central buffer and exits.
  
## Source files
- Semaphore.h

- Semaphore.cpp

- Message.h

- Message.cpp

- MessageBuffer.h

- MessageBuffer.cpp

- main.cpp

- Makefile

- Doxyfile


## Execution 
There is a **Makefile** we can use to compile the c++ source code of this program within exercises, you can do like this:
```
$ make
```
and then you can run the executable program with the command:
```
$ ./ProdCon
```
If you want to clean the target object files of the c++ source code compilation, you can do like this:
```
$ make CLEAN
```


## Debbuger
There is a dugger command within linux.

- gdb commands
  - list [number]: list the source code arround the specific number line.

  - list : list the source code of the specific function.

  - run: to run the executable file with debug mode

  - break : add the breakpoint at the specific function name

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

