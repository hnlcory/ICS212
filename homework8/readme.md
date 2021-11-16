# C++ programming [5 pts]

Redo the programming assignment from [Homework 2](../hw2/hw2.html) in C++. Replace all C input/output statements with
C++ statements (`cin`, `cout`) to get the same formatted output as Homework 2.

# Overview

Your code must follow the following items:

1. Create a C++ source file `homework8.cpp` and migrate your code from Homework 2.

1. Replace the C-style terminal input/output with those of C++.

   1. You cannot use `stdio.h` (you cannot use `cstdio`, either)
   1. Instead, use `iostream` and `iomanip`

      **See the details below**

1. Re-make the `is_multiple3` function as the following prototype:

   - `void is_multiple3(int, int&);`

   _Discuss and find how to use the parameters._

1. You must compile your code using `g++` command <font color="red">on UH Unix</font> using <font color="red">the required compilation options</font> described on the course main page.

# C++ terminal input/output

In your C code, you used to include `stdio.h`, right?
```
#include <stdio.h>
```

Replace this line with the following lines:
```
#include <iostream>
#include <iomanip>
```
<!--
- `iostream` provides methods to print data to the terminal and to get information from the terminal.
- `iomanip` provides methods to format the terminal outputs, e.g., alignment, number of digits, etc.
-->

## Optional

You are going to use features in the namespace `std`, and you need to specify
under which namespace the feature is defined, e.g., `std::cout`.
This is **optional**, but you can omit this by `using` declaration.
Right after the lines of `#include` directives, you can put this line.
```
using namespace std;
```
Then, you can simply use features without `std::`.
But it is good practice if you always explicitly write `std::` so that you can
understand which features are provided under `std`.

## Output

Instead for `printf` and other C-style functions, you must use **`cout`**.

For example, this line will print "Hello World" to the terminal.
```
std::cout << "Hello World" << std::endl;
```

You can find more examples with different datatypes on this page.
http://www.cplusplus.com/doc/tutorial/basic_io/#cout

**manipulators**

For formatting, you will insert "manipulators" before what you want to print. For example, this will print 10 in base 16, i.e., `a`.
```
std::cout << std::hex << 10 << std::endl;
```

You can find other manipulators in these pages. You will use some of them so that you can print the table in the required format.
- http://www.cplusplus.com/reference/ios/#functions
- http://www.cplusplus.com/reference/iomanip/


## Input

Instead for `scanf` and any other C-style functions, you must use **`cin`**. <!-- and/or **`getline`**.-->

`cin` can be used in a similar way as `cout`.
http://www.cplusplus.com/doc/tutorial/basic_io/#cin

The following piece of code will get a number from the terminal input and store it in the variable `num`.
```
int num;
std::cin >> num;
```
*Note: You don't need `std::` if you have `using namespace std;`.*

To check invalid inputs, `cin` has member functions which you can call like `cin.X()` (replace `X` with the function name).
You can find the functions on this page. See the functions under "State flag functions".
http://www.cplusplus.com/reference/ios/ios/#functions

<!--
To read a whole line, you can use `getline`. Be careful about the behavior as it is different from that of `fgets` to handle a newline character.
http://www.cplusplus.com/reference/string/string/getline/
-->

# FAQ

1. For this assignment, I am prohibited from using `stdio.h`, but can I use other C header files, e.g., `stdlib.h`?

   - *Yes, you can include them.*
     *You can also use specific forms to specifically include C header files, e.g., `cstdlib`*

1. Can I use `cstdio`?

   - *No because it is equivalent to `stdio.h`.*

1. Do I need to submit a Makefile?

   - *No.*

1. For testing, do I need to consider a specific case?

   - *No, just give an ordinary case to show that your program runs correctly.*

# Proof of compilation: proof.txt

- Show a proof of compilation by using `script` command
- The scripted file must be named as `proof.txt`

   ```
   % script proof.txt

   < compilation and linkage >

   % exit
   ```

- In the proof, compile and link your files and generate an executable named as `homework8`

- Again, you must use `g++` command and <font color="red">the required compilation options</font> described on the course main page.

# Testing results: `output.txt`

- Record the testing results by using `script` command
- The scripted file must be named as `output.txt`

   ```
   % script output.txt
   % ./homework8

   < testing results >

   % exit
   ```

# 📮 Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

   ```
   tar zcvf homework8.tar.gz homework8.cpp proof.txt output.txt
   ```

1. Verify your tarball by this command

   ```
   tar tvf homework8.tar.gz
   ```
   If the command does not show all the required files, there is something wrong.
   **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

1. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

## List of required files

- Source Code (`homework8.cpp`)

- Proof of compilation (`proof.txt`)

- Output with ONE test case (`output.txt`)
