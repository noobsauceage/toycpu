#ifndef INCL_ALU
#define INCL_ALU

#include "bit.h"
#include "word.h"

namespace ToyCpu
{
	/*
	arithmetic logic unit
	does boolean and decimal math on words
	*/
	class ALU
	{
	public:
		/*
		general purpose interface
		result = arg1 OP arg2
		opcode is same as cpu instruction opcodes for now
		*/
		void doAluOp(const Word &opcode, Word &result, const Word &arg1, const Word &arg2);

		// math
		void add(Word &result, const Word &arg1, const Word &arg2);
		void subtract(Word &result, const Word &arg1, const Word &arg2);

		// result is a bit mask
		// lsb = equality bit
		// second to lsb > greater than bit
		// third to lsb < less than bit
		void compare(Word &result, const Word &arg1, const Word &arg2);

		// shift
		//void shiftLeft(Word &result, const Word &arg1, const Word &arg2);
		//void shiftRight(Word &result, const Word &arg1, const Word &arg2);

		// value of overflow bit
		Bit overflow() const;

	private:
		Bit _overflow_bit;
	};
} // ToyCpu

#endif