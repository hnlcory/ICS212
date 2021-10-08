Work alone
You are expected to do your own work on all homework assignments. You may (and are encouraged to) engage in general discussions with your classmates regarding the assignments, but specific details of a solution, including the solution itself, must always be your own work. (See the statement of Academic Dishonesty on the course's syllabus.

📒 TRACE [5 pts]
Run the following C program on UH UNIX and complete the table showing all the variables. You may add printf function calls to obtain the addresses and values of all <strong style="color:red>14 variables. (Count the array ca as 3 variable/values and also include argc and argv in the table).

Note: When you compile this source code, the compiler may warn about some "unused" variables, but you can disregard such a warning message.

#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'B';
    float score1 = 20.5;
    char ca[3] = "Hi";

    dummy(num2, c1, ca, score1);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
    x++;
    y++;
    w = w + 2.1;

    /* pause here */
}
Tracing Table
Download this spreadsheet file: table.xlsx

In the file, you can see a template table whose columns represent Address, Name, Datatype, Scope, and Value.

Address	Name	Datatype	Scope	Value
argc			
argv			
num1			
...	...	...	...	...
By using this table, trace the code in a similar way as you did in the class, BUT you also need to investigate the code and show the actual values and addresses of the variables. Use printf function and insert function calls to the code so you can print actual values and addresses. Check how those variables are allocated on the actual memory. (You may also want to use the sizeof function to see the size of a variable type.)

Address

As you did in the class, address values are positive numbers. For this assignment, you must show addresses in hexadecimal (not like 60000. Check the specification of printf. You can find the table of options to format the output. There is a special option to print an address in hexadecimal).

"Hexadecimal? What is that?":

If you don't know what hexadecimal is, please do some research or ask a question. Every semester, some people think like hexadecimal is a specific datatype saying like "an address value is in hexadecimal on the actual memory" or "a pointer actually holds a hexadecimal number as an address", but this is NOT CORRECT. It is a way to represent a number. For example, 26 in decimal, or base 10, can be represented as 1A in hexadecimal, or base 16. They look different but both mean the same value. You will just intentionally print addresses in hexadecimal.

As you are going to see address values in hexadecimal on your tracing table, you should be able to tell which hexadecimal number is greater than the other. Can you tell if A3052C is greater than 9F0CEB? How about 1FA98C and 1FA9AC? What is the difference between E5A and EA1?

Name

It is already filled.

Datatype

Write the datatype of the variable.

Scope

Write the name of function in which the variable exists.

Value

Check the actual value stored in the variable and fill in this column. So your table will never have "?".

You need to show all the values the variable got. For example, if the code had an integer variable named a and its value changes as follows, you would need to fill like "-10498, 0, 10" (note the first one is an uninitialized value).

int a;
a = 0;
a = 10;
If the datatype of a variable is a pointer, you must show the address value stored in it. For example, if its datatype is char*, you must show the address stored in the variable, not the characters stored at the address.

Report
Create a plain text file report.txt. (You can work on your local machine.)

In the file, refer to your tracing and explain how the variables are allocated and how the actual memory allocation is different from what you practiced by hand in the class. Don't just say like "it is totally different from what I thought," "It is randomly allocated," "I am surprised that an address value is printed differently," etc.

In the past, some people used to write a very long essay mentioning unrelated items such as how you traced code by hand, how the values changed, how you print the values and addresses in the homework, etc. Please note that what you need to describe here is how the variables are allocated on the actual memory. Focus on how those "houses" are located with respect to each other.

You can use any text editor but please make sure that your report.txt is plain text. If you make a document file .doc, .docx, .rtf, .pages etc, please convert it to .txt. Note: simply renaming the file to report.txt or changing the extension to .txt DOES NOT convert the file content to plain text. If your file contains a special format of writing software, you may lose some points.

📮 Materials to Submit
Tracing table (table.xlsx)
Your explanation (see the instruction above) (report.txt)
Note: do not attach the source code.

You don't have to make a tarball or an archive file. You can just attach the files at the Laulima's submission page.
