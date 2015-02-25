#include "stdafx.h"

#include "constants.h"
#include "cpu.h"
#include "memory.h"
#include "register.h"
#include "word.h"

#include <iomanip>
#include <iostream>

namespace ToyCpu
{
	// CPU ///////////////////////////////////////////////////////////////////////
	// constructors //////////////////////////////////////////////////////////////

	CPU::CPU(Memory &memory)
		: _memory(memory)
	{}

	//////////////////////////////////////////////////////////////////////////////

	void CPU::executeInstruction(const Word &instruction_p1, const Word &instruction_p2)
	{
		Instruction myinst = doDecodeStage(instruction_p1, instruction_p2);

		doExecuteStage(myinst);
		doMemoryStage(myinst);
	}

	void CPU::printRegisters() const
	{
		for(int i = 0; i != NUM_REGISTERS; ++i)
		{
			std::cout << "register " << std::setw(2) << i << ": " << _registers[i].read() << std::endl;
		}
	}

	// cpu stages ////////////////////////////////////////////////////////////////

	void CPU::doFetchStage(Word &instruction_p1, Word &instruction_p2)
	{
		instruction_p1 = _memory.readAddress(_pc.read());
		_pc.increment();
		instruction_p2 = _memory.readAddress(_pc.read());
		_pc.increment();
	}

	CPU::Instruction CPU::doDecodeStage(const Word &instruction_p1, const Word &instruction_p2)
	{
		Word opcode, target, arg1, arg2;

		for(int i = WORD_SIZE - 1; i >= 4; --i)
		{
			opcode[i - 4] = instruction_p1[i];
			arg1[i - 4] = instruction_p2[i];
		}

		for(int i = 3; i >= 0; --i)
		{
			target[i] = instruction_p1[i];
			arg2[i] = instruction_p2[i];
		}

		Register &target_register = _registers[target.valueAsDecimal()];
		Register &arg1_register = _registers[arg1.valueAsDecimal()];
		Register &arg2_register = _registers[arg2.valueAsDecimal()];

		return Instruction(opcode, target, arg1, arg2);
	}

	void CPU::doExecuteStage(const Instruction &instruction)
	{
		// process opcode
		if((instruction.opcode().valueAsBinary() == AND) ||
		   (instruction.opcode().valueAsBinary() == OR) ||
		   (instruction.opcode().valueAsBinary() == INVERT) ||
		   (instruction.opcode().valueAsBinary() == COMPARE) ||
		   (instruction.opcode().valueAsBinary() == ADD) ||
		   (instruction.opcode().valueAsBinary() == SUBTRACT) ||
		   (instruction.opcode().valueAsBinary() == SHIFT_LEFT) ||
		   (instruction.opcode().valueAsBinary() == SHIFT_RIGHT) ||
		   (instruction.opcode().valueAsBinary() == JUMP_IF_EQUAL))
		{
			Register &arg1_register(_registers[instruction.arg1().valueAsDecimal()]);
			Register &arg2_register(_registers[instruction.arg2().valueAsDecimal()]);
			Register &target_register(_registers[instruction.target().valueAsDecimal()]);

			Word arg1_val(arg1_register.read());
			Word arg2_val(arg2_register.read());
			Word result;

			_alu.doAluOp(instruction.opcode(), result, arg1_val, arg2_val);

			target_register.write(result);
		}
	}

	void CPU::doMemoryStage(const Instruction &instruction)
	{
		if(instruction.opcode().valueAsBinary() == LOAD)
		{
			Word address_lowbits = instruction.arg2();
			Word address_highbits = instruction.arg1();

			// TODO rewrite
			Word address((address_highbits.valueAsDecimal() * 10000) + address_lowbits.valueAsDecimal());

			Register &target_register(_registers[instruction.target().valueAsDecimal()]);
			target_register.write(_memory.readAddress(address));
		} else if(instruction.opcode().valueAsBinary() == STORE)
		{
			Word address_lowbits = instruction.arg2();
			Word address_highbits = instruction.arg1();

			// TODO rewrite
			Word address((address_highbits.valueAsDecimal() * 10000) + address_lowbits.valueAsDecimal());

			Register &target_register(_registers[instruction.target().valueAsDecimal()]);
			_memory.writeAddress(target_register.read(), address);
		}
	}

	// Instruction ////////////////////////////////////////////////////////////

	CPU::Instruction::Instruction(const Word &opcode, Word &target, const Word &arg1, const Word &arg2)
		: _opcode(opcode), _target(target), _arg1(arg1), _arg2(arg2)
	{}

	Word CPU::Instruction::opcode() const
	{
		return _opcode;
	}

	Word CPU::Instruction::target() const
	{
		return _target;
	}

	Word CPU::Instruction::arg1() const
	{
		return _arg1;
	}

	Word CPU::Instruction::arg2() const
	{
		return _arg2;
	}
} // ToyCpu