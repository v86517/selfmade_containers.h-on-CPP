#include "test.h"

#include <gtest/gtest.h>

TEST(VECTOR, Constructors) {
  s21::vector<int> s21_1;
  std::vector<int> std_1;
  EXPECT_TRUE(s21_1 == std_1);

  s21::vector<int> s21_2 = {};
  std::vector<int> std_2 = {};
  EXPECT_TRUE(s21_2 == std_2);

  s21::vector<int> s21_3 = {1, 2, 3};
  std::vector<int> std_3 = {1, 2, 3};
  EXPECT_TRUE(s21_3 == std_3);

  s21::vector<int> s21_4(s21_3);
  std::vector<int> std_4(std_3);
  EXPECT_TRUE(s21_4 == std_4);

  s21::vector<int> s21_5 = s21_3;
  std::vector<int> std_5 = std_3;
  EXPECT_TRUE(s21_5 == std_5);

  s21::vector<int> s21_6 = std::move(s21_3);
  std::vector<int> std_6 = std::move(std_3);
  EXPECT_TRUE(s21_6 == std_6);
  EXPECT_TRUE(s21_3 == std_3);

  s21::vector<int> s21_7 = {1, 2, 3};
  std::vector<int> std_7 = {1, 2, 3};
  s21::vector<int> s21_8(std::move(s21_7));
  std::vector<int> std_8(std::move(std_7));
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::vector<int> s21_9({1, 2, 3});
  std::vector<int> std_9({1, 2, 3});
  EXPECT_TRUE(s21_9 == std_9);

  s21::vector<s21::vector<int>> s21_10;
  std::vector<std::vector<int>> std_10;
  EXPECT_TRUE(s21_10 == std_10);

  s21::vector<s21::vector<int>> s21_11 = {};
  std::vector<std::vector<int>> std_11 = {};
  EXPECT_TRUE(s21_11 == std_11);

  s21::vector<s21::vector<int>> s21_12 = {{1, 2}, {1, 3}};
  std::vector<std::vector<int>> std_12 = {{1, 2}, {1, 3}};
  EXPECT_TRUE(s21_12 == std_12);

  s21::vector<s21::vector<int>> s21_13(s21_12);
  std::vector<std::vector<int>> std_13(std_12);
  EXPECT_TRUE(s21_13 == std_13);

  s21::vector<s21::vector<int>> s21_14(s21_12);
  std::vector<std::vector<int>> std_14(std_12);
  EXPECT_TRUE(s21_14 == std_14);

  s21::vector<s21::vector<int>> s21_15 = std::move(s21_12);
  std::vector<std::vector<int>> std_15 = std::move(std_12);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_12 == std_12);

  s21::vector<s21::vector<int>> s21_16 = {{1, 2}, {1, 3}};
  std::vector<std::vector<int>> std_16 = {{1, 2}, {1, 3}};
  s21::vector<s21::vector<int>> s21_17(std::move(s21_16));
  std::vector<std::vector<int>> std_17(std::move(std_16));
  EXPECT_TRUE(s21_16 == std_16);
  EXPECT_TRUE(s21_17 == std_17);

  s21::vector<s21::vector<int>> s21_18({{1, 2}, {1, 3}});
  std::vector<std::vector<int>> std_18({{1, 2}, {1, 3}});
  EXPECT_TRUE(s21_18 == std_18);
}

TEST(VECTOR, FrontBack) {
  const s21::vector<int> s21_1 = {1, 2, 3};
  const std::vector<int> std_1 = {1, 2, 3};
  EXPECT_TRUE(s21_1.front() == std_1.front());
  EXPECT_TRUE(s21_1.back() == std_1.back());

  s21::vector<int> s21_2 = {1, 2, 3};
  std::vector<int> std_2 = {1, 2, 3};
  s21_2.front() = 5;
  s21_2.back() = 6;
  std_2.front() = 5;
  std_2.back() = 6;
  EXPECT_TRUE(s21_2 == std_2);

  const s21::vector<s21::vector<int>> s21_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const std::vector<std::vector<int>> std_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  EXPECT_TRUE(s21_3.front() == std_3.front());
  EXPECT_TRUE(s21_3.back() == std_3.back());

  s21::vector<s21::vector<int>> s21_4 = {{1}, {4, 5, 6, 7}, {4, 5, 6, 7, 8}};
  std::vector<std::vector<int>> std_4 = {{1}, {4, 5, 6, 7}, {4, 5, 6, 7, 8}};
  s21::vector<int> s21_5 = {1, 2, 3};
  std::vector<int> std_5 = {1, 2, 3};
  s21_4.front() = std::move(s21_5);
  s21_4.back() = {3, 4, 5, 6};
  std_4.front() = std::move(std_5);
  std_4.back() = {3, 4, 5, 6};
  EXPECT_TRUE(s21_4 == std_4);
}

TEST(VECTOR, Empty) {
  s21::vector<int> s21_1 = {1, 2, 3};
  std::vector<int> std_1 = {1, 2, 3};
  EXPECT_TRUE(s21_1.empty() == std_1.empty());

  s21::vector<int> s21_2;
  std::vector<int> std_2;
  EXPECT_TRUE(s21_2.empty() == std_2.empty());

  s21::vector<s21::vector<int>> s21_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> std_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  EXPECT_TRUE(s21_3.empty() == std_3.empty());

  s21::vector<s21::vector<int>> s21_4;
  std::vector<std::vector<int>> std_4;
  EXPECT_TRUE(s21_4.empty() == std_4.empty());
}

TEST(VECTOR, Insert) {
  s21::vector<int> s21_1 = {1, 2, 3, 4, 5};
  std::vector<int> std_1 = {1, 2, 3, 4, 5};
  auto s21_it_1 = s21_1.cbegin();
  auto std_it_1 = std_1.cbegin();
  auto s21_it_2 = s21_1.insert(s21_it_1, 9);
  auto std_it_2 = std_1.insert(std_it_1, 9);
  EXPECT_TRUE(*s21_it_2 == *std_it_2);
  EXPECT_TRUE(s21_1 == std_1);

  s21_it_1 = s21_1.cbegin();
  std_it_1 = std_1.cbegin();
  for (int k = 0; k < 2; ++k) {
    ++s21_it_1;
    ++std_it_1;
  }
  const int y = 8;

  auto s21_it_3 = s21_1.insert(s21_it_1, y);
  auto std_it_3 = std_1.insert(std_it_1, y);

  EXPECT_TRUE(*s21_it_3 == *std_it_3);
  s21_it_1 = s21_1.cend();
  std_it_1 = std_1.cend();
  const int x = 7;
  auto s21_it_4 = s21_1.insert(s21_it_1, x);
  auto std_it_4 = std_1.insert(std_it_1, x);
  EXPECT_TRUE(*s21_it_4 == *std_it_4);
  EXPECT_TRUE(s21_1 == std_1);
  s21_it_1 = s21_1.cbegin();
  std_it_1 = std_1.cbegin();
  auto s21_it_9 = s21_1.insert(s21_it_1, 11);
  auto std_it_9 = std_1.insert(std_it_1, 11);
  EXPECT_TRUE(*s21_it_9 == *std_it_9);
  EXPECT_TRUE(s21_1 == std_1);

  s21::vector<s21::vector<int>> s21_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> std_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto s21_it_5 = s21_2.cbegin();
  auto std_it_5 = std_2.cbegin();
  const s21::vector<int> s21_3 = {4, 5};
  const std::vector<int> std_3 = {4, 5};
  auto s21_it_6 = s21_2.insert(s21_it_5, s21_3);
  auto std_it_6 = std_2.insert(std_it_5, std_3);
  EXPECT_TRUE(*s21_it_6 == *std_it_6);
  s21_it_5 = s21_2.cbegin();
  std_it_5 = std_2.cbegin();
  for (int k = 0; k < 2; ++k) {
    ++s21_it_5;
    ++std_it_5;
  }
  auto s21_it_7 = s21_2.insert(s21_it_5, {1, 2});
  auto std_it_7 = std_2.insert(std_it_5, {1, 2});
  EXPECT_TRUE(*s21_it_7 == *std_it_7);
  s21_it_5 = s21_2.cend();
  std_it_5 = std_2.cend();
  auto s21_it_8 = s21_2.insert(s21_it_5, {3, 4});
  auto std_it_8 = std_2.insert(std_it_5, {3, 4});
  EXPECT_TRUE(*s21_it_8 == *std_it_8);
  EXPECT_TRUE(s21_2 == std_2);

  s21::vector<int> s21_4 = {1, 2, 3, 4, 5};
  std::vector<int> std_4 = {1, 2, 3, 4, 5};
  auto s21_it_10 = ++s21_4.cbegin();
  auto std_it_10 = ++std_4.cbegin();
  auto s21_it_11 = s21_4.insert(s21_it_10, 9, 20);
  auto std_it_11 = std_4.insert(std_it_10, 9, 20);
  EXPECT_TRUE(*s21_it_11 == *std_it_11);
  EXPECT_TRUE(s21_4 == std_4);

  s21::vector<int> s21_5 = {};
  std::vector<int> std_5 = {};
  auto s21_it_12 = s21_5.cend();
  auto std_it_12 = std_5.cend();
  auto s21_it_13 = s21_5.insert(s21_it_12, 9, 20);
  auto std_it_13 = std_5.insert(std_it_12, 9, 20);
  EXPECT_TRUE(*s21_it_13 == *std_it_13);
  EXPECT_TRUE(s21_5 == std_5);
}

TEST(VECTOR, ElementAccess) {
  s21::vector<int> s21_1 = {1, 2, 3, 4, 5};
  const s21::vector<int> s21_2 = {1, 2, 3, 4, 5};
  std::vector<int> std_1 = {1, 2, 3, 4, 5};
  const std::vector<int> std_2 = {1, 2, 3, 4, 5};
  EXPECT_THROW(s21_1.at(10), std::out_of_range);
  EXPECT_THROW(s21_2.at(10), std::out_of_range);
  s21_1.at(2) = 77;
  std_1.at(2) = 77;
  EXPECT_TRUE(s21_1.at(2) == std_1.at(2));
  EXPECT_TRUE(s21_2.at(2) == std_2.at(2));
  s21_1[3] = 88;
  std_1[3] = 88;
  EXPECT_TRUE(s21_1[3] == s21_1[3]);
  EXPECT_TRUE(s21_2[3] == s21_2[3]);

  s21::vector<s21::vector<int>> s21_3 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  const s21::vector<s21::vector<int>> s21_4 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  std::vector<std::vector<int>> std_3 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  const std::vector<std::vector<int>> std_4 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  s21_3.at(2) = {1, 2, 3};
  std_3.at(2) = {1, 2, 3};
  EXPECT_TRUE(s21_3.at(2) == std_3.at(2));
  EXPECT_TRUE(s21_4.at(2) == std_4.at(2));
  s21_3[3] = {1, 2};
  std_3[3] = {1, 2};
  EXPECT_TRUE(s21_3[3] == s21_3[3]);
  EXPECT_TRUE(s21_4[3] == s21_4[3]);
}

TEST(VECTOR, Data) {
  s21::vector<int> s21_1 = {1, 2, 3, 4, 5};
  std::vector<int> std_1 = {1, 2, 3, 4, 5};
  EXPECT_TRUE(s21_1.data()[0] == std_1.data()[0]);

  s21::vector<s21::vector<int>> s21_2 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  std::vector<std::vector<int>> std_2 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  EXPECT_TRUE(s21_2.data()[0] == std_2.data()[0]);

  const s21::vector<int> s21_3 = {1, 2, 3, 4, 5};
  const std::vector<int> std_3 = {1, 2, 3, 4, 5};
  EXPECT_TRUE(s21_3.data()[0] == std_3.data()[0]);

  const s21::vector<s21::vector<int>> s21_4 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  const std::vector<std::vector<int>> std_4 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  EXPECT_TRUE(s21_4.data()[0] == std_4.data()[0]);
}

TEST(VECTOR, ReserveShrink) {
  s21::vector<int> s21_1 = {};
  std::vector<int> std_1 = {};
  s21_1.reserve(2);
  std_1.reserve(2);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.shrink_to_fit();
  std_1.shrink_to_fit();
  EXPECT_TRUE(s21_1 == std_1);

  s21::vector<int> s21_2 = {1, 2};
  std::vector<int> std_2 = {1, 2};
  EXPECT_THROW(s21_2.reserve(s21_2.max_size() + 1), std::length_error);

  s21::vector<int> s21_3 = {1, 2};
  std::vector<int> std_3 = {1, 2};
  s21_3.reserve(3);
  std_3.reserve(3);
  EXPECT_TRUE(s21_3 == std_3);
  s21_3.shrink_to_fit();
  std_3.shrink_to_fit();
  EXPECT_TRUE(s21_3 == std_3);

  s21::vector<s21::vector<int>> s21_4 = {};
  std::vector<std::vector<int>> std_4 = {};
  s21_4.reserve(2);
  std_4.reserve(2);
  EXPECT_TRUE(s21_4 == std_4);
  s21_4.shrink_to_fit();
  std_4.shrink_to_fit();
  EXPECT_TRUE(s21_4 == std_4);

  s21::vector<s21::vector<int>> s21_5 = {{1}, {2}};
  std::vector<std::vector<int>> std_5 = {{1}, {2}};
  s21_5.reserve(2);
  std_5.reserve(2);
  EXPECT_TRUE(s21_5 == std_5);
  s21_5.shrink_to_fit();
  std_5.shrink_to_fit();
  EXPECT_TRUE(s21_5 == std_5);

  s21::vector<s21::vector<int>> s21_6 = {{1}, {2}};
  std::vector<std::vector<int>> std_6 = {{1}, {2}};
  s21_6.reserve(10);
  std_6.reserve(10);
  EXPECT_TRUE(s21_6 == std_6);
  s21_6.shrink_to_fit();
  std_6.shrink_to_fit();
  EXPECT_TRUE(s21_6 == std_6);
}

