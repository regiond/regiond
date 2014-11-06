#ifndef SOCKS_SERVER_H
#define SOCKS_SERVER_H

#include <boost/asio.hpp>

namespace regiond
{
	namespace socks
	{
		using namespace boost::asio;
		
		class socks_server
		{
		public:
			socks_server(io_service &service);
			virtual ~socks_server();
			
		protected:
			io_service &service;
		};
	}
}

#endif
