#include "sistema.h"

int sc_main (int argc, char* argv[]) {
	// Sistema que eh o modulo de mais alto nivel que instancia a ULA e o TestBench, interconectando-os
	sistema sistema_instance("sistema_instance");

	// Criacao do arquivo de rastreamento
	sistema_instance.create_vcd();

	// Inicio da simulacao
	sc_start();

	// Fecha arquivo de rastreamento
	sistema_instance.close_vcd();

	return 0;
}
