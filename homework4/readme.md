# Pseudocode [8 pts]

Write the pseudocode for the function, `addRecord`, to add a record to a linked list of records.

Assume the following variables are already defined, initialized and available for you to use:

- `start`: A pointer holding the address of the first record of the list (or NULL)
- `uaccountno`: The user's account number (integer)
- `uname`: a character array containing the user's name
- `uaddress`: a character array containing the user's address

Assume you have the following struct definition:

```
struct record
{
    int               accountno;
    char              name[25];
    char              address[50];
    struct record*    next;
};
```

The pseudocode must have the following features:

1. Records must be stored in a **linked list**.

1. The linked list must be sorted in a **descending order** of account #.

1. A new record must be inserted to the linked list without breaking the order.

   For example, if the list has records with the following account numbers:

   `1010`, `1005`, `1002`, `980`, `950`

   and you are going to add a record with `1000`, the list will be

   `1010`, `1005`, `1002`, `1000`, `980`, `950`

1. The list **CANNOT** have records with a duplicate account number.

    - If there is a duplicate in the list, return `-1` at the end.
    - Otherwise (so a successful case), return `0`.

    <strong style="color:red">If there is a duplicate, DON'T allocate any memory because otherwise it would cause a memory leak!</strong>

1. **You can ONLY use the vocabulary from the list below**

   - Pseudocode is not a standardized language. If you use someone else's vocabulary from the Internet, you are doing wrong.

   - You **MUST NOT** write any C code (of course in the pseudocode.

      **Don't even think of writing C code first and then translating it to pseudocode.**
      It is no point to do that, and many students in the past also eventually ended up with hard time to translate each line.

   - <strong style='color:red'>Frequent invalid usage of the vocabulary could result in critically low points or 0.</strong>

   - Functioning pseudocode can be about 30 lines or less. About 40 lines should be OK but it may be an indication that your pseudocode has redundant parts or some problem, e.g, you may be making something too complicated. **Excessively long pseudocode (like 50+ lines) may end up with point deduction.**

   - If you can only hit upon long pseudocode and cannot shorten it, please ask a question. **Don't just submit that long pseudocode followed by a long email to seek an excuse.**

# Vocabulary list

You can only use the following vocabulary to write your pseudocoe. Please make sure that you follow the syntax and <strong style="color:red">DO NOT CREATE OR INTRODUCE YOUR OWN VOCABULARY.</strong>

The bold parts are place holders. Replace them with your variables and expressions.

1. define **variable_type** called **variable_name**

   note: you can newly define <strong style="color:red">ONLY</strong> these variable types:

   - an int
   - a pointer to record

   example:
   ```
   define an int called i
   define a pointer to record called temp
   ```

1. allocate a heap space and store its address in **variable**

   note: **variable** must be a pointer to record.
   example:
   ```
   allocate a heap space and store its address into temp
   ```

1. copy from **expression** to **variable_name**

   Note: the data type of **expression** must match that of **variable_name**

   If the variables are character arrays, you can assume you can directly copy the characters.

   example:
   ```
   copy from temp1 to temp2
   copy from string1 to string2
   copy from i + 1 to i
   copy from 10 to i
   copy from NULL to temp
   ```

1. **field** in the record whose address is in **variable**

   In this way, you can access a field inside the record.

   - note1: **field** must be one of the fields in `struct record`.
   - note2: **variable** must be a pointer to `record`.

   example:
   ```
   copy from name in the record whose address is in temp to val
   copy from val to name in the record whose address is in temp
   ```

   BUT <span style="color:red">DON'T do this!</span>:
   ```
   copy from val to name in the record whose address is in next in the record whose address is in temp
   ```

1. Comparison

   You can use the following comparisons for address values:

   - **variable1** is equal to **variable2**
   - **variable1** is not equal to **variable2**

   In the case that you need to compare integers,
   you can use comparison symbols (`==`, `<`, `>`, `<=`, `>=`) or verbally express it.

   1. while( **Comparison** )

   - note1: inside a while loop, put 4 white spaces for indents
   - note2: you CANNOT use a break or continue statement.

   example:
   ```
   while ( accountno in the record whose address is in temp is equal to 0 )
       ...

   while ( accountno in the record whose address is in temp is not equal to 0 )
       ...
   ```

1. do-while( **Comparison** )

   - note1: inside a while loop, put 4 white spaces for indents
   - note2: you CANNOT use a break or continue statement.

   example:
   ```
   do
       ...
   while ( accountno in the record whose address is in temp is equal to 0 )

   do
       ...
   while ( accountno in the record whose address is in temp is not equal to 0 )
   ```

1. if( **Comparison** )

   - note1: inside an if statement, put 4 white spaces for indents
   - node2: you can use "else".

   example:
   ```
   if ( var is not equal to 0 )
       ...
   else if ( var2 is equal to 0 )
       ...
   else
       ...
   ```

1. Combining comparison expressions

   - If necessary, you may use "&&" and "||" to combine comparisons

   example:
   ```
   if ( var is not equal to 0 && var2 is equal to 0)
       ...
   else if ( var is less than 0 || var2 is greater than 0)
       ...
   ```

1. return **variable_name**

   This exits the function with the value given by **variable_name**

   note 1: <strong>variable_name</strong> must be an integer variable

   note 2: you can use this statement **ONLY ONCE** at the end.

# Template and Example

Use [this template of pseudocode](./pseudocode.txt).
Please replace "<strong>* WRITE YOUR PSEUDOCODE HERE</strong>" with your pseudocode.

This is sample pseudocode just demonstrating the vocabulary given above.
```
-----------------------------------
sampleFunc
------------------------------------

define a pointer to record called temp
allocate a heap space and store its address into temp

if( start is not equal to NULL )
    if( uaccountno is not equal to accountno in the record whose address is in temp )

        copy from uaccountno to accountno in the record whose address is in temp

        copy from uname to name in the record whose address is in temp

        copy from uaddress to address in the record whose address is in temp

        copy from NULL to next in the record whose address is in temp

    else
        copy from accountno in the record whose address is in start to accountno in the record whose address is in temp

        copy from name in the record whose address is in start to name in the record whose address is in temp

        copy from address in the record whose address is in start to address in the record whose address is in temp

        copy from next in the record whose address is in start to next in the record whose address is in temp
```

# Tracing
After you are done, trace your pseudocode with the following test cases and fill in **this file: [trace.xlsx](./trace.xlsx)**.

_Note: You don't have to have exactly the same data in the example. Just make up your own data for each of the test cases._

1. Adding a record to an empty list

   For example,
   - Record to add
      - `uaccountno`: 1000
      - `uname`: Ravi Narayan
      - `uaddress`: 1680 East-West Rd.
   - Heap:
      **No record**

2. Adding a record to a list that has two records (every account number is different form others)

   For example,
   - Record to add
      - `uaccountno`: 1000
      - `uname`: Ravi Narayan
      - `uaddress`: 1680 East-West Rd.
   - Heap:
      - Record1:
         - `accountno`: 1200
         - `name`: Tetsuya Idota
         - `address`: 1-1 Chiyoda
      - Record2:
         - `accountno`: 900
         - `name`: David Lassner
         - `address`: 2500 Campus Rd.

3. Adding a record to a list which has two records (the second existing record has the same account number as that of the new record)

   For example,
   - Record to add
      - `uaccountno`: 1000
      - `uname`: Ravi Narayan
      - `uaddress`: 1680 East-West Rd.
   - Heap:
      - Record1:
         - `accountno`: 1100
         - `name`: David Lassner
         - `address`: 2500 Campus Rd.
      - Record2:
         - `accountno`: **1000**
         - `name`: Tetsuya Idota
         - `address`: 1-1 Chiyoda

# Materials to submit

Your submission must include the following:

1. Pseudocode (`pseudocode.txt`) for the `addRecord` function described above.

  Again, **please use this template: →[pseudocode.txt](./pseudocode.txt)←!!!!!!**.

1. Traces that verify the algorithm for the following test cases (`trace.xlsx`).

  Again, **please use this template: →[trace.xlsx](./trace.xlsx)←!!!!!!**.
