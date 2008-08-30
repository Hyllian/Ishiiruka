// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef _PLUGIN_VIDEO_H
#define _PLUGIN_VIDEO_H

#include "Common.h"

#include "pluginspecs_video.h"

#include "ChunkFile.h"

namespace PluginVideo
{
bool IsLoaded();
bool LoadPlugin(const char *_Filename);
void UnloadPlugin();

// Function Types
typedef void (__cdecl* TGetDllInfo)(PLUGIN_INFO*);
typedef void (__cdecl* TDllAbout)(HWND);
typedef void (__cdecl* TDllConfig)(HWND);
typedef void (__cdecl* TVideo_Initialize)(SVideoInitialize*);
typedef void (__cdecl* TVideo_Prepare)();
typedef void (__cdecl* TVideo_Shutdown)();
typedef void (__cdecl* TVideo_SendFifoData)(BYTE*);
typedef void (__cdecl* TVideo_UpdateXFB)(BYTE*, DWORD, DWORD);
typedef BOOL (__cdecl* TVideo_Screenshot)(TCHAR*);
typedef void (__cdecl* TVideo_EnterLoop)();
typedef void (__cdecl* TVideo_AddMessage)(const char* pstr, unsigned int milliseconds);
typedef void (__cdecl* TVideo_DoState)(unsigned char **ptr, int mode);

// Function Pointers
extern TGetDllInfo         GetDllInfo;
extern TDllAbout           DllAbout;
extern TDllConfig          DllConfig;
extern TVideo_Initialize   Video_Initialize;
extern TVideo_Prepare      Video_Prepare;
extern TVideo_Shutdown     Video_Shutdown;
extern TVideo_SendFifoData Video_SendFifoData;
extern TVideo_UpdateXFB    Video_UpdateXFB;
extern TVideo_Screenshot   Video_Screenshot;
extern TVideo_EnterLoop    Video_EnterLoop;
extern TVideo_AddMessage   Video_AddMessage;
extern TVideo_DoState      Video_DoState;

} // end of namespace PluginVideo

#endif
