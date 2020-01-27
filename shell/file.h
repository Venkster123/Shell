#ifndef FILE_H_
#define FILE_H_

#include "item.h"

class file : public item {
protected:
	std::size_t m_capacity;
	std::string *m_content;
public:
	static const std::size_t default_capacity;
};

static const std::size_t file::default_capacity = 0x400;

#endif
