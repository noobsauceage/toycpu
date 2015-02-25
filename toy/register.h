#ifndef INCL_REGISTER
#define INCL_REGISTER

#include "word.h"

namespace ToyCpu
{
	class Register
	{
	public:
		Register();

		virtual ~Register();

		Word read() const;
		void write(const Word &w);

	protected:
		Word _data;
	};
} // ToyCpu

#endif