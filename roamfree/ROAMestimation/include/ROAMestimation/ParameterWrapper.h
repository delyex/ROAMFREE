/*
Copyright (c) 2013-2016 Politecnico di Milano.
All rights reserved. This program and the accompanying materials
are made available under the terms of the GNU Lesser Public License v3
which accompanies this distribution, and is available at
https://www.gnu.org/licenses/lgpl.html

Contributors:
    Davide A. Cucci (davide.cucci@epfl.ch)    
*/

/*
 * ParameterWrapper.h
 *
 *  Created on: May 13, 2014
 *      Author: davide
 */

#ifndef PARAMETERWRAPPER_H_
#define PARAMETERWRAPPER_H_

#include <Eigen/Dense>

namespace ROAMestimation {

/**
 * This class wraps a Parameter
 */

class ParameterWrapper {
public:
	virtual ~ParameterWrapper() {};

	virtual bool getFixed() const = 0; //!< returns if the parameter is fixed or not during the estimation
	virtual void setFixed(bool isFixed) = 0; //!< sets if the parameter is fixed or not during the estimation

	virtual const Eigen::VectorXd &getEstimate(double t) const = 0; //!< get a const reference to the vertex nearest to t
	virtual const Eigen::VectorXd &getEstimate() const = 0; //!< get a const reference to the estimate of the vertex with t = 0.0

  virtual void setEstimate(const Eigen::VectorXd &x, double t) = 0; //!< set estimate for vertex nearest to t
  virtual void setEstimate(const Eigen::VectorXd &x) = 0; //! set estimate for vertex nearest to 0.0

  virtual void setEstimate(double x, double t) = 0; //!< for Euclidean1D parameters, set estimate for vertex nearest to t
  virtual void setEstimate(double x) = 0; //!< for Euclidean1D parameters, set estimate for vertex nearest to 0.0

  virtual void getValueAt(Eigen::VectorXd &ret, double t) = 0; //!< get the value for the parameter at time t (may involve interpolation);

  virtual void setDerivativePriorsEnabled(bool enable) = 0; //!< enables or disables the priors on the parameter derivative
  virtual void setDerivativePriorNoisCov(const Eigen::MatrixXd &cov) = 0; //!< sets the noise covariance matrix for the parameter derivative prior
};

} /* namespace ROAMestimation */

#endif /* PARAMETERWRAPPER_H_ */