TEST(VECTOR, OperatorDoubeEq) {
  s21::vector<s21::vector<int>> s21_1 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  s21::vector<s21::vector<int>> s21_2 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  EXPECT_TRUE(s21_1 == s21_2);

  s21::vector<s21::vector<int>> s21_3 = {
      {1, 2, 3}, {1, 7, 5}, {1}, {1, 2, 3, 4, 5}};
  s21::vector<s21::vector<int>> s21_4 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  EXPECT_FALSE(s21_3 == s21_4);

  s21::vector<s21::vector<int>> s21_5 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}};
  s21::vector<s21::vector<int>> s21_6 = {
      {1, 2, 3}, {1, 4, 5}, {1}, {1, 2, 3, 4, 5}, {2}};
  EXPECT_FALSE(s21_5 == s21_6);
}

TEST(VECTOR, Resize) {
  s21::vector<int> s21_1 = {};
  std::vector<int> std_1 = {};
  s21_1.resize(0);
  std_1.resize(0);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(10);
  std_1.resize(10);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.reserve(20);
  std_1.reserve(20);
  s21_1.resize(15, 3);
  std_1.resize(15, 3);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(45, 1);
  std_1.resize(45, 1);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(5, -1);
  std_1.resize(5, -1);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_THROW(s21_1.resize(s21_1.max_size() + 1, -1), std::length_error);

  s21::vector<s21::vector<int>> s21_2 = {};
  std::vector<std::vector<int>> std_2 = {};
  s21_2.resize(0);
  std_2.resize(0);
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(10);
  std_2.resize(10);
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.reserve(20);
  std_2.reserve(20);
  s21_2.resize(15, {3});
  std_2.resize(15, {3});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(45, {1, 2});
  std_2.resize(45, {1, 2});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(5, {});
  std_2.resize(5, {});
  EXPECT_TRUE(s21_2 == std_2);
  EXPECT_THROW(s21_2.resize(s21_2.max_size() + 1, {-10}), std::length_error);
}

TEST(VECTOR, Erase) {
  s21::vector<int> s21_1 = {1, 2, 3, 4, 5, 6};
  std::vector<int> std_1 = {1, 2, 3, 4, 5, 6};
  auto s21_it_1 = s21_1.erase(s21_1.cbegin(), ++(++s21_1.cbegin()));
  auto std_it_1 = std_1.erase(std_1.cbegin(), ++(++std_1.cbegin()));
  EXPECT_TRUE(*s21_it_1 == *std_it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21::vector<int> s21_2 = {1, 2, 3, 4, 5, 6};
  std::vector<int> std_2 = {1, 2, 3, 4, 5, 6};
  auto s21_it_2 = s21_2.erase(s21_2.cbegin(), s21_2.cend());
  std_2.erase(std_2.cbegin(), std_2.cend());
  EXPECT_TRUE(s21_it_2 == s21_2.end());
  EXPECT_TRUE(s21_2 == std_2);

  s21::vector<int> s21_3 = {1, 2, 3, 4, 5, 6};
  std::vector<int> std_3 = {1, 2, 3, 4, 5, 6};
  auto s21_it_3 = s21_1.erase(++s21_1.cbegin());
  auto std_it_3 = std_1.erase(++std_1.cbegin());
  EXPECT_TRUE(*s21_it_3 == *std_it_3);
  EXPECT_TRUE(s21_3 == std_3);

  s21::vector<int> s21_4 = {1, 2, 3, 4, 5, 6};
  std::vector<int> std_4 = {1, 2, 3, 4, 5, 6};
  auto s21_it_4 = s21_4.erase(s21_4.cbegin(), s21_4.cbegin());
  auto std_it_4 = std_4.erase(std_4.cbegin(), std_4.cbegin());
  EXPECT_TRUE(*s21_it_4 == *std_it_4);
  EXPECT_TRUE(s21_4 == std_4);
}

TEST(VECTOR, InsertMany) {
  s21::vector<int> s21_1 = {1, 2, 3, 0, 1, 2};
  std::vector<int> std_1 = {1, 2, 3, 0, 1, 2, 4, 5, 5};
  s21_1.insert_many_back(4, 5, 5);
  s21_1.shrink_to_fit();
  std_1.shrink_to_fit();
  EXPECT_TRUE(s21_1 == std_1);

  s21::vector<int> s21_2 = {1, 2, 3, 0, 1, 2};
  std::vector<int> std_2 = {5, 5, 4, 1, 2, 3, 0, 1, 2};
  s21_2.insert_many(s21_2.cbegin(), 4, 5, 5);
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(ARRAY, SizeEmpty) {
  s21::array<int, 3> s21_1 = {1, 2, 3};
  std::array<int, 3> std_1 = {1, 2, 5};
  std::array<int, 4> std_2 = {1, 2, 5, 7};
  s21::array<int, 0> s21_2;
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_FALSE(s21_1.size() == std_2.size());
  EXPECT_TRUE(s21_2.empty());

  s21::array<s21::array<int, 1>, 3> s21_3 = {{1}, {2}, {3}};
  std::array<std::array<int, 1>, 3> std_3 = {{{1}, {2}, {3}}};
  std::array<std::array<int, 1>, 4> std_4 = {{{1}, {2}, {5}, {7}}};
  s21::array<s21::array<int, 1>, 0> s21_4;
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_FALSE(s21_3.size() == std_4.size());
  EXPECT_TRUE(s21_4.empty());
}

TEST(ARRAY, FrontBack) {
  const s21::array<int, 2> s21_1 = {1, 2};
  const std::array<int, 2> std_1 = {1, 2};
  EXPECT_TRUE(s21_1.back() == std_1.back());
  EXPECT_TRUE(s21_1.front() == std_1.front());

  s21::array<int, 2> s21_2 = {1, 2};
  std::array<int, 2> std_2 = {1, 2};
  s21_2.front() = 5;
  std_2.front() = 5;
  s21_2.back() = 5;
  std_2.back() = 5;
  EXPECT_TRUE(s21_1.back() == std_1.back());
  EXPECT_TRUE(s21_1.front() == std_1.front());

  const s21::array<s21::array<int, 1>, 2> s21_3 = {{1}, {2}};
  const std::array<std::array<int, 1>, 2> std_3 = {{{1}, {2}}};
  EXPECT_TRUE(s21_3.back() == std_3.back());
  EXPECT_TRUE(s21_3.front() == std_3.front());

  s21::array<s21::array<int, 1>, 2> s21_4 = {{1}, {2}};
  std::array<std::array<int, 1>, 2> std_4 = {{{1}, {2}}};
  s21_4.front() = {5};
  std_4.front() = {5};
  s21_4.back() = {7};
  std_4.back() = {7};
  EXPECT_TRUE(s21_4.back() == std_4.back());
  EXPECT_TRUE(s21_4.front() == std_4.front());
}

TEST(ARRAY, AtBracketsData) {
  const s21::array<int, 2> s21_1 = {1, 2};
  const std::array<int, 2> std_1 = {1, 2};
  EXPECT_TRUE(s21_1[1] == std_1[1]);
  EXPECT_TRUE(s21_1.at(1) == std_1.at(1));
  EXPECT_THROW(s21_1.at(5), std::out_of_range);
  EXPECT_TRUE(*s21_1.data() == *std_1.data());

  s21::array<int, 2> s21_2 = {1, 2};
  std::array<int, 2> std_2 = {1, 2};
  s21_2[1] = 4;
  std_2[1] = 4;
  s21_2.at(0) = 5;
  std_2.at(0) = 5;
  EXPECT_TRUE(s21_2[1] == std_2[1]);
  EXPECT_TRUE(s21_2.at(0) == std_2.at(0));
  EXPECT_THROW(s21_2.at(5), std::out_of_range);
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.data()[0] = 5;
  std_2.data()[0] = 5;
  EXPECT_TRUE(s21_2 == std_2);

  const s21::array<s21::array<int, 1>, 2> s21_3 = {{1}, {2}};
  const std::array<std::array<int, 1>, 2> std_3 = {{{1}, {2}}};
  EXPECT_TRUE(s21_3[1] == std_3[1]);
  EXPECT_TRUE(s21_3.at(1) == std_3.at(1));
  EXPECT_THROW(s21_3.at(5), std::out_of_range);
  EXPECT_TRUE(*s21_3.data() == *std_3.data());

  s21::array<s21::array<int, 1>, 2> s21_4 = {{1}, {2}};
  std::array<std::array<int, 1>, 2> std_4 = {{{1}, {2}}};
  s21_4[1] = {4};
  std_4[1] = {4};
  s21_4.at(0) = {5};
  std_4.at(0) = {5};
  EXPECT_TRUE(s21_4[1] == std_4[1]);
  EXPECT_TRUE(s21_4.at(0) == std_4.at(0));
  EXPECT_THROW(s21_4.at(5), std::out_of_range);
}

TEST(ARRAY, Iterators) {
  s21::array<int, 3> s21_1 = {1, 2, 3};
  std::array<int, 3> std_1 = {1, 2, 3};
  EXPECT_TRUE(*s21_1.begin() == *std_1.begin());
  auto it = std_1.end();
  --it;
  EXPECT_TRUE(*(--s21_1.end()) == *it);
  EXPECT_TRUE(*s21_1.cbegin() == *std_1.cbegin());
  auto cit = std_1.cend();
  --cit;
  EXPECT_TRUE(*(--s21_1.cend()) == *cit);
}

TEST(ARRAY, FillSwapEqual) {
  s21::array<int, 3> s21_1 = {1, 2, 3};
  std::array<int, 3> std_1 = {1, 2, 3};
  s21_1.fill(65);
  std_1.fill(65);
  EXPECT_TRUE(s21_1 == std_1);

  s21::array<s21::array<int, 1>, 2> s21_2 = {{1}, {2}};
  std::array<std::array<int, 1>, 2> std_2 = {{{1}, {2}}};
  s21_2.fill({65});
  std_2.fill({65});
  EXPECT_TRUE(s21_2 == std_2);

  s21::array<int, 3> s21_3 = {4, 5, 6};
  std::array<int, 3> std_3 = {4, 5, 6};
  s21_3.swap(s21_1);
  std_3.swap(std_1);
  EXPECT_TRUE(s21_3 == std_3);

  s21::array<s21::array<int, 1>, 2> s21_4 = {{11}, {22}};
  EXPECT_TRUE(s21_1 != s21_3);
  EXPECT_FALSE(s21_1 == s21_3);
  EXPECT_TRUE(s21_2 != s21_4);
  EXPECT_FALSE(s21_2 == s21_4);
}

TEST(ARRAY, ConstructorAssign) {
  s21::array<int, 3> s21_1 = {1, 2, 3};
  std::array<int, 3> std_1 = {1, 2, 3};
  s21::array<int, 3> s21_2(s21_1);
  std::array<int, 3> std_2(std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21::array<int, 3> s21_3 = {4, 5, 6};
  std::array<int, 3> std_3 = {4, 5, 6};
  s21::array<int, 3> s21_4(std::move(s21_3));
  std::array<int, 3> std_4(std::move(std_3));
  EXPECT_TRUE(s21_4 == std_4);

  s21::array<s21::array<int, 1>, 3> s21_5 = {{1}, {2}, {3}};
  std::array<std::array<int, 1>, 3> std_5 = {{{1}, {2}, {3}}};
  s21::array<s21::array<int, 1>, 3> s21_6(s21_5);
  std::array<std::array<int, 1>, 3> std_6(std_5);
  EXPECT_TRUE(s21_6 == std_6);

  s21::array<s21::array<int, 1>, 3> s21_7 = {{1}, {2}, {3}};
  std::array<std::array<int, 1>, 3> std_7 = {{{1}, {2}, {3}}};
  s21::array<s21::array<int, 1>, 3> s21_8(std::move(s21_7));
  std::array<std::array<int, 1>, 3> std_8(std::move(std_7));
  EXPECT_TRUE(s21_8 == std_8);
}

TEST(STACK, All) {
  s21::stack<int, s21::vector<int>> s21_0 = {1, 2};
  EXPECT_TRUE(s21_0.size() == 2);
  EXPECT_FALSE(s21_0.empty());
  EXPECT_TRUE(s21_0.top() == 2);

  s21::stack<int, s21::vector<int>> s21_1;
  std::stack<int, std::vector<int>> std_1;
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());
  for (int k = 0; k < 3; ++k) {
    s21_1.push(k);
    std_1.push(k);
  }
  for (int k = 0; k < 3; ++k) {
    s21_1.push(std::move(k));
    std_1.push(std::move(k));
  }
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.top() == std_1.top());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());
  for (int k = 0; k < 3; ++k) {
    s21_1.pop();
    std_1.pop();
  }
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.top() == std_1.top());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());

  const s21::stack<int, s21::vector<int>> s21_2(s21_1);
  const std::stack<int, std::vector<int>> std_2(std_1);
  EXPECT_TRUE(s21_2.size() == std_2.size());
  EXPECT_TRUE(s21_2.top() == std_2.top());
  EXPECT_TRUE(s21_2.empty() == std_2.empty());

  s21::stack<int, s21::vector<int>> s21_3;
  std::stack<int, std::vector<int>> std_3;
  s21_3 = s21_1;
  std_3 = std_1;
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_TRUE(s21_3.top() == std_3.top());
  EXPECT_TRUE(s21_3.empty() == std_3.empty());
  s21_3.top() = 10;
  std_3.top() = 10;
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_TRUE(s21_3.top() == std_3.top());
  EXPECT_TRUE(s21_3.empty() == std_3.empty());

  s21::stack<int, s21::vector<int>> s21_4;
  std::stack<int, std::vector<int>> std_4;
  s21_4 = std::move(s21_1);
  std_4 = std::move(std_1);
  EXPECT_TRUE(s21_4.size() == std_4.size());
  EXPECT_TRUE(s21_4.top() == std_4.top());
  EXPECT_TRUE(s21_4.empty() == std_4.empty());
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());

  s21::stack<int, s21::vector<int>> s21_5(std::move(s21_4));
  std::stack<int, std::vector<int>> std_5(std::move(std_4));
  EXPECT_TRUE(s21_5.size() == std_5.size());
  EXPECT_TRUE(s21_5.top() == std_5.top());
  EXPECT_TRUE(s21_5.empty() == std_5.empty());

  s21_5.swap(s21_3);
  std_5.swap(std_3);
  EXPECT_TRUE(s21_5.size() == std_5.size());
  EXPECT_TRUE(s21_5.top() == std_5.top());
  EXPECT_TRUE(s21_5.empty() == std_5.empty());
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_TRUE(s21_3.top() == std_3.top());
  EXPECT_TRUE(s21_3.empty() == std_3.empty());

  s21::stack<int, s21::vector<int>> s21_6;
  std::stack<int, std::vector<int>> std_6;
  for (int k = 0; k < 4; ++k) {
    s21_6.push(k);
    std_6.push(k);
  }
  std_6.push(4);
  std_6.push(5);
  std_6.push(5);
  s21_6.insert_many_back(4, 5, 5);
  EXPECT_TRUE(s21_6.size() == std_6.size());
  EXPECT_TRUE(s21_6.top() == s21_6.top());
  EXPECT_TRUE(s21_6.empty() == s21_6.empty());
}

