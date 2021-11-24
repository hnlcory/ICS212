# Project 1 [25 points]

This project combines homework and/or concepts from Homework 3 through 6.
Follow the instructions and definitions below.

# User-interface

Please refer to [the requirements for user-interface in Homework3b](../hw3b/hw3b.html#user-interface)

**Make sure that the user-interface uses all the database functions above at appropriate timing.**
**If you had problems in the user-interface side, please fix them as well.**

# Database

## Data structure of record

Please refer to [the requirements for data structure in Homework3b](../hw3b/hw3b.html#data-structure-of-record).

## Database functions

- the following functions must be declared/defined in separate files: `database.h` and `database.c`.

   ```
   int addRecord (struct record **, int, char [ ],char [ ]);
   void printAllRecords(struct record *);
   int findRecord (struct record *, int);
   int deleteRecord(struct record **, int);
   int readfile(struct record **, char []);
   int writefile(struct record *, char []);
   void cleanup(struct record **);
   ```

- Implement the functions above:

   - `addRecord` will add a new record into a right position so that the list is kept sorted in a descending order of account numbers. <!-- check this every semester -->
   <!-- - `addRecord` does not accept a duplicate account number. -->
   <!--- `printRecord` will print the record with the matching account number.-->
   - `printAllRecords` will print the contents of the entire database
   - `findRecord` will print record(s) with a specified account #.
   - `deleteRecord` will delete all the records with the specified account number. <!-- check this every semester -->
   - `readfile` must be called once before the program starts interacting with the user.
   - `writefile` must be called once after the user chooses the quit option.
   - `cleanup` will releases all allocated spaces in the heap memory **and assign NULL to `start`**.

- You cannot change the definition of the `record` datatype
- You cannot change the parameters used by the functions shown above.
- You cannot create any additional database functions without approval.
- **The heap memory must be cleaned up by the `cleanup` function before you quit the program.**

<strong style="color:red">Optional:</strong> This is not a requirement, but if you want to have a separate function like `getaddress` to read the address information from the file, define the following function.

   `void getaddressfromfile(char [], int, FILE*);`

# Debug mode

Please refer to [the requirements for debug mode in Homework3b](../hw3b/hw3b.html#debug-mode).

# Executable/Makefile

Your makefile must be named as `Makefile` and executable as `project`
so you can compile and run your program by the commands:
```
make
./project
```

# Testing

**Note: the testing here is different from what you did by the script command in the previous assignments! Please read the insturections carefully.**

Retrieve your `testplan.xlsx` from Homework6b. Test your program by following your test cases. Fill in the "Results" column to report the testing results.

If it fails a test case, please describe how it fails, e.g., "The message was not printed."

After that, write a summary of the testing `summary.txt`. Describe how the test went. If you faced some problems, describe them.

<!--
# Shell script & GIT

<strong style="color:red">Please proceed after completing everything above! You need your completed source code to finish this part.</strong>

- Create a new git repository and add `.gitignore` file

  `.gitignore` must contain

  ```
  *
  !.gitignore
  !*.c
  !*.cpp
  !*.h
  !*.sh
  !Makefile
  ```

- Write a shell script `getreport.sh` to run the following commands (research how to write a shell script!)

  ```
  git --no-pager log --graph --date-order --all --pretty=format:'%h %Cred%d %Cgreen%ad %Cblue%cn %Creset%s' --date=short
  echo
  git status
  ls -la
  rm *.o
  make
  ```

- Add all source files, including `Makefile`, `.gitignore`, and `getreport.sh` to the repository.

  **Don't forget to commit!**

- Make a branch named `project1` by the command:

  ```
  git branch project1

  ```

- Provide proof of git usage.

  In the repository directory, follow these steps:

  1. Start the script command.

    ```
    script proof.txt
    ```

  1. Run your shell script `getreport.sh` (find a way to run a shell script!)

  1. Run your program by `./project`

    Note: You only need to test one menu option and you can quit after that.

  1. Finish the script command.

    ```
    exit
    ```

  Note: keep the repository directory. You will use it for Project 2.
-->

# Proof of compilation: `proof.txt`

Use your `Makefile` and provide proof of compilation by `script` command.

Note: make sure to show **all compilation and linkage.** If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

# Report of outputs: `output.txt`

Run your code and show some results by `script` command.

**As you will provide a complete testing report of your project1, you can just show some results of a few menu options. (the purpose of output.txt here is to verify that your program actually runs.)**

# Materials to Submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

   ```
   tar zcvf project1.tar.gz user_interface.c database.c database.h record.h Makefile proof.txt output.txt
   ```

   Note: you can include `testplan.xlsx` and/or `summary.txt` in the tarball if you want.

1. Verify your tarball by this command

   ```
   tar tvf project1.tar.gz
   ```
   If the command does not show all the required files, there is something wrong.
   **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

1. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

   **Note: if you did not include `testplan.xlsx` and/or `summary.txt` in the tarball, don't forget to submit them!**


## List of required files

- Source code including `Makefile`

   - `user_interface.c`
   - `database.c`
   - `database.h`
   - `record.h`
   - `Makefile`

   <!-- Note: an executable and object files are not a part of source code. -->

- Updated `testplan.xlsx`

   **If you prefer, you can attach `testplan.xlsx` separately on the submission page instead of including it in the tarball.**

- Complete summary of the test results (`summary.txt`)

- Proof of compilation (`proof.txt`)

- (Brief) results of a few menu options (`output.txt`)
