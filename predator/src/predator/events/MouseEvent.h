#pragma once
#include"Event.h"
namespace predator {
	class PD_API MouseMovedEvent :public Event {
	public:
		MouseMovedEvent(float x,float y):
			m_mouseX(x),m_mouseY(y){}
		inline float getX() const { return m_mouseX; }
		inline float getY() const { return m_mouseY; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Moved " << m_mouseX << " " << m_mouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput);
	private:
		float m_mouseX;
		float m_mouseY;
	};
	class PD_API MouseScrolledEvent :public Event {
	public:
		MouseScrolledEvent(float x_offset, float y_offset) :
			mouse_x_offset(x_offset), mouse_y_offset(y_offset) {}
		inline float getX() const { return mouse_x_offset; }
		inline float getY() const { return mouse_y_offset; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Moved " << getX() << " " << getY();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput);
	private:
		float mouse_x_offset;
		float mouse_y_offset;
	};
	class PD_API MouseButtonEvent :public Event {
	public:
		inline int getButton() const { return m_button; }
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput);
	protected:
		MouseButtonEvent(int button) :
			m_button(button) {}
		int m_button;
	};
	class PD_API MouseButtonPressedEvent :public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Pressed Event " << getButton();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed);
	};
	class PD_API MouseButtonEvent :public Event {
	public:
		inline int getButton() const { return m_button; }
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput);
	protected:
		MouseButtonEvent(int button) :
			m_button(button) {}
		int m_button;
	};
	class PD_API MouseButtonReleasedEvent :public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button released Event " << getButton();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased);
	};


}



