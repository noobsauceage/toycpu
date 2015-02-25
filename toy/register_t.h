#ifndef INCL_REGISTER_T
#define INCL_REGISTER_T

#include "tests.h"

#include "register.h"

namespace ToyCpu
{
	namespace Tests
	{
		class RegisterTests
		{
		public:
			static void run()
			{
				defaultConstruction();

				readAndWrite();
			}

		private:
			static void defaultConstruction()
			{
				title("default construction");
				Register reg;

				if(reg.read().valueAsDecimal() != 0)
				{
					fail();
					return;
				}

				pass();
			}

			static void readAndWrite()
			{
				title("read and write");
				Register reg;
				reg.write(Word(100));

				if(reg.read().valueAsDecimal() != 100)
				{
					fail();
					return;
				}

				pass();
			}
		};
	} // Tests
} // ToyCpu

#endif