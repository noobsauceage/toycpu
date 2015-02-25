#ifndef INCL_BIT_T
#define INCL_BIT_T

#include "tests.h"

#include "bit.h"

#include <sstream>

namespace ToyCpu
{
	namespace Tests
	{
		class BitTests
		{
		public:
			static void run()
			{
				defaultConstruction();
				intConstruction();
				boolConstruction();
				copyConstruction();

				comparison();
				intComparison();
				boolComparison();

				modifiableReference();
				valueByValue();

				and();
				or();
				nand();
				nor();
				xor();
				xnor();
				not();

				assignment();
				intAssignment();
				boolAssignment();

				stream();
			}

		private:
			static void defaultConstruction()
			{
				title("default construction");
				Bit bit;
				std::cout << "zero: " << bit << std::endl;
			}

			static void intConstruction()
			{
				title("construct from int");
				Bit int_one(1);
				Bit int_zero(0);
				std::cout << "one: " << int_one << " zero: " << int_zero << std::endl;
			}

			static void boolConstruction()
			{
				title("construct from bool");
				Bit bool_one(true);
				Bit bool_zero(false);
				std::cout << "one: " << bool_one << " zero: " << bool_zero << std::endl;
			}

			static void copyConstruction()
			{
				title("copy construction");
				Bit one(1);
				Bit zero(0);
				Bit copy_one(one);
				Bit copy_zero(zero);
				std::cout << "one: " << copy_one << " zero: " << copy_zero << std::endl;
			}

			//

			static void comparison()
			{
				title("equality");
				Bit one(1);
				Bit zero(0);

				if(one != one)
				{
					fail();
					return;
				}

				if(zero != zero)
				{
					fail();
					return;
				}

				if(one == zero)
				{
					fail();
					return;
				}

				if(zero == one)
				{
					fail();
					return;
				}

				pass();
			}

			static void intComparison()
			{
				title("int equality");
				Bit one(1);
				Bit zero(0);

				if(one != 1)
				{
					fail();
					return;
				}

				if(1 != one)
				{
					fail();
					return;
				}

				if(zero != 0)
				{
					fail();
					return;
				}

				if(0 != zero)
				{
					fail();
					return;
				}

				if(one == 0)
				{
					fail();
					return;
				}

				if(0 == one)
				{
					fail();
					return;
				}

				if(zero == 1)
				{
					fail();
					return;
				}

				if(1 == zero)
				{
					fail();
					return;
				}

				pass();
			}

			static void boolComparison()
			{
				title("bool equality");
				Bit one(1);
				Bit zero(0);

				if(one != true)
				{
					fail();
					return;
				}

				if(true != one)
				{
					fail();
					return;
				}

				if(zero != false)
				{
					fail();
					return;
				}

				if(false != zero)
				{
					fail();
					return;
				}

				if(one == false)
				{
					fail();
					return;
				}

				if(false == one)
				{
					fail();
					return;
				}

				if(zero == true)
				{
					fail();
					return;
				}

				if(true == zero)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void modifiableReference()
			{
				title("modifiable reference");
				Bit bit;
				bool &bit_ref = bit.value();
				bit_ref = 1;

				if(bit.value() != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void valueByValue()
			{
				title("value");
				const Bit bit;
				bool bitval = true;
				bitval = bit.value();

				if(bitval != 0)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void and()
			{
				title("boolean and");
				Bit one(1);
				Bit zero(0);

				if(one.AND(zero) != 0)
				{
					fail();
					return;
				}

				if(one.AND(one) != 1)
				{
					fail();
					return;
				}

				if(zero.AND(one) != 0)
				{
					fail();
					return;
				}

				if(zero.AND(zero) != 0)
				{
					fail();
					return;
				}

				pass();
			}

			static void or()
			{
				title("boolean or");
				Bit one(1);
				Bit zero(0);

				if(one.OR(zero) != 1)
				{
					fail();
					return;
				}

				if(one.OR(one) != 1)
				{
					fail();
					return;
				}

				if(zero.OR(one) != 1)
				{
					fail();
					return;
				}

				if(zero.OR(zero) != 0)
				{
					fail();
					return;
				}

				pass();
			}

			static void nand()
			{
				title("boolean nand");
				Bit one(1);
				Bit zero(0);

				if(one.NAND(zero) != 1)
				{
					fail();
					return;
				}

				if(one.NAND(one) != 0)
				{
					fail();
					return;
				}

				if(zero.NAND(one) != 1)
				{
					fail();
					return;
				}

				if(zero.NAND(zero) != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void nor()
			{
				title("boolean nand");
				Bit one(1);
				Bit zero(0);

				if(one.NOR(zero) != 0)
				{
					fail();
					return;
				}

				if(one.NOR(one) != 0)
				{
					fail();
					return;
				}

				if(zero.NOR(one) != 0)
				{
					fail();
					return;
				}

				if(zero.NOR(zero) != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void xor()
			{
				title("boolean xor");
				Bit one(1);
				Bit zero(0);

				if(one.XOR(zero) != 1)
				{
					fail();
					return;
				}

				if(one.XOR(one) != 0)
				{
					fail();
					return;
				}

				if(zero.XOR(one) != 1)
				{
					fail();
					return;
				}

				if(zero.XOR(zero) != 0)
				{
					fail();
					return;
				}

				pass();
			}

			static void xnor()
			{
				title("boolean xnor");
				Bit one(1);
				Bit zero(0);

				if(one.XNOR(zero) != 0)
				{
					fail();
					return;
				}

				if(one.XNOR(one) != 1)
				{
					fail();
					return;
				}

				if(zero.XNOR(one) != 0)
				{
					fail();
					return;
				}

				if(zero.XNOR(zero) != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void not()
			{
				title("boolean not");
				Bit one(1);
				Bit zero(0);

				if(NOT(one) != 0)
				{
					fail();
					return;
				}

				if(NOT(zero) != 1)
				{
					fail();
					return;
				}

				pass();
			}

			//

			static void assignment()
			{
				title("assignment operator");
				Bit target(0);
				Bit source(1);

				target = source;

				if(target != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void intAssignment()
			{
				title("assignment operator with int");
				Bit target(0);
				int source(1);

				target = source;

				if(target != 1)
				{
					fail();
					return;
				}

				pass();
			}

			static void boolAssignment()
			{
				title("assignment operator with bool");
				Bit target(0);
				bool source(true);

				target = source;

				if(target != 1)
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
				Bit one(1);
				Bit zero(0);
				std::stringstream ss;

				ss << one << zero << one;

				if(ss.str() != "101")
				{
					fail();
				}

				pass();
			}
		};
	} // Tests
} // ToyCpu

#endif