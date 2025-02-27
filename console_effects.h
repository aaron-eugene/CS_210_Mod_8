
/***********************
	Aaron E. Befus
	CS 210
	Project 2
	2/5/2025
************************/

// The console_effects.h header adds additional functionality 
// to the standard console in a cross-platform manner - change 
// text color, move input cursor, and clear console contents.

#ifndef CONSOLE_EFFECTS_H
#define CONSOLE_EFFECTS_H

#include <iostream>

#include "os_detection.h"

#ifdef OS_WINDOWS
#include <windows.h>
#endif

// Namespace to improve readability in-app
namespace ConsoleEffects
{

// If we are running on some version of Windows
#ifdef OS_WINDOWS

	// Handle to the console
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Set console text color to green
	inline void greenText()
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}

	// Reset console text color to white
	inline void whiteText()
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED |
			FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	// Move to beginning of previous line
	inline void moveUpLine()
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo = {};
		GetConsoleScreenBufferInfo(hConsole, &consoleBufferInfo);

		COORD currentPosition = consoleBufferInfo.dwCursorPosition;

		// Move up if possible
		if (currentPosition.Y > 0)
		{
			--currentPosition.Y;
			currentPosition.X = 0;
			SetConsoleCursorPosition(hConsole, currentPosition);
		}
	}

	// Clear current console line
	inline void clearCurrentLine()
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo = {};
		GetConsoleScreenBufferInfo(hConsole, &consoleBufferInfo);

		COORD currentPosition = consoleBufferInfo.dwCursorPosition;
		DWORD written;

		// Clear the entire width of the line & move cursor back to start
		FillConsoleOutputCharacter(hConsole, ' ', consoleBufferInfo.dwSize.X,
			currentPosition, &written);
		SetConsoleCursorPosition(hConsole, currentPosition);
	}

	// Move up a given number of lines, clearing all of them
	inline void moveUpAndClear(int numLines)
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo = {};
		GetConsoleScreenBufferInfo(hConsole, &consoleBufferInfo);

		COORD position = consoleBufferInfo.dwCursorPosition;
		DWORD written;

		// Clear current line
		position.X = 0;
		FillConsoleOutputCharacter(hConsole, ' ', consoleBufferInfo.dwSize.X,
			position, &written);

		// Clear each line above
		for (int i = 0; i < numLines; ++i)
		{
			// Move up if possible
			if (position.Y > 0)
			{
				--position.Y;
				position.X = 0;
				SetConsoleCursorPosition(hConsole, position);
			}
			else
			{
				break;
			}

			// Clear the line
			FillConsoleOutputCharacter(hConsole, ' ', consoleBufferInfo.dwSize.X,
				position, &written);
		}

		// Move cursor to final position
		position.X = 0;
		SetConsoleCursorPosition(hConsole, position);
	}

	// Clear entire console
	inline void clearConsole()
	{
		COORD topLeft = { 0, 0 };
		CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo = {};
		DWORD written;

		// Get the number of cells in the console buffer
		GetConsoleScreenBufferInfo(hConsole, &consoleBufferInfo);
		DWORD consoleSize = consoleBufferInfo.dwSize.X * consoleBufferInfo.dwSize.Y;

		// Fill the entire screen with spaces
		FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &written);
		FillConsoleOutputAttribute(hConsole, consoleBufferInfo.wAttributes,
			consoleSize, topLeft, &written);

		// Move cursor to top-left corner
		SetConsoleCursorPosition(hConsole, topLeft);
	}
#endif

// If we are running on a Posix-based system (Linux, MacOS, etc.)
#ifdef OS_POSIX

	// Macros defining particular escape sequences
	#define GREEN_TEXT			"\033[92m"
	#define WHITE_TEXT			"\033[0m"
	#define MOVE_UP				"\033[A\r"
	#define CLEAR_CURRENT_LINE	"\033[2K\r"
	#define CLEAR_CONSOLE		"\033[2J\033[H"

	// Set console text color to green
	inline void greenText()
	{
		std::cout << GREEN_TEXT << std::flush;
	}

	// Reset console text color to white
	inline void whiteText()
	{
		std::cout << WHITE_TEXT << std::flush;
	}

	// Move to beginning of previous line
	inline void moveUpLine()
	{
		std::cout << MOVE_UP << std::flush;
	}

	// Clear current console line
	inline void clearCurrentLine()
	{
		std::cout << CLEAR_CURRENT_LINE << std::flush;
	}

	// Move up a given number of lines, clearing all of them
	inline void moveUpAndClear(int numLines)
	{
		// Clear current line
		std::cout << CLEAR_CURRENT_LINE;

		// Move up and clear each line above
		for (int i = 0; i < numLines; ++i)
		{
			std::cout << MOVE_UP << CLEAR_CURRENT_LINE;
		}

		std::cout << std::flush;
	}

	// Clear entire console
	inline void clearConsole()
	{
		std::cout << CLEAR_CONSOLE << std::flush;
	}
#endif
}
#endif
