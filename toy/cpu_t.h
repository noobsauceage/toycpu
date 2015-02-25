#ifndef INCL_CPU_T
#define INCL_CPU_T

#include "tests.h"

#include "constants.h"
#include "cpu.h"
#include "memory.h"
#include "word.h"

#include <cstdlib>
//#include <ctime>
#include <sstream>
#include <vector>

namespace ToyCpu
{
	ToyCpu::Word randomWord()
	{
		//srand(time(0));
		int word = 0;
		for(int i = 0; i != ToyCpu::WORD_SIZE; ++i)
		{
			int bit = rand() % 2;
			word *= 10;
			word += bit;
		}

		return ToyCpu::Word(word, Word::BINARY);
	}

	std::vector<ToyCpu::Word> generateSequentialWords(size_t n)
	{
		std::vector<ToyCpu::Word> word_vec;
		for(int i = 0; i != n; ++i)
		{
			word_vec.push_back(Word(i));
		}

		return word_vec;
	}

	std::vector<ToyCpu::Word> generateRandomWords(size_t n)
	{
		std::vector<ToyCpu::Word> word_vec;
		for(int i = 0; i != n; ++i)
		{
			word_vec.push_back(randomWord());
		}

		return word_vec;
	}

	namespace Tests
	{
		class CpuTests
		{
		public:
			static void run()
			{
				doStuff();
			}

		private:
			Memory _memory;

			static void setup(Memory &memory)
			{
				static const std::vector<Word> sequential = generateSequentialWords(MAX_ADDRESS);
				static const std::vector<Word> random = generateRandomWords(MAX_ADDRESS);

				memory.load(sequential);
			}

			static void doStuff()
			{
				title("default");
				Memory memory;
				setup(memory);
				CPU cpu(memory);

				// load
				Word load1_p1(10101, Word::BINARY);
				Word load1_p2(101, Word::BINARY);

				Word load2_p1(10011, Word::BINARY);
				Word load2_p2(11, Word::BINARY);

				cpu.executeInstruction(load1_p1, load1_p2);
				cpu.executeInstruction(load2_p1, load2_p2);

				// execute add
				Word add_p1(10010000, Word::BINARY);
				Word add_p2(1010011, Word::BINARY);

				cpu.executeInstruction(add_p1, add_p2);

				// store
				Word store_1(100000, Word::BINARY);
				Word store_2(0, Word::BINARY);

				cpu.executeInstruction(store_1, store_2);

				if(memory.readAddress(Word(0)).valueAsBinary() != 1000)
				{
					std::stringstream ss;
					ss << "value in memory: " << memory.readAddress(Word(35));
					fail(ss.str());
					return;
				}

				pass();
			}
		};
	} // Tests
} // ToyCpu

#endif