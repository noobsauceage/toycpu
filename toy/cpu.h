#ifndef INCL_CPU
#define INCL_CPU

#include "alu.h"
#include "constants.h"
#include "memory.h"
#include "program_counter.h"
#include "register.h"
#include "word.h"

#include <vector>

namespace ToyCpu
{
	class CPU
	{
	public:
		CPU(Memory &memory);

		void executeInstruction();
		// this version for testing only, normally executeInstruction reads instruction from memory
		void executeInstruction(const Word &instruction_p1, const Word &instruction_p2); // for testing
		void printRegisters() const;

	private:
		class Instruction
		{
		public:
			Instruction(const Word &opcode, Word &target, const Word &arg1, const Word &arg2);

			Word opcode() const;
			Word target() const;
			Word arg1() const;
			Word arg2() const;

		private:
			//bool _instruction_type;
			Word _opcode;
			Word _target;
			Word _arg1;
			Word _arg2;
		};

		const Register _zero_register;
		Register _registers[NUM_REGISTERS];
		ProgramCounter _pc;
		ALU _alu;

		Memory &_memory;

		void doFetchStage(Word &instruction_p1, Word &instruction_p2);
		Instruction doDecodeStage(const Word &instruction_p1, const Word &instruction_p2);
		void doExecuteStage(const Instruction &instruction);
		void doMemoryStage(const Instruction &instruction);
	};
} // ToyCpu

#endif