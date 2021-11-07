# Introduction of Bank Database Application [18 pt]

Imagine a banker sitting at the customer desk's computer. The banker's task is
to manage customer's bank records stored in their database: create a new
record, view an existing one, delete an record, etc. The software is
composed of two parts: user-interface (UI) and database (DB).
```
                             +----------+-----------+
                             |          |           |
Banker  <-- interactions --> |   UI   <-+->   DB    |
                             |          |           |
                             +----------+-----------+
```
To access the database, the banker interacts with user-interface, which displays
data and accepts inputs while accessing the database part.

In this assignment, you will finish the user-interface code. The database part
is to be developed later, but the UI must be able to call correct functions of
the DB part. To do so, the DB part must have "stub functions" which the UI
calls.
That is, after finishing this assignment, it will look like this.
```
                          Finish the UI!
                                 👇
                             +----------+-----------+
                             |          |           |
Banker  <-- interactions --> |   UI   <-+->  stubs  |
                             |          |           |
                             +----------+-----------+
                                        👆
                           Also make it to access the stubs.
```
For more details, see the following requirements below.

# Data structure of record

- Create `record.h` and define the following structure:

   ```
   struct record
   {
       int                accountno;
       char               name[25];
       char               address[50];
       struct record*     next;
   };
   ```

   **Don't forget to follow the coding style!**

# Database

