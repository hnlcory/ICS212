/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 7, 2021
//
//  FILE:        homework7.c
//
//  DESCRIPTION:
//   A file to read, wite, print, and generate response headers
//   to binary TCP .bin files.
//
****************************************************************/

#include<stdio.h> 

int readfile(const char [], unsigned char []);
int writefile(const char [], const unsigned char []);
void printheader(const unsigned char []);
void makeheader(const unsigned char [], unsigned char []);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls all functions for each of the provided
//                   .bin binary files
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : Completed properly
//
****************************************************************/

int main(int argc, char* argv[])
{
    unsigned char arr[20]; 
    unsigned char arrResponse[20];
    unsigned char arr2[20]; 
    unsigned char arrResponse2[20];
    unsigned char arr3[20]; 
    unsigned char arrResponse3[20];

    readfile("request1.bin",arr);
    printheader(arr);
    makeheader(arr,arrResponse); 
    writefile("response1.bin",arrResponse);
    readfile("request2.bin",arr2); 
    printheader(arr2);
    makeheader(arr2,arrResponse2);
    writefile("response2.bin",arrResponse2);
    readfile("request3.bin",arr3); 
    printheader(arr3);
    makeheader(arr3,arrResponse3);
    writefile("response3.bin",arrResponse3);
    return 0;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads in 20 bytes of data from a binary file and
//                 stores the data by byte in an array
//
//  Parameters:    const char fileName[] : the name of the file to read
//                 unsigned char tcpheader[] : the array to store data in
//
//  Return values:  0 : readfile completed
//
****************************************************************/

int readfile(const char fileName[], unsigned char tcpheader[])
{
    int status = 1;
    FILE * fileIn;
    fileIn = fopen(fileName,"rb");
    
    if (fileIn == NULL)
    {
        status = 0;
    }   

    while (status != 0)
    {
        if (feof(fileIn))
        {
            status = 0;
            fclose(fileIn);
        }
        else
        {
            fread(tcpheader,1,20,fileIn);       
        }
    } 
    
    return status;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes 20 bytes of data from an array to a specified 
//                 file.
//
//  Parameters:    const char fileName[] : the name of the file to write
//                 unsigned char tcpheader[] : the array bytes are stored in
//
//  Return values:  0 : writefile completed
//
****************************************************************/

int writefile(const char fileName[], const unsigned char tcpheader[])
{
    int status = 1;
    FILE * fileIn;
    fileIn = fopen(fileName,"wb");

     if (fileIn == NULL)
    {
        status = 0;
    }
    
    if (status != 0)
    {    
        fwrite(tcpheader,1,20,fileIn);   
        fclose(fileIn);
        status = 0;
    }    

    return status;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   Prints the data of the bytes into a formatted 
//                 command line output
//
//  Parameters:    unsigned char tcpheader[] : the array bytes are in
//
//  Return values:  void
//
****************************************************************/

void printheader(const unsigned char tcpheader[])
{
    unsigned int source1,source2,source3;
    unsigned int dest1,dest2,dest3;
    unsigned int seq1,seq2,seq3,seq4,seq5;
    unsigned int ack1,ack2,ack3,ack4,ack5;
    unsigned int cntrl;    
    
    source1 = tcpheader[0];
    source2 = tcpheader[1];
    source3 = (source2<<8)|(source1);
  
    dest1 = tcpheader[2];
    dest2 = tcpheader[3];
    dest3 = (dest2<<8)|(dest1);
    
    seq1 = tcpheader[4];
    seq2 = tcpheader[5];
    seq3 = tcpheader[6];
    seq4 = tcpheader[7];
    seq5 = (seq4<<24)|(seq3<<16)|(seq2<<8)|(seq1);

    ack1 = tcpheader[8];
    ack2 = tcpheader[9];
    ack3 = tcpheader[10];
    ack4 = tcpheader[11];
    ack5 = (ack4<<24)|(ack3<<16)|(ack2<<8)|(ack1);
 
    printf("\nSource port: %d",source3);
    printf("\nDestination port: %d",dest3);
    printf("\nSequence number: %u",seq5);
    printf("\nAcknowledgement number: %u",ack5);
    printf("\nFlags: ");
    
    cntrl = tcpheader[13];   

    if (cntrl & (1 << 5))   
    {
        printf("URG ");
    }
    if (cntrl & (1 << 4))
    {
        printf("ACK ");
    }
    if (cntrl & (1 << 3))
    {
        printf("PSH ");
    }
    if (cntrl & (1 << 2))
    {
        printf("RST ");
    }
    if (cntrl & (1 << 1))
    {
        printf("SYN ");
    }
    if (cntrl & (1))
    {
        printf("FIN ");
    }
  
    printf("\n"); 
} 

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   Creates a responseheader array based on rules imposed
//                 on the tcpheader read in.
//
//  Parameters:    unsigned char tcpheader[] : the array read bytes are in
//                 unsigned char responseheader[] : the array the response bytes
//                 are in
//
//  Return values:  void
//
****************************************************************/

void makeheader(const unsigned char tcpheader[], unsigned char responseheader[])
{
    unsigned int source1,source2,source3,temp[2];
    unsigned int seq1,seq2,seq3,seq4,seq5;
    unsigned int mask1,mask2,maskSyn;    
    unsigned int cntrl = tcpheader[13];

    source1 = tcpheader[0];
    source2 = tcpheader[1];
    source3 = (source2<<8)|(source1);
    
    responseheader[2] = tcpheader[2];
    responseheader[3] = tcpheader[3];

    if (source3 > (0x7FFF))
    {
        unsigned int result;    
        unsigned int xor;
        mask1 = 0xff;

        xor = ((source3 >> 2) ^ (source3 >> 7)) & ((1U << 1) - 1); 
        result = source3 ^ ((xor << 2) | (xor << 7));
        temp[0] = (result >> 8);
        temp[1] = (result & mask1);      
        
        responseheader[2] = responseheader[0];
        responseheader[3] = responseheader[1];
        responseheader[2] = temp[0];
        responseheader[3] = temp[1];

    }

    else
    {
        temp[0] = responseheader[0];
        temp[1] = responseheader[1];
        responseheader[0] = responseheader[2];
        responseheader[1] = responseheader[3];
        responseheader[2] = temp[0];
        responseheader[3] = temp[1]; 
    }

    responseheader[8] = tcpheader[4];
    responseheader[9] = tcpheader[5];
    responseheader[10] = tcpheader[6];
    responseheader[11] = tcpheader[7];    
    
    seq1 = tcpheader[4];
    seq2 = tcpheader[5];
    seq3 = tcpheader[6];
    seq4 = tcpheader[7];
    seq5 = (seq4<<24)|(seq3<<16)|(seq2<<8)|(seq1);
    seq5++; 
    
    mask1 = 0xFF00;
    mask2 = 0xFF;
    responseheader[4] = (seq5  & mask2);
    responseheader[5] = ((seq5 >> 8) & mask2);
    responseheader[6] = ((seq5 >> 16) & mask2);
    responseheader[7] = (seq5 >> 24); 

    if (cntrl & (1 << 1))
    {
        maskSyn = 0x12;
        responseheader[13] = (cntrl | maskSyn);
    }
 
    else
    {
        responseheader[13] = tcpheader[13];
    }
      
    responseheader[12] = tcpheader[12];
    responseheader[14] = tcpheader[14];
    responseheader[15] = tcpheader[15];
    responseheader[16] = tcpheader[16]; 
    responseheader[17] = tcpheader[17];
    responseheader[18] = tcpheader[18];
    responseheader[19] = tcpheader[19];

} 
