#include "SOCKSServer.h"

using namespace regiond;
using namespace boost::asio;

SOCKSServer::SOCKSServer(io_service &service):
	service(service)
{
	
}

SOCKSServer::~SOCKSServer()
{
	
}
