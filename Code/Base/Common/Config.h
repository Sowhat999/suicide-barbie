
#ifndef NEWAGE_BASE_COMMON_CONFIG_H
#define NEWAGE_BASE_COMMON_CONFIG_H

#if defined WIN32 || defined __psp__

// Disable "vsprintf() is deprecated, use vsprintf_s() instead" family of warnings
#pragma warning (disable : 4996)

// Make register-passing arguments go on stack for win32 builds
#define __reg(x)
#define __asm

// Ignore inlining for win32 builds
#define inline

#endif

#endif
