Work alone
You are expected to do your own work on all homework assignments. You may (and are encouraged to) engage in general discussions with your classmates regarding the assignments, but specific details of a solution, including the solution itself, must always be your own work. (See the statement of Academic Dishonesty on the course's syllabus.

📒 Java to C [5 pts]
You are going to convert Java code to C code. This assignment also includes instructions to work on UH Unix.

Please follow the instructions below. Unless additional instructions are given, you will basically do the same for later assignments.

🔰 Note: Homework1 gives step-by-step instructions for you to follow. However, the later assignments will not always give this kind of information. They will basically just provide "requirements." That is, you will need to bother understanding what you are doing and what you really need to do to achieve them.

1. Learn how to access UH Unix
Please refer to How to Acceess UH Unix and Use Commands. The instructions are different for the OS of your local machine. After that, you are supposed to be able to upload/download files and also run Unix commands on UH Unix.

Please be careful as some commands such as rm/rmdir cannot be undone.

2. Create a directory for the assignment
Now you are going to write some code. Log in to UH Unix by SSH and you will be first placed in your home directory.

In default, the command prompt (the part before % in the terminal) shows your current location, but it does not always do. You may see something different if you have (somehow) changed the settings or you are working in an different shell environment. So you should be able to check the current location by running a Unix command. To check the current location, you can use pwd. The output should look like this.

uhx02:/home/t/tidota% pwd
/home/t/tidota
It would be troublesome if you create and use all of your files right under your home directory. To get organized, create a directory under your home directory and work in it. For this assignment, create a directory named homework1.

mkdir homework1
Then, go to the directory.

cd homework1
Now you are in the homework1 directory. You will see that the prompt was changed like this.

uhx02:/home/t/tidota% cd homework1
uhx02:/home/t/tidota/homework1%
3. Run Java code
Download helloworld.java (right-click the link and choose "save link as..." or any relevant item on the context menu) and upload it to your directory on UH Unix (you can upload it by SFTP).

The Java code looks like this:

public class helloworld
{
    public static void main(String[] args)
    {
        int num;
        int i;

        for (i = 0; i < 6; i = i + 1)
        {
            if (i < 2)
                System.out.println("Hello");
            else if (i < 4)
                System.out.println("World");
            else
                System.out.println("!!!");
        }

        num = 0;
        while (num < 3)
        {
            System.out.println("While loop!");
            num = num + 1;
        }

        num = 0;
        do
        {
            System.out.println("Do-while loop!");
            num = num + 1;
        }
        while (num < 3);
    }
}
Assuming you are in the same directory where helloworld.java is stored on UH Unix. Compile the code by this command.

javac helloworld.java
You should get helloworld.class. Then, run the Java program.

java helloworld
The program should print the following outputs.

Hello
Hello
World
World
!!!
!!!
While loop!
While loop!
While loop!
Do-while loop!
Do-while loop!
Do-while loop!
4. Write C code
Now it's time to write your C code.

To write code, you can use text editors available on UH Unix: pico, nano, vi, and emacs.

To use vi,

vi homework1.c
Resources:

Master the Vi text editor - Linux Tutorial
An introduction to the vi editor
Basic vi Commands
If you want to use pico,

pico homework1.c
Resources:

Getting Started with Pico.
Don't forget that you must follow the coding style.

If you want to use the template file,

Download template.c to your PC and then upload it to your directory on UH Unix

Or you can use wget

Replace <URL of this website> with the actual URL.

wget -N <URL of this website>/materials/template.c
For example, since the course website for Fall 2021 is at http://www2.hawaii.edu/~tidota/212fall21,

wget -N http://www2.hawaii.edu/~tidota/212fall21/materials/template.c
Now you have template.c in the current directory.

Then, rename it as homework1.c. Note: If you already have homework1.c, it will be overwritten.

mv template.c homework1.c
After that, your homework1.c contains template comments. Make sure that you edit them so your code has proper information.

WARNING: The template file is just an example to show how your code should generally look based on the coding style so you can easily copy and use some specific formats like file/function header comments. The template file is not half-finished homework1 code! For example, you are NOT supposed to define or use that foo function in the template. It is just an example to show how you should define and annotate your function. You also need to replace the < ... > parts with appropriate code.

If you prepared homework1.c correctly, it should look like this homework1.c. (please note you must still edit some items in the comments accordingly)

/*****************************************************************
//
//  NAME:        ***Your Name***
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        January 1, 2021
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//   ***Explain the code in your words***
//
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   ***Explain the function in your words***
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    /* Write your code here */

    return 0;
}
In the main function, write C code to print the same output, i.e.,

