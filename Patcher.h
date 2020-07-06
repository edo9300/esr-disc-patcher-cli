#pragma once
#include "defines.h"

class CPatcher
{
public:
	CPatcher(void);
	~CPatcher(void);
	int doPatch(char* filename, char* payloadfilename1, char* payloadfilename2, char* launcherfilename);
	int doUnPatch(char* filename);

private:
	static const unsigned short crc_itu_t_table[256];
	static const unsigned char dvdvdata[20480];
	unsigned short crc_itu_t_byte(unsigned short crc, const unsigned char data);
	unsigned short crc_itu_t(unsigned short crc, const unsigned char* buffer, size_t len);
};
