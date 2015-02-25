#ifndef INCL_WORD_T
#define INCL_WORD_T

#include "tests.h"

#include "word.h"

#include <sstream>

namespace ToyCpu
{
	namespace Tests
	{
		class WordTests
		{
		public:
			static void run()
			{
				defaultConstruction();
				intDecimalConstruction();
				intBinaryConstruction();

				valueDecimal();
				valueBinary();

				bitAccess();
				constBitAccess();

				assignment();
				
				stream();
			}

		private:
			static void defaultConstruction()
			{
				title("default construction");
				Word word;
				
				std::cout << "zeroes: " << word << std::endl;
			}

			static void intDecimalConstruction()
			{
				title("decimal construction");
				Word word(5);

				std::cout << "five: " << word << std::endl;
			}

			static void intBinaryConstruction()
			{
				title("binary construction");
				
				Word word(101, Word::BINARY);

				std::cout << "five: " << word << std::endl;
			}

			//

			static void valueDecimal()
			{
				title("value as decimal");
				Word word(5);

				if(word.valueAsDecimal() != 5)
				{
					fail();
					return;
				}

				pass();
			}

			static void valueBinary()
			{
				title("value as binary");
				Word word(5);

				if(word.valueAsBinary() != 101)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void bitAccess()
			{
				title("bit access operator");
				Word word(5);

				if(word[0] != 1)
				{
					fail("lsb");
					return;
				}

				if(word[1] != 0)
				{
					fail("second to least bit");
					return;
				}

				if(word[2] != 1)
				{
					fail("third to least bit");
					return;
				}

				pass();
			}

			static void constBitAccess()
			{
				title("const bit access operator");
				const Word word(5);

				if(word[0] != 1)
				{
					std::stringstream ss;
					ss << "least significant bit: " << word[0];
					fail(ss.str());
					return;
				}

				if(word[1] != 0)
				{
					fail("second to least bit");
					return;
				}

				if(word[2] != 1)
				{
					fail("third to least bit");
					return;
				}

				pass();
			}

			//

			static void assignment()
			{
				title("assignment");
				Word target(5);
				Word source(10);

				target = source;

				if(target.valueAsDecimal() != 10)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void stream()
			{
				title("stream insertion");
				Word word(5);
				std::stringstream ss;

				ss << word;

				if(ss.str() != "00000101")
				{
					fail(ss.str());
					return;
				}

				pass();
			}
		};
	}
}

#endif