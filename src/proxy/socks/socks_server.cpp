#include "socks_server.h"

using namespace regiond;
using namespace regiond::proxy::socks;
using namespace boost::asio;
using namespace boost::asio::ip;

socks_server::socks_server(io_service &service):
	service(service)
{
	
}

socks_server::~socks_server()
{
	
}

bool socks_server::bind(tcp::endpoint ep)
{
	return false;
}