- the following functions must be declared in `database.h` and defined in `database.c`.

   ```
   int addRecord (struct record **, int, char [ ],char [ ]);
   void printAllRecords(struct record *);
   int findRecord (struct record *, int);
   int deleteRecord(struct record **, int);
   ```

   <strong style="color:red">Do not implement or complete the above functions.</strong> They are **stubs** for now, and will be implemented in the later assignments. (if you don't know what "stub" means, do some research or ask a question!)

# User-interface

- Create `user_interface.c` and implement your user-interface.
- Define the following item **in the main function**:

   ```
   struct record * start = NULL;
   ```
   and pass it or its address to the database functions.

## Menu

- The transactions must be formatted in this form.

   ```
   <introductory message>

   <instruction for the user to choose a menu option>
   add: <description>
   printall: <description>
   find: <description>
   ...

   <the user types the corresponding option and hit the enter>

   <ask for additional information if necessary (e.g., account# etc)>

   <call the database function specified by the menu option with the user inputs>

   <display the results (this may be done in later assignments)>

   <repeat the transaction again unless the selected option was to quit the program>
   ```

   - Display a introductory message at the beginning.
   - Display instructions for the menu and the menu options.
   - The user must be able to specify the menu option by typing the option name (menu options to implement are listed below).
   - If needed for the selected menu option, collect the appropriate information from the user (e.g., account # etc).
   - Display the results
   - Unless the user chose to quit the program, display the menu and ask for a menu option again.

- The following menu options must be available:

   - `add`: Add a new record in the database
   - `printall`: Print all records in the database
   - `find`: Find record(s) with a specified account #
   - `delete`: Delete existing record(s) from the database using the account # as a key
   - `quit`: Quit the program

- The program must allow the user to type a partial or full option name (listed above) to choose an option.

   **For example, if the user gives `a` or `ad`, the program must accept it as an option for `add`, BUT it must reject invalid word starting with the command such as `adding`, `address`, etc.**

- To check what the user typed for the menu option, use at least one function declared in `string.h`.

   For example,

   - `strlen`
   - `strcmp`, `strncmp`
   - `strcpy`, `strncpy`
   - `strcat`, `strncat`

   You can find the details in the textbook and some online websites such as https://en.cppreference.com/w/cpp/header/cstring

- If the user gives invalid option name, display an error message and ask for a valid menu option (it must not exit!)
- Except for `quit` option, a menu option must call the corresponding database function with the appropriate user input.
- You must use a while or do-while loop for the menu.

## User Inputs

Each record contains the account number (int), name (char [ ]), and
mailing address(char [ ]) fields.

- The account number must be a positive number (> 0).

   Like you did in the past homework, if the user gives an invalid input such as a negative number, 0, or alphabets (e.g., `abc`),
   the program must **display an error message** AND **prompt the user to enter a positive integer.**

   You only need to test for the input of characters and integers. You do not have to worry about floats being entered. Also, if the input is like `123abc`, you can either extract the number or simply reject it as an invalid input.

- The name field must accept a string containing white spaces, i.e., it allows all characters until it sees a newline character.

   For example, "Ravi", "Tetsuya", "Dr. Dennis Ritchie", "John F. Kennedy Jr.", "Elizabeth the 1st" and so on.

   You can deal with symbols like "#", "$", etc as regular characters.

- Write your `getaddress` function to obtain the address information

   - The address field may have **multiple lines** of address
   - The user can provide the address information in any format.

      The user may type
      ```
      111 Dole St, Honolulu, HI 96822
      ```
      ```
      111 Dole St
      Honolulu, HI 96822
      ```
      ```
      111 Another St, Apt. 222
      Some city, CA 12345 USA
      ```
      ```
      Some ward
      Far city
      ABC
      Distant Republic
      ```
      ```
      Jezero crater
      North hemisphere
      Mars
      ```
      or any multi-line string.

      So you cannot assume it always ends with a specific pattern like zip code.

   - It must be stored as **one character array**

      **The array must hold the address information as it is.**
      When you print it into the terminal, it must appear the same as what the
      user typed.
      (you must not replace newline characters with white spaces or other
      characters.)

   - You **CANNOT** ask the user how many lines of address they are going to type
   - You **CANNOT** ask if the user wants to type one more line during typing.
   - Prototype for the function is
      ```
      void getaddress (char [], int);
      ```

## FAQ

_Can I define a function that is not specified in the assignment instructions? I want to use it as a helper function._

Please refer to the [FAQs](../../main_sub/faq.html) for general rules for defining a helper function.
Additionally, you should also be (really) careful about a pointer for `strcut record`.
If you are considering some function taking a pointer of struct record (`struct record*`) or a pointer of pointer (`struct record**`), it is NOT recommendable. In the past, there were some students who made helper functions for each menu option taking pointers. And in the later assignments, they faced many problems when they were implementing the database.c, and they spent a lot of time for debugging and even re-writing their code entirely.

# Debug Mode

- Your program must use command-line arguments for debugging.
- This program may be invoked by typing the executable name (`./homework3`) or with the option `debug`. (`./homework3 debug`). Anything else such as `./homework3 debug test` or `./homework3 test` should give an error message **AND EXIT**.
<!-- - The format of the error must be similar to the one you get when you type `cp` in UNIX. -->
- To check the given argument, use at least one function declared in `string.h`.

- A global variable, `debugmode`, must be defined and used to indicate whether the program is running in the debug mode or not.

- When the program runs in the debug option, **every function (except for the main)** must print additional information on the screen when it is called.

   - The output must verify the following items

      - _The name of the called function_
      - _The function parameter names and values_ (but you don't have to print variables of `struct record *` and `struct record **`)

   - The output must be meaningful and distinguishable from the regular output.

      If you can see which part of the output is from the debug mode at a glance, that is good enough.
      At least, you should add a blank line between the regular and debug outputs.
      **If the output is too ugly to read, you may lose points.**

   - *Q: Would it be OK if I printed the debug information in the main function? For example, I would print the debug information about some function before I actually call the function.*

      *A: What do you think? :) Would it achieve the purpose of this debug mode?*

   - *Q: If the datatype of some parameter is `char *`, should I print the address stored in it or the string to which it points?*

      *A: What do you think? :) What are we trying to make sure here by printing the debug information? Which one is more informative?*

# Executable/Makefile

Create a `Makefile` for your code.
We may briefly discuss `Makefile` in a class but you're responsible for doing the majority of research on your own. Fortunately, there is a lot of information available on the Internet about this utility. These are some online pages you can check. You only need the first parts.

- GNU make - An Introduction to Makefiles: https://www.gnu.org/software/make/manual/make.html#Introduction

   You may read 2.1 and 2.2. But 2.3 and later parts are not necessary.

- Learn Makefiles - Getting Started: https://makefiletutorial.com/#getting-started

   You may read the page until the secion "Beginner Examples". The parts beyond this section are not necessary.

- What is a Makefile and how does it work?: https://opensource.com/article/18/8/what-how-makefile

   "Basic examples" should be enough. Once it starts talking about "@echo", you can stop reading as the further parts of that page are not necessary.

<strong style="color:red">Note:</strong> The example Makefiles in those pages above are for their own sample code. So you cannot blindly copy and paste since it will not work. Also, don't forget that you need to use `gcc` with [the required options](../../main_sub/compilation.html). **You will lose points if your Makefile does not run the required compilation/linkage commands.**

Your `Makefile` must achieve the following requirements.

- It must compile a source file separately with the required options.

- It must link the object files to generate an executable named as `homework3`.

- Do **NOT** use any **macro** or **substitution references**! (stick to basics)

   If your `Makefile` contains `$`, `@`, or `%`, you are highly likely using them and you may lose some points.
   **This rule is also applied to the later assignments.**

- It must behave in the same way as the example below:

   ```
   % touch *.c
   % make
   <compilation>
   <linkage>
   % make
   make: 'homework3' is up to date.
   % touch user_interface.c
   % make
   <compilation only for user_interface.c>
   <linkage>
   % touch *.o
   % make
   <linkage>
   % ./homework3
   <output of homework3>
   ```

Your makefile must be named as `Makefile` and executable as `homework3`
so you can compile and run your program by the commands:
```
$ make
$ ./homework3
```

# Proof of compilation: `proof.txt`

Use your `Makefile` and provide proof of compilation by `script` command.

Note: make sure to show **all compilation and linkage.** If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

# Report of outputs: `output.txt`

Test your code and provide actual outputs by `script` command.

Note: Testing is NOT just running your program with some random input. You must **verify that your code correctly works and achieves all the requirements.** (Is only one test case enough to verify your code?)

# Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

   ```
   tar zcvf homework3.tar.gz user_interface.c database.c database.h record.h proof.txt output.txt Makefile
   ```

1. Verify your tarball by this command

   ```
   tar tvf homework3.tar.gz
   ```
   If the command does not show all the required files, there is something wrong.
   **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

1. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

## List of required files

- Source code including `Makefile`

   - `user_interface.c`
   - `database.c`
   - `database.h`
   - `record.h`
   - `Makefile`

- Proof of compilation (`proof.txt`)

- Output with testing (`output.txt`)
