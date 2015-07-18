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
 * VectorField.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: davide
 */

#include "VectorField.h"

namespace ROAMfunctions {

const bool VectorFieldM::_usedComponents[] = { false, true, false, false, false,
		false, false, false, false, false };

const std::string VectorFieldM::_paramsNames[] = { "R", "S", "h" };

} /* namespace ROAMfunctions */
