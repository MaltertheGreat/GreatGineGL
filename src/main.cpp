#include "GGApplication.h"

#include <exception>
#include <iostream>

int main()
{
	GGApplication app;

	try
	{
		app.Run();
	}
	catch(std::exception& e)
	{
		std::cerr << "Error occured!" << std::endl << e.what() << std::endl;

		return -1;
	}

	return 0;
}
