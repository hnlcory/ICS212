
# File I/O [8 pts]

Write two functions: `writefile` to write data of an array into a file, and `readfile` to read data from a file and store it into an array.

Imagine like you are developing these two functions for some other programmer who will use the functions.
Before passing your source code to him/her, you must to make sure that the functions work correctly.
That is, you also need to write **driver code**, which actually calls the functions and provides results which you can use to prove that your funcitons work.
The output of the driver code must clearly show what the driver code is doing and what it got as the results so that anyone can objectively decide if the functions work.
(So you could NOT prove anything if your driver code called the functions in some way and just printed "yes, they work" at the end.)

# Structure definition

The elements of the array are `struct pokemon` objects.
Create a header file, `pokemon.h`, containing the following definition. (don't forget to follow the coding style)

```
struct pokemon
{
    int                level;
    char               name[25];
};
```

# Read/Write Functions

Create a header file, `iofunctions.h`, containing the following function prototypes. (don't forget to follow the coding style)

```
int writefile( struct pokemon pokearray[ ], int num, char filename[ ] );
int readfile( struct pokemon pokearray[ ], int* num, char filename[ ] );
```

Then, create a source file, `iofunctions.c`, defining the functions above.

Specifications

- The `writefile` function will write the data stored in the array into a text file.

  <strong style="color:red">If the text file already exits with some data, `writefile` must OVERWRITE it with the newly given data.</strong>
  For example, if the file has one pikachu and the array has a charizard and a bulbasaur, the file will only have a charizard and a bulbasaur after `writefile` function is called.

- The `readfile` function will read the data from a text file and store it in the array called by `pokearray`.

  - It must not load the pokemons more than the array can hold. If the array size is 10, the function must not load more than 10 pokemons.

  - It must tell the function which called `readfile` how many pokemons it has stored into the array.

- The return values must be used to tell whether the file was successfully open.

   - If the function could successfully open the file: return `0`
   - Otherwise, return `-1`

   <string style="color:red">IMPORTANT: You can assume that the file is always correctly formatted. You do not have to worry about incompatible data types, for example float where the pokeman name should be.</strong>

- _"The readfile may fail when the file cannot be open, but can we assume the writefile always works successfully as it creates a file?"_

   No, there is some case that the file cannot be open to write, e.g., the file system error.

- The size of the array and the number of pokemons in the text file are assumed to be arbitrary (You cannot assume the array size is always 5).

- The file name of the text file is also arbitrary.

- The text file must be just a sequence of items, i.e., it must not tell how many pokemons it contains at the beginning.

  For example, the contents in a file should look like this:
  ```
  16
  Pikachu
  9
  Metapod
  70
  Mewtwo
  ```

- They must not crash (segmentation fault) **even if the file does not exist or cannot be open.** (first run, some problem in the file system, etc)

**Reminder: `writefile` and `readfile` functions must not have the terminal I/O's (printf, scanf, etc).**

# Driver Code

- Create a source file, `driver.c`, defining the following local variables in the main function:

  ```
  struct pokemon pokemonbank[5];
  int numpokemons;
  ```
  **Note: You can define another array in the driver code if you need for your testing cases.**

- Test `writefile`/`readfile` by calling them with testing data.

  - You may get input from the keyboard or hardcode your testing data in the driver code.

  - The output of the program must be clear and self-explanatory (DO NOT just print like "The functions worked perfectly.", "SUCCESS", etc)

  - Test cases and results must be definitive proof that the functions work; make sure that your test cases can really prove that the functions work. (**critical thinking!**, e.g., *"What if the function was totally broken and it did not access the array and the file at all? Would the results be different from the successful case?"*)

- The driver code **MUST NOT** directly read or write a file.

# Executable/Makefile

Write a makefile which generates an executable from your source code.
Your makefile must be named as `Makefile` and executable as `homework5`
so you can compile and run your program by the commands:
```
make
./homework5
```

# Proof of compilation: `proof.txt`

Use your `Makefile` and provide proof of compilation by `script` command.

Note: make sure to show **all compilation and linkage.** If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

# Report of outputs: `output.txt`

Run your code and provide actual testing results by `script` command.

Note: If your driver code uses user-interface rather than using hardcoded testing inputs, make sure that you run your program with appropriate test cases to verify the functions.

# 📮 Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

  ```
  tar zcvf homework5.tar.gz driver.c iofunctions.h iofunctions.c pokemon.h proof.txt output.txt Makefile
  ```

2. Verify your tarball by this command

  ```
  tar tvf homework5.tar.gz
  ```
  If the command does not show all the required files, there is something wrong.
  **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

3. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

## List of required files

- Source code (`driver.c`, `iofunctions.h`, `iofunctions.c`, `pokemon.h`)

- `Makefile`

- Proof of compilation (`proof.txt`)

- Output with testing (`output.txt`)
