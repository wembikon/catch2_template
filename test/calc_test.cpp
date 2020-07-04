#include "catch2/catch.hpp"

#include "calc.h"

TEST_CASE("should add two integers", "[dummy_tag]") {
  Calc adder;

  REQUIRE(adder.add(1, 2) == 3);
}
