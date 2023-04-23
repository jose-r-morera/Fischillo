#include <gtest/gtest.h>

#include <cmath>
#include <sstream>
#include <string>

#include "../src/BigInt.h"

std::stringstream stream_for_tests{};

/*****************\
|* Constructores *|
\*****************/

/**
 * Tests Constructor Long
 */
TEST(BigIntTest, LongConstructorPorDefecto) {
  BigInt<10> A{};
  stream_for_tests << A;
  EXPECT_EQ("0", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, LongConstructorPositivo) {
  BigInt<10> A{1523};
  stream_for_tests << A;
  EXPECT_EQ("1523", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, LongConstructorNegativo) {
  /// BASE 16 y SIGNO NEGATIVO
  long input{-1884845987};
  BigInt<16> B{input};
  stream_for_tests << B;
  EXPECT_EQ(std::to_string(input), stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, LongConstructorInvalido) {
  testing::internal::CaptureStderr();
  BigInt<2> C{123};
  /// Comprobamos que se muestra el mensaje
  std::string log = testing::internal::GetCapturedStderr();
  EXPECT_NE(log, "");

  stream_for_tests << C;
  EXPECT_NE(std::to_string(123), stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, LongConstructorBinario) {
  int number{110110001};
  testing::internal::CaptureStderr();
  BigInt<2> D{number};
  std::string log = testing::internal::GetCapturedStderr();
  EXPECT_EQ(log, "");

  stream_for_tests << D;
  EXPECT_EQ("110110001", stream_for_tests.str());
  stream_for_tests.str("");
}

/**
 * Test that checks the std::string and C string constructor
 */
TEST(BigIntTest, StringConstructorPositivo) {
  BigInt<10> A{"1523"};
  stream_for_tests << A;
  EXPECT_EQ("1523", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, StringConstructorNegativo) {
  /// BASE 16 y SIGNO NEGATIVO
  std::string input{"-188A4845B987"};
  BigInt<16> B{input};
  stream_for_tests << B;
  EXPECT_EQ(input, stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, StringConstructorInvalido) {
  BigInt<2> C{"123"};
  stream_for_tests << C;
  EXPECT_NE("123", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, StringConstructorBinario) {
  BigInt<2> D{"110110001"};
  stream_for_tests << D;
  EXPECT_EQ("110110001", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, StringConstructorCero) {
  BigInt<2> E{"0"};
  stream_for_tests << E;
  EXPECT_EQ("0", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, StringConstructorCerosPrefijo) {
  BigInt<2> E{"0000110110001"};
  stream_for_tests << E;
  EXPECT_EQ("110110001", stream_for_tests.str());
  stream_for_tests.str("");

  BigInt<2> F{"01"};
  stream_for_tests << F;
  EXPECT_EQ("1", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, StringConstructorVacio) {
  BigInt<2> G{""};
  stream_for_tests << G;
  EXPECT_EQ("0", stream_for_tests.str());
  stream_for_tests.str("");
}

/**
 * Test that checks the copyconstructor
 */
TEST(BigIntTest, CopyConstructorPositivo) {
  BigInt<16> A{"A15B2D3"};
  stream_for_tests << A;
  std::string A_str{stream_for_tests.str()};
  stream_for_tests.str("");

  BigInt<16> B{A};
  stream_for_tests << B;
  EXPECT_EQ(A_str, stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, CopyConstructorNegativo) {
  std::string input{"-188A4845B987"};
  BigInt<16> A{input};
  std::string A_str{stream_for_tests.str()};
  stream_for_tests.str("");

  BigInt<16> B{A};
  stream_for_tests << B;
  EXPECT_EQ(input, stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, CopyConstructorBinario) {
  BigInt<2> A{110110001};
  stream_for_tests << A;
  std::string A_str{stream_for_tests.str()};
  stream_for_tests.str("");

  BigInt<2> B{A};
  stream_for_tests << B;
  EXPECT_EQ(A_str, stream_for_tests.str());
  stream_for_tests.str("");
}

/****************************\
|* Sobrecarga de Operadores *|
\****************************/

/**
 * Asignación de copia
 */
TEST(BigIntTest, CopyAssignPositive) {
  BigInt<2> A{110110001};
  stream_for_tests << A;
  std::string A_str{stream_for_tests.str()};
  stream_for_tests.str("");

  BigInt<2> B{10010000};
  B = A;
  stream_for_tests << B;
  EXPECT_EQ(A_str, stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, CopyAssignNegative) {
  BigInt<16> A{"-3201D10001"};
  stream_for_tests << A;
  std::string A_str{stream_for_tests.str()};
  stream_for_tests.str("");

  BigInt<16> B{10010000};
  B = A;
  stream_for_tests << B;
  EXPECT_EQ(A_str, stream_for_tests.str());
  stream_for_tests.str("");
}

/**
 * Extracción de flujo
 */
TEST(BigIntTest, ExtraccionPositivo) {
  std::stringstream foo_cout{"+10101"};
  BigInt<2> A{110110001};
  foo_cout >> A;
  stream_for_tests << A;

  EXPECT_EQ("10101", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, ExtraccionNegativo) {
  std::stringstream foo_cout{"-2abc10101"};
  BigInt<16> A{110110001};
  foo_cout >> A;
  stream_for_tests << A;

  EXPECT_EQ("-2ABC10101", stream_for_tests.str());
  stream_for_tests.str("");
}

TEST(BigIntTest, ExtraccionCerosPrevios) {
  std::stringstream foo_cout{"-0040501"};
  BigInt<8> A{110001};
  foo_cout >> A;
  stream_for_tests << A;

  EXPECT_EQ("-40501", stream_for_tests.str());
  stream_for_tests.str("");
}

/**
 * Comparación
 */
TEST(BigIntTest, Igualdad) {
  BigInt<8> A{110001};
  BigInt<8> B{110001};
  EXPECT_EQ(A, B);

  B = BigInt<8>{-110001};
  EXPECT_TRUE(!(A == B));

  BigInt<8> C{2377637};
  EXPECT_TRUE(!(B == C));

  BigInt<8> D{C};
  EXPECT_EQ(C, D);
}

TEST(BigIntTest, Desigualdad) {
  BigInt<8> A{110001};
  BigInt<8> B{-110001};
  EXPECT_TRUE(A != B);

  B = BigInt<8>{110001};
  EXPECT_TRUE(!(A != B));

  BigInt<8> C{2377637};
  EXPECT_TRUE(B != C);
}

TEST(BigIntTest, MayorPositivo) {
  BigInt<8> A{110101};
  BigInt<8> B{110001};
  EXPECT_TRUE(A > B);
  EXPECT_TRUE(!(B > A));

  BigInt<8> C{"010101"};
  EXPECT_TRUE(A > C);
  EXPECT_TRUE(!(C > A));

  BigInt<8> D{"001101010"};
  EXPECT_TRUE(D > C);

  BigInt<8> E{7770};
  BigInt<8> F{2345};
  EXPECT_TRUE(E > F);
  EXPECT_TRUE(!(F > E));
}

TEST(BigIntTest, MayorSigno) {
  BigInt<8> A{-110101};
  BigInt<8> B{110001};
  EXPECT_TRUE(B > A);
  EXPECT_TRUE(!(A > B));

  BigInt<8> C{"0010101"};
  EXPECT_TRUE(C > A);
  EXPECT_TRUE(B > C);
  EXPECT_TRUE(!(A > C));
  EXPECT_TRUE(!(C > B));

  BigInt<8> D{"-001101010"};
  EXPECT_TRUE(C > D);
  EXPECT_TRUE(!(D > C));

  EXPECT_TRUE(A > D);
  EXPECT_TRUE(!(D > A));
}

TEST(BigIntTest, Menor) {
  BigInt<8> A{110101};
  BigInt<8> B{110001};
  EXPECT_TRUE(B < A);
  EXPECT_TRUE(!(A < B));

  BigInt<8> C{"010101"};
  EXPECT_TRUE(C < A);
  EXPECT_TRUE(!(A < C));

  BigInt<8> D{"001101010"};
  EXPECT_TRUE(C < D);

  BigInt<8> E{7770};
  BigInt<8> F{2345};
  EXPECT_TRUE(!(E < F));
}

TEST(BigIntTest, MayorOIgual) {
  BigInt<8> A{110101};
  BigInt<8> B{110001};
  EXPECT_TRUE(A >= B);
  EXPECT_TRUE(!(B >= A));

  BigInt<8> C{"0110101"};
  EXPECT_TRUE(A >= C);
  EXPECT_TRUE(C >= A);
}

TEST(BigIntTest, MenorOIgual) {
  BigInt<8> A{110101};
  BigInt<8> B{110001};
  EXPECT_TRUE(B <= A);
  EXPECT_TRUE(!(A <= B));

  BigInt<8> C{"0110101"};
  EXPECT_TRUE(A <= C);
  EXPECT_TRUE(C <= A);
}

/**
 * Incremento y decremento
 */

/**
 * Suma y Resta
 */
TEST(BigIntTest, SumaPositivos) {
  BigInt<8> A{2345};
  BigInt<8> B{127};
  BigInt<8> C{2474};
  EXPECT_EQ(A + B, C);
  EXPECT_EQ(B + A, C);

  BigInt<8> D{};
  EXPECT_EQ(A + D, A);
  EXPECT_EQ(D + A, A);
}

TEST(BigIntTest, SumaNegativos) {
  BigInt<8> A{-2345};
  BigInt<8> B{-120};
  BigInt<8> C{-2465};
  EXPECT_EQ(A + B, C);
  EXPECT_EQ(B + A, C);

  BigInt<8> D{};
  EXPECT_EQ(A + D, A);
  EXPECT_EQ(D + A, A);
}

TEST(BigIntTest, SumaPositivoNegativo) {
  BigInt<8> A{2345};
  BigInt<8> B{-1};
  BigInt<8> C{2344};
  EXPECT_EQ(A + B, C);
  EXPECT_EQ(B + A, C);

  BigInt<8> D{-150};
  BigInt<8> E{2175};
  EXPECT_EQ(A + D, E);
  EXPECT_EQ(D + A, E);

  BigInt<2> F{11010};
  BigInt<2> G{-1001};
  BigInt<2> H{10001};
  EXPECT_EQ(F + G, H);
  EXPECT_EQ(G + F, H);

  BigInt<2> I{-11010};
  BigInt<2> J{};
  EXPECT_EQ(I + F, J);
  EXPECT_EQ(F + I, J);

  BigInt<8> K{-2345};
  BigInt<8> L{346};
  BigInt<8> M{-1777};
  EXPECT_EQ(K + L, M);
  EXPECT_EQ(L + K, M);
}

TEST(BigIntTest, CambioSigno) {
  BigInt<8> A{2345};
  BigInt<8> B{-2345};
  EXPECT_EQ(-A, B);
  EXPECT_EQ(-B, A);
  EXPECT_EQ(-(-A), A);
}

TEST(BigIntTest, RestaPositivos) {
  BigInt<8> A{2345};
  BigInt<8> B{346};
  BigInt<8> C{1777};
  EXPECT_EQ(A - B, C);
  EXPECT_EQ(B - A, -C);

  BigInt<8> D{2300};
  BigInt<8> E{45};
  EXPECT_EQ(A - D, E);
  EXPECT_EQ(D - A, -E);

  BigInt<8> F{};
  EXPECT_EQ(A - A, F);

  BigInt<8> G{100};
  BigInt<8> H{1};
  BigInt<8> I{77};
  EXPECT_EQ(G - H, I);
}

TEST(BigIntTest, RestaNegativos) {
  BigInt<8> A{2345};
  BigInt<8> B{-346};
  BigInt<8> C{1777};
  EXPECT_EQ(C - B, A);
  EXPECT_EQ(B - C, -A);

  BigInt<8> D{-2300};
  BigInt<8> E{4645};
  EXPECT_EQ(A - D, E);
  EXPECT_EQ(D - A, -E);

  BigInt<8> F{};
  EXPECT_EQ(B - B, F);

  BigInt<8> G{-12000};
  BigInt<8> H{14345};
  EXPECT_EQ(A - G, H);
  EXPECT_EQ(G - A, -H);

  BigInt<8> I{-146};
  BigInt<8> J{200};
  EXPECT_EQ(I - B, J);
  EXPECT_EQ(B - I, -J);
}

TEST(BigIntTest, PreincrementoPredecremento) {
  BigInt<8> A{23456};
  BigInt<8> B{23457};
  BigInt<8> C{23460};
  EXPECT_EQ(++A, B);
  EXPECT_EQ(++B, C);
  EXPECT_EQ(C, B);

  BigInt<8> D{23450};
  BigInt<8> E{23451};
  BigInt<8> F{23447};
  EXPECT_EQ(--E, D);
  EXPECT_EQ(--D, F);
  EXPECT_EQ(F, D);

  BigInt<8> G{};
  BigInt<8> H{-1};
  BigInt<8> I{};
  EXPECT_EQ(--G, H);
  EXPECT_EQ(++H, I);

  BigInt<8> J{77};
  BigInt<8> K{100};
  EXPECT_EQ(--K, J);
}

TEST(BigIntTest, PostincrementoPostdecremento) {
  BigInt<8> A{23457};
  BigInt<8> B{23457};
  BigInt<8> C{23460};
  EXPECT_EQ(A++, B);
  EXPECT_EQ(A, C);

  EXPECT_EQ(C--, ++B);
  EXPECT_EQ(C, --B);

  BigInt<8> D{23450};
  BigInt<8> E{23451};
  BigInt<8> F{23447};
  EXPECT_EQ(E--, ++D);
  EXPECT_EQ(E, --D);
  EXPECT_EQ(D--, E);
  EXPECT_EQ(F, D);

  BigInt<8> G{};
  BigInt<8> H{-1};
  BigInt<8> I{};
  EXPECT_EQ(G--, I);
  EXPECT_EQ(G, H);
  EXPECT_EQ(H++, G);
  EXPECT_EQ(H, I);
}

TEST(BigIntTest, MultiplicacionPositiva) {
  BigInt<8> A{23457};
  BigInt<8> B{1};
  EXPECT_EQ(A * B, A);
  EXPECT_EQ(B * A, A);

  BigInt<8> C{};
  EXPECT_EQ(A * C, C);
  EXPECT_EQ(C * A, C);

  BigInt<8> D{3};
  BigInt<8> E{72615};
  EXPECT_EQ(A * D, E);
  EXPECT_EQ(D * A, E);

  BigInt<8> F{23000000};
  BigInt<8> G{2134567000000};
  EXPECT_EQ(F * E, G);
  EXPECT_EQ(E * F, G);
}

TEST(BigIntTest, MultiplicacionNegativa) {
  BigInt<8> A{23457};
  BigInt<8> B{-1};
  EXPECT_EQ(A * B, -A);
  EXPECT_EQ(B * A, -A);

  BigInt<8> C{};
  EXPECT_EQ(A * C, C);
  EXPECT_EQ(C * A, C);

  A = -A;
  EXPECT_EQ(A * B, -A);
  EXPECT_EQ(B * A, -A);

  EXPECT_EQ(A * C, C);
  EXPECT_EQ(C * A, C);

  BigInt<8> D{3};
  BigInt<8> E{-72615};
  EXPECT_EQ(A * D, E);
  EXPECT_EQ(D * A, E);

  BigInt<8> F{-23000000};
  BigInt<8> G{2134567000000};
  EXPECT_EQ(F * E, G);
  EXPECT_EQ(E * F, G);
}

TEST(BigIntTest, DivisionPositiva) {
  BigInt<8> A{23457};
  BigInt<8> B{1};
  BigInt<8> C{};
  EXPECT_EQ(A / B, A);
  EXPECT_EQ(B / A, C);

  testing::internal::CaptureStderr();
  /// Comprobamos que se muestra el mensaje de error
  A / C;
  std::string log = testing::internal::GetCapturedStderr();
  EXPECT_NE(log, "");

  EXPECT_EQ(C / A, C);

  BigInt<8> D{10};
  BigInt<8> E{2345};
  EXPECT_EQ(A / D, E);
  EXPECT_EQ(D / A, C);

  BigInt<8> F{23};
  BigInt<8> G{1017};
  EXPECT_EQ(A / F, G);
  EXPECT_EQ(F / A, C);
}

TEST(BigIntTest, DivisionNegativa) {
  BigInt<8> A{23457};
  BigInt<8> B{-1};
  BigInt<8> C{};
  EXPECT_EQ(A / B, -A);
  EXPECT_EQ(B / A, C);

  A = -A;
  EXPECT_EQ(A / B, -A);
  EXPECT_EQ(B / A, C);

  BigInt<8> D{-10};
  BigInt<8> E{2345};
  EXPECT_EQ(A / D, E);
}

TEST(BigIntTest, ModuloPositivo) {
  BigInt<8> A{23457};
  BigInt<8> B{2};
  BigInt<8> C{1};
  BigInt<8> D{};
  EXPECT_EQ(A % B, C);
  EXPECT_EQ(A % C, D);
  EXPECT_EQ(A % D, A);  // Indefinido o error

  BigInt<8> E{6};
  BigInt<8> F{5};
  EXPECT_EQ(A % E, F);
}

TEST(BigIntTest, ModuloNegativo) {
  BigInt<8> A{23457};
  BigInt<8> B{-2};
  BigInt<8> C{-1};
  BigInt<8> D{};
  EXPECT_EQ(A % B, -C);
  EXPECT_EQ(A % C, D);
  EXPECT_EQ(A % D, A);  // Indefinido o error

  A = -A;
  EXPECT_EQ(A % B, -C);
  EXPECT_EQ(A % C, D);

  BigInt<8> E{6};
  BigInt<8> F{5};
  EXPECT_EQ(A % E, F);
}

TEST(BigIntTest, PotenciaPositiva) {
  BigInt<8> A{23457};
  BigInt<8> B{1};
  BigInt<8> C{};
  BigInt<8> D{-1};
  EXPECT_EQ(pow(A, B), A);
  EXPECT_EQ(pow(A, C), B);
  EXPECT_EQ(pow(A, D), C);
  EXPECT_EQ(pow(B, B), B);
  EXPECT_EQ(pow(B, A), B);

  BigInt<8> E{7};
  BigInt<8> F{4};
  BigInt<8> G{4541};
  EXPECT_EQ(pow(E, F), G);
}

TEST(BigIntTest, PotenciaBaseNegativa) {
  BigInt<8> A{-23457};
  BigInt<8> B{1};
  BigInt<8> C{};
  BigInt<8> D{-1};
  EXPECT_EQ(pow(A, B), A);
  EXPECT_EQ(pow(A, C), B);
  EXPECT_EQ(pow(A, D), C);

  BigInt<8> E{-7};
  BigInt<8> F{4};
  BigInt<8> G{4541};
  EXPECT_EQ(pow(E, F), G);

  BigInt<8> H{5};
  BigInt<8> I{-40647};
  EXPECT_EQ(pow(E, H), I);
}

TEST(BigIntTest, PotenciaUnos) {
  BigInt<8> A{1};
  BigInt<8> B{-1};
  BigInt<8> C{};
  BigInt<8> D{4};
  BigInt<8> E{11};
  EXPECT_EQ(pow(A, A), A);
  EXPECT_EQ(pow(A, B), A);
  EXPECT_EQ(pow(A, C), A);
  EXPECT_EQ(pow(A, D), A);
  EXPECT_EQ(pow(A, E), A);
  EXPECT_EQ(pow(A, -C), A);
  EXPECT_EQ(pow(A, -D), A);
  EXPECT_EQ(pow(A, -E), A);

  EXPECT_EQ(pow(B, A), B);
  EXPECT_EQ(pow(B, B), B);
  EXPECT_EQ(pow(B, C), A);
  EXPECT_EQ(pow(B, D), A);
  EXPECT_EQ(pow(B, E), B);
  EXPECT_EQ(pow(B, -C), A);
  EXPECT_EQ(pow(B, -D), A);
  EXPECT_EQ(pow(B, -E), B);
}
