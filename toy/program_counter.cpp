#include "stdafx.h"

#include "program_counter.h"
#include "bit.h"
#include "word.h"

namespace ToyCpu
{
	void ProgramCounter::increment()
	{
		// each instruction is 2 words long, but increment() called twice during fetch stage
		Word incr_size(1);

		Bit bit_sum;
		Bit carry(0);

		// iterate lsb to msb
		for(int i = 0; i != WORD_SIZE; ++i)
		{
			bit_sum = _data[i].XOR(incr_size[i]).XOR(carry);
			carry = (_data[i].AND(incr_size[i])).OR(carry.AND(_data[i].XOR(incr_size[i])));

			_data[i] = bit_sum;
		}
	}
} // ToyCpu