#include "fat32.h"

status_t initMBR()
{
	status_t status = status_ok;

	// init main mbr struct

	return status;
}

status_t parseMBR(char *buf)
{
	status_t status = status_ok;
	
	for(int i=0; i<mbrEntries; i++)
	{
		

	}

	return status
}


void printMBR(void)
{
	for(int i=0; i<mbrEntries; i++)
	{
		printK();
	}
}
