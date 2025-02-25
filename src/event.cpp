#include "event.hpp"
#include <cstring>
#include <map>
#include <string>
#include <utility>

static std::map<void (*)(BaseEvent *), std::string> listeners = { };

void	register_listener(void (*listener)(BaseEvent *), std::string event_name)
{
	auto	check = listeners.find(listener);

	if (check != listeners.end())
			return ;
	listeners.insert(std::pair<void (*)(BaseEvent *), std::string>(listener, event_name));
}

void	delete_listener(void (*listener)(BaseEvent *))
{
	auto	check = listeners.find(listener);

	if (check != listeners.end())
		listeners.erase(listener);
}

void	fire_event(BaseEvent *event)
{
	for (auto listener : listeners)
		if (!strcmp(listener.second.c_str(), event->get().c_str()))
			listener.first(event);
	delete event;
}
