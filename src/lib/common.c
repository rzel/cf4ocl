/*   
 * This file is part of cf4ocl (C Framework for OpenCL).
 * 
 * cf4ocl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 * 
 * cf4ocl is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License along with cf4ocl. If not, see 
 * <http://www.gnu.org/licenses/>.
 * */
 
/** 
 * @file
 * 
 * Common _cf4ocl_ implementations.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU Lesser General Public License version 3 (LGPLv3)](http://www.gnu.org/licenses/lgpl.html)
 * */
 
#include "common.h"

/** 
 * Resolves to error category identifying string, in this case an
 * error in _cf4ocl_.
 * 
 * @return A GQuark structure defined by category identifying string,
 * which identifies the error as a cf4ocl generated error.
 */
GQuark ccl_error_quark() {
	return g_quark_from_static_string("ccl-error-quark");
}

/** 
 *  Resolves to error category identifying string, in this case
 * an error in the OpenCL library.
 * 
 * @return A GQuark structure defined by category identifying string,
 * which identifies the error as an error in the OpenCL library.
 */
GQuark ccl_ocl_error_quark() {
	return g_quark_from_static_string("ccl-ocl-error-quark");
}