TEST(QUEUE, All) {
  s21::queue<int, s21::list<int>> s21_0 = {1, 2};
  EXPECT_TRUE(s21_0.size() == 2);
  EXPECT_FALSE(s21_0.empty());
  EXPECT_TRUE(s21_0.front() == 1);
  EXPECT_TRUE(s21_0.back() == 2);

  s21::queue<int, s21::list<int>> s21_1;
  std::queue<int, std::list<int>> std_1;
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());
  for (int k = 0; k < 3; ++k) {
    s21_1.push(k);
    std_1.push(k);
  }
  for (int k = 0; k < 3; ++k) {
    s21_1.push(std::move(k));
    std_1.push(std::move(k));
  }
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.front() == std_1.front());
  EXPECT_TRUE(s21_1.back() == std_1.back());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());
  for (int k = 0; k < 3; ++k) {
    s21_1.pop();
    std_1.pop();
  }
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.front() == std_1.front());
  EXPECT_TRUE(s21_1.back() == std_1.back());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());

  const s21::queue<int, s21::list<int>> s21_2(s21_1);
  const std::queue<int, std::list<int>> std_2(std_1);
  EXPECT_TRUE(s21_2.size() == std_2.size());
  EXPECT_TRUE(s21_2.front() == std_2.front());
  EXPECT_TRUE(s21_2.back() == std_2.back());
  EXPECT_TRUE(s21_2.empty() == std_2.empty());

  s21::queue<int, s21::list<int>> s21_3;
  std::queue<int, std::list<int>> std_3;
  s21_3 = s21_1;
  std_3 = std_1;
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_TRUE(s21_3.back() == std_3.back());
  EXPECT_TRUE(s21_3.front() == std_3.front());
  EXPECT_TRUE(s21_3.empty() == std_3.empty());
  s21_3.front() = 10;
  std_3.front() = 10;
  s21_3.back() = 20;
  std_3.back() = 20;
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_TRUE(s21_3.front() == std_3.front());
  EXPECT_TRUE(s21_3.back() == std_3.back());
  EXPECT_TRUE(s21_3.empty() == std_3.empty());

  s21::queue<int, s21::list<int>> s21_4;
  std::queue<int, std::list<int>> std_4;
  s21_4 = std::move(s21_1);
  std_4 = std::move(std_1);
  EXPECT_TRUE(s21_4.size() == std_4.size());
  EXPECT_TRUE(s21_4.front() == std_4.front());
  EXPECT_TRUE(s21_4.back() == std_4.back());
  EXPECT_TRUE(s21_4.empty() == std_4.empty());
  EXPECT_TRUE(s21_1.size() == std_1.size());
  EXPECT_TRUE(s21_1.empty() == std_1.empty());

  s21::queue<int, s21::list<int>> s21_5(std::move(s21_4));
  std::queue<int, std::list<int>> std_5(std::move(std_4));
  EXPECT_TRUE(s21_5.size() == std_5.size());
  EXPECT_TRUE(s21_5.front() == std_5.front());
  EXPECT_TRUE(s21_5.back() == std_5.back());
  EXPECT_TRUE(s21_5.empty() == std_5.empty());

  s21_5.swap(s21_3);
  std_5.swap(std_3);
  EXPECT_TRUE(s21_5.size() == std_5.size());
  EXPECT_TRUE(s21_5.front() == std_5.front());
  EXPECT_TRUE(s21_5.back() == std_5.back());
  EXPECT_TRUE(s21_5.empty() == std_5.empty());
  EXPECT_TRUE(s21_3.size() == std_3.size());
  EXPECT_TRUE(s21_3.front() == std_3.front());
  EXPECT_TRUE(s21_3.back() == std_3.back());
  EXPECT_TRUE(s21_3.empty() == std_3.empty());

  s21::queue<int, s21::list<int>> s21_6;
  std::queue<int, std::list<int>> std_6;
  for (int k = 0; k < 4; ++k) {
    s21_6.push(k);
    std_6.push(k);
  }
  std_6.push(4);
  std_6.push(5);
  std_6.push(5);
  s21_6.insert_many_back(4, 5, 5);
  EXPECT_TRUE(s21_6.size() == std_6.size());
  EXPECT_TRUE(s21_6.empty() == s21_6.empty());
  EXPECT_TRUE(s21_6.front() == s21_6.front());
  EXPECT_TRUE(s21_6.back() == s21_6.back());
}

TEST(LIST, Constructors) {
  s21::list<int> s21_1;
  std::list<int> std_1;
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<int> s21_2 = {};
  std::list<int> std_2 = {};
  EXPECT_TRUE(s21_2 == std_2);

  s21::list<int> s21_3 = {1, 2, 3};
  std::list<int> std_3 = {1, 2, 3};
  EXPECT_TRUE(s21_3 == std_3);

  s21::list<int> s21_4(s21_3);
  std::list<int> std_4(std_3);
  EXPECT_TRUE(s21_4 == std_4);

  s21::list<int> s21_5 = s21_3;
  std::list<int> std_5 = std_3;
  EXPECT_TRUE(s21_5 == std_5);

  s21::list<int> s21_6 = std::move(s21_3);
  std::list<int> std_6 = std::move(std_3);
  EXPECT_TRUE(s21_6 == std_6);
  EXPECT_TRUE(s21_3 == std_3);

  s21::list<int> s21_7 = {1, 2, 3};
  std::list<int> std_7 = {1, 2, 3};
  s21::list<int> s21_8(std::move(s21_7));
  std::list<int> std_8(std::move(std_7));
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::list<int> s21_9({1, 2, 3});
  std::list<int> std_9({1, 2, 3});
  EXPECT_TRUE(s21_9 == std_9);

  s21::list<s21::list<int>> s21_10;
  std::list<std::list<int>> std_10;
  EXPECT_TRUE(s21_10 == std_10);

  s21::list<s21::list<int>> s21_11 = {};
  std::list<std::list<int>> std_11 = {};
  EXPECT_TRUE(s21_11 == std_11);

  s21::list<s21::list<int>> s21_12 = {{1, 2}, {1, 3}};
  std::list<std::list<int>> std_12 = {{1, 2}, {1, 3}};
  EXPECT_TRUE(s21_12 == std_12);

  s21::list<s21::list<int>> s21_13(s21_12);
  std::list<std::list<int>> std_13(std_12);
  EXPECT_TRUE(s21_13 == std_13);

  s21::list<s21::list<int>> s21_14(s21_12);
  std::list<std::list<int>> std_14(std_12);
  EXPECT_TRUE(s21_14 == std_14);

  s21::list<s21::list<int>> s21_15 = std::move(s21_12);
  std::list<std::list<int>> std_15 = std::move(std_12);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_12 == std_12);

  s21::list<s21::list<int>> s21_16 = {{1, 2}, {1, 3}};
  std::list<std::list<int>> std_16 = {{1, 2}, {1, 3}};
  s21::list<s21::list<int>> s21_17(std::move(s21_16));
  std::list<std::list<int>> std_17(std::move(std_16));
  EXPECT_TRUE(s21_16 == std_16);
  EXPECT_TRUE(s21_17 == std_17);

  s21::list<s21::list<int>> s21_18({{1, 2}, {1, 3}});
  std::list<std::list<int>> std_18({{1, 2}, {1, 3}});
  EXPECT_TRUE(s21_18 == std_18);
}

TEST(LIST, FrontBack) {
  const s21::list<int> s21_1 = {1, 2, 3};
  const std::list<int> std_1 = {1, 2, 3};
  EXPECT_TRUE(s21_1.front() == std_1.front());
  EXPECT_TRUE(s21_1.back() == std_1.back());

  s21::list<int> s21_2 = {1, 2, 3};
  std::list<int> std_2 = {1, 2, 3};
  s21_2.front() = 5;
  s21_2.back() = 6;
  std_2.front() = 5;
  std_2.back() = 6;
  EXPECT_TRUE(s21_2 == std_2);

  const s21::list<s21::list<int>> s21_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const std::list<std::list<int>> std_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  EXPECT_TRUE(s21_3.front() == std_3.front());
  EXPECT_TRUE(s21_3.back() == std_3.back());

  s21::list<s21::list<int>> s21_4 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::list<std::list<int>> std_4 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s21_4.front() = {1, 2};
  s21_4.back() = {3, 4};
  std_4.front() = {1, 2};
  std_4.back() = {3, 4};
  EXPECT_TRUE(s21_4 == std_4);
}

TEST(LIST, Empty) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  EXPECT_TRUE(s21_1.empty() == std_1.empty());

  s21::list<int> s21_2;
  std::list<int> std_2;
  EXPECT_TRUE(s21_2.empty() == std_2.empty());

  s21::list<s21::list<int>> s21_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::list<std::list<int>> std_3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  EXPECT_TRUE(s21_3.empty() == std_3.empty());

  s21::list<s21::list<int>> s21_4;
  std::list<std::list<int>> std_4;
  EXPECT_TRUE(s21_4.empty() == std_4.empty());
}

