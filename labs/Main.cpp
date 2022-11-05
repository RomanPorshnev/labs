#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include "Start.h"
#include "InputOutput.h"
int main() {
	Start st = Start();
	InputOutput InOut;
	InOut.info();
	st.run();
	return 0;
}