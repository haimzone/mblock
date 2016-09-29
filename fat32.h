#ifndef __FAT32_H__
#define __FAT32_H__

#include "defines.h"

#define MBR_ENTRIES	 	29			// number of fields in mbr
#define STR_LEN			32

typdef enum mbrType_
{
	t_int = 0,
	t_str
} mbrType;

// index of item inside mbrRecords
typedef enum mbrName_
{
	JumpCode = 0,
	OEM_Identifier,
	BytesPerSector,
	SectorsPerCluster,
	ReservedSectors,
	NumberOfFATs,
	RootEntries,
	NumberOfSectors,
	MediaDescriptor,
	SectorsPerFAT,
	SectorsPerHead,
	HeadsPerCylinder,
	HiddenSectors,
	BigNumberOfSectors,
	BigSectorsPerFAT,
	ExtFlags,
	FSVersion,
	RootDirectoryStart,
	FSInfoSector,
	BackupBootSector,
	Reserved,
	LogicalDriveNumber,
	Unused,
	ExtendedSignature,
	PartitionSerialNum,
	PartitionVolumeNum,
	FATName,
	ExecutableCode,
	MBRSignature
} mbrName;

typedef mbrItem_
{
	char *name[STR_LEN];
	int length;
	int offset;
	mbrType type;
	int value;
	char *valueStr[STR_LEN];
} mbrItem;


// arrays of mbr items
mbrItem mbrRecords[MBR_ENTRIES] = {
	{ "JumpCode",		 3, 	0x00,	t_int,   },
	{ "OEM_Identifier",	 8, 	0x03,	t_str,   },
	{ "BytesPerSector",	 2,	0x0B,	t_int,   },
	{ "SectorsPerCluster",	 1, 	0x0D,	t_int,   },
	{ "ReservedSectors",	 2, 	0x0E,	t_int,   },
	{ "NumberOfFATs",	 1, 	0x10,	t_int,   },
	{ "RootEntries",	 2, 	0x11,	t_int,   },
	{ "NumberOfSectors",	 2, 	0x13,	t_int,   },
	{ "MediaDescriptor",	 1, 	0x15,	t_int,   },
	{ "SectorsPerFAT",	 2, 	0x16,	t_int,   },
	{ "SectorsPerHead",	 2, 	0x18,	t_int,   },
	{ "HeadsPerCylinder",	 2, 	0x1A,	t_int,   },
	{ "HiddenSectors",	 4, 	0x1C,	t_int,   },
	{ "BigNumberOfSectors",	 4, 	0x20,	t_int,   },
	{ "BigSectorsPerFAT",	 4, 	0x24,	t_int,   },
	{ "ExtFlags",		 2, 	0x28,	t_int,   },
	{ "FSVersion",		 2, 	0x2A,	t_int,   },
	{ "RootDirectoryStart",	 4, 	0x2C,	t_int,   },
	{ "FSInfoSector",	 2, 	0x30,	t_int,   },
	{ "BackupBootSector",	 2, 	0x32,	t_int,   },
	{ "Reserved",		 12,	0x34,	t_str,   },
	{ "LogicalDriveNumber",	 1,	0x40,	t_int,   },
	{ "Unused",		 1,	0x41,	t_int,   },
	{ "ExtendedSignature",	 1,	0x42,	t_int,   },
	{ "PartitionSerialNum",  4,	0x43,	t_int,   },
	{ "PartitionVolumeNum",	 11,	0x47,	t_int,   },
	{ "FATName",		 8,	0x52,	t_str,   },
	{ "ExecutableCode",	 420,	0x5A,	t_str,   },
	{ "MBRSignature",	 2,	0x1FE,	t_int,   }
	
};


// declerations
status_t initMBR();
status_t parseMBR(char *buf);
status_t validateMBR(char *mbr);
void printMBR(void);



#endif	// __FAT32_H__
