/// @see https://www.geeksforgeeks.org/gtest-framework/

#include <gtest/gtest.h>

#include <cmath>
#include <sstream>
#include <string>

#include "../src/base_datos.h"

std::stringstream stream_for_tests{};

/*********\
|* TESTS *|
\*********/

TEST(TestBaseDatos, InsercionesDeUsuarioYCerradura) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  EXPECT_EQ(base_de_datos.GetUsuarios().size(), 1);
  EXPECT_EQ(base_de_datos.GetCerraduras().size(), 1);
  EXPECT_EQ(base_de_datos.GetUsuarios()[0].GetId(), 1001);
  EXPECT_EQ(base_de_datos.GetUsuarios()[0].GetNombreUsuario(), "platinita");
  EXPECT_EQ(base_de_datos.GetUsuarios()[0].ConfirmarContrasenya("1234567"), true);
  EXPECT_EQ(base_de_datos.GetCerraduras()[0].Id(), 1002);
  EXPECT_EQ(base_de_datos.GetCerraduras()[0].Nombre(), "cerradurita");
}

TEST(TestBaseDatos, InsercionesDeAccesos) {
  // TO BE CONTINUED
}

TEST(TestBaseDatos, Eliminaciones) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  EXPECT_EQ(base_de_datos.GetUsuarios().size(), 1);
  EXPECT_EQ(base_de_datos.GetCerraduras().size(), 1);
  base_de_datos.EliminarUsuario(1001);
  base_de_datos.EliminarCerradura(1002);
  EXPECT_EQ(base_de_datos.GetUsuarios().size(), 0);
  EXPECT_EQ(base_de_datos.GetCerraduras().size(), 0);
}

TEST(TestBaseDatos, NuevosIds) {
  BaseDatos base_de_datos;
  EXPECT_EQ(base_de_datos.NuevoId(), 1001);
  EXPECT_EQ(base_de_datos.NuevoId(), 1002);
  EXPECT_EQ(base_de_datos.NuevoId(), 1003);
  EXPECT_EQ(base_de_datos.NuevoId(), 1004);
  EXPECT_EQ(base_de_datos.NuevoId(), 1005);
}

TEST(TestBaseDatos, NumeroDeUsuariosYCerraduras) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "a", "1234567");
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "b", "1234567");
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "c", "1234567");
  EXPECT_EQ(base_de_datos.NumeroDeUsuarios(), 3);
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "d", "1234567");
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "e", "1234567");
  EXPECT_EQ(base_de_datos.NumeroDeCerraduras(), 5);
}

TEST(TestBaseDatos, ObtenerRegistros) {
  // TO BE CONTINUED
}

TEST(TestBaseDatos, Getters) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  // TO BE CONTINUED
}

TEST(TestBaseDatos, Buscar) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario(base_de_datos.NuevoId(), "platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  EXPECT_EQ(base_de_datos.ExisteUsuario("platinita"), true);
  EXPECT_EQ(base_de_datos.ExisteUsuario("roberto"), false);
  EXPECT_EQ(base_de_datos.BuscarUsuario("platinita").GetNombreUsuario(), "platinita");
  EXPECT_EQ(base_de_datos.BuscarUsuario("platinita").GetId(), 1001);
}