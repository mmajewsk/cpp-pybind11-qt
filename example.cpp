
#include <pybind11/embed.h>
#include <QDate>
#include <QtCore/QtGlobal>

#if defined(MYSHAREDLIB_LIBRARY)
#  define MYSHAREDLIB_EXPORT Q_DECL_EXPORT
#else
#  define MYSHAREDLIB_EXPORT Q_DECL_IMPORT
#endif


#include <iostream>

using namespace std;
int multiply(int i, int j) {
    std::cout << "Da Date2:" << QDate::currentDate().toString().toStdString();
    return i * j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("multiply", &multiply, "A function which multiplies two numbers");
}
