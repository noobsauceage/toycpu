#ifndef INCL_MEMORY
#define INCL_MEMORY

#include "word.h"

#include <vector>

namespace ToyCpu
{
	class Memory
	{
	public:
		// default constructs to all zeroes
		Memory();

		Word readAddress(const Word &address) const;
		void writeAddress(const Word &value, const Word &address);

		// loads words starting from address 0 through words.size()
		void load(const std::vector<Word> &words);

	private:
		Word _word_array[MAX_ADDRESS];
	};
} // ToyCpu

#endif