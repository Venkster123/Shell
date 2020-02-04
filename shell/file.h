#ifndef FILE_H_
#define FILE_H_

#include "item.h"

class file : public item {
protected:
	std::size_t m_capacity;
	std::string *m_content;
public:
	file(std::string, item * = nullptr);
	file(std::string, std::string, m_perms, item);
	file(std::string, std::string, m_perms, item * = nullptr);

	file(const item &);
	file(const item &, std::string, item);
	file(const item &, std::string, item * = nullptr);
};

file::file(std::string name, item *parent) : item(name, parent) {}

file::file(std::string name, std::string path, m_perms status, item *parent)
	: item(name, path, status, parent) {}

file::file(std::string name, std::string path, m_perms status,
	item parent) : item(name, path, status, parent) {}

#endif
