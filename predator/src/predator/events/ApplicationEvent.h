#pragma once
#include"Event.h"
#include<sstream>

namespace predator {
	class WindowResizeEvent :public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_width(width), m_height(height) {}
		inline unsigned int getWidth()const { return m_width; }
		inline unsigned int getHeight()const { return m_height; }
		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent " << getWidth() << " " << getHeight();
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);

	private:
		unsigned int m_width;
		unsigned int m_height;
	};
	class WindowCloseEvent :public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};

	class AppTickEvent :public Event {
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};
	class AppUpdateEvent :public Event {
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};
	class AppRenderEvent :public Event {
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};
}


