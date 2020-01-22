#ifndef ITEM_H_
#define ITEM_H_

#include <cstdlib>
#include <ctime>
#include <string>
#include <type_traits>

class item {
public:
	enum m_perms {
		p_user,
		p_admin,
		p_root,
		p_sudo
	};
protected:
	std::string m_name;
	std::string m_path;

	size_t m_size;

	time_t m_created;
	time_t m_modified;

	m_perms m_status;

	item *m_parent;
public:
	item(std::string, std::string, m_perms);
	item(std::string, std::string, m_perms, item);
	item(std::string, std::string, m_perms, item *);

	void move(item);
	void move(item *);
};

item::item(std::string name, std::string path, m_perms status)
	: m_name(name), m_path(path), m_status(status), m_size(0),
	m_parent(nullptr), m_created(clock()), m_modified(clock()) {}

item::item(std::string name, std::string path, m_perms status,
	item parent) : item(name, path, status)
{
	m_parent = &parent;
}

item::item(std::string name, std::string path, m_perms status,
	item *parent) : item(name, path, status)
{
	m_parent = parent;
}

#endif
