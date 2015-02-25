#ifndef INCL_TESTS
#define INCL_TESTS

#include <string>

namespace ToyCpu
{
	namespace Tests
	{
		void title(const std::string &title);

		void pass();
		void fail(const std::string &error = "N/A");
	} // Tests
} // ToyCpu

#endif