TEST(LIST, Insert) {
  s21::list<int> s21_1 = {1, 2, 3, 4, 5};
  std::list<int> std_1 = {1, 2, 3, 4, 5};
  auto s21_it_1 = s21_1.cbegin();
  auto std_it_1 = std_1.cbegin();
  auto s21_it_2 = s21_1.insert(s21_it_1, 9);
  auto std_it_2 = std_1.insert(std_it_1, 9);
  EXPECT_TRUE(*s21_it_2 == *std_it_2);
  for (int k = 0; k < 2; ++k) {
    ++s21_it_1;
    ++std_it_1;
  }
  const int y = 8;
  auto s21_it_3 = s21_1.insert(s21_it_1, y);
  auto std_it_3 = std_1.insert(std_it_1, y);
  EXPECT_TRUE(*s21_it_3 == *std_it_3);
  s21_it_1 = s21_1.cend();
  std_it_1 = std_1.cend();
  const int x = 7;
  auto s21_it_4 = s21_1.insert(s21_it_1, x);
  auto std_it_4 = std_1.insert(std_it_1, x);
  EXPECT_TRUE(*s21_it_4 == *std_it_4);
  EXPECT_TRUE(s21_1 == std_1);
  auto s21_it_9 = s21_1.insert(s21_it_1, 2, 11);
  auto std_it_9 = std_1.insert(std_it_1, 2, 11);
  EXPECT_TRUE(*s21_it_9 == *std_it_9);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::list<std::list<int>> std_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto s21_it_5 = s21_2.cbegin();
  auto std_it_5 = std_2.cbegin();
  const s21::list<int> s21_3 = {4, 5};
  const std::list<int> std_3 = {4, 5};
  auto s21_it_6 = s21_2.insert(s21_it_5, s21_3);
  auto std_it_6 = std_2.insert(std_it_5, std_3);
  EXPECT_TRUE(*s21_it_6 == *std_it_6);
  for (int k = 0; k < 2; ++k) {
    ++s21_it_5;
    ++std_it_5;
  }
  auto s21_it_7 = s21_2.insert(s21_it_5, {1, 2});
  auto std_it_7 = std_2.insert(std_it_5, {1, 2});
  EXPECT_TRUE(*s21_it_7 == *std_it_7);
  s21_it_5 = s21_2.cend();
  std_it_5 = std_2.cend();
  auto s21_it_8 = s21_2.insert(s21_it_5, {3, 4});
  auto std_it_8 = std_2.insert(std_it_5, {3, 4});
  EXPECT_TRUE(*s21_it_8 == *std_it_8);
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, OperatorEq) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21::list<int> s21_2 = {4, 5, 6, 7};
  std::list<int> std_2 = {4, 5, 6, 7};
  s21_1 = s21_2;
  std_1 = std_2;
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<int> s21_3 = {1, 2, 3};
  std::list<int> std_3 = {1, 2, 3};
  s21::list<int> s21_4 = {4, 5, 6, 7};
  std::list<int> std_4 = {4, 5, 6, 7};
  s21_3 = std::move(s21_4);
  std_3 = std::move(std_4);
  EXPECT_TRUE(s21_3 == std_3);
  EXPECT_TRUE(s21_4 == std_4);

  s21::list<int> s21_5 = {1, 2, 3};
  std::list<int> std_5 = {1, 2, 3};
  s21::list<int> s21_6 = {};
  std::list<int> std_6 = {};
  s21_5 = s21_6;
  std_5 = std_6;
  EXPECT_TRUE(s21_5 == std_5);

  s21::list<int> s21_7 = {1, 2, 3};
  std::list<int> std_7 = {1, 2, 3};
  s21::list<int> s21_8 = {};
  std::list<int> std_8 = {};
  s21_7 = std::move(s21_8);
  std_7 = std::move(std_8);
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::list<int> s21_9 = {};
  std::list<int> std_9 = {};
  s21::list<int> s21_10 = {4, 5, 6, 7};
  std::list<int> std_10 = {4, 5, 6, 7};
  s21_9 = s21_10;
  std_9 = std_10;
  EXPECT_TRUE(s21_9 == std_9);

  s21::list<int> s21_11 = {};
  std::list<int> std_11 = {};
  s21::list<int> s21_12 = {4, 5, 6, 7};
  std::list<int> std_12 = {4, 5, 6, 7};
  s21_11 = std::move(s21_12);
  std_11 = std::move(std_12);
  EXPECT_TRUE(s21_11 == std_11);
  EXPECT_TRUE(s21_12 == std_12);

  s21::list<int> s21_13 = {};
  std::list<int> std_13 = {};
  s21::list<int> s21_14 = {};
  std::list<int> std_14 = {};
  s21_13 = s21_14;
  std_13 = std_14;
  EXPECT_TRUE(s21_13 == std_13);

  s21::list<int> s21_15 = {};
  std::list<int> std_15 = {};
  s21::list<int> s21_16 = {};
  std::list<int> std_16 = {};
  s21_15 = std::move(s21_16);
  std_15 = std::move(std_16);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_16 == std_16);

  s21::list<s21::list<int>> s21_17 = {{1}, {2}, {3}};
  std::list<std::list<int>> std_17 = {{1}, {2}, {3}};
  s21::list<s21::list<int>> s21_18 = {{1}, {2}, {3}, {4}};
  std::list<std::list<int>> std_18 = {{1}, {2}, {3}, {4}};
  s21_17 = s21_18;
  std_17 = std_18;
  EXPECT_TRUE(s21_17 == std_17);
}

TEST(LIST, Erase) {
  s21::list<int> s21_1 = {1, 2, 3, 4, 5, 6, 7};
  std::list<int> std_1 = {1, 2, 3, 4, 5, 6, 7};
  auto s21_it_1 = s21_1.cbegin();
  auto std_it_1 = std_1.cbegin();
  auto s21_it_2 = s21_1.erase(s21_it_1);
  auto std_it_2 = std_1.erase(std_it_1);
  EXPECT_TRUE(*s21_it_2 == *std_it_2);
  for (int k = 0; k < 2; ++k) {
    ++s21_it_2;
    ++std_it_2;
  }
  auto s21_it_3 = s21_1.erase(s21_it_2);
  auto std_it_3 = std_1.erase(std_it_2);
  EXPECT_TRUE(*s21_it_3 == *std_it_3);
  s21_it_1 = --s21_1.cend();
  std_it_1 = --std_1.cend();
  auto s21_it_4 = s21_1.erase(s21_it_1);
  auto std_it_4 = std_1.erase(std_it_1);
  EXPECT_TRUE(*s21_it_4 == *std_it_4);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1, 2}, {3, 4},  {5, 6},
                                     {7, 8}, {9, 10}, {11, 12}};
  std::list<std::list<int>> std_2 = {{1, 2}, {3, 4},  {5, 6},
                                     {7, 8}, {9, 10}, {11, 12}};
  auto s21_it_5 = s21_2.cbegin();
  auto std_it_5 = std_2.cbegin();
  auto s21_it_6 = s21_2.erase(s21_it_5);
  auto std_it_6 = std_2.erase(std_it_5);
  EXPECT_TRUE(*s21_it_6 == *std_it_6);
  for (int k = 0; k < 2; ++k) {
    ++s21_it_6;
    ++std_it_6;
  }
  auto s21_it_7 = s21_2.erase(s21_it_6);
  auto std_it_7 = std_2.erase(std_it_6);
  EXPECT_TRUE(*s21_it_7 == *std_it_7);
  s21_it_5 = --s21_2.cend();
  std_it_5 = --std_2.cend();
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {1, 2, 3, 4, 5, 6, 7};
  std_1 = {1, 2, 3, 4, 5, 6, 7};
  auto s21_it_8 = s21_1.cbegin();
  auto std_it_8 = std_1.cbegin();
  auto s21_it_9 = s21_1.cbegin();
  auto std_it_9 = std_1.cbegin();
  for (int k = 0; k < 5; ++k) {
    ++s21_it_9;
    ++std_it_9;
    ++s21_it_8;
    ++std_it_8;
  }
  s21_it_9 = s21_1.erase(s21_it_8, s21_it_9);
  std_it_9 = std_1.erase(std_it_8, std_it_9);
  EXPECT_TRUE(*s21_it_9 == *std_it_9);
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(LIST, PushPop) {
  s21::list<int> s21_1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_1 = {1, 2, 3, 4, 5, 6, 7, 8};
  s21_1.push_front(2);
  std_1.push_front(2);
  EXPECT_TRUE(s21_1 == std_1);
  const int x = 9;
  const int y = 9;
  s21_1.push_front(x);
  std_1.push_front(y);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.push_back(3);
  std_1.push_back(3);
  EXPECT_TRUE(s21_1 == std_1);
  const int m = 5;
  const int n = 5;
  s21_1.push_front(m);
  std_1.push_front(n);
  EXPECT_TRUE(s21_1 == std_1);
  for (size_t k = 0; k < s21_1.size() / 2; ++k) {
    s21_1.pop_back();
    std_1.pop_back();
    s21_1.pop_front();
    std_1.pop_front();
  }
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1}, {2, 3}, {3, 4, 5},
                                     {0}, {-2},   {2, 55}};
  std::list<std::list<int>> std_2 = {{1}, {2, 3}, {3, 4, 5},
                                     {0}, {-2},   {2, 55}};
  s21_2.push_front({1, 2});
  std_2.push_front({1, 2});
  EXPECT_TRUE(s21_2 == std_2);
  const s21::list<int> p = {9};
  const std::list<int> o = {9};
  s21_2.push_front(p);
  std_2.push_front(o);
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.push_back({8, 9});
  std_2.push_back({8, 9});
  EXPECT_TRUE(s21_2 == std_2);
  const s21::list<int> s = {5};
  const std::list<int> r = {5};
  s21_2.push_front(s);
  std_2.push_front(r);
  EXPECT_TRUE(s21_2 == std_2);
  for (size_t k = 0; k < s21_2.size() / 2; ++k) {
    s21_2.pop_back();
    std_2.pop_back();
    s21_2.pop_front();
    std_2.pop_front();
  }
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, Swap) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21::list<int> s21_2 = {4, 5, 6, 7};
  std::list<int> std_2 = {4, 5, 6, 7};
  s21_1.swap(s21_2);
  std_1.swap(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21::list<int> s21_5 = {1, 2, 3};
  std::list<int> std_5 = {1, 2, 3};
  s21::list<int> s21_6 = {};
  std::list<int> std_6 = {};
  s21_5.swap(s21_6);
  std_5.swap(std_6);
  EXPECT_TRUE(s21_5 == std_5);
  EXPECT_TRUE(s21_6 == std_6);

  s21::list<int> s21_9 = {};
  std::list<int> std_9 = {};
  s21::list<int> s21_10 = {4, 5, 6, 7};
  std::list<int> std_10 = {4, 5, 6, 7};
  s21_9.swap(s21_10);
  std_9.swap(std_10);
  EXPECT_TRUE(s21_9 == std_9);
  EXPECT_TRUE(s21_10 == std_10);

  s21::list<int> s21_13 = {};
  std::list<int> std_13 = {};
  s21::list<int> s21_14 = {};
  std::list<int> std_14 = {};
  s21_13.swap(s21_14);
  std_13.swap(std_14);
  EXPECT_TRUE(s21_13 == std_13);
  EXPECT_TRUE(s21_14 == std_14);

  s21::list<s21::list<int>> s21_17 = {{1}, {2}, {3}};
  std::list<std::list<int>> std_17 = {{1}, {2}, {3}};
  s21::list<s21::list<int>> s21_18 = {{1}, {2}, {3}, {4}};
  std::list<std::list<int>> std_18 = {{1}, {2}, {3}, {4}};
  s21_17.swap(s21_18);
  std_17.swap(std_18);
  EXPECT_TRUE(s21_17 == std_17);
  EXPECT_TRUE(s21_18 == std_18);

  s21::list<s21::list<int>> s21_19 = {};
  std::list<std::list<int>> std_19 = {};
  s21::list<s21::list<int>> s21_20 = {};
  std::list<std::list<int>> std_20 = {};
  s21_19.swap(s21_20);
  std_19.swap(std_20);
  EXPECT_TRUE(s21_19 == std_19);
  EXPECT_TRUE(std_20 == std_20);
}

TEST(LIST, Resize) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21_1.resize(s21_1.size());
  std_1.resize(std_1.size());
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(5, 7);
  std_1.resize(5, 7);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(2, 2);
  std_1.resize(2, 2);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(0, 3);
  std_1.resize(0, 3);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(0, 4);
  std_1.resize(0, 4);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.resize(10);
  std_1.resize(10);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1}, {2}, {3}, {4}};
  std::list<std::list<int>> std_2 = {{1}, {2}, {3}, {4}};
  s21_2.resize(s21_2.size());
  std_2.resize(std_2.size());
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(5, {7});
  std_2.resize(5, {7});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(2, {2});
  std_2.resize(2, {2});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(0, {3});
  std_2.resize(0, {3});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(0, {4});
  std_2.resize(0, {4});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.resize(10);
  std_2.resize(10);
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, Reverse) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21_1.reverse();
  std_1.reverse();
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {};
  std_1 = {};
  s21_1.reverse();
  std_1.reverse();
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {1};
  std_1 = {1};
  s21_1.reverse();
  std_1.reverse();
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1}, {2}, {3}, {4}};
  std::list<std::list<int>> std_2 = {{1}, {2}, {3}, {4}};
  s21_2.reverse();
  std_2.reverse();
  EXPECT_TRUE(s21_2 == std_2);
  s21_2 = {};
  std_2 = {};
  s21_2.reverse();
  std_2.reverse();
  EXPECT_TRUE(s21_2 == std_2);
  s21_2 = {{1}};
  std_2 = {{1}};
  s21_2.reverse();
  std_2.reverse();
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, Remove) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21_1.remove(4);
  std_1.remove(4);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1.remove(2);
  std_1.remove(2);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {};
  std_1 = {};
  s21_1.remove(4);
  std_1.remove(4);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {1, 1, 1, 2, 1, 3, 1, 1, 5};
  std_1 = {1, 1, 1, 2, 1, 3, 1, 1, 5};
  s21_1.remove(1);
  std_1.remove(1);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1}, {2}, {3}};
  std::list<std::list<int>> std_2 = {{1}, {2}, {3}};
  s21_2.remove({4});
  std_2.remove({4});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2.remove({2});
  std_2.remove({2});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2 = {};
  std_2 = {};
  s21_2.remove({4});
  std_2.remove({4});
  EXPECT_TRUE(s21_2 == std_2);
  s21_2 = {{1}, {1}, {1}, {2}, {1}, {3}, {1}, {1}, {5}};
  std_2 = {{1}, {1}, {1}, {2}, {1}, {3}, {1}, {1}, {5}};
  s21_2.remove({1});
  std_2.remove({1});
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, Unique) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21_1.unique();
  std_1.unique();
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {};
  std_1 = {};
  s21_1.unique();
  std_1.unique();
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {1, 2, 2, 3, 3, 2, 1, 1, 2};
  std_1 = {1, 2, 2, 3, 3, 2, 1, 1, 2};
  s21_1.unique();
  std_1.unique();
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<s21::list<int>> s21_2 = {{1}, {2}, {3}};
  std::list<std::list<int>> std_2 = {{1}, {2}, {3}};
  s21_2.unique();
  std_2.unique();
  EXPECT_TRUE(s21_2 == std_2);
  s21_2 = {};
  std_2 = {};
  s21_2.unique();
  std_2.unique();
  EXPECT_TRUE(s21_2 == std_2);
  s21_2 = {{1}, {2}, {2}, {3}, {3}, {2}, {1}, {1}, {2}, {2}};
  std_2 = {{1}, {2}, {2}, {3}, {3}, {2}, {1}, {1}, {2}, {2}};
  s21_2.unique();
  std_2.unique();
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, Splice_First) {
  s21::list<int> s21_1 = {1, 2, 3};
  std::list<int> std_1 = {1, 2, 3};
  s21::list<int> s21_2 = {4, 5, 6};
  std::list<int> std_2 = {4, 5, 6};
  s21_1.splice(s21_1.cbegin(), s21_2);
  std_1.splice(std_1.cbegin(), std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21::list<int> s21_3 = {1, 2, 3};
  std::list<int> std_3 = {1, 2, 3};
  s21_1.splice(++s21_1.cbegin(), std::move(s21_3));
  std_1.splice(++std_1.cbegin(), std::move(std_3));
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_3 == std_3);

  s21::list<int> s21_4 = {1, 2, 3};
  std::list<int> std_4 = {1, 2, 3};
  s21_1.splice(s21_1.cend(), s21_4);
  std_1.splice(std_1.cend(), std_4);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_4 == std_4);

  s21::list<int> s21_5;
  std::list<int> std_5;
  s21_1.splice(s21_1.cend(), s21_5);
  std_1.splice(std_1.cend(), std_5);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_5 == std_5);

  s21::list<int> s21_6;
  std::list<int> std_6;
  s21_6.splice(s21_1.cend(), s21_5);
  std_6.splice(std_1.cend(), std_5);
  EXPECT_TRUE(s21_6 == std_6);
  EXPECT_TRUE(s21_5 == std_5);
}

