# Inheritance [10pt]

Follow the instructions below and create a simple program which uses a class hierarchy.

# Class hierarchy

Create three pokemon classes which derive from the parent class `Pokemon`.

No idea which pokemons to create? Pick up three from here: https://www.pokemon.com/us/pokedex/

## Parent class: `Pokemon`

- has these member variables

   ```
   protected:
       string type; // e.g., electric, poison, etc
       float weight;
   ```

- Constructor:

   - print `Pokemon Constructor`

- Destructor:

   - print `Pokemon Destructor`

- has the following member function prototype: `void printData();`

   ***note: only prototype in this class. You will define it for each child class.***

- **must be an abstract class**

## Three child classes

- Constructor:

   - initialize the member variables for the child class

   - print `<class name> Constructor` (replace `<class name>` with the actual class name)

- Destructor:

   - print `<class name> Destructor` (replace `<class name>` with the actual class name)

- must inherit `void printData();` and the function must print the following information.

   - Name of the child class
   - A string stored in `type`
   - A value stored in `weight`

## Requirements for both parent and child classes

- Each class must have its own `.cpp` and `.h` files.

   - cpp file: member function definitions, etc.
   - h file: class definition, etc.

- All destructors must be `virtual`.

# The main function

Create `main.cpp` and write a main function which performs the following.

- Create instances of all the child classes **in the heap memory**, and store their addresses in **pointers of `Pokemon`, i.e., `Pokemon*`**.

   ***Do not define any child class pointer!***

- Give a nickname to each of your pokemons (child classes)

   This step is just necessary for the next step.
   Just write them down on a piece of paper or just memorize them.

   For example, if you have Pikachu, how about "Zappy"?

- Create a `vector` container and store the three nicknames you made in the previous step

   C++ has the standard template library (STL), offering a variety of data structures.
   `vector` is one of them and it can hold items like an array but with more features.

   Do some research and learn how to use `vector`. You can find some online resources including these pages.

   - https://en.cppreference.com/w/cpp/container/vector
   - http://www.cplusplus.com/reference/vector/vector/vector/

   When you define a `vector` container, you will need to specify the datatype of items to be stores.
   **Here, the datatype of item in the vector must be `std::string`.**

- Create a `map` container which stores a Pokemon pointer by its corresponding nickname as a key.

   `map` is another data structure provided from C++ STL.

   Do some research and learn how to use `map`. You can find some online resources including these pages.

   - https://en.cppreference.com/w/cpp/container/map
   - http://www.cplusplus.com/reference/map/map/

   When you define a `map` container, you will need to specify the datatypes of key and item.
   **Here, the datatype of key must be `std::string` and that of the item must be `Pokemon*`.**

   So this container will "map" from the nickname to the corresponding Pokemon pointer.
   For example, given "Zappy" (`std::string`), you can get the address of the Pikachu object (`Pokemon*`).

- Define a function named `checkPokedex` which calls the polymorphic function, `printData()`, of the given pokemon.

   <strong style="color:red">This is not a member function in any class.</strong>
   ```
   void checkPokedex(Pokemon *pokemon)
   {
       pokemon->printData();
   }
   ```

- Show that everything works.

   **This step is the most complicated here so please read the instructions carefully and ask a question if you are confused.**

   By using each element of the `vector` container (the nickname), access the corresponding item stored in the `map` container (the Pokemon pointer). Then, call the `checkPokedex` function with the pointer.
   For example, if you get "Zappy" from the `vector`, you will get the pointer to the corresponding Pikachu object from the `map` container. Then, call the `checkPokedex` function with the pointer.

   You can use `iterator` to access the element in the `vector` if you want. However, you CANNOT use `iterator` for the `map`. (instead, use the key from the `vector`)

   As a result, in the terminal, all the three pokemons will be printed by the `checkPokedex` function.

- Clean up the heap memory.

   Make sure the child class destructors are called when you delete the objects.

# Notes

Make sure that the output explains clearly what you are doing, e.g., which key you are using, which item you are accessing, etc.
You may lose points if it shows only a sequence of output by `printData()`.

# Executable/Makefile

Write a makefile which generates an executable from your source code.
Your makefile must be named as `Makefile` and executable as `homework9`
so you can compile and run your program by the commands:
```
make
./homework9
```

# Proof of compilation: `proof.txt`

Use your `Makefile` and provide proof of compilation by `script` command.

Note: make sure to show **all compilation and linkage.** If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

# Report of outputs: `output.txt`

Run your program and provide actual testing results by `script` command.

# 📮 Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command.

   ```
   tar zcvf homework9.tar.gz main.cpp <all cpp/h files for your pokemons> Makefile proof.txt output.txt
   ```
   Note: Replace `<all cpp/h files for your pokemons>` with your actual source and header files for the pokemons you defined (you have 3 pairs of .cpp and .h files).

1. Verify your tarball by this command

   ```
   tar tvf homework9.tar.gz
   ```
   If the command does not show all the required files, there is something wrong.
   **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

1. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

## List of required files

- Source Code
- `Makefile`
- Proof of compilation (`proof.txt`)
- Output showing that your program works as expected (`output.txt`)
