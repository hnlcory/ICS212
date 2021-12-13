# PROGRAM (Using javac and C compilers in UNIX) [10pt]

<strong style="color:red">This homework contains coding in both C and Java.</strong>

Use JNI (Java Native Interface) to create a program that allows a front-end Java user-interface which calls C functions.
The program you will develop must provide the same output as [Homework2](../hw2/hw2.html).

In homework2, you had everything in a single C source file.
```
            +----------------homework2.c-----------------------+
            |  user_interface                                  |
User <----> |                                                  |
            |  print_table -->(function call)--> is_multiple3  |
            +--------------------------------------------------+
```
Here, you will have the following structure.
```
            +-homework10.java-+               +-homework10.c--+
            |  user_interface |               |               |
User <----> |                 |               |               |
            |  print_table -->(function call)--> is_multiple3 |
            +-----------------+               +---------------+
```

Start by researching JNI on the web and try out simple examples.
Here is one of the online resources you can find.
https://www.oracle.com/webfolder/technetwork/tutorials/obe/java/JNI_OBE/JNI_OBE.html

# Java Requirements

1. File must be named as `homework10.java`

1. Define and use `user_interface` function which works in the same way as that in [Homework2](../hw2/hw2.html).

   - If the given number is less than or equal to 0, the program must display an error message and prompt the user to re-enter a value.

1. Define and use `print_table` function which generates the same table of [Homework2](../hw2/hw2.html).

   - It **MUST** call the `is_multiple3` function which is to be implemented in the C code. (the C code part is described in the next part)

1. Declare `is_multiple3` as a native method.

   A part of the declaration must be `int is_multiple3(int num);`

1. You will need to specify your C library to load in the Java code. There are more than one possible way but one of them would require you to type the absolute path (like `/home/...`). This would make your program runnable ONLY in your directory. So please **AVOID** it, and find a way **WITHOUT** using an absolute path. (If you never see any absolute path in your code, you are totally fine.)

1. Don't set `LD_LIBRARY_PATH`

   Your program must run without setting this environment variable.

# C Requirements

1. File must be named as `homework10.c`

1. Implement the function to be called by the Java code

1. No terminal output/input is allowed in C code

# Hints

1. <strong>The JDK installations on UH Unix are in: `/usr/java`</strong>

1. You will need to tell the C compiler the paths to directories containing the following:

   - `jni.h`
   - `jni_md.h`

   You can use `find` command to search them.

1. The name of shared library files in Unix should start with `lib`.

# Executable/Makefile

Write a makefile which generates a Java class file and library file from your source code.
Your makefile must be named as `Makefile`, and by running the command `make`, it must generate all files.
```
make
```

The command line to run your program may be long to type. To avoid typing a lengthy command, add a rule whose target is `run` into your `Makefile`. Then, under the rule, add the command line to run your program.
So it must be able to run your program by typing the following:
```
make run
```

# Proof of compilation: `proof.txt`

Use your `Makefile` and provide proof of compilation (both Java and C) by `script` command.

Note: make sure to show **all compilation and linkage.** If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

# Report of outputs: `output.txt`

Test your code and provide actual outputs by `script` command.

Note: Testing is NOT just running your program with some random input. You must **verify that your code correctly works and achieves all the requirements.** (Is only one test case enough to verify your code?)

# Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

   ```
   tar zcvf homework10.tar.gz homework10.java homework10.c Makefile proof.txt output.txt
   ```

2. Verify your tarball by this command

   ```
   tar tvf homework10.tar.gz
   ```
   If the command does not show all the required files, there is something wrong.
   **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

3. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

- Source code (`homework10.java` and `homework10.c`)

- `Makefile`

- Proof of compilation (`proof.txt`)

- sample output with two or three test cases (`output.txt`)