/*TEST(LIST, Splice_Second) {
  s21::list<int> s21_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto s21_first_1 = s21_1.cbegin();
  auto std_first_1 = std_1.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_first_1;
    ++std_first_1;
  }
      s21_1.splice(s21_1.cbegin(), s21_1, s21_first_1);
      std_1.splice(std_1.cbegin(), std_1, std_first_1);
      EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_first_1 = s21_1.cbegin();
  std_first_1 = std_1.cbegin();
  s21_1.splice(s21_1.cend(), s21_1, s21_first_1);
  std_1.splice(std_1.cend(), std_1, std_first_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_first_1 = s21_1.cbegin();
  std_first_1 = std_1.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_first_1;
    ++std_first_1;
  }
  s21_1.splice(s21_1.cend(), s21_1, s21_first_1);
  std_1.splice(std_1.cend(), std_1, std_first_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<int> s21_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::list<int> s21_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto s21_first_2 = s21_3.cbegin();
  auto std_first_2 = std_3.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_first_2;
    ++std_first_2;
  }
  s21_2.splice(s21_2.cbegin(), std::move(s21_3), s21_first_2);
  std_2.splice(std_2.cbegin(), std::move(std_3), std_first_2);
  EXPECT_TRUE(s21_2 == std_2);
  EXPECT_TRUE(s21_3 == std_3);

  s21_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_first_2 = s21_3.cbegin();
  std_first_2 = std_3.cbegin();
  s21_2.splice(s21_2.cend(), s21_3, s21_first_2);
  std_2.splice(std_2.cend(), std_3, std_first_2);
  EXPECT_TRUE(s21_2 == std_2);
  EXPECT_TRUE(s21_3 == std_3);
}*/

TEST(LIST, Splice_Third) {
  s21::list<int> s21_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto s21_first_1 = s21_1.cbegin();
  auto std_first_1 = std_1.cbegin();
  auto s21_last_1 = s21_1.cbegin();
  auto std_last_1 = std_1.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_last_1;
    ++std_last_1;

    if (i < 2) {
      ++s21_first_1;
      ++std_first_1;
    }
  }
  s21_1.splice(s21_1.cbegin(), s21_1, s21_first_1, s21_last_1);
  std_1.splice(std_1.cbegin(), std_1, std_first_1, std_last_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_first_1 = s21_1.cbegin();
  std_first_1 = std_1.cbegin();
  s21_last_1 = s21_1.cend();
  std_last_1 = std_1.cend();
  s21_1.splice(s21_1.cend(), s21_1, s21_first_1, s21_last_1);
  std_1.splice(std_1.cend(), std_1, std_first_1, std_last_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_first_1 = s21_1.cbegin();
  std_first_1 = std_1.cbegin();
  s21_last_1 = s21_1.cbegin();
  std_last_1 = std_1.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_last_1;
    ++std_last_1;

    if (i < 2) {
      ++s21_first_1;
      ++std_first_1;
    }
  }
  s21_1.splice(s21_1.cend(), s21_1, s21_first_1, s21_last_1);
  std_1.splice(std_1.cend(), std_1, std_first_1, std_last_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<int> s21_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::list<int> s21_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto s21_first_2 = s21_3.cbegin();
  auto std_first_2 = std_3.cbegin();
  auto s21_last_2 = s21_3.cbegin();
  auto std_last_2 = std_3.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_last_2;
    ++std_last_2;

    if (i < 2) {
      ++s21_first_2;
      ++std_first_2;
    }
  }
  s21_2.splice(s21_2.cbegin(), std::move(s21_3), s21_first_2, s21_last_2);
  std_2.splice(std_2.cbegin(), std::move(std_3), std_first_2, std_last_2);
  EXPECT_TRUE(s21_2 == std_2);
  EXPECT_TRUE(s21_3 == std_3);

  s21_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_first_2 = s21_3.cbegin();
  std_first_2 = std_3.cbegin();
  s21_last_2 = s21_3.cend();
  std_last_2 = std_3.cend();
  s21_2.splice(s21_2.cend(), s21_3, s21_first_2, s21_last_2);
  std_2.splice(std_2.cend(), std_3, std_first_2, std_last_2);
  EXPECT_TRUE(s21_2 == std_2);
  EXPECT_TRUE(s21_3 == std_3);
}

