# Project 2 [18 points]

Write a C++ version of your [Project1](../project1/project1.html) to implement these features below.

You will make new files but they correspond to the features of project1.

| |Project1|Project2|
|---|:---|:---|
| Database | `database.c` `database.h` | `llist.cpp` `llist.h` |
| User Interface |`user_interface.c` | `user_interface.cpp` |
| Record Structure | `record.h` | `record.h` *you can use the same file |

# Database

## Structure of record

Please refer to [the requirements for data structure in Homework3b](../hw3b/hw3b.html#data-structure-of-record).

## Database functions

"Capsulize" your database by defining the following class, `llist`, which contains the database with necessary methods.

1. Create `llist.h`, containing this class definition.

   ***Note: You cannot change the class definition without consent or instruction.***

   ***Note: But you can add `<<` operator for the requirement and copy constructor/assignment operator for the extra credits.***

   ***Note: You will need the same definition of `struct record`, which was used for Homework3 and Project1***

   ```
   class llist
   {
   private:
       record *    start;
       char        filename[16];
       int         readfile();
       int         writefile();
       void        cleanup();

   public:
       llist();
       llist(char[]);
       ~llist();
       int addRecord(int, char [ ],char [ ]);
       int findRecord(int);
       void printAllRecords();
       int deleteRecord(int);
   };
   ```

1. Create `llist.cpp`, containing the function definitions for all the class member functions, including the constructor and destructor.

   - The constructor will do what you need at the beginning.

   - The destructor will do what you need at the end including deallocation of the linked list. (Check when it is called.)

   - The database functions with the same function names of [those in Project1](../project1/project1.html#database) must be able to provide the same features. Note that they are now member functions of `llist`.

   - **You cannot use any of the C I/O functions (`stdio.h`/`cstdio`).**

<!--
   - Implement the `reverse` method using recursion.

     - **It will reverse the list without printing it!**
     - **DO NOT use loops!**
-->

   - *Extra Credits:*

      - Implement a copy constructor of  the `llist` class. (2.5)

      - Overload assignment operator for the `llist` class. (2.5)

         ```
         llist& operator=(const llist&);
         ```

      - Overload the `<<` operator to print the contents of the entire database so that it replaces the function call of `printAllRecords` in the user-interface. (2.0)

         ```
         friend ostream& operator<<(ostream&, const llist&);
         ```

# User-Interface

Write C++ user-interface code `user-interface.cpp` with the following features. Others are the same as [Project1](../project1/project1.html#user-interface) and [Homework3b](../hw3b/hw3b.html#user-interface).

- While you must define the two constructor functions in the class, you may use either one in the main function.

  For example, in the main function, you will have

  - `llist mylist;` or `llist mylist("data.txt");`

- Use `cin.get`/`getline` to get the name field, which may contain white spaces, and the address field, which may have multiple lines.

   - `cin.get`

      http://www.cplusplus.com/reference/istream/istream/get/

   - `getline`

      http://www.cplusplus.com/reference/string/string/getline/

   You may notice that they look similar to `fgets`, but **read the pages carefully as their behaviors are a little different.** (For example, `fgets` includes the newline character, but what about those methods?)

<!--
- Add an option to use the `reverse` function. The menu option name must be `reverse`.
-->

- **The rule for selection of the menu option are the same as that of Homework3 and Project1.**

   That is, a menu option must be able to selected by typing its option name or a part of it.

   For example, in the case of of `add`, it must accept `a`, `ad`, and `add`.

   And don't forget to reject invalid menu option like `assignment`, `adam`, `address`, `adduction` etc.

- **You cannot use any of the C I/O functions (`stdio.h`/`cstdio`).**

# Debug Mode

- Implement debug mode using **preprocessor** directives, instead of command line arguments.

   That is, your code must be able to compile to generate two different versions of executable: release (non-debug) mode and debug mode.

   You **CANNOT** have another source file to generate an executable in the debug mode. You must be able to switch the debug mode **by the compilation option.**

   Hint: you should check `#ifdef` directives and `-D` flag for the compiler.

- The debug outputs are the same as that of project1. So when you run the debug mode executable, additional output will be printed on the screen such as name of function called and parameters (parameter name and value) passed. (You may ignore the printing of address values) Anything else is the same as what the release-mode executable does.

# Other Requirements for Coding

1. **No global variables** can be used.
1. DO NOT use `malloc/free`. Use C++ features to allocate/deallocate heap memory spaces.
1. Include guard: Use **ifndef directives** for the header files.

# Executable/Makefile

<strong style="color:red">Warning! It is totally different from other assignments. Please read this section carefully!</strong>

For this project, you must have TWO makefiles named as `debug.mak` and `release.mak`. The first one is for the debug mode and the second one is for the release mode (that is, nondebug mode). **Now you have makefiles with different names rather than `Makefile`. Find a way to use a makefile with a specific file name!**

Your makefiles must achieve the following items:

- Don't forget to use the required compilation options!

- `debug.mak`

  - It must generate an executable named as **`project_debug`**

  - The executable **must print the debug information.**

  ```
  % < make command with debug.mak >
        ...
  < compilation and linkage >
        ...
  % ./project_debug
        ...
  < outputs with debug information >
        ...
  ```

- `release.mak`

  - It must generate an executable named as **`project`**

  - The executable **must NOT print the debug information.**

  ```
  % < make command with release.mak >
        ...
  < compilation and linkage >
        ...
  % ./project
        ...
  < outputs WITHOUT debug information >
        ...
  ```

# Proof of compilation: `proof.txt`

Use your makefiles and provide proof of compilation by `script` command.

<strong style="color:red">Show the proof by both makefiles: `debug.mak` and `release.mak`.</strong> So your `proof.txt` will show the compilation/linkage by `debug.mak` and then the compilation/linkage by `release.mak`.

Note: Make sure to show <strong style="color:red">all compilation and linkage.</strong> If it just says like "Nothing to be done" or skips some compilation or linkage, **some points will be taken off.** This rule is applied to the later assignments. **Please be careful as some of you are still sending incorrect proof.txt or misunderstanding how to make/use a makefile.**

# Report of outputs: `output.txt`

Run your program (both `project` and `project_debug`) and show some results by `script` command.

**Like Project1, you can just show some results of a few menu options. (the purpose of output.txt here is to verify that your program actually runs.)**

**And, please DO NOT use any text editor while running the script command. Even now, some of you apparently try to show their code by pico/vi for some reason and end up with a messed output.txt.**

# Testing

Test your project2 program with your test plans.

Write a summary `summary.txt` of results containing the following items

- Requirements not met/not functional
- Additional features/extra credit
- Future enhancements and/or general comments

<!--
# GIT (After completing this project)

Assumptions: you have directories named as `project1` and `project2`, containing source files for Project1 and Project2, respectively. And the files of `project1` have already been checked in as required in Project1.

1. Copy the directory of Project1 and name it as `project2_git`.

   ```
   % cp -R project1 project2_git
   % cd ./project2_git
   % git checkout project1
   ```

   The command lines above will take you to the copied git repository and then switch to the `project1` branch, which is what you submitted for Project1.
   If you see any error, you might not have successfully copied the files. Otherwise, proceed to the next step.

1. Make and checkout a branch named as `project2`

   ```
   git branch project2
   git checkout project2
   ```

   or

   ```
   git checkout -b project2
   ```

   Now you are on a new branch that you can update for project2.

   **Note: In the real life, you would edit the files which are originally project1 to develop your poject2. But since you already have your poject2 code, and for simplicity, you are going to copy the project2 files to this branch in the following steps.**

1. Run the following commands

   ```
   git mv user_interface.c user_interface.cpp
   git mv database.c llist.cpp
   git mv database.h llist.h
   git rm Makefile
   git commit -m "Rename files and remove Makefile"
   ```

   These commands tell the git that those C++ files are the next version of the C files. It also make sure that Project2 will not contain a makefile named as `Makefile`.

1. Copy your Project2 source files including `debug.mak` and `release.mak` into the directory.

   - `user_interface.cpp`
   - `llist.cpp`
   - `llist.h`
   - `record.h`
   - `release.mak`
   - `debug.mak`

   After that, the renamed files above will be overwritten with those from your project2. `git status` will show those files have been updated.

   Then, **don't forget to commit the updates!**

1. Edit `getreport.sh`

   Now you have `debug.mak` and `release.mak` instead of `Makefile`, update `getreport.sh` so that it can use your new makefiles.

   ```
   git --no-pager log --graph --date-order --all --pretty=format:'%h %Cred%d %Cgreen%ad %Cblue%cn %Creset%s' --date=short
   echo
   git status
   ls -la
   rm *.o
   < make with debug.mak >
   < make with release.mak >
   ```

1. Provide proof of git usage.

   The repository now contains both versions of project1/2.

   In the `project2_git` directory, follow these steps:

   1. Run the following commands:

      ```
      script proof.txt
      git checkout project1
      sh getreport.sh
      ```

      **The line of make must not skip any compilation or linkage.**

   1. Run your program by `./project`

      Note: The output must be that from Project1

      Note: You only need to test one menu option and you can quit after that.

   1. Run the following commands:

      ```
      git checkout project2
      sh getreport.sh
      ```

      **Compilation must not skip any compilation or linkage.**

   1. Run your program by `./project`

      Note: The output must be that from Project2

      Note: You only need to test one menu option and you can quit after that.

   1. Run your program by `./project_debug`

      Note: The output must be that from Project2 **+ debug output**

      Note: You only need to test one menu option and you can quit after that.

   1. Finish the script command.

      ```
      exit
      ```
-->

#  Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

   ```
   tar zcvf project2.tar.gz user_interface.cpp llist.cpp llist.h record.h debug.mak release.mak proof.txt output.txt
   ```

   Note: you can include `summary.txt` in the tarball if you want.

1. Verify your tarball by this command

   ```
   tar tvf project2.tar.gz
   ```
   If the command does not show all the required files, there is something wrong.
   **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

1. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

   **Note: if you did not include `summary.txt` in the tarball, don't forget to submit it!**

## List of required files

- Source code including `debug.mak` and `release.mak`

   - `user_interface.cpp`
   - `llist.cpp`
   - `llist.h`
   - `record.h`
   - `debug.mak`
   - `release.mak`

   Note: an executable and object files are not a part of source code.

- Proof of compilation (`proof.txt`)

- (Brief) results of a few menu options (`output.txt`)

- `summary.txt`

   **If you prefer, you can attach `summary.txt` separately on the submission page instead of including it in the tarball.**

<!--
1. Updated shell script `getreport.sh`

   **Not the one for Project1, but the one for Project2!**

1. Proof of GIT, compilation, and sample output (`proof.txt`)
-->
