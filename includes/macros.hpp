#ifndef MACROS_H
# define MACROS_H

# include <stdio.h>

# define INFO "INFO"
# define ERROR "ERROR"
# define WARNING "WARNING"

// technically, __FILE_NAME__ is not part of the C standard library
# ifndef __FILE_NAME__
#  define __FILE_NAME__ __FILE__
# endif

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

# define UNFORMATED_LOG(type) "[AlchemyLogger] %s [%s:%d] > ", type, __FILE_NAME__, __LINE__

# define LOG(type, message) \
	printf(UNFORMATED_LOG(type)); \
	printf(message); \
	printf("\n")

# define V_LOG(type, message, ...) \
	printf(UNFORMATED_LOG(type)); \
	printf(message, __VA_ARGS__); \
	printf("\n")

#endif
