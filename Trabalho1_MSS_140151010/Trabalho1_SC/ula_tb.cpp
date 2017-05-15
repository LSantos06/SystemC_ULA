#include "ula_tb.h"

void driver::drive(){
	// Tempo para inicializacao
	wait(1, SC_NS);

	// Se SIZE = 16
	#if SIZE == 16

	//// ADD
	cout << "//// Testes ADD:" << endl;
	opcode = ADD;
	// A = 4, B = 4, Z esperado = 8
	A = "0x0004"; B = "0x0004";
	wait(1, SC_NS);
	// A = 4, B = - 4, Z esperado = 0, zero esperado = 1
	A = "0x0004"; B = "0xfffc";
	wait(1, SC_NS);
	// A = -2, B = -2, Z esperado = -4
	A = "0xfffe"; B = "0xfffe";
	wait(1, SC_NS);

	//// SUB
	cout << "//// Testes SUB:" << endl;
	opcode = SUB;
	// A = 14, B = 10, Z esperado = 4
	A = "0x000e"; B = "0x000a";
	wait(1, SC_NS);
	// A = 4, B = 8, Z esperado = - 4
	A = "0x0004"; B = "0x0008";
	wait(1, SC_NS);
	// A = 14, B = -2, Z esperado = 16
	A = "0x000e"; B = "0xfffe";
	wait(1, SC_NS);

	//// AND
	cout << "//// Testes AND:" << endl;
	opcode = AND;
	// Z esperado = 0xf0f0
	A = "0xffff"; B = "0xf0f0";
	wait(1, SC_NS);
	// Z esperado = 0x0000, zero esperado = 1
	A = "0x0000"; B = "0xffff";
	wait(1, SC_NS);
	// Z esperado = 0xf000, zero esperado = 1
	A = "0xff0f"; B = "0xf0f0";
	wait(1, SC_NS);

	//// OR
	cout << "//// Testes OR:" << endl;
	opcode = OR;
	// Z esperado = 0xf0f0
	A = "0xf0f0"; B = "0x0000";
	wait(1, SC_NS);
	// Z esperado = 0xffff
	A = "0xffff"; B = "0x0000";
	wait(1, SC_NS);
	// Z esperado = 0x0f0f
	A = "0x0000"; B = "0x0f0f";
	wait(1, SC_NS);

	//// NOT
	cout << "//// Testes NOT:" << endl;
	opcode = NOT;
	// Z esperado 0xffff
	A = "0x0000";
	wait(1, SC_NS);
	// Z esperado 0x0000, zero esperado = 1
	A = "0xffff";
	wait(1, SC_NS);
	// Z esperado 0xf0f0
	A = "0x0f0f";
	wait(1, SC_NS);

	//// XOR
	cout << "//// Testes XOR:" << endl;
	opcode = XOR;
	// Z esperado 0x0f0f
	A = "0x0f0f"; B = "0x0000";
	wait(1, SC_NS);
	// Z esperado 0xffff
	A = "0xf0f0"; B = "0x0f0f";
	wait(1, SC_NS);
	// Z esperado 0x0000, zero esperado = 0
	A = "0xf0f0"; B = "0xf0f0";
	wait(1, SC_NS);

	//// BYPASS
	cout << "//// Testes BYPASS:" << endl;
	opcode = BYPASS;
	// Z esperado = 0x8449
	A = "0x8449";
	wait(1, SC_NS);
	// Z esperado = 0x0000, zero = 1
	A = "0x0000";
	wait(1, SC_NS);
	// Z esperado = 0x7193
	A = "0x7193";
	wait(1, SC_NS);

	//// SLT
	cout << "//// Testes SLT:" << endl;
	opcode = SLT;
	// A > B, Z esperado = 0, zero esperado = 1
	A = "0x0001"; B = "0x0000";
	wait(1, SC_NS);
	// A < B, Z esperado = 1
	A = "0xffff"; B = "0x0000";
	wait(1, SC_NS);
	// A = B, Z esperado = 0, zero esperado = 1
	A = "0x0001"; B = "0x0001";
	wait(1, SC_NS);

	// Se SIZE = 32
	#elif SIZE == 32

	//// ADD
	cout << "//// Testes ADD:" << endl;
	opcode = ADD;
	// A = 4, B = 4, Z esperado = 8
	A = "0x00000004"; B = "0x00000004";
	wait(1, SC_NS);
	// A = 4, B = - 4, Z esperado = 0, zero esperado = 1
	A = "0x00000004"; B = "0xfffffffc";
	wait(1, SC_NS);
	// A = -2, B = -2, Z esperado = -4
	A = "0xfffffffe"; B = "0xfffffffe";
	wait(1, SC_NS);

	//// SUB
	cout << "//// Testes SUB:" << endl;
	opcode = SUB;
	// A = 14, B = 10, Z esperado = 4
	A = "0x0000000e"; B = "0x0000000a";
	wait(1, SC_NS);
	// A = 4, B = 8, Z esperado = - 4
	A = "0x00000004"; B = "0x00000008";
	wait(1, SC_NS);
	// A = 14, B = -2, Z esperado = 16
	A = "0x0000000e"; B = "0xfffffffe";
	wait(1, SC_NS);

	//// AND
	cout << "//// Testes AND:" << endl;
	opcode = AND;
	// Z esperado = 0xf0f00000
	A = "0xffff0000"; B = "0xf0f0ffff";
	wait(1, SC_NS);
	// Z esperado = 0x00000000, zero esperado = 1
	A = "0xffff0000"; B = "0x0000ffff";
	wait(1, SC_NS);
	// Z esperado = 0xf0f00f0f
	A = "0xffff0f0f"; B = "0xf0f0ffff";
	wait(1, SC_NS);

	//// OR
	cout << "//// Testes OR:" << endl;
	opcode = OR;
	// Z esperado = 0xfffff0f0
	A = "0xf0f0f0f0"; B = "0x0f0f0000";
	wait(1, SC_NS);
	// Z esperado = 0xffffffff
	A = "0xffffffff"; B = "0x00000000";
	wait(1, SC_NS);
	// Z esperado = 0xffff0000
	A = "0xf0f00000"; B = "0x0f0f0000";
	wait(1, SC_NS);

	//// NOT
	cout << "//// Testes NOT:" << endl;
	opcode = NOT;
	// Z esperado 0x0000ffff
	A = "0xffff0000";
	wait(1, SC_NS);
	// Z esperado 0x00000000, zero esperado = 1
	A = "0xffffffff";
	wait(1, SC_NS);
	// Z esperado 0xffffffff
	A = "0x00000000";
	wait(1, SC_NS);

	//// XOR
	cout << "//// Testes XOR:" << endl;
	opcode = XOR;
	// Z esperado 0xf0f00f0f
	A = "0xf0f0f0f0"; B = "0x0000ffff";
	wait(1, SC_NS);
	// Z esperado 0xffffffff
	A = "0xf0f0f0f0"; B = "0x0f0f0f0f";
	wait(1, SC_NS);
	// Z esperado 0x00000000, zero esperado = 0
	A = "0xf0f0f0f0"; B = "0xf0f0f0f0";
	wait(1, SC_NS);

	//// BYPASS
	cout << "//// Testes BYPASS:" << endl;
	opcode = BYPASS;
	// Z esperado = 0x84496206
	A = "0x84496206";
	wait(1, SC_NS);
	// Z esperado = 0x00000000, zero = 1
	A = "0x00000000";
	wait(1, SC_NS);
	// Z esperado = 0x71936250
	A = "0x71936250";
	wait(1, SC_NS);

	//// SLT
	cout << "//// Testes SLT:" << endl;
	opcode = SLT;
	// A > B, Z esperado = 0, zero esperado = 1
	A = "0x00000001"; B = "0x00000000";
	wait(1, SC_NS);
	// A < B, Z esperado = 1
	A = "0x00000000"; B = "0x00000001";
	wait(1, SC_NS);
	// A = B, Z esperado = 0, zero esperado = 1
	A = "0x00000001"; B = "0x00000001";
	wait(1, SC_NS);

	#endif

}

void monitor::monitora(){
	cout << "Tempo " << sc_time_stamp() << ": ";
	cout << "Z = 0x" << Z.read().to_string(SC_HEX, false) << "; zero = " << zero << endl << endl;
}