Hello
Hello
World
World
!!!
!!!
While loop!
While loop!
While loop!
Do-while loop!
Do-while loop!
Do-while loop!
Note: the C code must have the equivalent program structure of the Java code. (for/while/do-while and if statements) Don't just put a line of printf to print the message above.

5. Compile your C code
After saving the file, compile it by gcc with -ansi -pedantic-errors -Wall -c options.

gcc -ansi -pedantic-errors -Wall -c homework1.c
Then, you will get an object file called homework1.o. If you get errors or warnings, find and correct problems in your code.

6. Link your object file
To generate an executable, link your object file by the same command.

gcc -o homework1 homework1.o
7. Execute your program
To execute your program, type "./" followed by the executable name.

./homework1
8. Proof of Compilation and Sample Output
Use script command in UH Unix to record the terminal outputs, and show that you have used the correct compilation options and your program runs correctly on UH Unix.

Warning1: While running the script command, do not run any unrelated command, which could modify the terminal format (e.g., text editor like pico). Otherwise, your file will be filled with many special characters that cannot be displayed correctly.

Warning2: We strongly recommend you to have a wide terminal window enough to prevent text wrap. If you are using a narrow window and some texts are wrapped, the file may be corrupted and could not be graded.

Proof of Compilation

Run script command with the file name to create.

script proof.txt
After that, compile and link your file. Then, run exit command to close and save the file.

Your terminal will look like this.

uhx02:/home/t/tidota/homework1% script proof.txt
Script started, file is proof.txt
uhx02:/home/t/tidota/homework1% gcc -ansi -pedantic-errors -Wall -c homework1.c
uhx02:/home/t/tidota/homework1% gcc -o homework1 homework1.o
uhx02:/home/t/tidota/homework1% exit
exit
Script done, file is proof.txt
uhx02:/home/t/tidota/homework1%
Finally, you will get proof.txt.

Verify the file by cat command.

cat proof.txt
It will print its contents like this.

uhx02:/home/t/tidota/homework1% cat proof.txt
Script started on Sun 26 Jul 2020 02:58:14 AM HST
uhx02:/home/t/tidota/homework1% gcc -ansi -pedantic-errors -Wall -c homework1.c
uhx02:/home/t/tidota/homework1% gcc -o homework1 homework1.o
uhx02:/home/t/tidota/homework1% exit
exit

Script done on Sun 26 Jul 2020 02:58:37 AM HST
uhx02:/home/t/tidota/homework1%
Sample Output

After you generate an executable file, run script command with the file name to create.

script output.txt
After that, run your program. Then, run exit command to close and save the file.

Your terminal will look like this.

uhx02:/home/t/tidota/homework1% script output.txt
Script started, file is output.txt
uhx02:/home/t/tidota/homework1% ./homework1
Hello
Hello
World
World
!!!
!!!
While loop!
While loop!
While loop!
Do-while loop!
Do-while loop!
Do-while loop!
uhx02:/home/t/tidota/homework1% exit
exit
Script done, file is output.txt
uhx02:/home/t/tidota/homework1%
Verify the file by cat command.

cat output.txt
It will print its contents like this.

uhx02:/home/t/tidota/homework1% cat output.txt
Script started on Tue 29 Dec 2020 02:47:57 AM HST
uhx02:/home/t/tidota/homework1% ./homework1
Hello
Hello
World
World
!!!
!!!
While loop!
While loop!
While loop!
Do-while loop!
Do-while loop!
Do-while loop!
uhx02:/home/t/tidota/homework1% exit
exit

Script done on Tue 29 Dec 2020 02:48:05 AM HST
uhx02:/home/t/tidota/homework1%
9. Proof of Usage of Unix Commands
Show that you can now use Unix commands by following the steps below. Please be careful when you run rm/rmdir as they cannot be undone. Don't delete any important files such as your source file!!!!

