#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expectedX = MatrixXd(3, 3);
    expectedX << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
    fileToOpen = "../data/m3.csv";
    matrixSize = 3;
  }

  MatrixXd    expectedX;
  std::string fileToOpen;
  int         matrixSize;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(IO1)
{
  MatrixXd testMatrix = matrixIO::openData(fileToOpen, matrixSize);

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      // checking matrix values
      BOOST_TEST(testMatrix(i, j) == expectedX(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()