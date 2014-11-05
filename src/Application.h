#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

namespace regiond
{
	/**
	 * Regiond's main application class.
	 * 
	 * This doesn't do much itself, it's basically a glorified main().
	 */
	class Application
	{
	public:
		/**
		 * Constructor.
		 * 
		 * @arg args The application's commandline arguments, if any
		 */
		Application(std::vector<std::string> args);
		
		virtual ~Application();
		
		/**
		 * Runs the application.
		 * 
		 * @returns The application's exit code
		 */
		int run();
	};
}

#endif
