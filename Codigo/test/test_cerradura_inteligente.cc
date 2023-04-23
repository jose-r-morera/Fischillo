/// @see https://www.geeksforgeeks.org/gtest-framework/

#include <gtest/gtest.h>
#include <cmath>
#include <sstream>
#include <string>

#include "../src/cerradura_inteligente.h"

std::stringstream stream_for_tests{};

/****************\
|* TESTS PARA X *|
\****************/

TEST(TestCerraduraInteligente, CreacionCerradura) {
  CerraduraInteligente cerradura_test{10};
  EXPECT_EQ(cerradura_test.Id(), 10);

  CerraduraInteligente cerradura_test2{34783};
  EXPECT_EQ(cerradura_test2.Id(), 34783);

  
}

TEST(TestCerraduraInteligente, InteractuarCerradura) {
  CerraduraInteligente cerradura_test{10};
  EXPECT_EQ(cerradura_test.Abierto(), false);
  cerradura_test.Interaccion(); /// Abrir
  EXPECT_EQ(cerradura_test.Abierto(), true);
  cerradura_test.Interaccion(); /// Cerrar
  EXPECT_EQ(cerradura_test.Abierto(), false);
}
