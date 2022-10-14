# Salesman Management System with File Handling

The final project of COMP 20033 Computer Programming 2 written in the C Language.



## How to use
*Note: Make sure you have a C compiler like [GCC](https://gcc.gnu.org/). To check, run `gcc -v` in your terminal*

1. First clone this git repository to your local device
```
git clone https://github.com/Pilner/salesman-management-with-file-system.git
```
2. Compile the code into your terminal
```
gcc main.c -o main.exe
```
3. Run the program
```
./main.exe
```



## Salesman Management System
Each of the salesman has these types of data assigned to each of them:
- Salesman ID
- Salesman Name
- Total Sales
- Commission



## How it Works
This program is intended to be used as a management system to manipulate the data of employees of a sales company.

It has four functions:
1. **Add** - Add data to the database
2. **Edit** - Edit respective data
3. **Delete** - Delete data
4. **View** - View the list of data in the database



## File Handling System
This program also makes use of the File Handling System from the standard library `stdio.h`. An external file, the `database.txt` file is used to act as the database of this program.



## Error Catching System
We brainstormed for all of the possible errors and bugs that is created by mostly human error which we strive to accomplish **Garbage Input - Perfect Output (GIPO)**. This means that invalid inputs will be rejected *but* will not break the program.



## Collaborators
- Alvin L. Almerol
- Zoe Tatianna M. Ong
- Paolo Luigi G. Recio
- Samantha Neil Q. Rico
- Fabian Railey A. Victuelles



## Licenses
MIT License

Copyright (c) 2022 Almerol, Ong, Recio, Rico, Victuelles

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.