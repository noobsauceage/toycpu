#include "stdafx.h"

#include "tests.h"

#include <iostream>
#include <string>

namespace ToyCpu
{
	namespace Tests
	{
		void title(const std::string &title)
		{
			std::cout << title << std::endl;
		}

		void pass()
		{
			std::cout << "pass" << std::endl;
		}

		void fail(const std::string &error)
		{
			std::cout << "FAIL: " << error << std::endl;
		}
	} // Tests
} // ToyCpu