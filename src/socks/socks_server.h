#ifndef SOCKS_SERVER_H
#define SOCKS_SERVER_H

#include <boost/asio.hpp>

namespace regiond
{
	namespace socks
	{
		using namespace boost::asio;
		
		/**
		 * Implements a SOCKS 4a proxy server.
		 * 
		 * Currently only implements the CONNECT operation, allowing outward
		 * connections - to accept inbound connections as well, the BIND
		 * operation would have to be implemented.
		 * 
		 * Specifications used:
		 * 
		 * - https://github.com/hailiang/socks/blob/master/spec/SOCKS4.protocol.txt
		 * - https://github.com/hailiang/socks/blob/master/spec/socks4A.protocol.txt
		 */
		class socks_server
		{
		public:
			/**
			 * Creates a SOCKS server using the given ASIO Service.
			 * 
			 * This does not actually bind to a port, use bind() for that.
			 */
			socks_server(io_service &service);
			virtual ~socks_server();
			
			/**
			 * Binds the server to the specified endpoint.
			 */
			bool bind(ip::tcp::endpoint ep);
			
		protected:
			io_service &service;			///< The service on which the server runs
		};
	}
}

#endif
