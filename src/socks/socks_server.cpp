#include "socks_server.h"

using namespace regiond;
using namespace regiond::socks;
using namespace boost::asio;

socks_server::socks_server(io_service &service):
	service(service)
{
	
}

socks_server::~socks_server()
{
	
}
