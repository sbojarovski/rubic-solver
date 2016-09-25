#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Cube.h"

TEST_CASE("testing the cube transformations") {
    Cube cube;

    SUBCASE("front cw") {
        cube.transform(CubeTransforms::FRONT_CW);

        CHECK(cube.isValid() == true);
    }
}
