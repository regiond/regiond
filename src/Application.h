#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

namespace regiond
{
	class Application
	{
	public:
		Application(std::vector<std::string> args);
		virtual ~Application();
		
		int run();
	};
}

#endif