TEST(LIST, Merge) {
  s21::list<int> s21_1;
  std::list<int> std_1;
  s21::list<int> s21_2 = {1, 2, 3};
  std::list<int> std_2 = {1, 2, 3};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21::list<int> s21_3;
  std::list<int> std_3;
  s21_3.merge(s21_2);
  std_3.merge(std_2);
  EXPECT_TRUE(s21_3 == std_3);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {1, 3, 3, 5, 9};
  std_1 = {1, 3, 3, 5, 9};
  s21_2 = {-10, -3, 2, 3, 4, 4, 7, 8, 10, 20};
  std_2 = {-10, -3, 2, 3, 4, 4, 7, 8, 10, 20};
  s21_1.merge(std::move(s21_2));
  std_1.merge(std::move(std_2));
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(LIST, Sort) {
  s21::list<int> s21_1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::list<int> std_1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  s21_1.sort();
  std_1.sort();
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {2, 1};
  std_1 = {2, 1};
  s21_1.sort();
  std_1.sort();
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1};
  std_1 = {1};
  s21_1.sort();
  std_1.sort();
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {};
  std_1 = {};
  s21_1.sort();
  std_1.sort();
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(LIST, InsertMany) {
  s21::list<int> s21_1 = {1, 2, 3, 0, 1, 2};
  std::list<int> std_1 = {1, 2, 3, 0, 1, 2, 4, 5, 5};
  s21_1.insert_many_back(4, 5, 5);
  EXPECT_TRUE(s21_1 == std_1);

  s21::list<int> s21_2 = {1, 2, 3, 0, 1, 2};
  std::list<int> std_2 = {5, 5, 4, 1, 2, 3, 0, 1, 2};
  s21_2.insert_many_front(4, 5, 5);
  EXPECT_TRUE(s21_2 == std_2);

  s21::list<int> s21_3 = {1, 2, 3, 0, 1, 2};
  std::list<int> std_3 = {5, 5, 4, 1, 2, 3, 0, 1, 2};
  s21_3.insert_many(s21_3.cbegin(), 4, 5, 5);
  EXPECT_TRUE(s21_2 == std_2);
}

TEST(MAP, Constructors) {
  s21::map<int, int> s21_1;
  std::map<int, int> std_1;
  EXPECT_TRUE(s21_1 == std_1);

  s21::map<int, int> s21_2 = {};
  std::map<int, int> std_2 = {};
  EXPECT_TRUE(s21_2 == std_2);

  s21::map<int, int> s21_3 = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_3 = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_TRUE(s21_3 == std_3);

  s21::map<int, int> s21_4(s21_3);
  std::map<int, int> std_4(std_3);
  EXPECT_TRUE(s21_4 == std_4);

  s21::map<int, int> s21_5 = s21_3;
  std::map<int, int> std_5 = std_3;
  EXPECT_TRUE(s21_5 == std_5);

  s21::map<int, int> s21_6 = std::move(s21_3);
  std::map<int, int> std_6 = std::move(std_3);
  EXPECT_TRUE(s21_6 == std_6);
  EXPECT_TRUE(s21_3 == std_3);

  s21::map<int, int> s21_7 = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_7 = {{1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> s21_8(std::move(s21_7));
  std::map<int, int> std_8(std::move(std_7));
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::map<int, int> s21_9({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_9({{1, 1}, {2, 2}, {3, 3}});
  EXPECT_TRUE(s21_9 == std_9);

  s21::map<std::list<int>, std::string> s21_10;
  std::map<std::list<int>, std::string> std_10;
  EXPECT_TRUE(s21_10 == std_10);

  s21::map<std::list<int>, std::string> s21_11 = {};
  std::map<std::list<int>, std::string> std_11 = {};
  EXPECT_TRUE(s21_11 == std_11);

  s21::map<std::string, std::list<int>> s21_12 = {
      {"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}};
  std::map<std::string, std::list<int>> std_12 = {
      {"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}};
  EXPECT_TRUE(s21_12 == std_12);

  s21::map<std::string, std::list<int>> s21_13(s21_12);
  std::map<std::string, std::list<int>> std_13(std_12);
  EXPECT_TRUE(s21_13 == std_13);

  s21::map<std::string, std::list<int>> s21_14 = s21_13;
  std::map<std::string, std::list<int>> std_14 = std_13;
  EXPECT_TRUE(s21_14 == std_14);

  s21::map<std::string, std::list<int>> s21_15 = std::move(s21_12);
  std::map<std::string, std::list<int>> std_15 = std::move(std_12);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_12 == std_12);

  s21::map<std::string, std::list<int>> s21_16 = {
      {"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}};
  std::map<std::string, std::list<int>> std_16 = {
      {"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}};
  s21::map<std::string, std::list<int>> s21_17(std::move(s21_16));
  std::map<std::string, std::list<int>> std_17(std::move(std_16));
  EXPECT_TRUE(s21_16 == std_16);
  EXPECT_TRUE(s21_17 == std_17);

  s21::map<std::string, std::list<int>> s21_18(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  std::map<std::string, std::list<int>> std_18(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  EXPECT_TRUE(s21_18 == std_18);
}

TEST(MAP, OperatorEq) {
  s21::map<int, int> s21_1 = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_1 = {{1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> s21_2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21_1 = s21_2;
  std_1 = std_2;
  EXPECT_TRUE(s21_1 == std_1);
  s21::map<int, int> &s21_1_1 = s21_1;
  std::map<int, int> &std_1_1 = std_1;
  s21_1_1 = s21_1;
  std_1_1 = std_1;
  EXPECT_TRUE(s21_1_1 == std_1_1);

  s21::map<int, int> s21_3 = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_3 = {{1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> s21_4 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  std::map<int, int> std_4 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21_3 = std::move(s21_4);
  std_3 = std::move(std_4);
  EXPECT_TRUE(s21_3 == std_3);
  EXPECT_TRUE(s21_4 == std_4);
  s21::map<int, int> &s21_3_1 = s21_3;
  std::map<int, int> &std_3_1 = std_3;
  s21_3_1 = s21_3;
  std_3_1 = std_3;
  EXPECT_TRUE(s21_3_1 == std_3_1);

  s21::map<int, int> &s21_3_2 = s21_3_1;
  std::map<int, int> &std_3_2 = std_3_1;
  s21_3_2 = std::move(s21_3_1);
  std_3_2 = std::move(std_3_1);
  EXPECT_TRUE(s21_3_2 == std_3_2);

  s21::map<int, int> s21_5 = {{1, 1}, {2, 2}, {3, 3}, {3, 3}};
  std::map<int, int> std_5 = {{1, 1}, {2, 2}, {3, 3}, {3, 3}};
  s21::map<int, int> s21_6 = {};
  std::map<int, int> std_6 = {};
  s21_5 = s21_6;
  std_5 = std_6;
  EXPECT_TRUE(s21_5 == std_5);

  s21::map<int, int> s21_7 = {{1, 1}, {2, 2}, {3, 3}};
  std::map<int, int> std_7 = {{1, 1}, {2, 2}, {3, 3}};
  s21::map<int, int> s21_8 = {};
  std::map<int, int> std_8 = {};
  s21_7 = std::move(s21_8);
  std_7 = std::move(std_8);
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::map<int, int> s21_9 = {};
  std::map<int, int> std_9 = {};
  s21::map<int, int> s21_10 = {{4, 4}, {5, 5}, {6, 6}, {7, 7}};
  std::map<int, int> std_10 = {{4, 4}, {5, 5}, {6, 6}, {7, 7}};
  s21_9 = s21_10;
  std_9 = std_10;
  EXPECT_TRUE(s21_9 == std_9);

  s21::map<int, int> s21_11 = {};
  std::map<int, int> std_11 = {};
  s21::map<int, int> s21_12 = {{4, 4}, {5, 5}, {6, 6}, {7, 7}};
  std::map<int, int> std_12 = {{4, 4}, {5, 5}, {6, 6}, {7, 7}};
  s21_11 = std::move(s21_12);
  std_11 = std::move(std_12);
  EXPECT_TRUE(s21_11 == std_11);
  EXPECT_TRUE(s21_12 == std_12);

  s21::map<int, int> s21_13 = {};
  std::map<int, int> std_13 = {};
  s21::map<int, int> s21_14 = {};
  std::map<int, int> std_14 = {};
  s21_13 = s21_14;
  std_13 = std_14;
  EXPECT_TRUE(s21_13 == std_13);

  s21::map<int, int> s21_15 = {};
  std::map<int, int> std_15 = {};
  s21::map<int, int> s21_16 = {};
  std::map<int, int> std_16 = {};
  s21_15 = std::move(s21_16);
  std_15 = std::move(std_16);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_16 == std_16);

  s21::map<std::string, std::list<int>> s21_17(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  std::map<std::string, std::list<int>> std_17(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  s21::map<std::string, std::list<int>> s21_18(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}, {"cc", {1, 5}}});
  std::map<std::string, std::list<int>> std_18(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}, {"cc", {1, 5}}});
  s21_17 = s21_18;
  std_17 = std_18;
  EXPECT_TRUE(s21_17 == std_17);

  s21::map<int, int> s21_19;
  std::map<int, int> std_19;
  s21_19 = {{4, 4}, {5, 5}, {6, 6}, {7, 7}};
  std_19 = {{4, 4}, {5, 5}, {6, 6}, {7, 7}};
  EXPECT_TRUE(s21_19 == std_19);
  s21_19 = {};
  std_19 = {};
  EXPECT_TRUE(s21_19 == std_19);
}

TEST(MAP, AtOperatorBracketsInsertOrAssign) {
  s21::map<int, int> s21_1 = {{1, 11}, {2, 22}, {3, 33}};
  std::map<int, int> std_1 = {{1, 11}, {2, 22}, {3, 33}};
  EXPECT_TRUE(s21_1.at(1) == std_1.at(1));
  EXPECT_THROW(s21_1.at(-2), std::out_of_range);
  s21_1.at(2) = 55;
  std_1.at(2) = 55;
  EXPECT_TRUE(s21_1 == std_1);

  const s21::map<int, int> s21_2 = {{1, 11}, {2, 22}, {3, 33}};
  const std::map<int, int> std_2 = {{1, 11}, {2, 22}, {3, 33}};
  EXPECT_TRUE(s21_2.at(1) == std_2.at(1));
  EXPECT_THROW(s21_2.at(-2), std::out_of_range);

  s21::map<std::string, std::list<int>> s21_3(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  std::map<std::string, std::list<int>> std_3(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  EXPECT_TRUE(s21_3.at("bb") == std_3.at("bb"));
  EXPECT_THROW(s21_3.at("accc"), std::out_of_range);
  s21_3.at("ba") = {1};
  std_3.at("ba") = {1};
  EXPECT_TRUE(s21_3 == std_3);

  const s21::map<std::string, std::list<int>> s21_4(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  const std::map<std::string, std::list<int>> std_4(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  EXPECT_TRUE(s21_4.at("aa") == std_4.at("aa"));
  EXPECT_THROW(s21_4.at("z"), std::out_of_range);

  s21::map<int, int> s21_5 = {{0, 11}, {2, 22}, {3, 33}};
  std::map<int, int> std_5 = {{0, 11}, {2, 22}, {3, 33}};
  s21_5[0] = 12;
  std_5[0] = 12;
  EXPECT_TRUE(s21_5[0] == std_5[0]);
  EXPECT_TRUE(s21_5[1] == std_5[1]);
  EXPECT_TRUE(s21_5[7] == std_5[7]);
  EXPECT_TRUE(s21_5 == std_5);
  s21_5.clear();
  std_5.clear();
  EXPECT_TRUE(s21_5[1] == std_5[1]);
  EXPECT_TRUE(s21_5 == std_5);

  s21_5 = {{0, 11}, {2, 22}, {3, 33}};
  std_5 = {{0, 11}, {2, 22}, {3, 33}};
  s21_5.insert_or_assign(3, 44);
  std_5.insert_or_assign(3, 44);
  EXPECT_TRUE(s21_5 == std_5);

  s21_5.insert_or_assign(-2, 44);
  std_5.insert_or_assign(-2, 44);
  EXPECT_TRUE(s21_5 == std_5);

  s21_5.clear();
  std_5.clear();
  s21_5.insert_or_assign(-2, 44);
  std_5.insert_or_assign(-2, 44);
  EXPECT_TRUE(s21_5 == std_5);
}

TEST(MAP, CountFindSwapContains) {
  s21::map<int, int> s21_1 = {{1, 11}, {2, 22}, {3, 33}};
  std::map<int, int> std_1 = {{1, 11}, {2, 22}, {3, 33}};
  EXPECT_TRUE(s21_1.count(1) == std_1.count(1));
  EXPECT_TRUE(s21_1.count(5) == std_1.count(5));
  s21_1.clear();
  std_1.clear();
  EXPECT_TRUE(s21_1.count(1) == std_1.count(1));
  EXPECT_FALSE(s21_1.contains(1));

  s21::map<std::string, std::list<int>> s21_2(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  std::map<std::string, std::list<int>> std_2(
      {{"bb", {1, 2}}, {"ba", {1}}, {"aa", {1, 5}}});
  EXPECT_TRUE(s21_2.count("bb") == std_2.count("bb"));
  EXPECT_TRUE(s21_2.count("qq") == std_2.count("qq"));
  EXPECT_TRUE(s21_2.contains("bb"));
  s21_2.clear();
  std_2.clear();
  EXPECT_TRUE(s21_2.count("ba") == std_2.count("ba"));

  s21::map<int, int> s21_3 = {{1, 11}, {2, 22}, {3, 33}};
  std::map<int, int> std_3 = {{1, 11}, {2, 22}, {3, 33}};
  auto s21_it = s21_3.find(1);
  auto it = std_3.find(1);
  EXPECT_TRUE(*s21_it == *it);
  s21_it = s21_3.find(10);
  EXPECT_TRUE((*(--s21_it)) == (*(--s21_3.end())));

  const s21::map<int, int> s21_4 = {{1, 11}, {2, 22}, {3, 33}};
  const std::map<int, int> std_4 = {{1, 11}, {2, 22}, {3, 33}};
  auto s21_cit = s21_4.find(1);
  auto cit = std_4.find(1);
  EXPECT_TRUE(*s21_cit == *cit);
  s21_cit = s21_4.find(10);
  EXPECT_TRUE((*(--s21_cit)) == (*(--s21_4.cend())));

  s21_1 = {{10, 110}, {20, 220}, {30, 330}};
  std_1 = {{10, 110}, {20, 220}, {30, 330}};
  s21_3 = {{1, 11}, {2, 22}, {3, 33}};
  std_3 = {{1, 11}, {2, 22}, {3, 33}};
  s21_1.swap(s21_3);
  std_1.swap(std_3);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_3 == std_3);
}

TEST(MAP, Erase) {
  s21::map<int, int> s21_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20},
                              {40, 40}, {60, 60}, {80, 80}, {10, 10},
                              {25, 25}, {35, 35}, {90, 90}};
  std::map<int, int> std_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20},
                              {40, 40}, {60, 60}, {80, 80}, {10, 10},
                              {25, 25}, {35, 35}, {90, 90}};
  auto sit_1 = s21_1.erase(s21_1.begin());
  auto it_1 = std_1.erase(std_1.begin());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(-- --s21_1.end());
  it_1 = std_1.erase(-- --std_1.end());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(++ ++s21_1.begin());
  it_1 = std_1.erase(++ ++std_1.begin());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {{50, 50}};
  std_1 = {{50, 50}};
  sit_1 = s21_1.erase(s21_1.cbegin());
  it_1 = std_1.erase(std_1.cbegin());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60},
           {80, 80}, {10, 10}, {25, 25}, {35, 35}, {37, 37}};
  std_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60},
           {80, 80}, {10, 10}, {25, 25}, {35, 35}, {37, 37}};
  sit_1 = s21_1.erase(++ ++ ++s21_1.cbegin());
  it_1 = std_1.erase(++ ++ ++std_1.cbegin());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(-- --s21_1.end());
  it_1 = std_1.erase(-- --std_1.end());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60},
           {80, 80}, {10, 10}, {25, 25}, {35, 35}, {37, 37}};
  std_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60},
           {80, 80}, {10, 10}, {25, 25}, {35, 35}, {37, 37}};
  s21_1.erase(s21_1.cbegin(), s21_1.cend());
  std_1.erase(std_1.cbegin(), std_1.cend());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60},
           {80, 80}, {10, 10}, {25, 25}, {35, 35}, {37, 37}};
  std_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60},
           {80, 80}, {10, 10}, {25, 25}, {35, 35}, {37, 37}};
  size_t s_res = s21_1.erase(99);
  size_t res = std_1.erase(99);
  EXPECT_TRUE(s_res == res);
  EXPECT_TRUE(s21_1 == std_1);
  s_res = s21_1.erase(50);
  res = std_1.erase(50);
  EXPECT_TRUE(s_res == res);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{20, 20}, {10, 10}, {30, 30}, {25, 25}, {40, 40}, {22, 22}};
  std_1 = {{20, 20}, {10, 10}, {30, 30}, {25, 25}, {40, 40}, {22, 22}};
  sit_1 = s21_1.erase(--s21_1.end());
  it_1 = std_1.erase(--std_1.end());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{10, 10}, {5, 5}, {20, 20}, {15, 15}, {30, 30}, {25, 25}};
  std_1 = {{10, 10}, {5, 5}, {20, 20}, {15, 15}, {30, 30}, {25, 25}};
  sit_1 = s21_1.erase(s21_1.begin());
  it_1 = std_1.erase(std_1.begin());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20},
           {40, 40}, {60, 60}, {80, 80}, {65, 65}};
  std_1 = {{50, 50}, {30, 30}, {70, 70}, {20, 20},
           {40, 40}, {60, 60}, {80, 80}, {65, 65}};
  sit_1 = s21_1.erase(++ ++ ++s21_1.begin());
  it_1 = std_1.erase(++ ++ ++std_1.begin());
  EXPECT_TRUE((*sit_1).first == (*it_1).first);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std_1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {{12, 12}, {14, 14}, {15, 15}, {13, 13}, {11, 11}, {10, 10}};
  std_1 = {{12, 12}, {14, 14}, {15, 15}, {13, 13}, {11, 11}, {10, 10}};
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(MAP, Merge) {
  s21::map<int, int> s21_1 = {{1, 11}, {2, 22}, {3, 33}, {0, 0}};
  std::map<int, int> std_1 = {{1, 11}, {2, 22}, {3, 33}, {0, 0}};
  s21::map<int, int> s21_2 = {{-1, 4}, {5, 5}, {6, 6}, {0, 0}};
  std::map<int, int> std_2 = {{-1, 4}, {5, 5}, {6, 6}, {0, 0}};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {};
  std_1 = {};
  s21_2 = {{4, 4}, {5, 5}, {6, 6}, {0, 0}};
  std_2 = {{4, 4}, {5, 5}, {6, 6}, {0, 0}};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {{1, 11}, {2, 22}, {3, 33}, {0, 0}};
  std_1 = {{1, 11}, {2, 22}, {3, 33}, {0, 0}};
  s21_2 = {};
  std_2 = {};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {};
  std_1 = {};
  s21_2 = {};
  std_2 = {};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {{4, 4}, {5, 5}, {6, 6}, {0, 0}};
  std_1 = {{4, 4}, {5, 5}, {6, 6}, {0, 0}};
  s21_2 = {{4, 4}, {5, 5}, {6, 6}, {0, 0}};
  std_2 = {{4, 4}, {5, 5}, {6, 6}, {0, 0}};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1.merge(s21_1);
  std_1.merge(std_1);
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(MAP, InsertMany) {
  s21::map<int, int> s21_1 = {{1, 11}, {2, 22}, {3, 33}, {0, 0}};
  std::map<int, int> std_1 = {{1, 11}, {2, 22}, {3, 33},
                              {0, 0},  {-1, 4}, {5, 5}};
  s21_1.insert_many(std::make_pair(-1, 4), std::make_pair(5, 5));
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(SET, Constructors) {
  s21::set<int> s21_1;
  std::set<int> std_1;
  EXPECT_TRUE(s21_1 == std_1);

  s21::set<int> s21_2 = {};
  std::set<int> std_2 = {};
  EXPECT_TRUE(s21_2 == std_2);

  s21::set<int> s21_3 = {1, 2, 3, 3};
  std::set<int> std_3 = {1, 2, 3, 3};
  EXPECT_TRUE(s21_3 == std_3);

  s21::set<int> s21_4(s21_3);
  std::set<int> std_4(std_3);
  EXPECT_TRUE(s21_4 == std_4);

  s21::set<int> s21_5 = s21_3;
  std::set<int> std_5 = std_3;
  EXPECT_TRUE(s21_5 == std_5);

  s21::set<int> s21_6 = std::move(s21_3);
  std::set<int> std_6 = std::move(std_3);
  EXPECT_TRUE(s21_6 == std_6);
  EXPECT_TRUE(s21_3 == std_3);

  s21::set<int> s21_7 = {1, 2, 3};
  std::set<int> std_7 = {1, 2, 3};
  s21::set<int> s21_8(std::move(s21_7));
  std::set<int> std_8(std::move(std_7));
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::set<int> s21_9({1, 2, 3});
  std::set<int> std_9({1, 2, 3});
  EXPECT_TRUE(s21_9 == std_9);

  s21::set<std::list<int>> s21_10;
  std::set<std::list<int>> std_10;
  EXPECT_TRUE(s21_10 == std_10);

  s21::set<std::list<int>> s21_11 = {};
  std::set<std::list<int>> std_11 = {};
  EXPECT_TRUE(s21_11 == std_11);

  s21::set<std::string> s21_12 = {"bb", "ba", "aa"};
  std::set<std::string> std_12 = {"bb", "ba", "aa"};
  EXPECT_TRUE(s21_12 == std_12);

  s21::set<std::string> s21_13(s21_12);
  std::set<std::string> std_13(std_12);
  EXPECT_TRUE(s21_13 == std_13);

  s21::set<std::string> s21_14 = s21_13;
  std::set<std::string> std_14 = std_13;
  EXPECT_TRUE(s21_14 == std_14);

  s21::set<std::string> s21_15 = std::move(s21_12);
  std::set<std::string> std_15 = std::move(std_12);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_12 == std_12);

  s21::set<std::string> s21_16 = {"bb", "ba", "aa"};
  std::set<std::string> std_16 = {"bb", "ba", "aa"};
  s21::set<std::string> s21_17(std::move(s21_16));
  std::set<std::string> std_17(std::move(std_16));
  EXPECT_TRUE(s21_16 == std_16);
  EXPECT_TRUE(s21_17 == std_17);

  s21::set<std::string> s21_18({"bb", "ba", "aa"});
  std::set<std::string> std_18({"bb", "ba", "aa"});
  EXPECT_TRUE(s21_18 == std_18);
}

TEST(SET, OperatorEq) {
  s21::set<int> s21_1 = {1, 2, 3};
  std::set<int> std_1 = {1, 2, 3};
  s21::set<int> s21_2 = {1, 2, 3, 4};
  std::set<int> std_2 = {1, 2, 3, 4};
  s21_1 = s21_2;
  std_1 = std_2;
  EXPECT_TRUE(s21_1 == std_1);
  s21::set<int> &s21_1_1 = s21_1;
  std::set<int> &std_1_1 = std_1;
  s21_1_1 = s21_1;
  std_1_1 = std_1;
  EXPECT_TRUE(s21_1_1 == std_1_1);

  s21::set<int> s21_3 = {1, 2, 3};
  std::set<int> std_3 = {1, 2, 3};
  s21::set<int> s21_4 = {1, 2, 3, 4};
  std::set<int> std_4 = {1, 2, 3, 4};
  s21_3 = std::move(s21_4);
  std_3 = std::move(std_4);
  EXPECT_TRUE(s21_3 == std_3);
  EXPECT_TRUE(s21_4 == std_4);
  s21::set<int> &s21_3_1 = s21_3;
  std::set<int> &std_3_1 = std_3;
  s21_3_1 = s21_3;
  std_3_1 = std_3;
  EXPECT_TRUE(s21_3_1 == std_3_1);

  s21::set<int> &s21_3_2 = s21_3_1;
  std::set<int> &std_3_2 = std_3_1;
  s21_3_2 = std::move(s21_3_1);
  std_3_2 = std::move(std_3_1);
  EXPECT_TRUE(s21_3_2 == std_3_2);

  s21::set<int> s21_5 = {1, 2, 3, 3};
  std::set<int> std_5 = {1, 2, 3, 3};
  s21::set<int> s21_6 = {};
  std::set<int> std_6 = {};
  s21_5 = s21_6;
  std_5 = std_6;
  EXPECT_TRUE(s21_5 == std_5);

  s21::set<int> s21_7 = {1, 2, 3};
  std::set<int> std_7 = {1, 2, 3};
  s21::set<int> s21_8 = {};
  std::set<int> std_8 = {};
  s21_7 = std::move(s21_8);
  std_7 = std::move(std_8);
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::set<int> s21_9 = {};
  std::set<int> std_9 = {};
  s21::set<int> s21_10 = {4, 5, 6, 7};
  std::set<int> std_10 = {4, 5, 6, 7};
  s21_9 = s21_10;
  std_9 = std_10;
  EXPECT_TRUE(s21_9 == std_9);

  s21::set<int> s21_11 = {};
  std::set<int> std_11 = {};
  s21::set<int> s21_12 = {4, 5, 6, 7};
  std::set<int> std_12 = {4, 5, 6, 7};
  s21_11 = std::move(s21_12);
  std_11 = std::move(std_12);
  EXPECT_TRUE(s21_11 == std_11);
  EXPECT_TRUE(s21_12 == std_12);

  s21::set<int> s21_13 = {};
  std::set<int> std_13 = {};
  s21::set<int> s21_14 = {};
  std::set<int> std_14 = {};
  s21_13 = s21_14;
  std_13 = std_14;
  EXPECT_TRUE(s21_13 == std_13);

  s21::set<int> s21_15 = {};
  std::set<int> std_15 = {};
  s21::set<int> s21_16 = {};
  std::set<int> std_16 = {};
  s21_15 = std::move(s21_16);
  std_15 = std::move(std_16);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_16 == std_16);

  s21::set<std::string> s21_17({"bb", "ba", "aa"});
  std::set<std::string> std_17({"bb", "ba", "aa"});
  s21::set<std::string> s21_18({"bb", "ba", "aa", "cc"});
  std::set<std::string> std_18({"bb", "ba", "aa", "cc"});
  s21_17 = s21_18;
  std_17 = std_18;
  EXPECT_TRUE(s21_17 == std_17);

  s21::set<int> s21_19;
  std::set<int> std_19;
  s21_19 = {4, 5, 6, 7};
  std_19 = {4, 5, 6, 7};
  EXPECT_TRUE(s21_19 == std_19);
  s21_19 = {};
  std_19 = {};
  EXPECT_TRUE(s21_19 == std_19);
}

