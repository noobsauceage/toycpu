#ifndef INCL_ALU_T
#define INCL_ALU_T

#include "tests.h"

#include "alu.h"
#include "word.h"

#include <sstream>

namespace ToyCpu
{
	namespace Tests
	{
		class AluTests
		{
		public:
			static void run()
			{
				defaultConstruction();

				add();
				addOverflow();
				subtract();
				subtractOverflow();

				compareEquals();
				compareLessThan();
				compareGreaterThan();

				opcodes();
			}

		private:
			static void defaultConstruction()
			{
				title("default construction");
				ALU alu;

				if(alu.overflow() != 0)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void add()
			{
				title("add");
				ALU alu;
				Word sum;
				Word addend1(30);
				Word addend2(99);
				alu.add(sum, addend1, addend2);

				if(sum.valueAsDecimal() != 129)
				{
					std::stringstream ss;
					ss << "sum: " << sum.valueAsDecimal();
					fail(ss.str());
					return;
				}

				pass();
			}

			static void addOverflow()
			{
				title("add with overflow");
				ALU alu;
				Word sum;
				Word addend1(200);
				Word addend2(99);
				alu.add(sum, addend1, addend2);

				if(sum.valueAsDecimal() != 43)
				{
					std::stringstream ss;
					ss << "sum: " << sum.valueAsDecimal();
					fail(ss.str());
					return;
				}

				if(alu.overflow() != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void subtract()
			{
				title("subtract");
				ALU alu;
				Word difference;
				Word minuend(99);
				Word subtrahend(30);
				alu.subtract(difference, minuend, subtrahend);

				if(difference.valueAsDecimal() != 69)
				{
					std::stringstream ss;
					ss << "difference: " << difference.valueAsDecimal();
					fail(ss.str());
					return;
				}

				pass();
			}

			static void subtractOverflow()
			{
				title("subtract with underflow");
				ALU alu;
				Word difference;
				Word minuend(99);
				Word subtrahend(200);
				alu.subtract(difference, minuend, subtrahend);

				if(difference.valueAsDecimal() != 155)
				{
					std::stringstream ss;
					ss << "difference: " << difference.valueAsDecimal();
					fail(ss.str());
					return;
				}

				if(alu.overflow() != 1)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void compareEquals()
			{
				title("equality");
				ALU alu;
				Word result;
				Word lhs(82);
				Word rhs(82);
				alu.compare(result, lhs, rhs);

				if((result[0] != 1) ||
				   (result[1] != 0) ||
				   (result[2] != 0))
				{
					std::stringstream ss;
					ss << "result: " << result.valueAsBinary();
					fail(ss.str());
					return;
				}

				pass();
			}

			static void compareLessThan()
			{
				title("less than");
				ALU alu;
				Word result;
				Word lhs(1);
				Word rhs(255);
				alu.compare(result, lhs, rhs);

				if((result[0] != 0) ||
				   (result[1] != 0) ||
				   (result[2] != 1))
				{
					std::stringstream ss;
					ss << "result: " << result.valueAsBinary();
					fail(ss.str());
					return;
				}

				pass();
			}

			static void compareGreaterThan()
			{
				title("greater than");
				ALU alu;
				Word result;
				Word lhs(177);
				Word rhs(176);
				alu.compare(result, lhs, rhs);

				if((result[0] != 0) ||
				   (result[1] != 1) ||
				   (result[2] != 0))
				{
					std::stringstream ss;
					ss << "result: " << result.valueAsBinary();
					fail(ss.str());
					return;
				}

				pass();
			}

			//

			static void opcodes()
			{
				title("opcodes");
				ALU alu;
				Word result;
				Word lhs(100);
				Word rhs(10);
				Word add(1001, Word::BINARY);
				Word subtract(1010, Word::BINARY);
				Word compare(1000, Word::BINARY);
				alu.doAluOp(add, result, lhs, rhs);

				if(result.valueAsDecimal() != 110)
				{
					std::stringstream ss;
					ss << "add result: " << result.valueAsBinary();
					fail(ss.str());
					return;
				}

				alu.doAluOp(subtract, result, lhs, rhs);
				
				if(result.valueAsDecimal() != 90)
				{
					std::stringstream ss;
					ss << "subtract result: " << result.valueAsBinary();
					fail(ss.str());
					return;
				}

				alu.doAluOp(compare, result, lhs, rhs);

				if(result.valueAsBinary() != 10)
				{
					std::stringstream ss;
					ss << "compare result: " << result.valueAsBinary();
					fail(ss.str());
					return;
				}

				pass();
			}
		};
	}
}

#endif