#ifndef __ULA_TB
#define __ULA_TB

#include <systemc.h>
#include "ula.h"

SC_MODULE ( driver ) {
	// Saidas do driver sao as entradas da ULA
	sc_out< sc_uint <3> > opcode;
	sc_out< sc_int  <SIZE> > A, B;

	// Descricao do funcionamento do Driver
	void drive();

	SC_CTOR ( driver ) {
		SC_THREAD (drive);
	}
};

SC_MODULE ( monitor ) {
	// Entradas do monitor sao as saidas da ULA
	sc_in < sc_int  <SIZE> > Z;
	sc_in < bool > zero;

	// Descricao do funcionamento do Monitor
	void monitora();

	SC_CTOR ( monitor ) {
		SC_METHOD (monitora);
		sensitive << Z << zero;
	}

};

SC_MODULE ( ula_tb ) {
	// Instanciacao do driver e do monitor
	driver *driver_ula;
	monitor *monitor_ula;

	SC_CTOR ( ula_tb ) {
		driver_ula = new driver("driver_ula");
		monitor_ula = new monitor("monitor_ula");
	}
};
#endif
