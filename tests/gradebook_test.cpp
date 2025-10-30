#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gradebook.hpp"

TEST_CASE( "Gradebook basic functionality" ) {
    Gradebook gb;
    gb.add_student("Alice", "Smith", "A001");
    gb.add_assignment("Quiz1", 100);
    gb.enter_grade("Alice Smith", "Quiz1", 92);

    string output = gb.report();

    REQUIRE(output.find("Alice") != string::npos);
    REQUIRE(output.find("Smith") != string::npos);
    REQUIRE(output.find("92") != string::npos);
    REQUIRE(output.find("Quiz1") != string::npos);
}
TEST_CASE("Missing grade shows as 'none'") {
    Gradebook gb;
    gb.add_student("Bob", "Brown", "B001");
    gb.add_assignment("Lab1", 50);

    string output = gb.report();
    REQUIRE(output.find("none") != string::npos);
}