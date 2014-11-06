#ifndef SOCKSSERVER_H
#define SOCKSSERVER_H

#include <boost/asio.hpp>

namespace regiond
{
	using namespace boost::asio;
	
	class SOCKSServer
	{
	public:
		SOCKSServer(io_service &service);
		virtual ~SOCKSServer();
		
	protected:
		io_service &service;
	};
}

#endif
