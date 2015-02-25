#include "stdafx.h"

#include "bit.h"

namespace ToyCpu
{
	// constructors ///////////////////////////////////////////////////////////

	Bit::Bit()
		: _bit(false)
	{}

	Bit::Bit(bool val)
		: _bit(val)
	{}

	Bit::Bit(int val)
		: _bit((val == 1)) // keep the compiler happy
	{}

	Bit::Bit(const Bit &rhs)
		: _bit(rhs.value())
	{}

	// getters and setters ////////////////////////////////////////////////////

	bool &Bit::value()
	{
		return _bit;
	}

	bool Bit::value() const
	{
		return _bit;
	}

	// boolean operators //////////////////////////////////////////////////////

	Bit Bit::AND(const Bit &rhs) const
	{
		return Bit(this->_bit && rhs._bit);
	}

	Bit Bit::OR(const Bit &rhs) const
	{
		return Bit(this->_bit || rhs._bit);
	}

	Bit Bit::NAND(const Bit &rhs) const
	{
		return NOT(this->AND(rhs));
	}

	Bit Bit::NOR(const Bit &rhs) const
	{
		return NOT(this->OR(rhs));
	}

	Bit Bit::XOR(const Bit &rhs) const
	{
		return ( this->AND(NOT(rhs)) ).OR( NOT(*this).AND(rhs) );
	}

	Bit Bit::XNOR(const Bit &rhs) const
	{
		return ( this->AND(rhs) ).OR( NOT(*this).AND(NOT(rhs)) );
	}

	// member operators ///////////////////////////////////////////////////////

	Bit &Bit::operator=(const Bit &rhs)
	{
		this->_bit = rhs._bit;

		return *this;
	}

	// non-member operators ///////////////////////////////////////////////////

	Bit NOT(const Bit &b)
	{
		return Bit(!b.value());
	}

	bool operator==(const Bit&lhs, const Bit &rhs)
	{
		return lhs.value() == rhs.value();
	}

	bool operator!=(const Bit &lhs, const Bit &rhs)
	{
		return !(lhs == rhs);
	}

	std::ostream &operator<<(std::ostream &lhs, const Bit &rhs)
	{
		lhs << rhs.value();
		
		return lhs;
	}
} // ToyCpu