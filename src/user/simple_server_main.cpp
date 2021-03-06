#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int TCPServer (int port)
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( port );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
