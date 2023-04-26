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
  Usuario nuevo_usuario("platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  EXPECT_EQ(base_de_datos.GetUsuarios().size(), 1);
  EXPECT_EQ(base_de_datos.GetCerraduras().size(), 1);
  EXPECT_EQ(base_de_datos.GetUsuarios()[0].GetNombreUsuario(), "platinita");
  EXPECT_EQ(base_de_datos.GetUsuarios()[0].ConfirmarContrasenya("1234567"), true);
  EXPECT_EQ(base_de_datos.GetCerraduras()[0].Id(), 1002);
  EXPECT_EQ(base_de_datos.GetCerraduras()[0].Nombre(), "cerradurita");
}

TEST(TestBaseDatos, InsercionesDeAccesos) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario("platinita", "1234567");
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  acceso acceso1(nuevo_usuario, nueva_cerradura, "abrir");
  base_de_datos.Insertar(acceso1);
  EXPECT_EQ(base_de_datos.GetAccesos().size(), 1);
  EXPECT_EQ(base_de_datos.GetAccesos()[0].usuario_, "platinita");
  EXPECT_EQ(base_de_datos.GetAccesos()[0].cerradura_, 1001);
  EXPECT_EQ(base_de_datos.GetAccesos()[0].accion_, "abrir");
}

TEST(TestBaseDatos, Eliminaciones) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario("platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  EXPECT_EQ(base_de_datos.GetUsuarios().size(), 1);
  EXPECT_EQ(base_de_datos.GetCerraduras().size(), 1);
  base_de_datos.EliminarUsuario("platinita");
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
  Usuario nuevo_usuario("a", "1234567");
  Usuario nuevo_usuario("b", "1234567");
  Usuario nuevo_usuario("c", "1234567");
  EXPECT_EQ(base_de_datos.NumeroDeUsuarios(), 3);
  Usuario nuevo_usuario("d", "1234567");
  Usuario nuevo_usuario("e", "1234567");
  EXPECT_EQ(base_de_datos.NumeroDeCerraduras(), 5);
}

TEST(TestBaseDatos, ObtenerRegistros) {
  BaseDatos base_de_datos;
  Usuario usuario1("platinita", "1234567");
  Usuario usuario2("Valerio", "1234567");
  CerraduraInteligente cerradura1(base_de_datos.NuevoId(), "cerradurita");
  CerraduraInteligente cerradura2(base_de_datos.NuevoId(), "fischillo");
  acceso acceso1(usuario1, cerradura1, "abrir");
  acceso acceso2(usuario2, cerradura2, "cerrar");
  base_de_datos.Insertar(acceso1);
  base_de_datos.Insertar(acceso2);
  std::vector<acceso> busqueda1 = base_de_datos.ObtenerRegistro("platinita");
  std::vector<acceso> busqueda2 = base_de_datos.ObtenerRegistro(1002);
  EXPECT_EQ(busqueda1.size(), 1);
  EXPECT_EQ(busqueda1[0].usuario_, "platinita");
  EXPECT_EQ(busqueda1[0].cerradura_, "cerradurita");
  EXPECT_EQ(busqueda1[0].accion_, "abrir");
  EXPECT_EQ(busqueda2.size(), 1);
  EXPECT_EQ(busqueda2[0].usuario_, "Valerio");
  EXPECT_EQ(busqueda2[0].cerradura_, "fischillo");
  EXPECT_EQ(busqueda2[0].accion_, "cerrar");
}

TEST(TestBaseDatos, Getters) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario("platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  // TO BE CONTINUED
}

TEST(TestBaseDatos, Buscar) {
  BaseDatos base_de_datos;
  Usuario nuevo_usuario("platinita", "1234567");
  base_de_datos.Insertar(nuevo_usuario);
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  base_de_datos.Insertar(nueva_cerradura);
  EXPECT_EQ(base_de_datos.ExisteUsuario("platinita"), true);
  EXPECT_EQ(base_de_datos.ExisteUsuario("roberto"), false);
  EXPECT_EQ(base_de_datos.BuscarUsuario("platinita").GetNombreUsuario(), "platinita");
}