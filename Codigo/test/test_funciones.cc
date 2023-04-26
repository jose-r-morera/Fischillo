#include <gtest/gtest.h>

#include <cmath>
#include <sstream>
#include <string>

#include "../src/cliente_funciones.h"

std::stringstream stream_for_tests{};

TEST(TestFunciones, Identificacion) {
  BaseDatos base_datos;
  Identificacion(base_datos);
  
}