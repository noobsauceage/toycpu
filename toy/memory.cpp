#include "stdafx.h"

#include "memory.h"
#include "word.h"

namespace ToyCpu
{
	Memory::Memory()
	{
		for(int i = 0; i != MAX_ADDRESS; ++i)
		{
			_word_array[i] = Word(0);
		}
	}

	Word Memory::readAddress(const Word &address) const
	{
		return _word_array[address.valueAsDecimal()];
	}

	void Memory::writeAddress(const Word &value, const Word &address)
	{
		_word_array[address.valueAsDecimal()] = value;
	}

	void Memory::load(const std::vector<Word> &words)
	{
		for(size_t i = 0; i != words.size(); ++i)
		{
			writeAddress(words[i], Word(i));
		}
	}
} // ToyCpu