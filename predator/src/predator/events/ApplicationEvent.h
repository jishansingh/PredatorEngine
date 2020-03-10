#pragma once

#include"Event.h"

namespace predator {
	class PD_API WindowResizeEvent :public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_width(width), m_height(height) {}
		inline unsigned int getWidth()const { return m_width; }
		inline unsigned int getHeight()const { return m_height; }
		std::string ToString() const override {
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

	class PD_API WindowCloseEvent :public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};

	class PD_API AppTickEvent :public Event {
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};
	class PD_API AppUpdateEvent :public Event {
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};
	class PD_API AppRenderEvent :public Event {
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication);
	};
}


