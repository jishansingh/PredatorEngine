
#ifdef PD_PLATFORM_WINDOWS
	#ifdef PD_BUILD_DLL
		#define PD_API __declspec(dllexport)
	#else
		#define PD_API __declspec(dllimport)
	#endif
#else
	#error predator only for windows
#endif


