#ifndef MACROS_H
# define MACROS_H

// create a one time use setter
// put at the end of a class declaration
// in the code that need to call it, you can use set_[variablename]
// with its new value.
// useful for classes where a constructor is only used to set
// private variables
# define SET_ONCE(member)							\
public:												\
	void	set_##member(typeof(member) value) {	\
		if (!m_##member##_set) { this->member = value; m_##member##_set = 1; }	\
	}	\
private:											\
	int		m_##member##_set = 0

#endif
