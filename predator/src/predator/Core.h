
#ifdef PD_PLATFORM_WINDOWS
	#ifdef PD_BUILD_DLL
		#define PD_API __declspec(dllexport)
	#else
		#define PD_API __declspec(dllimport)
	#endif
#else
	#error predator only for windows
#endif

#define BIT(x) (1<<x)

#define EVENT_CLASS_TYPE(type) static EventType getStaticType(){return EventType::##type;} virtual EventType getEventType() const override{return getStaticType();}virtual char* getName()const override{return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override{return category;}


