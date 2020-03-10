#pragma once
#include"Event.h"
namespace predator {
	class PD_API KeyEvent :public Event{
	public:
		inline int getKeyCode()const { return m_keycode; }
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryKeyboard | (int)EventCategory::EventCategoryInput);
	protected:
		KeyEvent(int keycode) {
			m_keycode = keycode;
		}
		int m_keycode;
	};

	class PD_API KeyPressedEvent :public KeyEvent {
	public:
		KeyPressedEvent(int keycode,int keycount):
			KeyEvent(keycode),m_keycount(keycount){}

		inline int getKeyCount()const { return m_keycount; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyPressedEvent " << m_keycode << "(" << m_keycount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed);
	protected:
		int m_keycount;
	};
	class PD_API KeyReleasedEvent :public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) :
			KeyEvent(keycode){}

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent " << m_keycode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased);
	};

}



