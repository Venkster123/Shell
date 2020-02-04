#ifndef DIR_H_
#define DIR_H_

#include <vector>
#include <string>
#include <algorithm>

#include "item.h"
#include "file.h"

#include "window.h"

class dir : public item {
protected:
	std::vector <item *> m_items;
public:
	dir(std::string, item * = nullptr);
	dir(std::string, std::string, m_perms, item);
	dir(std::string, std::string, m_perms, item * = nullptr);

	dir(const item &);
	dir(const item &, std::string, item);
	dir(const item &, std::string, item * = nullptr);

	// Add flags for sorting
	// the directory
	enum m_sort {m_by_name};

	void mkdir(std::string);
	void touch(std::string);

	// Add flags for this
	// member function
	enum m_list {m_regular};

	void list(window &, m_list = m_regular) const;

	friend item *cd(dir *, std::string);
private:
	void sort(m_sort = m_by_name);
};

dir::dir(std::string name, item *parent) : item(name, parent) {}

dir::dir(std::string name, std::string path, m_perms status, item *parent)
	: item(name, path, status, parent) {}

dir::dir(std::string name, std::string path, m_perms status,
	item parent) : item(name, path, status, parent) {}

void dir::sort(m_sort type)
{
	// Change to adapt for flags
	std::sort(m_items.begin(), m_items.end(),
		[](item *a, item *b) {
			return a->name() < b->name();
		});
}

void dir::mkdir(std::string name)
{
	m_items.push_back(new dir(name, this));
	sort();
}

void dir::touch(std::string name)
{
	m_items.push_back(new dir(name, this));
	sort();
}

void dir::list(window &win, m_list flag) const
{
	win << m_name << window::w_endl;
	for (item *i : m_items)
		win << i->name() << window::w_endl;
}

item *cd(dir *curr, std::string name)
{
	// Binary search for
	// appropriate directory
	// and return it

	int last = curr->m_items.size();
	int first = 0;
	int mid;

	while (last - first > 0) {
		mid = (first + last) / 2;

		if (curr->m_items[mid]->name() > name)
			first = mid;
		else
			last = mid;
	}

	return curr->m_items[first];
}

#endif