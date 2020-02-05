#ifndef MACHINE_H_
#define MACHINE_H_

#include <string>
#include <vector>

#include "dir.h"
#include "window.h"
#include "parser.h"

// Add sockets and
// networking later
class machine {
	std::string m_name;
	dir *m_root;

	// for now, assume only one window
	window m_scr;
	//std::vector <window *> m_windows; list of available windows
	//std::vector <bool> m_open; reflects whether a window is open or not

	enum m_commands {m_mkdir, m_touch};
public:
	machine(std::string);

	// Later add file constructor
	// machine(ifstream &)

	// Actually running
	// the machine
	virtual void operator()();
protected:
	// this function will take
	// the line as input and then
	// perform the necessary operations
	virtual void perform(std::string);
	virtual m_commands get_code(std::string);
};

machine::machine(std::string name) : m_name(name),
	m_scr(stdscr)
{
	m_root = new dir("", nullptr);
	// m_scr = window(stdscr);
}

void machine::operator()()
{
	std::string input;
	while (true) {
		m_scr << m_name << ": " << m_root->path() << " $ ";
		input = m_scr.get_line(window::w_noecho);
		perform(input);
	}
}

void machine::perform(std::string line)
{
	std::vector <std::string> flags;
	flags = get_flags(line);

	if (flags.size() <= 0)
		return;

	std::string cmd = flags[0];
	m_commands type = 
}

void machine::get_code(std::)

#endif