#pragma once

#include"predator/Core.h"
#include<string>

namespace predator {
	enum class EventType {
		None=0,KeyPressed,KeyReleased
	};

	enum class EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class PD_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual char* getName() const = 0;
		virtual std::string toString()const { return getName(); }
	protected:
		bool m_handled = false;
	};

}

