#ifndef INCL_PROGRAM_COUNTER_T
#define INCL_PROGRAM_COUNTER_T

#include "tests.h"

#include "program_counter.h"

#include <sstream>

namespace ToyCpu
{
	namespace Tests
	{
		class ProgramCounterTests
		{
		public:
			static void run()
			{
				defaultConstruction();

				increment();
			}

		private:
			static void defaultConstruction()
			{
				title("default construction");
				ProgramCounter pc;

				if(pc.read().valueAsDecimal() != 0)
				{
					fail();
					return;
				}

				pass();
			}

			static void increment()
			{
				title("increment");
				ProgramCounter pc;
				pc.increment();

				if(pc.read().valueAsDecimal() != 1)
				{
					fail();
					return;
				}

				pc.write(Word(76));
				pc.increment();

				if(pc.read().valueAsDecimal() != 77)
				{
					std::stringstream ss;
					ss << "post-increment value: " << pc.read().valueAsDecimal();
					fail(ss.str());
					return;
				}

				pass();
			}
		};
	} // Tests
} // ToyCpu

#endif