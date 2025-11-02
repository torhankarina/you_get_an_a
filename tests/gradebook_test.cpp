#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gradebook.hpp"

TEST_CASE("Gradebook basic functionality") {
    Gradebook gb;

    gb.add_student("Alice", "Anderson", "AAA111");
    gb.add_assignment("HW1", 100);
    gb.enter_grade("Alice Anderson", "HW1", 90);

    std::string report = gb.report();

    REQUIRE(report == "Last_Name,First_Name,Student_Id,HW1\nAnderson,Alice,AAA111,90\n");
}

TEST_CASE("Gradebook shows 'none' when grade not entered") {
    Gradebook gb;

    gb.add_student("Bob", "Bobberson", "BBB222");
    gb.add_assignment("Quiz1", 50);

    std::string report = gb.report();

    REQUIRE(report == "Last_Name,First_Name,Student_Id,Quiz1\nBobberson,Bob,BBB222,none\n");
}

TEST_CASE("Multiple students and assignments") {
    Gradebook gb;

    gb.add_student("Sam", "Sammerson", "CCC333");
    gb.add_student("Jess", "Jesserson", "DDD444");
    gb.add_assignment("Lab1", 25);
    gb.add_assignment("Quiz1", 50);

    gb.enter_grade("Sam Sammerson", "Lab1", 20);
    gb.enter_grade("Jess Jesserson", "Quiz1", 45);

    std::string expected =
        "Last_Name,First_Name,Student_Id,Lab1,Quiz1\n"
        "Sammerson,Sam,CCC333,20,none\n"
        "Jesserson,Jess,DDD444,none,45\n";

    REQUIRE(gb.report() == expected);
}