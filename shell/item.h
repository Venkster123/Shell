#ifndef ITEM_H_
#define ITEM_H_

#include <cstdlib>
#include <ctime>
#include <string>

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

	item(const item &, std::string);

	~item();

	/* Keep the following virtual
	 * functions virtual to allow
	 * different operations to be
	 * done for each function in
	 * the other levels of
	 * inheritance
	 *
	 * Also, make sure to change
	 * the value of modified each
	 * time a mutator is called, and
	 * thrown exceptions whenever
	 * errors such as duplicate
	 * existence is encountered */
	virtual void move(item);
	virtual void move(item *);

	virtual void rename(std::string);

	virtual const item &copy();
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

void item::move(item parent)
{
	if (parent != *m_parent) {
		m_parent = &parent;
		m_modified = clock();
	}
}

void item::move(item *parent)
{
	if (parent != m_parent) {
		m_parent = parent;
		m_modified = clock();
	}
}

void item::rename(std::string name)
{
	if (name != m_name) {
		m_name = name;
		m_modified = clock();
	}
}

#endif
