#pragma once

#include"predator/Core.h"
#include<string>
#include <functional>
namespace predator {
	enum class EventType {
		None=0,KeyPressed,KeyReleased,
		MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased,
		WindowResize, WindowClose,
		AppTick,AppUpdate,AppRender
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
		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & (int)category;
		}
	protected:
		bool m_handled = false;
	};
	class PD_API EventDispatcher {
		template<typename T>
		using EventFn = std::function< bool(T&) >;
	public:
		EventDispatcher(Event& event):
			m_event(event) {}
		
		template<typename T>
		bool dispatch(EventFn<T>func) {
			if (m_event.getEventType() == T::getStaticType()) {
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}

}

