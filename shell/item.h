#ifndef ITEM_H_
#define ITEM_H_

#include <cstdlib>
#include <ctime>
#include <string>

class dir;

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

	// later, make sure to
	// ensure that m_parent
	// is of class directory
	item *m_parent;
public:
	item(std::string, item * = nullptr);
	item(std::string, std::string, m_perms, item);
	item(std::string, std::string, m_perms, item * = nullptr);

	// item(const item &);
	item(const item &, std::string, item);
	item(const item &, std::string, item * = nullptr);

	// ~item();

	std::string name() const;
	std::string path() const;

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

	virtual item copy(std::string) const;

	// Later move add the copied
	// item into the new directory
	virtual item copy_to(item, std::string = "") const;
	virtual item copy_to(item *, std::string = "") const;

	bool operator==(const item &) const;
	bool operator!=(const item &) const;
};

item::item(std::string name, item *parent) : m_name(name),
	m_status(p_user), m_size(0), m_parent(parent),
	m_created(clock()), m_modified(clock())
{
	if (parent == nullptr)
		m_path = (m_name.empty()) ? "~" : ("~/" + m_name);
	else
		m_path = parent->m_path + "/" + m_name;
}

item::item(std::string name, std::string path, m_perms status, item *parent)
	: m_name(name), m_path(path), m_status(status), m_size(0),
	m_parent(parent), m_created(clock()), m_modified(clock()) {}

item::item(std::string name, std::string path, m_perms status,
	item parent) : item(name, path, status)
{
	m_parent = &parent;
}

item::item(const item &it, std::string name, item parent)
{
	*this = it;
	m_name = name;
	m_parent = &parent;
}

item::item(const item &it, std::string name, item *parent)
{
	*this = it;
	m_name = name;
	m_parent = parent;
}

std::string item::name() const
{
	return m_name;
}

std::string item::path() const
{
	return m_path;
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

item item::copy(std::string name) const
{
	return item(*this, name);
}

item item::copy_to(item parent, std::string name) const
{
	item new_item = item(*this, name);
	new_item.move(parent);
	return new_item;
}

item item::copy_to(item *parent, std::string name) const
{
	item new_item = item(*this, name);
	new_item.move(parent);
	return new_item;
}

bool item::operator==(const item &other) const
{
	if (m_name == other.m_name
		&& m_created == other.m_created
		&& m_modified == other.m_modified
		&& m_parent == other.m_parent
		&& m_path == other.m_path
		&& m_status == other.m_status
		&& m_size == other.m_size)
		return true;
	return false;
}

bool item::operator!=(const item &other) const
{
	return !(*this == other);
}

#endif
