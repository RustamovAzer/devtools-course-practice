// Copyright 2021 Rustamov Azer

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Rustamov_Azer_ComplexNumberTest, Complex_Conjugate_Addition) {
    double re_1 = 2.5;
    double im_1 = 3.0;
    double re_2 = re_1;
    double im_2 = -im_1;
    ComplexNumber num1(re_1, im_1);
    ComplexNumber num2(re_2, im_2);
    ComplexNumber sum = num1 + num2;

    ASSERT_DOUBLE_EQ(sum.getRe(), 2 * re_1);
    ASSERT_DOUBLE_EQ(sum.getIm(), 0.0);
}

TEST(Rustamov_Azer_ComplexNumberTest, Complex_Conjugate_Multiplication) {
    double re_1 = 2.5;
    double im_1 = 3.0;
    double re_2 = re_1;
    double im_2 = -im_1;
    ComplexNumber num1(re_1, im_1);
    ComplexNumber num2(re_2, im_2);
    ComplexNumber res = num1 * num2;

    double lensq_expected = (re_1*re_1 + im_1*im_1)*(re_1*re_1 + im_1*im_1);
    double res_Resq = res.getRe() * res.getRe();

    ASSERT_DOUBLE_EQ(res_Resq, lensq_expected);
    ASSERT_DOUBLE_EQ(res.getIm(), 0.0);
}

TEST(Rustamov_Azer_ComplexNumberTest, Complex_Conjugate_Equal_lengths) {
    double re_1 = 2.5;
    double im_1 = 3.0;
    double re_2 = re_1;
    double im_2 = -im_1;
    ComplexNumber num1(re_1, im_1);
    ComplexNumber num2(re_2, im_2);

    double len1sq = num1.getRe() * num1.getRe() + num1.getIm() * num1.getIm();
    double len2sq = num2.getRe() * num2.getRe() + num1.getIm() * num1.getIm();

    ASSERT_DOUBLE_EQ(len1sq, len2sq);
}
