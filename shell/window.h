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

	int printf(const char *, ...) const;
	int operator()(const char *, ...) const;

	int get_char() const;


	enum m_flush {w_endl};
	enum m_echo {w_echo, w_noecho};

	std::string get_line(m_echo) const;
};

window::window(WINDOW *win)
{
	m_win = win;

	// Add options later
	keypad(m_win, TRUE);
	scrollok(m_win, TRUE);
}

int window::operator()(const char *format, ...) const
{
	va_list arg;
	int done;
	
	va_start(arg, format);
	done = wprintw(m_win, format, arg, 0);
	va_end(arg);
	
	return done;
}

int window::printf(const char *format, ...) const
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = wprintw(m_win, format, arg);
	va_end(arg);

	return done;
}

int window::get_char() const
{
	return wgetch(m_win);
}

std::string window::get_line(m_echo echo_status) const
{
	std::string line;
	int cur_pos;
	int cur_in;
	int ch;

	switch (echo_status) {
	case w_noecho:
		noecho();
		break;
	case w_echo:
		echo();
		break;
	default:
		// argument error
		return line;
	}

	cur_pos = 0;
	while ((ch = wgetch(m_win)) != '\n') {
		if (ch == KEY_BACKSPACE
			|| ch == KEY_DC) {
			if (cur_pos > 0) {
				wprintw(m_win, "\b \b");
				cur_pos--;
			}

			// ignore if this case
			// is not satisfied

			// wprintw(m_win, "delted");
		} else {
			waddch(m_win, ch);
			line += ch;
			cur_pos++;
		}

		wrefresh(m_win);
	}
	
	return line;
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

// Speciallize w_endl
window &operator<<(window &win, window::m_flush fl)
{
	// do flushing later
	win("\n");
	return win;
}

#endif
