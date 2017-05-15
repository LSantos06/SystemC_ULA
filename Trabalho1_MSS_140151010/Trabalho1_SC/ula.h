#ifndef __ULA_H
#define __ULA_H

#include <systemc.h>

enum OPCODE {
	ADD, SUB, AND, OR, NOT, XOR, BYPASS, SLT
};

// SIZE possui testes para tamanho 32 e 16 bits
#define SIZE 32

SC_MODULE( ula ) {
	// Entradas
	sc_in  < sc_uint <3> > opcode;
	sc_in  < sc_int  <SIZE> > A, B;

	// Saidas
	sc_out < sc_int  <SIZE> > Z;
	sc_out < bool > zero;

	// Descricao do funcionamento da ULA
	void exec();

	SC_CTOR( ula ) {
		SC_METHOD(exec);
		sensitive << A << B << opcode;
	}
};
#endif
