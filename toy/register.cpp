#include "stdafx.h"

#include "register.h"
#include "word.h"

namespace ToyCpu
{
	Register::Register()
		: _data()
	{}

	Register::~Register()
	{}
	
	Word Register::read() const
	{
		return _data;
	}

	void Register::write(const Word &w)
	{
		_data = w;
	}
} // ToyCpu