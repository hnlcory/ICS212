# TCP packet [6 pts]

Create `homework7.c` and write code to read binary data of a TCP header and generate a response header.

**You don't need to know the details of TCP and computer networks. (some parts of process are also modified for this assignment work and different from the official TCP) You just need to know how the binary data is formatted and how to modify it. This information is all given below, and please carefully read the instructions.**

Your code must do the following tasks for each of [the input files](#input):

1. Using [the readfile function described below](#file-io), read a binary file, and store the data into an `unsigned char` array.
1. Using [the printheader function described below](#print-a-header), print the data to the terminal.
1. Using [the makeheader function described below](#response-header), generate a response header and store another `unsigned char` array.
1. Using [the printheader function described below](#print-a-header), print the data in the generated header to the terminal.
1. Using [the writefile function described below](#file-io), write the generated data to a new file with the name specified in [the output section](#output).

<strong style="color:red">Warning!</strong>

- DON'T define any function unless it is required or allowed

  If you want to define some helper function, please ask us to get approval. **If you just defined some function not allowed by us, you may lose some points.**

- DON'T include `string.h`

  Why not? There is a "clever" way to achieve some requirement without using bitwise operators if you use functions from `string.h`, but you would not learn anything about binary stuff.
  So don't use it.

# Data format

The binary files contain a TCP header, which is 160-bit (20 bytes) long data.
The data format of the header is shown in the table below.
Note that each hexadecimal number represents one **bit** position.

(You don't know what "hexadecimal number" is? Research or ask a question)

<table border="3">
  <tbody>
    <tr>
      <th>00</th><th>01</th><th>02</th><th>03</th><th>04</th><th>05</th><th>06</th><th>07</th>
      <th>08</th><th>09</th><th>0A</th><th>0B</th><th>0C</th><th>0D</th><th>0E</th><th>0F</th>
      <th>10</th><th>11</th><th>12</th><th>13</th><th>14</th><th>15</th><th>16</th><th>17</th>
      <th>18</th><th>19</th><th>1A</th><th>1B</th><th>1C</th><th>1D</th><th>1E</th><th>1F</th>
    </tr>
    <tr>
      <td class="pkthdr" colspan="16">Source Port</td>
      <td class="pkthdr" colspan="16">Destination Port</td>
    </tr>
    <tr>
      <th>20</th><th>21</th><th>22</th><th>23</th><th>24</th><th>25</th><th>26</th><th>27</th>
      <th>28</th><th>29</th><th>2A</th><th>2B</th><th>2C</th><th>2D</th><th>2E</th><th>2F</th>
      <th>30</th><th>31</th><th>32</th><th>33</th><th>34</th><th>35</th><th>36</th><th>37</th>
      <th>38</th><th>39</th><th>3A</th><th>3B</th><th>3C</th><th>3D</th><th>3E</th><th>3F</th>
    </tr>
    <tr>
      <td class="pkthdr" colspan="32">Sequence Number</td>
    </tr>
    <tr>
      <th>40</th><th>41</th><th>42</th><th>43</th><th>44</th><th>45</th><th>46</th><th>47</th>
      <th>48</th><th>49</th><th>4A</th><th>4B</th><th>4C</th><th>4D</th><th>4E</th><th>4F</th>
      <th>50</th><th>51</th><th>52</th><th>53</th><th>54</th><th>55</th><th>56</th><th>57</th>
      <th>58</th><th>59</th><th>5A</th><th>5B</th><th>5C</th><th>5D</th><th>5E</th><th>5F</th>
    </tr>
    <tr>
      <td class="pkthdr" colspan="32">Acknowledgement Number</td>
    </tr>
    <tr>
      <th>60</th><th>61</th><th>62</th><th>63</th><th>64</th><th>65</th><th>66</th><th>67</th>
      <th>68</th><th>69</th><th>6A</th><th>6B</th><th>6C</th><th>6D</th><th>6E</th><th>6F</th>
      <th>70</th><th>71</th><th>72</th><th>73</th><th>74</th><th>75</th><th>76</th><th>77</th>
      <th>78</th><th>79</th><th>7A</th><th>7B</th><th>7C</th><th>7D</th><th>7E</th><th>7F</th>
    </tr>
    <tr>
      <td class="pkthdr" colspan="4">Data Offset</td>
      <td class="pkthdr" colspan="6">Reserved</td>
      <td style="font-size:10px;">URG</td>
      <td style="font-size:10px;">ACK</td>
      <td style="font-size:10px;">PSH</td>
      <td style="font-size:10px;">RST</td>
      <td style="font-size:10px;">SYN</td>
      <td style="font-size:10px;">FIN</td>
      <td class="pkthdr" colspan="16">Window</td>
    </tr>
    <tr>
      <th>80</th><th>81</th><th>82</th><th>83</th><th>84</th><th>85</th><th>86</th><th>87</th>
      <th>88</th><th>89</th><th>8A</th><th>8B</th><th>8C</th><th>8D</th><th>8E</th><th>8F</th>
      <th>90</th><th>91</th><th>92</th><th>93</th><th>94</th><th>95</th><th>96</th><th>97</th>
      <th>98</th><th>99</th><th>9A</th><th>9B</th><th>9C</th><th>9D</th><th>9E</th><th>9F</th>
    </tr>
    <tr>
      <td class="pkthdr" colspan="16">Checksum</td>
      <td class="pkthdr" colspan="16">Urgent Pointer</td>
    </tr>
  </tbody>
</table>

- **Source Port**: 16 bits
  The source port number.

  <strong style="color:red">Note: the first byte represents the lower bits, and the second one is for the higher bits.</strong>

  For example, if the value is 1500 (`05DC`), you first see `DC`, and then `05`.

- **Destination Port**: 16 bits
  The destination port number.

  <strong style="color:red">Note: the first byte represents the lower bits, and the second one is for the higher bits.</strong>

- **Sequence Number**: 32 bits

  <strong style="color:red">Note: Similarly, lower bits of the value are stored earlier than higher bits.</strong>

  For example, if the value is 2149449473 (`801DFF01`), you will see them in the order of `01`, `FF`, `1D`, and `80`.

- **Acknowledgment Number**: 32 bits

  <strong style="color:red">Note: Similarly, lower bits of the value are stored earlier than higher bits.</strong>

- **Data Offset**: 4 bits

  The number of 32 bit words in the TCP Header.

- **Reserved**: 6 bits

  Reserved for future use.
  Must be zero.

- **Control Bits**: 6 bits `URG|ACK|ACK|PSH|RST|SYN|FIN`

  - URG: Urgent Pointer field significant
  - ACK: Acknowledgment field significant
  - PSH: Push Function
  - RST: Reset the connection
  - SYN: Synchronize sequence numbers
  - FIN: No more data from sender

- **Window**: 16 bits
  Must be zero.

- **Checksum**: 16 bits
  Must be `0xFFFF`.

- **Urgent Pointer**: 16 bits
  Must be zero.

# File IO

In `homework7.c`, define the following functions to read/write a TCP header from/to a file. **Note: they are NOT the same functions you made in HW5 or Project1!!!**
Make sure that they do not crash even when there is an error to access a file. (don't cause a segmentation fault)

- `int readfile(const char [], unsigned char []);`

  **Use the `fread()` function to read data from a file.**

- `int writefile(const char [], const unsigned char []);`

  **Use the `fwrite()` function to write data into a file.**

**Reminder: You are going to read and write a BINARY file, not a text file. You may want to check how to open a binary file.**

# Print the data

In `homework7.c`, define the following function to display a given header data in the specified form.

- `void printheader(const unsigned char []);`
- The function must print:

  - Source port (**decimal** number)
  - Destination port (**decimal** number)
  - Sequence number (**(unsigned) decimal** number)

     You will need to store the value in an `unsigned int` variable.
     Use `%u` to print it.

  - Acknowledgement number (**(unsigned) decimal** number)

     You will need to store the value in an `unsigned int` variable.
     Use `%u` to print it.

  - Control bits

     You can print the names of control bits which are set to 1.

     For example,
     ```
     Control bits which are set to 1:
     ACK
     FIN
     ```

  The others are not required to be printed.

# Response header

In `homework7.c`, define the following function to generate a response header based on a request header.

- `void makeheader(const unsigned char [], unsigned char []);`

The response header must be generated based on the following rules:

1. **By using bitwise operators** (`&`, `|`, `^`, `~`, `<<`, `>>`), check if the source port is greater than 32767 (0x7FFF).

   - If it is true, "flip" the 2nd and 7th bits.

      For example, if the bits are like
      0xD9F7 (1<strong style="color:red">1</strong>01 10<strong style="color:red">0</strong>1 1111 0111),
      you need to change it to
      0x9BF7 (1<strong style="color:red">0</strong>01 10<strong style="color:red">1</strong>1 1111 0111)

   - Otherwise, don't change it.

   <strong style='color:red'>Again, you must use bitwise operators. That is, to check the source port, you CANNOT use the following operators:</strong>

   1. Comparison operators (except for `==` and `!=`): `>`, `<`, `>=`, and `<=`
   2. Arithmetic operators: `+`, `-`, `*`, `/`, `%`, `+=`, `-=`, `*=`, `/=`, `%=`, `++`, and `--`.

1. Switch the source and destination ports.

   The source port of the response header will be the destination port of the request header.
   The destination port of the response header will be the source port of the request header or the value processed in the previous step if it is applied.

1. Set the acknowledgment number to the sequence number of the request header.

   The acknowledgment number of the response header is equal to the sequence number of the request header.

1. Set the sequence number to the sequence number of the request header AND increment it.

   For example, if the sequence number of the request header is 10, the sequence number of the response header will be 11.

   - _Can I use arithmetic operators like `+` and `++` in this step?_

      Yes.

1. If SYN is set to 1 in the request header, both SYN and ACK in the response header must be set to 1.

1. The rest of the part must be identical to that of the request header.

# Input

Download the input files.

- [request1.bin](./request1.bin).

   The data looks like this. (Each number is a byte in base 16, i.e., hexadecimal.)
   ```
   3C 73 16 9D FF FF AD 9D 96 0B 39 28 50 11 00 00 FF FF 00 00
   ```

   The data contains the following information.
   - source port: 29500
   - destination port: 40214
   - sequence number: 2645426175
   - acknowledgement number: 674827158
   - flags: ACK FIN

- [request2.bin](./request2.bin).

   The data looks like this. (Each number is a byte in base 16, i.e., hexadecimal.)
   ```
   4A B9 A7 2E FF FF FF 72 CA E8 76 63 50 2A 00 00 FF FF 00 00
   ```

   The data contains the following information.
   - source port: 47434
   - destination port: 11943
   - sequence number: 1929379839
   - acknowledgement number: 1668737226
   - flags: URG PSH SYN

- [request3.bin](./request3.bin).

   The data looks like this. (Each number is a byte in base 16, i.e., hexadecimal.)
   ```
   BA 10 F7 59 98 01 C6 3B 7E 2D EE 22 50 03 00 00 FF FF 00 00
   ```

   The data contains the following information.
   - source port: 4282
   - destination port: 23031
   - sequence number: 1002832280
   - acknowledgement number: 586034558
   - flags: SYN FIN


You can copy these file to your directory in UH Unix by `wget` command like this:

```
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/request1.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/request2.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/request3.bin
```

You can directly see the binary data by the `xxd` command like this.
```
$ xxd somefile
00000000: 3039 379c ff80 6615 0129 eba8 5013 0000  097...f..)..P...
00000010: ffff 0000                                ....
$ xxd -u somefile
00000000: 3039 379C FF80 6615 0129 EBA8 5013 0000  097...f..)..P...
00000010: FFFF 0000                                ....
```

<strong style="color:red">Note: You will use this data to show the results of your program for `output.txt`, but your program must be able to process NOT ONLY this data, but also any other possible data based on the file format.</strong>

Place the input files in the same working directly.

# Output

Once you run your program, i.e., `./homework7`, it must be able to print out the necessary information
and generate a file containing the response header.

- For `request1.bin`, it generates `response1.bin`.
- For `request2.bin`, it generates `response2.bin`.
- For `request3.bin`, it generates `response3.bin`.

That is, your terminal will look like this.

```
% ls
homework7 request1.bin request2.bin request3.bin
*and possibly some other files...*

% ./homework7

*output of your program*

% ls
homework7 request1.bin request2.bin request3.bin
response1.bin response2.bin response3.bin
*and some other files...*
```

## Self-check

The following file are the expected response header data which is supposed to be generated from the input files. You can compare your generated response header with them.

- [response1_expected.bin](./response1_expected.bin)

   ```
   16 9D 3C 73 00 00 AE 9D FF FF AD 9D 50 11 00 00 FF FF 00 00
   ```

   The data contains the following information.
   - source port: 40214
   - destination port: 29500
   - sequence number: 2645426176
   - acknowledgement number: 2645426175
   - flags: ACK FIN

- [response2_expected.bin](./response2_expected.bin)

   ```
   A7 2E 4A FB 00 00 00 73 FF FF FF 72 50 3A 00 00 FF FF 00 00
   ```

   The data contains the following information.
   - source port: 11943
   - destination port: 64330
   - sequence number: 1929379840
   - acknowledgement number: 1929379839
   - flags: URG ACK PSH SYN

- [response3_expected.bin](./response3_expected.bin)

   ```
   F7 59 BA 10 99 01 C6 3B 98 01 C6 3B 50 13 00 00 FF FF 00 00
   ```

   The data contains the following information.
   - source port: 23031
   - destination port: 4282
   - sequence number: 1002832281
   - acknowledgement number: 1002832280
   - flags: ACK SYN FIN

You can get the file in the same way as you did for the input files like this.
```
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/response1_expected.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/response2_expected.bin
wget http://www2.hawaii.edu/~tidota/212fall21/hw/hw7/response3_expected.bin
```

To compare two binary files,
```
cmp response1.bin response1_expected.bin
```
If it does not print anything, that means the files have the same data.

<strong style="color:red">Again, your program must be able to process NOT ONLY the provided input files but also other possible data. For example, if your program always generates the same data of the provided response header files no matter what input data it reads, you will not get points.</strong>

# Executable/Makefile

Write a makefile which generates an executable from your source code.
Your makefile must be named as `Makefile` and executable as `homework7`
so you can compile and run your program by the commands:
```
make
./homework7
```

# Proof of compilation: `proof.txt`

Use your `Makefile` and provide proof of compilation by `script` command.

Note: make sure to show **all compilation and linkage.** If it just says like "Nothing to be done" or skips some compilation or linkage, some points will be taken off. This rule is applied to the later assignments.

# Report of outputs: `output.txt`

Run your code (as instructed above), and provide actual testing results by `script` command.

That is, run the following commands in a directory where you have the executable `homework7` and the input files.
```
script output.txt
ls
./homework7
ls
exit
```

# 📮 Materials to submit

1. In the directory where you have **all the required files listed below**, run the following command. (**Do not mis-type anything**)

  ```
  tar zcvf homework7.tar.gz homework7.c proof.txt output.txt Makefile
  ```

2. Verify your tarball by this command

  ```
  tar tvf homework7.tar.gz
  ```
  If the command does not show all the required files, there is something wrong.
  **It is your responsibility to have all correct files in the tarball.** If you are not sure if you made a correct tarball, try to extract files into an empty directory to see if you can get the correct files. (if you don't even know how to do this, please ask a question)

3. Once you verify your tarball, download it to your local machine and submit it to the Laulima.

## List of required files

- Source code (`homework7.c`)

- `Makefile`

- Proof of compilation (`proof.txt`)

- Output with testing (`output.txt`)
