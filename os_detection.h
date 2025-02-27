
/***********************
	Aaron E. Befus
	CS 210
	Project 2
	2/5/2025
************************/

// The os_detection.h header detects what OS the application 
// is running on and defines a macro to inform console_effects.h

#ifndef OS_DETECTION_H
#define OS_DETECTION_H

#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS
#else
#define OS_POSIX
#endif
#endif
