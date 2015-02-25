#include "stdafx.h"

#include "alu.h"
#include "bit.h"
#include "constants.h"
#include "word.h"

namespace ToyCpu
{
	void ALU::doAluOp(const Word &opcode, Word &result, const Word &arg1, const Word &arg2)
	{
		if(opcode.valueAsBinary() == ADD)
		{
			add(result, arg1, arg2);
		} else if(opcode.valueAsBinary() == SUBTRACT)
		{
			subtract(result, arg1, arg2);
		} else if(opcode.valueAsBinary() == COMPARE)
		{
			compare(result, arg1, arg2);
		}
	}

	void ALU::add(Word &result, const Word &arg1, const Word &arg2)
	{
		_overflow_bit = 0;

		Bit bit_sum;
		Bit carry(0);
		
		// iterate lsb to msb
		for(int i = 0; i != WORD_SIZE; ++i)
		{
			bit_sum = arg1[i].XOR(arg2[i]).XOR(carry);
			carry = (arg1[i].AND(arg2[i])).OR(carry.AND(arg1[i].XOR(arg2[i])));

			result[i] = bit_sum;
		}

		_overflow_bit = carry;
	}

	void ALU::subtract(Word &result, const Word &arg1, const Word &arg2)
	{
		_overflow_bit = 0;

		Bit bit_diff;
		Bit borrow(0);

		// iterate lsb to msb
		for(int i = 0; i != WORD_SIZE; ++i)
		{
			bit_diff = arg1[i].XOR(arg2[i]).XOR(borrow);
			borrow = (arg2[i].AND(borrow)).OR(NOT(arg1[i]).AND(arg2[i].XOR(borrow)));

			result[i] = bit_diff;
		}

		_overflow_bit = borrow;
	}

	void ALU::compare(Word &result, const Word &arg1, const Word &arg2)
	{
		// TODO rewrite with bit operations
		for(int i = 0; i != WORD_SIZE; ++i)
		{
			result[i] = 0;
		}

		// LSB is equals bit
		result[0] = (arg1.valueAsDecimal() == arg2.valueAsDecimal());

		// next lowest bit is GT
		result[1] = (arg1.valueAsDecimal() > arg2.valueAsDecimal());

		// 3rd lowest bit is LT
		result[2] = (arg1.valueAsDecimal() < arg2.valueAsDecimal());
	}

	Bit ALU::overflow() const
	{
		return _overflow_bit;
	}
} // ToyCpu