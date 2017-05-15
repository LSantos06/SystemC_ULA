#include "ula.h"
#include "ula_tb.h"

SC_MODULE ( sistema ) {
	// ULA
	ula ula_instance;
	// TestBench da ULA
	ula_tb ula_tb_instance;
	// Arquivo de rastreamento
	sc_trace_file* trace_file;

	// "Fios" para conectar a ULA com o seu respectivo TestBench
	sc_signal < sc_int  <SIZE> > A, B, Z;
	sc_signal < sc_uint <3> > opcode;
	sc_signal < bool > zero;

	// Funcoes para a criacao e fechamento do arquivo de rastreamento
	void create_vcd(){
		// Cria arquivo de rastreamento
		trace_file = sc_create_vcd_trace_file("trace_file");

		// Seta a unidade do tempo de simulacao
		trace_file->set_time_unit(0.5, SC_NS);

		// Define sinais a serem rastreados
		sc_trace(trace_file, A, "A");
		sc_trace(trace_file, B, "B");
		sc_trace(trace_file, opcode, "opcode");
		sc_trace(trace_file, Z, "Z");
		sc_trace(trace_file, zero, "zero");
	}
	void close_vcd(){
		// Fecha o arquivo de rastreamento
		sc_close_vcd_trace_file(trace_file);
		cout << "Arquivo de rastreamento trace_file.vcd criado!" << endl;
	}

	// Conexao da ULA com o TestBench da ULA
	SC_CTOR ( sistema ) : ula_instance("ula_instance"), ula_tb_instance("ula_tb_instance") {
		// Entradas da ULA sao as saidas do Driver
		ula_instance.opcode(opcode);		ula_tb_instance.driver_ula->opcode(opcode);
		ula_instance.A(A);					ula_tb_instance.driver_ula->A(A);
		ula_instance.B(B);					ula_tb_instance.driver_ula->B(B);
		// Saidas da ULA sao as entradas do Monitor
		ula_instance.Z(Z);					ula_tb_instance.monitor_ula->Z(Z);
		ula_instance.zero(zero); 			ula_tb_instance.monitor_ula->zero(zero);
	}
};
