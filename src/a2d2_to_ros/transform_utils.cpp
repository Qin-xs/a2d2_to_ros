/*
 * MIT License
 *
 * Copyright (c) 2020 Mapless AI, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include "a2d2_to_ros/transform_utils.hpp"

#include "a2d2_to_ros/checks.hpp"

namespace a2d2_to_ros {

//------------------------------------------------------------------------------

Eigen::Matrix3d get_orthonormal_basis(const Eigen::Vector3d& X,
                                      const Eigen::Vector3d& Y,
                                      double epsilon) {
  Eigen::Matrix3d basis;
  basis.setZero();
  if (!axes_are_valid(X, Y, epsilon)) {
    return basis;
  }

  const Eigen::Vector3d Z = X.cross(Y);
  const Eigen::Vector3d Y_ortho = Z.cross(X);

  basis.col(0) = X.normalized();
  basis.col(1) = Y_ortho.normalized();
  basis.col(2) = Z.normalized();
  return basis;
}

//------------------------------------------------------------------------------

Eigen::Affine3d Tx_global_sensor(const Eigen::Matrix3d& basis,
                                 const Eigen::Vector3d& origin) {
  const Eigen::Matrix3d R = basis;
  const Eigen::Translation3d T(origin);
  Eigen::Affine3d Tx = (T * R);
  return Tx;
}

//------------------------------------------------------------------------------

}  // namespace a2d2_to_ros
