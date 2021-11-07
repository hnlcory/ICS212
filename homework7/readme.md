Work alone
You are expected to do your own work on all homework assignments. You may (and are encouraged to) engage in general discussions with your classmates regarding the assignments, but specific details of a solution, including the solution itself, must always be your own work. (See the statement of Academic Dishonesty on the course's syllabus.

TCP packet [6 pts]
Create homework7.c and write code to read binary data of a TCP header and generate a response header.

You don't need to know the details of TCP and computer networks. (some parts of process are also modified for this assignment work and different from the official TCP) You just need to know how the binary data is formatted and how to modify it. This information is all given below, and please carefully read the instructions.

Your code must do the following tasks for each of the input files:

Using the readfile function described below, read a binary file, and store the data into an unsigned char array.
Using the printheader function described below, print the data to the terminal.
Using the makeheader function described below, generate a response header and store another unsigned char array.
Using the printheader function described below, print the data in the generated header to the terminal.
Using the writefile function described below, write the generated data to a new file with the name specified in the output section.
Warning!

DON'T define any function unless it is required or allowed

If you want to define some helper function, please ask us to get approval. If you just defined some function not allowed by us, you may lose some points.

DON'T include string.h

Why not? There is a "clever" way to achieve some requirement without using bitwise operators if you use functions from string.h, but you would not learn anything about binary stuff. So don't use it.

Data format
The binary files contain a TCP header, which is 160-bit (20 bytes) long data. The data format of the header is shown in the table below. Note that each hexadecimal number represents one bit position.

(You don't know what "hexadecimal number" is? Research or ask a question)

00	01	02	03	04	05	06	07	08	09	0A	0B	0C	0D	0E	0F	10	11	12	13	14	15	16	17	18	19	1A	1B	1C	1D	1E	1F
Source Port	Destination Port
20	21	22	23	24	25	26	27	28	29	2A	2B	2C	2D	2E	2F	30	31	32	33	34	35	36	37	38	39	3A	3B	3C	3D	3E	3F
Sequence Number
40	41	42	43	44	45	46	47	48	49	4A	4B	4C	4D	4E	4F	50	51	52	53	54	55	56	57	58	59	5A	5B	5C	5D	5E	5F
Acknowledgement Number
60	61	62	63	64	65	66	67	68	69	6A	6B	6C	6D	6E	6F	70	71	72	73	74	75	76	77	78	79	7A	7B	7C	7D	7E	7F
Data Offset	Reserved	URG	ACK	PSH	RST	SYN	FIN	Window
80	81	82	83	84	85	86	87	88	89	8A	8B	8C	8D	8E	8F	90	91	92	93	94	95	96	97	98	99	9A	9B	9C	9D	9E	9F
Checksum	Urgent Pointer
Source Port: 16 bits The source port number.

Note: the first byte represents the lower bits, and the second one is for the higher bits.

For example, if the value is 1500 (05DC), you first see DC, and then 05.

Destination Port: 16 bits The destination port number.

Note: the first byte represents the lower bits, and the second one is for the higher bits.

Sequence Number: 32 bits

Note: Similarly, lower bits of the value are stored earlier than higher bits.

For example, if the value is 2149449473 (801DFF01), you will see them in the order of 01, FF, 1D, and 80.

Acknowledgment Number: 32 bits

Note: Similarly, lower bits of the value are stored earlier than higher bits.

Data Offset: 4 bits

The number of 32 bit words in the TCP Header.

Reserved: 6 bits

Reserved for future use. Must be zero.

Control Bits: 6 bits URG|ACK|ACK|PSH|RST|SYN|FIN

URG: Urgent Pointer field significant
ACK: Acknowledgment field significant
PSH: Push Function
RST: Reset the connection
SYN: Synchronize sequence numbers
FIN: No more data from sender
Window: 16 bits Must be zero.

Checksum: 16 bits Must be 0xFFFF.

Urgent Pointer: 16 bits Must be zero.

File IO
In homework7.c, define the following functions to read/write a TCP header from/to a file. Note: they are NOT the same functions you made in HW5 or Project1!!! Make sure that they do not crash even when there is an error to access a file. (don't cause a segmentation fault)

int readfile(const char [], unsigned char []);

Use the fread() function to read data from a file.

int writefile(const char [], const unsigned char []);

Use the fwrite() function to write data into a file.

Reminder: You are going to read and write a BINARY file, not a text file. You may want to check how to open a binary file.

Print the data
In homework7.c, define the following function to display a given header data in the specified form.

void printheader(const unsigned char []);

The function must print:

Source port (decimal number)

Destination port (decimal number)

Sequence number ((unsigned) decimal number)

You will need to store the value in an unsigned int variable. Use %u to print it.

Acknowledgement number ((unsigned) decimal number)

You will need to store the value in an unsigned int variable. Use %u to print it.

Control bits

You can print the names of control bits which are set to 1.

For example,

Control bits which are set to 1:
ACK
FIN
The others are not required to be printed.

Response header
In homework7.c, define the following function to generate a response header based on a request header.

void makeheader(const unsigned char [], unsigned char []);
The response header must be generated based on the following rules:

By using bitwise operators (&, |, ^, ~, <<, >>), check if the source port is greater than 32767 (0x7FFF).

If it is true, "flip" the 2nd and 7th bits.

For example, if the bits are like 0xD9F7 (1101 1001 1111 0111), you need to change it to 0x9BF7 (1001 1011 1111 0111)

Otherwise, don't change it.

Again, you must use bitwise operators. That is, to check the source port, you CANNOT use the following operators:

Comparison operators (except for == and !=): >, <, >=, and <=
Arithmetic operators: +, -, *, /, %, +=, -=, *=, /=, %=, ++, and --.
Switch the source and destination ports.

The source port of the response header will be the destination port of the request header. The destination port of the response header will be the source port of the request header or the value processed in the previous step if it is applied.

Set the acknowledgment number to the sequence number of the request header.

The acknowledgment number of the response header is equal to the sequence number of the request header.

Set the sequence number to the sequence number of the request header AND increment it.

For example, if the sequence number of the request header is 10, the sequence number of the response header will be 11.

Can I use arithmetic operators like + and ++ in this step?

Yes.

If SYN is set to 1 in the request header, both SYN and ACK in the response header must be set to 1.

The rest of the part must be identical to that of the request header.

Input
Download the input files.

request1.bin.

The data looks like this. (Each number is a byte in base 16, i.e., hexadecimal.)

3C 73 16 9D FF FF AD 9D 96 0B 39 28 50 11 00 00 FF FF 00 00
The data contains the following information.

source port: 29500
destination port: 40214
sequence number: 2645426175
acknowledgement number: 674827158
flags: ACK FIN
request2.bin.

The data looks like this. (Each number is a byte in base 16, i.e., hexadecimal.)

4A B9 A7 2E FF FF FF 72 CA E8 76 63 50 2A 00 00 FF FF 00 00
The data contains the following information.

source port: 47434
destination port: 11943
sequence number: 1929379839
acknowledgement number: 1668737226
flags: URG PSH SYN
request3.bin.

The data looks like this. (Each number is a byte in base 16, i.e., hexadecimal.)

BA 10 F7 59 98 01 C6 3B 7E 2D EE 22 50 03 00 00 FF FF 00 00
The data contains the following information.

source port: 4282
destination port: 23031
sequence number: 1002832280
acknowledgement number: 586034558
flags: SYN FIN
You can copy these file to your directory in UH Unix by wget command like this:

wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/request1.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/request2.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/request3.bin
You can directly see the binary data by the xxd command like this.

$ xxd somefile
00000000: 3039 379c ff80 6615 0129 eba8 5013 0000  097...f..)..P...
00000010: ffff 0000                                ....
$ xxd -u somefile
00000000: 3039 379C FF80 6615 0129 EBA8 5013 0000  097...f..)..P...
00000010: FFFF 0000                                ....
Note: You will use this data to show the results of your program for output.txt, but your program must be able to process NOT ONLY this data, but also any other possible data based on the file format.

Place the input files in the same working directly.

Output
Once you run your program, i.e., ./homework7, it must be able to print out the necessary information and generate a file containing the response header.

For request1.bin, it generates response1.bin.
For request2.bin, it generates response2.bin.
For request3.bin, it generates response3.bin.
That is, your terminal will look like this.

% ls
homework7 request1.bin request2.bin request3.bin
*and possibly some other files...*

% ./homework7

*output of your program*

% ls
homework7 request1.bin request2.bin request3.bin
response1.bin response2.bin response3.bin
*and some other files...*
Self-check
The following file are the expected response header data which is supposed to be generated from the input files. You can compare your generated response header with them.

response1_expected.bin

16 9D 3C 73 00 00 AE 9D FF FF AD 9D 50 11 00 00 FF FF 00 00
The data contains the following information.

source port: 40214
destination port: 29500
sequence number: 2645426176
acknowledgement number: 2645426175
flags: ACK FIN
response2_expected.bin

A7 2E 4A FB 00 00 00 73 FF FF FF 72 50 3A 00 00 FF FF 00 00
The data contains the following information.

source port: 11943
destination port: 64330
sequence number: 1929379840
acknowledgement number: 1929379839
flags: URG ACK PSH SYN
response3_expected.bin

F7 59 BA 10 99 01 C6 3B 98 01 C6 3B 50 13 00 00 FF FF 00 00
The data contains the following information.

source port: 23031
destination port: 4282
sequence number: 1002832281
acknowledgement number: 1002832280
flags: ACK SYN FIN
You can get the file in the same way as you did for the input files like this.

wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/response1_expected.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/response2_expected.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/response3_expected.bin
To compare two binary files,

cmp response1.bin response1_expected.bin
If it does not print anything, that means the files have the same data.

Again, your program must be able to process NOT ONLY the provided input files but also other possible data. For example, if your program always generates the same data of the provided response header files no matter what input data it reads, you will not get points.

Executable/Makefile
Write a makefile which generates an executable from your source code. Your makefile must be named as Makefile and executable as homework7 so you can compile and run your program by the commands:

make
./homework7
Proof of compilation: proof.txt
Use your Makefile and provide proof of compilation by script command.

Note: make sure to show all compilation and linkage. If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

Report of outputs: output.txt
Run your code (as instructed above), and provide actual testing results by script command.

That is, run the following commands in a directory where you have the executable homework7 and the input files.

script output.txt
ls
./homework7
ls
exit
📮 Materials to submit
In the directory where you have all the required files listed below, run the following command. (Do not mis-type anything)
tar zcvf homework7.tar.gz homework7.c proof.txt output.txt Makefile
Verify your tarball by this command
tar tvf homework7.tar.gz
If the command does not show all the required files, there is something wrong. It is your responsibility to have all correct files in the tarball. If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

Once you verify your tarball, download it to your local machine and submit it to the Laulima.
List of required files
Source code (homework7.c)

Makefile

Proof of compilation (proof.txt)

Output with testing (output.txt)

