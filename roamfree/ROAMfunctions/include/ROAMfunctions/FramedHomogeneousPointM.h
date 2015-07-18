/*
 Copyright (c) 2013-2014 Politecnico di Milano.
 All rights reserved. This program and the accompanying materials
 are made available under the terms of the GNU Lesser Public License v3
 which accompanies this distribution, and is available at
 https://www.gnu.org/licenses/lgpl.html

 Contributors:
 Davide A. Cucci (cucci@elet.polimi.it)
 */

/*
 * FramedHomogeneousPointM.h
 *
 *  Created on: Nov 13, 2014
 *      Author: davide
 */

#ifndef FRAMEDHOMOGENEOUSPOINT_H_
#define FRAMEDHOMOGENEOUSPOINT_H_

#include <Eigen/Dense>

namespace ROAMfunctions {

class FramedHomogeneousPointM {

public:
	static const bool _usedComponents[];

	static const std::string _paramsNames[];
	static const int _nParams = 3;

	static const unsigned int _ORDER = 0;

	static const unsigned int _ERROR_SIZE = 2;
	static const unsigned int _NOISE_SIZE = 2;
	static const unsigned int _MEASUREMENT_SIZE = 2;

	const std::string* getParamsList() {
		return _paramsNames;
	}
	const int getNParams() {
		return _nParams;
	}

	bool predict(const Eigen::VectorXd &x, double **params,
			const Eigen::VectorXd& z, double dt, Eigen::VectorXd &xhat) {
		return false;
	}

	template<typename T>
	bool error(const Eigen::VectorXd &x, double **params,
			const Eigen::VectorXd& z, Eigen::MatrixBase<T> const &const_ret) {

		Eigen::Map<Eigen::Vector3d> hp(params[0]);
		Eigen::Map<Eigen::Matrix<double,7, 1> > f(params[1]);
		Eigen::Map<Eigen::Matrix<double, 9,1> > cm(params[2]);

		Eigen::MatrixBase<T> & err = const_cast<Eigen::MatrixBase<T>&>(const_ret);

		const static int _OFF = -1;

#   include "generated/FramedHomogeneousPoint_Err.cppready"

		return false;
	}

	template<typename T>
	bool errorJacobian(const Eigen::VectorXd &x, double **params,
			const Eigen::VectorXd& z, int wrt,
			Eigen::MatrixBase<T> const &const_ret) {

		Eigen::Map<Eigen::Vector3d> hp(params[0]);
		Eigen::Map<Eigen::Matrix<double,7, 1> > f(params[1]);
		Eigen::Map<Eigen::Matrix<double, 9,1> > cm(params[2]);

		Eigen::MatrixBase<T> & J = const_cast<Eigen::MatrixBase<T>&>(const_ret);

		const static int _OFF = -1;

		switch (wrt) {

		case -2: // jacobian wrt to q
		{
#     include "generated/FramedHomogeneousPoint_JErrQ.cppready"
			return true;
			break;
		}

		case -1: // jacobian wrt pose
		{
#     include "generated/FramedHomogeneousPoint_JErrPose.cppready"
			return true;
			break;
		}
		case 0: // jacobian wrt to noises
		{
			// it is the identity matrix
			// #include "generated/FramedHomogeneousPoint_JErrNoises.cppready"
			return false;
			break;
		}
		case 1: // jacobian wrt homogeneous point
		{
 #  	include "generated/FramedHomogeneousPoint_JErrHP.cppready"
			return true;
			break;
		}
		case 2: // jacobian wrt frame
		{
 #  	include "generated/FramedHomogeneousPoint_JErrF.cppready"
			return true;
			break;
		}
		/*
		case 3: // jacobian wrt camera matrix
		{
#			include "generated/IMUint_JErrBw.cppready"
			return true;
			break;
		}
		*/
		}

		assert(false);
		return false;
	}
};

} /* namespace ROAMfunctions */

#endif /* FRAMEDHOMOGENEOUSPOINT_H_ */