TEST(SET, CountFindSwapContains) {
  s21::set<int> s21_1 = {1, 2, 3};
  std::set<int> std_1 = {1, 2, 3};
  EXPECT_TRUE(s21_1.count(1) == std_1.count(1));
  EXPECT_TRUE(s21_1.count(5) == std_1.count(5));
  s21_1.clear();
  std_1.clear();
  EXPECT_TRUE(s21_1.count(1) == std_1.count(1));
  EXPECT_FALSE(s21_1.contains(1));

  s21::set<std::string> s21_2({"bb", "ba", "aa"});
  std::set<std::string> std_2({"bb", "ba", "aa"});
  EXPECT_TRUE(s21_2.count("bb") == std_2.count("bb"));
  EXPECT_TRUE(s21_2.count("qq") == std_2.count("qq"));
  EXPECT_TRUE(s21_2.contains("bb"));
  s21_2.clear();
  std_2.clear();
  EXPECT_TRUE(s21_2.count("ba") == std_2.count("ba"));

  s21::set<int> s21_3 = {1, 2, 3};
  std::set<int> std_3 = {1, 2, 3};
  auto s21_it = s21_3.find(1);
  auto it = std_3.find(1);
  EXPECT_TRUE(*s21_it == *it);
  s21_it = s21_3.find(10);
  EXPECT_TRUE((*(--s21_it)) == (*(--s21_3.end())));

  const s21::set<int> s21_4 = {1, 2, 3};
  const std::set<int> std_4 = {1, 2, 3};
  auto s21_cit = s21_4.find(1);
  auto cit = std_4.find(1);
  EXPECT_TRUE(*s21_cit == *cit);
  s21_cit = s21_4.find(10);
  EXPECT_TRUE((*(--s21_cit)) == (*(--s21_4.cend())));

  s21_1 = {10, 20, 30};
  std_1 = {10, 20, 30};
  s21_3 = {1, 2, 3};
  std_3 = {1, 2, 3};
  s21_1.swap(s21_3);
  std_1.swap(std_3);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_3 == std_3);
}

