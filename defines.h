#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

enum eFileErr
{
	ESR_FILE_OK = 0,
	ESR_FILE_CANNOT_OPEN = -1,
	ESR_FILE_ALREADY_PATCHED = -2,
	ESR_FILE_WRONG_FORMAT = -3,
	ESR_FILE_NO_UDF_DESCRIPTOR = -4,
	ESR_FILE_NOT_PATCHED = -5,
	ESR_FILE_CANNOT_OPEN1 = -6,
	ESR_FILE_CANNOT_OPEN2 = -7,
	ESR_FILE_CANNOT_OPEN3 = -8
};
