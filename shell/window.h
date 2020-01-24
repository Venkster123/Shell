#ifndef WINDOW_H_
#define WINDOW_H_

#include <ostream>
#include <iostream>
#include <streambuf>
#include <ncurses.h>

class window : std::streambuf {
protected:
	WINDOW *m_win;
public:
	window(WINDOW *);

	int operator()(const char *, ...);

	/* Implement the following later
	std::streamsize xsputn(const char_type* s, std::streamsize n);
	int_type overflow(int_type c); */

	int printf(const char *, ...);

	// boolean for initscr-ed
	static bool initialized;
};

bool window::initialized = false;

window::window(WINDOW *win)
{
	using namespace std;

	/*if (!initialized) {
		initialized = true;
		initscr();
	}*/

	initscr();

	m_win = win;
}

int window::operator()(const char *format, ...)
{
	va_list arg;
	int done;
	
	va_start(arg, format);
	done = wprintw(m_win, format, arg, 0);
	va_end(arg);
	
	return done;
}

int window::printf(const char *format, ...)
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = wprintw(m_win, format, arg);
	va_end(arg);

	return done;
}

#endif
