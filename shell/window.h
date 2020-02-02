#ifndef WINDOW_H_
#define WINDOW_H_

#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

#include <ncurses.h>

class window : std::streambuf {
protected:
	WINDOW *m_win;
public:
	window(WINDOW *);

	int operator()(const char *, ...);

	int printf(const char *, ...);
};

window::window(WINDOW *win)
{
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

// Global insertion operator overload
template <class T>
window &operator<<(window &win, const T &in)
{
	std::ostringstream oss;

	oss << in;
	win(oss.str().c_str());

	return win;
}

// Define endl for windows
window &w_endl(window &win)
{
	// For now, simply do newline,
	// later actualyl flush output
	win("\n");
	refresh();
	return win;
}

#endif
