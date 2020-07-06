/*
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA  02110-1301, USA.

    ---
    Copyright (C) 2008, Tatsh
 */

#include <iostream>
#include "Patcher.h"

int main(int argc, char *argv[]) {
  if (argc != 5) {
    std::cout << "Usage: " << argv[0] << " <ISO or BIN to patch> <payload (VIDEO_TS.IFO)> <payload (VTS_01_0.IFO)> <ESR launcher elf>" << std::endl;
    return 1;
  }
  
  bool ok;
  CPatcher m_patcher;
  
  switch (m_patcher.doPatch(argv[1], argv[2], argv[3], argv[4])) {
    case ESR_FILE_OK:
      ok = true;
      break;

    case ESR_FILE_ALREADY_PATCHED:
      std::cout << argv[1] << " is already patched." << std::endl;
      ok = false;
      break;

    case ESR_FILE_CANNOT_OPEN:
      std::cout << "Could not open " << argv[1] << "." << std::endl;
      ok = false;
      break;

    case ESR_FILE_NO_UDF_DESCRIPTOR:
      std::cout << "No UDF descriptor found in " << argv[1] << "." << std::endl;
      ok = false;
      break;

	case ESR_FILE_CANNOT_OPEN1:
		std::cout << "Could not open " << argv[2] << "." << std::endl;
		ok = false;
		break;

	case ESR_FILE_CANNOT_OPEN2:
		std::cout << "Could not open " << argv[3] << "." << std::endl;
		ok = false;
		break;

	case ESR_FILE_CANNOT_OPEN3:
		std::cout << "Could not open " << argv[4] << "." << std::endl;
		ok = false;
		break;

    default:
      std::cout << "Unknown error during patching procedure." << std::endl;
      ok = false;
      break;
  }
  
  if (!ok)
    return 1;
  else
    return 0;
}
