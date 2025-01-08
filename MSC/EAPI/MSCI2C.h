#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MSCI2C_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MSCI2C_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MSCI2C_EXPORTS
#define MSCI2C_API __declspec(dllexport)
#include <collection.h>
#include <string>
#include <vector>
#else
#define MSCI2C_API __declspec(dllimport)
#endif


// The I2C Controller friendly names are delivered by the I2CDevice (mirroring the ACPI definitions, i.e. "I2C4").
// This array is returned by the interface function ListI2cControllers().
// One of this friendly names is then passed to the read/write functions (see below).
//
//
// There are several read and write interface functions.
// read0 reads without any command byte, read1 reads with one command byte, read2 reads with 2 command bytes.
// The write functions are defined equivalent.
// There is an additional writeread interface function for general I2C protocol use. This function writes the passed write buffer
// over the I2C bus and then starts reading.
// 
// The main parameters of the read/write functions are:
// const char *I2CBus:				The I2C Controller friendly name (i.e. "I2C4"), one of the controller names returned by ListI2cControllers()
// unsigned int I2CAddr:			The I2C 7 Bit device address on the I2CBus (without read/write bit, i.e. 0x50)
// unsigned int I2CSpeed:			The speed of the I2C transfer. Valid values: 100, 400
// unsigned int CmdOffset:			The command/offset byte (only used with read1/write1).
// unsigned int CmdOffset_MSB:      The upper byte of the command/offset word (only used with read2/write2 functions).
// unsigned int CmdOffset_LSB:      The lower byte of the command/offset word (only used with read2/write2 functions).
// unsigned int nbrBytes:			Number of bytes to be read (only used with the read and writeread functions).
// UCHAR *readBufPtr:				The buffer where the read bytes shall be stored.
// unsigned int *pBytesRead:		Actually read bytes.
// UCHAR *writeBuf:					The buffer where the bytes to be written are passed.
// unsigned int writeBufLen:		The lehngth of the write buffer.
// unsigned int *pBytesWritten:		Actually written bytes.

#ifdef __cplusplus
extern "C"
{
#endif
	const unsigned int I2CControllerNameArrLen = 10;	// number of I2C Controller friendly names
	const unsigned int I2CControllerNameLen = 40;		// max. length of an I2C Controller friendly name
	MSCI2C_API char* ListI2cControllers(unsigned int *pNbrI2CControllers);
	// ListI2cControllers returns a two dimensional char array containing up to 'I2CControllerNameArrLen' I2C Controller friendly names.
	// The max. size of each friendly name is 'I2CControllerNameLen'.

	// read, no offset:
	MSCI2C_API bool read0(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, unsigned int nbrBytes, UCHAR *readBuf, unsigned int *pBytesRead);
	// read, 1 offset:
	MSCI2C_API bool read1(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, unsigned int CmdOffset, unsigned int nbrBytes, UCHAR *readBuf, unsigned int *pBytesRead);
	// read, 2 offsets:
	MSCI2C_API bool read2(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, unsigned int CmdOffset_MSB, unsigned int CmdOffset_LSB, unsigned int nbrBytes, UCHAR *readBuf, unsigned int *pBytesRead);

	// write, no offset:
	MSCI2C_API bool write0(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, UCHAR *writeBuf, unsigned int writeBufLen, unsigned int *pBytesWritten);
	// write, 1 offset:
	MSCI2C_API bool write1(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, unsigned int CmdOffset, UCHAR *writeBuf, unsigned int writeBufLen, unsigned int *pBytesWritten);
	// write, 2 offsets:
	MSCI2C_API bool write2(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, unsigned int CmdOffset_MSB, unsigned int CmdOffset_LSB, UCHAR *writeBuf, unsigned int writeBufLen, unsigned int *pBytesWritten);

	// write, then read:
	MSCI2C_API bool writeread(const char *I2CBus, unsigned int I2CAddr, unsigned int I2CSpeed, UCHAR *writeBuf, unsigned int writeBufLen, unsigned int *pBytesWritten, unsigned int nbrBytes, UCHAR *readBuf, unsigned int *pBytesRead);

#ifdef __cplusplus
}
#endif