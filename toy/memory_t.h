#ifndef INCL_MEMORY_T
#define INCL_MEMORY_T

#include "tests.h"

#include "memory.h"
#include "word.h"

#include <sstream>

namespace ToyCpu
{
	namespace Tests
	{
		class MemoryTests
		{
		public:
			static void run()
			{
				defaultConstruction();
				
				readWrite();
			}

		private:
			static void defaultConstruction()
			{
				title("default construction");
				Memory memory;

				// make sure some random addresses are zero
				if(memory.readAddress(Word(0)).valueAsDecimal() != 0)
				{
					fail();
					return;
				}

				if(memory.readAddress(Word(127)).valueAsDecimal() != 0)
				{
					fail();
					return;
				}

				if(memory.readAddress(Word(255)).valueAsDecimal() != 0)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void readWrite()
			{
				title("read and write");
				Memory memory;

				memory.writeAddress(Word(11111111, Word::BINARY), Word(0));
				memory.writeAddress(Word(10101010, Word::BINARY), Word(127));
				memory.writeAddress(Word(1010101, Word::BINARY), Word(255));

				if(memory.readAddress(Word(0)).valueAsBinary() != 11111111)
				{
					fail("address 0");
					return;
				}

				if(memory.readAddress(Word(127)).valueAsBinary() != 10101010)
				{
					fail("address 127");
					return;
				}

				if(memory.readAddress(Word(255)).valueAsBinary() != 1010101)
				{
					std::stringstream ss;
					ss << "address 255: " << memory.readAddress(Word(255)).valueAsBinary();
					fail(ss.str());
					return;
				}

				pass();
			}
		};
	} // Tests
} // ToyCpu

#endif