Go to the directory homework1
Start script command to record the terminal output (the file name must be unix_prac.txt)
Show the current working directory path by pwd
Create a directory named unix_prac
Copy the executable homework1 to unix_prac
Go to the directory unix_prac
Rename the copied homework1 to hw1
Run the copied executable by ./hw1
Delete the copied executable
Go back to homework1
Delete the directory unix_prac
Stop the recording
You will get unix_prac.txt and the contents should look like this (you can print it by cat unix_prac.txt)

Script started on Wed 06 Jan 2021 05:43:57 PM HST
uhx02:/home/t/tidota/homework1% pwd
/home/t/tidota/homework1
uhx02:/home/t/tidota/homework1% mkdir unix_prac
uhx02:/home/t/tidota/homework1% cp homework1 unix_prac/
uhx02:/home/t/tidota/homework1% cd unix_prac/
uhx02:/home/t/tidota/homework1/unix_prac% mv homework1 hw1
uhx02:/home/t/tidota/homework1/unix_prac% ./hw1
Hello
Hello
World
World
!!!
!!!
While loop!
While loop!
While loop!
Do-while loop!
Do-while loop!
Do-while loop!
uhx02:/home/t/tidota/homework1/unix_prac% rm hw1
uhx02:/home/t/tidota/homework1/unix_prac% cd ..
uhx02:/home/t/tidota/homework1% rmdir unix_prac
uhx02:/home/t/tidota/homework1% exit
exit

Script done on Wed 06 Jan 2021 05:44:53 PM HST
📮 Materials to Submit
On UH UNIX, make a compressed tar file (a.k.a. tarball) containing the following files:

Source Code (homework1.c)
Proof of compilation (proof.txt)
Output of the program (output.txt)
Proof of Unix commands practice (unix_prac.txt)
How to create a tarball
You can create it by running this command in the directory where those files exist.

tar zcvf homework1.tar.gz homework1.c proof.txt output.txt unix_prac.txt
Then, you will get a file named homework1.tar.gz. This is what you will submit.

To check if the created tarball has the correct files,

tar tvf homework1.tar.gz
If the tarball was correctly created, it will print a list of files like this.

uhx02:/home/t/tidota/homework1% tar tvf homework1.tar.gz
-rw-r--r-- tidota/uh      1058 2020-07-26 02:49 homework1.c
-rw-r--r-- tidota/uh       350 2020-07-26 02:49 proof.txt
-rw-r--r-- tidota/uh       299 2020-07-26 02:49 output.txt
-rw-r--r-- tidota/uh       205 2020-07-26 02:49 unix_prac.txt
You may want to double check the data. For your practice, you may want to copy the tarball to another directory and try to extract files.

First, create a new directory test and copy the tarball there.

mkdir test
cp homework1.tar.gz ./test/
Then, go to the directory and extract files from the copied tarball.

cd test
tar zxvf homework1.tar.gz
To check the files you have in the current directory,

ls -la
The output will look like this.

uhx02:/home/t/tidota/homework1/test% ls -la
total 20
drwxr-xr-x. 2 tidota uh  102 Jul 26 02:52 .
drwxr-xr-x. 3 tidota uh  114 Jul 26 02:51 ..
-rw-r--r--. 1 tidota uh 1058 Jul 26 02:49 homework1.c
-rw-r--r--. 1 tidota uh  930 Jul 26 02:52 homework1.tar.gz
-rw-r--r--. 1 tidota uh  299 Jul 26 02:49 output.txt
-rw-r--r--. 1 tidota uh  350 Jul 26 02:49 proof.txt
-rw-r--r--. 1 tidota uh  205 Jul 26 02:49 unix_prac.txt
To check if the contents are correct, try to compile and run the code, and print out the contents in the text files.

How to turn in the tarball
Download the tarball from UH Unix by SFTP.

The instructions are available at the section under How to Access UH Unix of the main page.

Once you download the file, please make sure it is not empty.

Go to the course page of Laulima

On the assignment page of Laulima, you can find the corresponding submission page. Attach your tarball there.
