#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

#include "../src/base_datos.h"
#include "../src/usuario.h"

// Comprueba que los usuarios creados por defecto no contengan información residual

TEST(TestUsuario, CreacionUsuariosPorDefecto) {
  Usuario nuevo_usuario;
  EXPECT_EQ(nuevo_usuario.GetNombreUsuario(), "");
  EXPECT_FALSE(nuevo_usuario.EsAdministrador());
  EXPECT_EQ(nuevo_usuario.GetCerradurasPermitidas().size(), 0);
}

// Comprueba la correcta generación de contraseñas

TEST(TestUsuario, GeneracionContrasenyas) {
  Usuario nuevo_usuario("Lola Mento", "123456");
  EXPECT_TRUE (nuevo_usuario.ConfirmarContrasenya("123456"));
  EXPECT_FALSE(nuevo_usuario.ConfirmarContrasenya("654321"));
  nuevo_usuario.SetContrasenya("456789");
  EXPECT_TRUE (nuevo_usuario.ConfirmarContrasenya("456789"));
  EXPECT_FALSE(nuevo_usuario.ConfirmarContrasenya("123456"));
}

// Comprueba la adición de permisos de acceso de una cerradura a un usuario

TEST(TestUsuario, PermisosDeAcceso) {
  Usuario nuevo_usuario("Helen Chufe", "123456");
  BaseDatos base_de_datos;
  CerraduraInteligente nueva_cerradura(base_de_datos.NuevoId(), "cerradurita");
  nuevo_usuario.PermitirAccesoCerradura(nueva_cerradura.Id());
  EXPECT_EQ(nuevo_usuario.GetCerradurasPermitidas().size(), 1);
  EXPECT_EQ(nuevo_usuario.GetCerradurasPermitidasAt(0), nueva_cerradura.Id());
}