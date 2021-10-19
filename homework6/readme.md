Work alone
You are expected to do your own work on all homework assignments. You may (and are encouraged to) engage in general discussions with your classmates regarding the assignments, but specific details of a solution, including the solution itself, must always be your own work. (See the statement of Academic Dishonesty on the course's syllabus.

Pseudocode for deleteRecord and Test Plans for Project1 [13 pts]
There are two parts (pseudocode and test plans). Please check each part.

Part1: Pseudocode [8 pts]
Write the pseudocode for the function, deleteRecord, to delete a record from a linked list of records.

Assume the following variables are already defined, initialized and available for you to use:

start: The pointer to the first record of the list (or NULL)
uaccountno: The user's account number (integer)
Assume the following struct definition:

struct record
{
    int               accountno;
    char              name[25];
    char              address[50];
    struct record*    next;
};
The pseudocode must have the following features:

If a record with the specified account number is found, delete it from the linked list AND return 0

Otherwise, return -1

It must not cause a memory leak.

There must be no use of any C code (also no curly braces, no semicolon) in the pseudocode

Don't even think of writing C code first and then translating it to pseudocode. It is no point to do it, and many students in the past also ended up with hard time to translate each line.

You may ONLY use the allowed vocabulary from the list below with variations to accommodate different memory locations

Frequent invalid usage of vocabulary could result in 0 points

Functioning pseudocode can be about 30 lines. If you write excessively long pseudocde (like 50+ lines), your pseudocode highly likely contains some problems or redundant parts.

Vocabulary list
replace the bold parts with your variables and expressions.

define variable_type called variable_name

note: you can newly define ONLY these variable types:

an int
a pointer to record
example:

define an int called i
define a pointer to record called temp
release the space whose address is in variable_name

note: variable_name must be a pointer to record.

example:

release the space whose address is in temp
copy from variable_name1 to variable_name2

This copies the value in variable_name1 to variable_name2.

If the variables are character arrays, you can assume you can directly copy the characters.

You can also assign a result from an expression or a constant value. (be sure about the data type. NULL is for a pointer, not an integer!)

example:

copy from temp1 to temp2
copy from string1 to string2
copy from i + 1 to i
copy from 10 to i
copy from NULL to temp
field_name in the record whose address is in variable_name

By this expression, you can access a field inside the record.

note1: field_name must be one of the fields in struct record.

note2: variable_name must be a pointer to record, but must not be the next field in a record.

example:

copy from name in the record whose address is in temp to val
copy from val to name in the record whose address is in temp
BUT DON'T do this!:

copy from val to name in the record whose address is in next in the record whose address is in temp
Comparison

You can use the following comparisons:

variable_name1 is / is not equal to variable_name2

variable_name1 is less than variable_name2

variable_name1 is greater than variable_name2

while( Comparison )

note1: inside a while loop, put 4 white spaces for indents

note2: you CANNOT use a break or continue statement.

example:

while( accountno in the record whose address is in temp is equal to 0 )
     ...
while( accountno in the record whose address is in temp is not equal to 0 )
     ...
do-while( Comparison )

note1: inside a while loop, put 4 white spaces for indents

note2: you CANNOT use a break or continue statement.

example:

do
    ...
while( accountno in the record whose address is in temp is equal to 0 )

do
    ...
while( accountno in the record whose address is in temp is not equal to 0 )
if( Comparison )

note1: inside an if statement, put 4 white spaces for indents

node2: you can use "else".

example:

if( var is not equal to 0 )
    ...
else if( var2 is equal to 0 )
    ...
else
    ...
Combining comparisons

If necessary, you may use "&&" and "||" to combine comparisons
example:

if ( var is not equal to 0 && var2 is equal to 0)
 ...
else if ( var is less than 0 || var2 is greater than 0)
 ...
return variable_name

This exits the function with the value given by variable_name

note 1: variable_name must be an integer

note 2: you must not use this statement more than once

Template and Example
Use this template of pseudocode. Please replace "* WRITE YOUR PSEUDOCODE HERE" with your pseudocode.

The following pseudocode shows an example demonstrating the vocabulary given above.

-----------------------------------
sampleFunc
------------------------------------

define a pointer to record called temp

if( start is not equal to NULL )
    copy from start to temp
    copy from next in the record whose address is in temp to start
    release the space whose address is in temp
Tracing
After you are done, trace your pseudocode with the following test cases and fill in this file: trace.xlsx.

Note: You don't have to have exactly the same data in the example. Just make up your own data for each of the test cases.

Trying to delete a record in an empty list

For example,

uaccountno: 1000
Heap: No record
Trying to delete the first record in a list of three records

For example,

uaccountno: 1300
Heap:
Record1:
accountno: 1300
name: David Lassner
address: 2500 Campus Rd.
Record2:
accountno: 1200
name: Ravi Narayan
address: 1680 East-West Rd.
Record3:
accountno: 1100
name: Tetsuya Idota
address: 1-1 Chiyoda
Trying to delete the second record in a list of three records

For example,

uaccountno: 1100
Heap:
Record1:
accountno: 1200
name: David Lassner
address: 2500 Campus Rd.
Record2:
accountno: 1100
name: Ravi Narayan
address: 1680 East-West Rd.
Record3:
accountno: 900
name: Tetsuya Idota
address: 1-1 Chiyoda
Part2: TEST PLAN [5 pts]
Write a test plan consisting of a series of test cases and desired outcomes to completely test Project 1. Use this template: testplan.xlsx. Replace the sample test cases with your actual test cases.

Plus, your test plan must achieve the following requirements:

Each test case must be "small."

Think like each test case is an action for a human tester to take step by step. To choose a specific option, "Type X and hit Enter" can be one test case. To provide inputs for a specific option, "Give the following inputs: ..." can also be one test case. So a lengthy instruction composed of multiple actions like "Run the program. Add X records. Delete Y records. Print them. Then, exit." CANNOT be a single test case.

Test cases must be "sequential."

Your test plan is to be conducted sequentially from the first test case to the last, so each test case depends on the results of its previous test case.

A test case must provide specific testing inputs.

Testing results must be the same even if a different person follows your test plan. If some test case asks you to just "input some random number" or "give an incorrect name", is it a good test case?

You will need around 30 to 40 test cases to go through all the requirements.

📮 Materials to submit
Your submission must include the following:

Pseudocode (pseudocode.txt) for the deleteRecord function described above.

Again, please use this template: →pseudocode.txt←!!!!!!.

Traces that verify the algorithm for the following test cases (trace.xlsx).

Again, please use this template: →trace.xlsx←!!!!!!.

testplan.xlsx

Again, please use this template: →testplan.xlsx←!!!!!!.
