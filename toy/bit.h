#ifndef INCL_BIT
#define INCL_BIT

#include <iostream>

namespace ToyCpu
{
	class Bit
	{
	public:
		// construction and implicit conversions
		Bit();
		Bit(bool val);
		Bit(int val);
		Bit(const Bit &rhs);

		bool &value();
		bool value() const;

		// boolean ops
		Bit AND(const Bit &rhs) const;
		Bit OR(const Bit &rhs) const;
		Bit NAND(const Bit &rhs) const;
		Bit NOR(const Bit &rhs) const;
		Bit XOR(const Bit &rhs) const;
		Bit XNOR(const Bit &rhs) const;

		Bit &operator=(const Bit &rhs);

	private:
		bool _bit;
	};

	// better syntax with this out here
	Bit NOT(const Bit &rhs);

	bool operator==(const Bit &lhs, const Bit &rhs);
	bool operator!=(const Bit &lhs, const Bit &rhs);

	std::ostream &operator<<(std::ostream &lhs, const Bit &rhs);
} // ToyCpu

#endif