#ifndef DIR_H_
#define DIR_H_

#include <vector>

#include "item.h"

class dir : public item {
protected:
	(item *) *m_dir;
public:
	static const std::size_t default_capacity;
};

static const std::size_t dir::default_capacity = 0x400;

#endif