#ifndef ITEM_H_
#define ITEM_H_

#include <cstdlib>
#include <string>

class item {
protected:
	std::string m_name;
	std::string m_path;
	size_t m_size;
public:
	enum m_perms {
		p_user,
		p_admin,
		p_root,
		p_sudo
	};
};

#endif