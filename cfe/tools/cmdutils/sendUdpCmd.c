/*
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement. 
**
** command line test for sendUdp
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h> /* memset() */

/*
** sendUdp prototype
*/
int SendUdp(const char *endian, char *hostname, char *portNum, char *packetAsciiData);

/*
** Main 
*/
int main(int argc, char *argv[]) 
{
  
  int retStat;
  
  /* 
  ** check command line args 
  */
  if(argc<3) 
  {
    printf("usage : %s <[BE|LE]> <server> <port> <packet data> \n", argv[0]);
    printf("        <server> = The network address to send the command to.\n");
    printf("         <port>  = The UDP Port to send the command to.\n");
    printf("          BE     = Sending to a Big Endian Target.\n");
    printf("       or LE     = Sending to a Little Endian Target.\n");
    printf("   <packet data> = The Hex ASCII Packet Data.\n");
    printf("              The data must be 16 bit hex numbers separated by commas,\n");
    printf("              With NO spaces or tabs in between.\n");
    printf("              example: 0x1801,0xC000,0x0003,0x0001\n"); 

    return(1);
  }
 
  /*
  ** Send the packet
  */
  retStat = SendUdp(argv[1], argv[2], argv[3], argv[4]);
  
  if ( retStat < 0 )
  {
     printf("Problem sending UDP packet: %d\n", retStat);
  }
  
  return 0;

}
