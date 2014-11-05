#include "Application.h"

#include <string>
#include <vector>

using namespace regiond;

int main(int argc, char *argv[])
{
	std::vector<std::string> args;
	for (int i = 0; i < argc; ++i)
		args.push_back(std::string(argv[i]));
	
	Application app(args);
	return app.run();
}
