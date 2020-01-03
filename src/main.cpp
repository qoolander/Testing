#include <iostream>
#include "Factorial.h"
#include <QtWidgets/QApplication>
#include "UI/MainWindow.h"

int main(int argc, char *argv[]) {
	std::cout << "Hello CMake!\n" << "The factorial of 5 is ";
	std::cout << Factorial(5) << "\n";

	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}