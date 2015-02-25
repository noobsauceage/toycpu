#ifndef INCL_PROGRAM_COUNTER
#define INCL_PROGRAM_COUNTER

#include "register.h"

namespace ToyCpu
{
	class ProgramCounter : public Register
	{
	public:
		void increment();

		// inherits read() and write()

	protected:
		// inherits _data
	};
} // ToyCpu

#endif