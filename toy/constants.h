#ifndef INCL_CONSTANTS
#define INCL_CONSTANTS

namespace ToyCpu
{
	// TODO make the cpu reconfigurable
	const int WORD_SIZE = 8;
	const int NUM_REGISTERS = 16;
	const int MAX_ADDRESS = 256; // 2^WORD_SIZE

	//const int LSB = 0;
	//const int MSB = WORD_SIZE - 1;

	enum Opcode
	{
		NOP = 0,
		LOAD = 1,
		STORE = 10,
		JUMP = 11,
		JUMP_IF_EQUAL = 100,
		AND = 101,
		OR = 110,
		INVERT = 111,
		COMPARE = 1000,
		ADD = 1001,
		SUBTRACT = 1010,
		SHIFT_LEFT = 1011,
		SHIFT_RIGHT = 1100
	};
} // ToyCpu

#endif