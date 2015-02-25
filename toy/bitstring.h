#ifndef INCL_BITSTRING
#define INCL_BITSTRING

#include "bit.h"

#include <iostream>

namespace ToyCpu
{
	/*
	string of n bits
	can be constructed from decimal int 1234 (default) or binary int 10011 (with mode = Word::BINARY)
	IMPORTANT be careful not to have leading zeroes when constructing binary
	index operator starts at LSB for bit 0 and goes to MSB for bit N-1
	*/
	template<size_t N>
	class BitString
	{
	public:
		enum ConstructMode
		{
			DECIMAL,
			BINARY
		};

		BitString();
		// set flag to have this function interpret input as binary string
		BitString(int value, ConstructMode mode = DECIMAL);
		// TODO implement more constructors

		virtual ~BitString();

		int valueAsDecimal() const;
		int valueAsBinary() const;

		// IMPORTANT: index 0 is the LSB
		Bit &operator[](int i);
		const Bit &operator[](int i) const;

		BitString<N> &operator=(const BitString<N> &rhs);

	private:
		Bit _bit_array[N];
	};

	template<size_t N>
	std::ostream &operator<<(std::ostream &lhs, const BitString<N> &rhs);

	// template class definitions /////////////////////////////////////////////
	// constructors and destructors ///////////////////////////////////////////

	template<size_t N>
	BitString<N>::BitString()
	{
		for(int i = 0; i != N; ++i)
		{
			_bit_array[i] = 0;
		}
	}

	template<size_t N>
	BitString<N>::BitString(int value, typename BitString<N>::ConstructMode mode)
	{
		int bit_value;

		if(mode == BitString::BINARY)
		{
			// TODO validate binary input

			// iterate lsb to msb
			for(int i = N - 1; i >= 0; --i)
			{
				bit_value = value % 10;
				value /= 10;

				_bit_array[i] = bit_value;
			}
		} else
		{
			// iterate lsb to msb
			for(int i = N - 1; i >= 0; --i)
			{
				bit_value = value % 2;
				value /= 2;

				_bit_array[i] = bit_value;
			}
		}

		// TODO error checking of some sort
	}

	template<size_t N>
	BitString<N>::~BitString()
	{}

	// getters ////////////////////////////////////////////////////////////////

	template<size_t N>
	int BitString<N>::valueAsDecimal() const
	{
		int result = 0;
		int decimal_bit_value = 1;

		// iterate lsb to msb
		for(int i = N - 1; i >= 0; --i)
		{
			if(_bit_array[i] == 1)
			{
				result += decimal_bit_value;
			}

			decimal_bit_value *= 2;
		}

		return result;
	}

	template<size_t N>
	int BitString<N>::valueAsBinary() const
	{
		int result = 0;
		int bit_value = 1;

		// iterate lsb to msb
		for(int i = N - 1; i >= 0; --i)
		{
			if(_bit_array[i] == 1)
			{
				result += bit_value;
			}

			bit_value *= 10;
		}

		return result;
	}

	// member operators ///////////////////////////////////////////////////////

	template<size_t N>
	Bit &BitString<N>::operator[](int i)
	{
		if((i < N) && (i >= 0))
			return _bit_array[N - 1 - i];

		// TODO error
		return _bit_array[0];
	}

	template<size_t N>
	const Bit &BitString<N>::operator[](int i) const
	{
		if((i < N) && (i >= 0))
			return _bit_array[N - 1 - i];

		// TODO error
		return _bit_array[0];
	}

	template<size_t N>
	BitString<N> &BitString<N>::operator=(const BitString<N> &rhs)
	{
		for(int i = 0; i != N; ++i)
		{
			this->_bit_array[i] = rhs._bit_array[i];
		}

		return *this;
	}

	// non-member operators ///////////////////////////////////////////////////

	template<size_t N>
	std::ostream &operator<<(std::ostream &lhs, const BitString<N> &rhs)
	{
		// print each bit
		// msb to lsb -- this isn't a member and is using the external [] interface
		for(int i = N - 1; i >= 0; --i)
		{
			lhs << rhs[i];
		}

		return lhs;
	}
} // ToyCpu

#endif