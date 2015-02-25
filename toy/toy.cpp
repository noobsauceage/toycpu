// toy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "alu.h"
#include "bit.h"
#include "constants.h"
#include "cpu.h"
#include "memory.h"
#include "register.h"
#include "word.h"

#include "alu_t.h"
#include "bit_t.h"
#include "cpu_t.h"
#include "memory_t.h"
#include "program_counter_t.h"
#include "register_t.h"
#include "word_t.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace ToyCpu;

int _tmain(int argc, _TCHAR* argv[])
{
	Tests::BitTests::run();
	Tests::WordTests::run();
	Tests::MemoryTests::run();
	Tests::RegisterTests::run();
	Tests::ProgramCounterTests::run();
	Tests::AluTests::run();
	Tests::CpuTests::run();

	std::string in;
	std::cin >> in;
	std::cout << in << std::endl;

	return 0;
}