TEST(SET, Erase) {
  s21::set<int> s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 90};
  std::set<int> std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 90};
  auto sit_1 = s21_1.erase(s21_1.begin());
  auto it_1 = std_1.erase(std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(-- --s21_1.end());
  it_1 = std_1.erase(-- --std_1.end());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(++ ++s21_1.begin());
  it_1 = std_1.erase(++ ++std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {50};
  std_1 = {50};
  sit_1 = s21_1.erase(s21_1.cbegin());
  it_1 = std_1.erase(std_1.cbegin());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  sit_1 = s21_1.erase(++ ++ ++s21_1.cbegin());
  it_1 = std_1.erase(++ ++ ++std_1.cbegin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(-- --s21_1.end());
  it_1 = std_1.erase(-- --std_1.end());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  s21_1.erase(s21_1.cbegin(), s21_1.cend());
  std_1.erase(std_1.cbegin(), std_1.cend());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  size_t s_res = s21_1.erase(99);
  size_t res = std_1.erase(99);
  EXPECT_TRUE(s_res == res);
  EXPECT_TRUE(s21_1 == std_1);
  s_res = s21_1.erase(50);
  res = std_1.erase(50);
  EXPECT_TRUE(s_res == res);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {20, 10, 30, 25, 40, 22};
  std_1 = {20, 10, 30, 25, 40, 22};
  sit_1 = s21_1.erase(--s21_1.end());
  it_1 = std_1.erase(--std_1.end());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {10, 5, 20, 15, 30, 25};
  std_1 = {10, 5, 20, 15, 30, 25};
  sit_1 = s21_1.erase(s21_1.begin());
  it_1 = std_1.erase(std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 65};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 65};
  sit_1 = s21_1.erase(++ ++ ++s21_1.begin());
  it_1 = std_1.erase(++ ++ ++std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1, 2, 3, 4, 5};
  std_1 = {1, 2, 3, 4, 5};
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {12, 14, 15, 13, 11, 10};
  std_1 = {12, 14, 15, 13, 11, 10};
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(SET, InsertMany) {
  s21::set<int> s21_1 = {1, 2, 3, 0};
  std::set<int> std_1 = {1, 2, 3, 0, 4, 5};
  s21_1.insert_many(4, 5);
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(MULTISET, Constructors) {
  s21::multiset<int> s21_1;
  std::multiset<int> std_1;
  EXPECT_TRUE(s21_1 == std_1);

  s21::multiset<int> s21_2 = {};
  std::multiset<int> std_2 = {};
  EXPECT_TRUE(s21_2 == std_2);

  s21::multiset<int> s21_3 = {1, 2, 3, 3, 1, 1};
  std::multiset<int> std_3 = {1, 2, 3, 3, 1, 1};
  EXPECT_TRUE(s21_3 == std_3);

  s21::multiset<int> s21_4(s21_3);
  std::multiset<int> std_4(std_3);
  EXPECT_TRUE(s21_4 == std_4);

  s21::multiset<int> s21_5 = s21_3;
  std::multiset<int> std_5 = std_3;
  EXPECT_TRUE(s21_5 == std_5);

  s21::multiset<int> s21_6 = std::move(s21_3);
  std::multiset<int> std_6 = std::move(std_3);
  EXPECT_TRUE(s21_6 == std_6);
  EXPECT_TRUE(s21_3 == std_3);

  s21::multiset<int> s21_7 = {1, 2, 3, 2, 2, 2};
  std::multiset<int> std_7 = {1, 2, 3, 2, 2, 2};
  s21::multiset<int> s21_8(std::move(s21_7));
  std::multiset<int> std_8(std::move(std_7));
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::multiset<int> s21_9({1, 2, 3, 3, 3, 3});
  std::multiset<int> std_9({1, 2, 3, 3, 3, 3});
  EXPECT_TRUE(s21_9 == std_9);

  s21::multiset<std::list<int>> s21_10;
  std::multiset<std::list<int>> std_10;
  EXPECT_TRUE(s21_10 == std_10);

  s21::multiset<std::list<int>> s21_11 = {};
  std::multiset<std::list<int>> std_11 = {};
  EXPECT_TRUE(s21_11 == std_11);

  s21::multiset<std::string> s21_12 = {"bb", "ba", "aa", "aa"};
  std::multiset<std::string> std_12 = {"bb", "ba", "aa", "aa"};
  EXPECT_TRUE(s21_12 == std_12);

  s21::multiset<std::string> s21_13(s21_12);
  std::multiset<std::string> std_13(std_12);
  EXPECT_TRUE(s21_13 == std_13);

  s21::multiset<std::string> s21_14 = s21_13;
  std::multiset<std::string> std_14 = std_13;
  EXPECT_TRUE(s21_14 == std_14);

  s21::multiset<std::string> s21_15 = std::move(s21_12);
  std::multiset<std::string> std_15 = std::move(std_12);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_12 == std_12);

  s21::multiset<std::string> s21_16 = {"bb", "ba", "aa", "aa"};
  std::multiset<std::string> std_16 = {"bb", "ba", "aa", "aa"};
  s21::multiset<std::string> s21_17(std::move(s21_16));
  std::multiset<std::string> std_17(std::move(std_16));
  EXPECT_TRUE(s21_16 == std_16);
  EXPECT_TRUE(s21_17 == std_17);

  s21::multiset<std::string> s21_18({"bb", "ba", "aa", "ba"});
  std::multiset<std::string> std_18({"bb", "ba", "aa", "ba"});
  EXPECT_TRUE(s21_18 == std_18);
}

TEST(SET, Merge) {
  s21::set<int> s21_1 = {1, 2, 3, 0};
  std::set<int> std_1 = {1, 2, 3, 0};
  s21::set<int> s21_2 = {-1, 5, 6, 0};
  std::set<int> std_2 = {-1, 5, 6, 0};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {};
  std_1 = {};
  s21_2 = {4, 5, 6, 0};
  std_2 = {4, 5, 6, 0};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {1, 2, 3, 0};
  std_1 = {1, 2, 3, 0};
  s21_2 = {};
  std_2 = {};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {};
  std_1 = {};
  s21_2 = {};
  std_2 = {};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {4, 5, 6, 0};
  std_1 = {4, 5, 6, 0};
  s21_2 = {4, 5, 6, 0};
  std_2 = {4, 5, 6, 0};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1.merge(s21_1);
  std_1.merge(std_1);
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(MULTISET, OperatorEq) {
  s21::multiset<int> s21_1 = {1, 2, 3, 3, 3};
  std::multiset<int> std_1 = {1, 2, 3, 3, 3};
  s21::multiset<int> s21_2 = {1, 2, 3, 3, 3, 4, 4};
  std::multiset<int> std_2 = {1, 2, 3, 3, 3, 4, 4};
  s21_1 = s21_2;
  std_1 = std_2;
  EXPECT_TRUE(s21_1 == std_1);
  s21::multiset<int> &s21_1_1 = s21_1;
  std::multiset<int> &std_1_1 = std_1;
  s21_1_1 = s21_1;
  std_1_1 = std_1;
  EXPECT_TRUE(s21_1_1 == std_1_1);

  s21::multiset<int> s21_3 = {1, 2, 3, 3, 3};
  std::multiset<int> std_3 = {1, 2, 3, 3, 3};
  s21::multiset<int> s21_4 = {1, 2, 3, 3, 3, 4, 4};
  std::multiset<int> std_4 = {1, 2, 3, 3, 3, 4, 4};
  s21_3 = std::move(s21_4);
  std_3 = std::move(std_4);
  EXPECT_TRUE(s21_3 == std_3);
  EXPECT_TRUE(s21_4 == std_4);
  s21::multiset<int> &s21_3_1 = s21_3;
  std::multiset<int> &std_3_1 = std_3;
  s21_3_1 = s21_3;
  std_3_1 = std_3;
  EXPECT_TRUE(s21_3_1 == std_3_1);

  s21::multiset<int> &s21_3_2 = s21_3_1;
  std::multiset<int> &std_3_2 = std_3_1;
  s21_3_2 = std::move(s21_3_1);
  std_3_2 = std::move(std_3_1);
  EXPECT_TRUE(s21_3_2 == std_3_2);

  s21::multiset<int> s21_5 = {1, 2, 3, 3};
  std::multiset<int> std_5 = {1, 2, 3, 3};
  s21::multiset<int> s21_6 = {};
  std::multiset<int> std_6 = {};
  s21_5 = s21_6;
  std_5 = std_6;
  EXPECT_TRUE(s21_5 == std_5);

  s21::multiset<int> s21_7 = {1, 2, 3, 2, 2};
  std::multiset<int> std_7 = {1, 2, 3, 2, 2};
  s21::multiset<int> s21_8 = {};
  std::multiset<int> std_8 = {};
  s21_7 = std::move(s21_8);
  std_7 = std::move(std_8);
  EXPECT_TRUE(s21_7 == std_7);
  EXPECT_TRUE(s21_8 == std_8);

  s21::multiset<int> s21_9 = {};
  std::multiset<int> std_9 = {};
  s21::multiset<int> s21_10 = {4, 5, 6, 7, 7, 6};
  std::multiset<int> std_10 = {4, 5, 6, 7, 7, 6};
  s21_9 = s21_10;
  std_9 = std_10;
  EXPECT_TRUE(s21_9 == std_9);

  s21::multiset<int> s21_11 = {};
  std::multiset<int> std_11 = {};
  s21::multiset<int> s21_12 = {4, 5, 6, 7, 1, 2};
  std::multiset<int> std_12 = {4, 5, 6, 7, 2, 1};
  s21_11 = std::move(s21_12);
  std_11 = std::move(std_12);
  EXPECT_TRUE(s21_11 == std_11);
  EXPECT_TRUE(s21_12 == std_12);

  s21::multiset<int> s21_13 = {};
  std::multiset<int> std_13 = {};
  s21::multiset<int> s21_14 = {};
  std::multiset<int> std_14 = {};
  s21_13 = s21_14;
  std_13 = std_14;
  EXPECT_TRUE(s21_13 == std_13);

  s21::multiset<int> s21_15 = {};
  std::multiset<int> std_15 = {};
  s21::multiset<int> s21_16 = {};
  std::multiset<int> std_16 = {};
  s21_15 = std::move(s21_16);
  std_15 = std::move(std_16);
  EXPECT_TRUE(s21_15 == std_15);
  EXPECT_TRUE(s21_16 == std_16);

  s21::multiset<std::string> s21_17({"bb", "ba", "aa"});
  std::multiset<std::string> std_17({"bb", "ba", "aa"});
  s21::multiset<std::string> s21_18({"bb", "ba", "aa", "cc"});
  std::multiset<std::string> std_18({"bb", "ba", "aa", "cc"});
  s21_17 = s21_18;
  std_17 = std_18;
  EXPECT_TRUE(s21_17 == std_17);

  s21::multiset<int> s21_19;
  std::multiset<int> std_19;
  s21_19 = {4, 5, 6, 7};
  std_19 = {4, 5, 6, 7};
  EXPECT_TRUE(s21_19 == std_19);
  s21_19 = {};
  std_19 = {};
  EXPECT_TRUE(s21_19 == std_19);
}

TEST(MULTISET, CountFindSwapContainsEqualRange) {
  s21::multiset<int> s21_1 = {1, 2, 3, 1, 2, 3};
  std::multiset<int> std_1 = {1, 2, 3, 1, 2, 3};
  EXPECT_TRUE(s21_1.count(1) == std_1.count(1));
  EXPECT_TRUE(s21_1.count(5) == std_1.count(5));
  s21_1.clear();
  std_1.clear();
  EXPECT_TRUE(s21_1.count(1) == std_1.count(1));
  EXPECT_FALSE(s21_1.contains(1));

  s21::multiset<std::string> s21_2({"bb", "ba", "aa"});
  std::multiset<std::string> std_2({"bb", "ba", "aa"});
  EXPECT_TRUE(s21_2.count("bb") == std_2.count("bb"));
  EXPECT_TRUE(s21_2.count("qq") == std_2.count("qq"));
  EXPECT_TRUE(s21_2.contains("bb"));
  s21_2.clear();
  std_2.clear();
  EXPECT_TRUE(s21_2.count("ba") == std_2.count("ba"));

  s21::multiset<int> s21_3 = {1, 2, 3};
  std::multiset<int> std_3 = {1, 2, 3};
  auto s21_it = s21_3.find(1);
  auto it = std_3.find(1);
  EXPECT_TRUE(*s21_it == *it);
  s21_it = s21_3.find(10);
  EXPECT_TRUE((*(--s21_it)) == (*(--s21_3.end())));

  const s21::multiset<int> s21_4 = {1, 2, 3, 1, 1};
  const std::multiset<int> std_4 = {1, 2, 3, 1, 1};
  auto s21_cit = s21_4.find(1);
  auto cit = std_4.find(1);
  EXPECT_TRUE(*s21_cit == *cit);
  s21_cit = s21_4.find(10);
  EXPECT_TRUE((*(--s21_cit)) == (*(--s21_4.cend())));

  s21_1 = {10, 20, 30, 10};
  std_1 = {10, 20, 30, 10};
  s21_3 = {1, 2, 3, 2};
  std_3 = {1, 2, 3, 2};
  s21_1.swap(s21_3);
  std_1.swap(std_3);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_3 == std_3);

  s21_1 = {9, 10, 10, 10, 30, 10};
  std::pair<s21::multiset<int>::iter, s21::multiset<int>::iter> res = {
      ++s21_1.begin(), --s21_1.end()};
  std::pair<s21::multiset<int>::iter, s21::multiset<int>::iter> eq =
      s21_1.equal_range(10);
  EXPECT_TRUE(res == eq);

  const s21::multiset<int> s21_5 = {9, 10, 10, 10, 30, 10};
  std::pair<s21::multiset<int>::c_iter, s21::multiset<int>::c_iter> c_res = {
      ++s21_5.cbegin(), --s21_5.cend()};
  std::pair<s21::multiset<int>::c_iter, s21::multiset<int>::c_iter> c_eq =
      s21_5.equal_range(10);
  EXPECT_TRUE(c_res == c_eq);
}

TEST(MULTISET, Erase) {
  s21::multiset<int> s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 90, 90};
  std::multiset<int> std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 90, 90};
  auto sit_1 = s21_1.erase(s21_1.begin());
  auto it_1 = std_1.erase(std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(-- --s21_1.end());
  it_1 = std_1.erase(-- --std_1.end());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(++ ++s21_1.begin());
  it_1 = std_1.erase(++ ++std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  s21_1 = {50};
  std_1 = {50};
  sit_1 = s21_1.erase(s21_1.cbegin());
  it_1 = std_1.erase(std_1.cbegin());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  sit_1 = s21_1.erase(++ ++ ++s21_1.cbegin());
  it_1 = std_1.erase(++ ++ ++std_1.cbegin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);
  sit_1 = s21_1.erase(-- --s21_1.end());
  it_1 = std_1.erase(-- --std_1.end());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37};
  s21_1.erase(s21_1.cbegin(), s21_1.cend());
  std_1.erase(std_1.cbegin(), std_1.cend());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37, 50, 50};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 37, 50, 50};
  size_t s_res = s21_1.erase(99);
  size_t res = std_1.erase(99);
  EXPECT_TRUE(s_res == res);
  EXPECT_TRUE(s21_1 == std_1);
  s_res = s21_1.erase(50);
  res = std_1.erase(50);
  EXPECT_TRUE(s_res == res);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {20, 10, 30, 25, 40, 22};
  std_1 = {20, 10, 30, 25, 40, 22};
  sit_1 = s21_1.erase(--s21_1.end());
  it_1 = std_1.erase(--std_1.end());
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {10, 5, 20, 15, 30, 25};
  std_1 = {10, 5, 20, 15, 30, 25};
  sit_1 = s21_1.erase(s21_1.begin());
  it_1 = std_1.erase(std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {50, 30, 70, 20, 40, 60, 80, 65};
  std_1 = {50, 30, 70, 20, 40, 60, 80, 65};
  sit_1 = s21_1.erase(++ ++ ++s21_1.begin());
  it_1 = std_1.erase(++ ++ ++std_1.begin());
  EXPECT_TRUE(*sit_1 == *it_1);
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {1, 2, 3, 4, 5};
  std_1 = {1, 2, 3, 4, 5};
  EXPECT_TRUE(s21_1 == std_1);

  s21_1 = {12, 14, 15, 13, 11, 10};
  std_1 = {12, 14, 15, 13, 11, 10};
  EXPECT_TRUE(s21_1 == std_1);
}

TEST(MULTISET, Merge) {
  s21::multiset<int> s21_1 = {1, 2, 3, 0};
  std::multiset<int> std_1 = {1, 2, 3, 0};
  s21::multiset<int> s21_2 = {-1, 5, 6, 0};
  std::multiset<int> std_2 = {-1, 5, 6, 0};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {};
  std_1 = {};
  s21_2 = {4, 5, 6, 0};
  std_2 = {4, 5, 6, 0};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {1, 2, 3, 0};
  std_1 = {1, 2, 3, 0};
  s21_2 = {};
  std_2 = {};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {};
  std_1 = {};
  s21_2 = {};
  std_2 = {};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1 = {4, 5, 6, 0};
  std_1 = {4, 5, 6, 0};
  s21_2 = {4, 5, 6, 0};
  std_2 = {4, 5, 6, 0};
  s21_1.merge(s21_2);
  std_1.merge(std_2);
  EXPECT_TRUE(s21_1 == std_1);
  EXPECT_TRUE(s21_2 == std_2);

  s21_1.merge(s21_1);
}

TEST(MULTISET, InsertMany) {
  s21::multiset<int> s21_1 = {1, 2, 3, 0, 1, 2};
  std::multiset<int> std_1 = {1, 2, 3, 0, 4, 5, 1, 2, 5};
  s21_1.insert_many(4, 5, 5);
  EXPECT_TRUE(s21_1 == std_1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
