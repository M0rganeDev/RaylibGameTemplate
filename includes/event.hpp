#ifndef EVENT_HPP
# define EVENT_HPP

# include <typeinfo>
# include <string>
# include <functional>

# define REGISTER_LISTENER(method, class)	\
	register_listener((void (*)(BaseEvent *))(method), GET_TYPE(class))

# define CLASS_MEMBER(method, class) \
	std::bind(&class::method, this, std::placeholders::_1)

# define CREATE_EVENT(name) class name : public BaseEvent

# define GET_TYPE(class) \
	std::string(typeid(class).name())

# define CREATE_EVENT_CONSTRUCTOR(m_Class)	\
public:										\
	m_Class() {								\
		this->m_Name = GET_TYPE(m_Class);	\
	}

// one con of C++ : cant do weird shit with classes
# define CHECK_EVENT(class, event) \
	BaseEvent *_event = dynamic_cast<class*>(event); \
	if (_event == nullptr) return


class BaseEvent {
public:
	BaseEvent () { }
	virtual		~BaseEvent() {}
	std::string	get() { return m_Name; }
protected:
	std::string	m_Name = GET_TYPE(this);
};

// declare event classes that dont require any content here
CREATE_EVENT(RenderImguiEvent) {
	CREATE_EVENT_CONSTRUCTOR(RenderImguiEvent)
};
CREATE_EVENT(RenderWorldEvent) {
	CREATE_EVENT_CONSTRUCTOR(RenderWorldEvent)
};

void	register_listener(void (*listener)(BaseEvent *), std::string event_name);
void	delete_listener(void (*listener)(BaseEvent *));
void	fire_event(BaseEvent *event);

#endif
