#include "ula.h"

void ula::exec(){
	// Auxiliar que armazena o resultado da operacao da ULA
	sc_int <SIZE> aux;

	switch(opcode.read()){
		case ADD:
			// Z recebe (A + B), incluindo o vem-um
			aux = (A.read() + B.read());
			break;

		case SUB:
			// Z recebe (A - B)
			aux = (A.read() - B.read());
			break;

		case AND:
			// Z recebe (A and B), bit a bit
			aux = (A.read() & B.read());
			break;

		case OR:
			// Z recebe (A or B), bit a bit
			aux = (A.read() | B.read());
			break;

		case NOT:
			// Z recebe (not A), bit a bit
			aux = ~(A.read());
			break;

		case XOR:
			// Z recebe (A xor B), bit a bit
			aux = A.read() ^ B.read();
			break;

		case BYPASS:
			// Z recebe A
			aux = A.read();
			break;

		case SLT:
			// Se (A < B), Z = 1; Senao Z = 0
			(A.read() < B.read()) ? aux = 1 : aux = 0;
			break;

		default:
			break;
	}

	// Z recebe o resultado da operacao
	Z.write(aux);
	// zero eh true, se o resultado da operacao (Z) for 0
	zero = (aux == 0);
}
