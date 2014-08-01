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
 * @brief Functions for querying OpenCL devices.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU Lesser General Public License version 3 (LGPLv3)](http://www.gnu.org/licenses/lgpl.html)
 * */
 
#ifndef _CCL_DEVICE_QUERY_H_
#define _CCL_DEVICE_QUERY_H_

#include "common.h"
#include "gerrorf.h"
#include "device_wrapper.h"
#include "errors.h"
#include "string.h"
#include "oclversions.h"

/**
 * @defgroup DEVICE_QUERY Device query
 *
 * @brief Objects and functions to query OpenCL devices.
 * 
 * Todo: detailed description of module with code examples.
 * 
 * @{
 */

/** 
 * @brief Output formatting function.
 * 
 * @param info CL device information bitfield.
 * @param out Char buffer (pre-allocated) were to write formatted output.
 * @param size Maximum output length.
 * @param units Parameter units suffix.
 * @return Formatted output (same address as parameter out).
 * */
typedef char* (*ccl_devquery_format)(CCLWrapperInfo* info, char* out, 
	size_t size, const char* units);

/** 
 * @brief Maps a string to a cl_device_info bitfield. 
 * */
typedef struct ccl_devquery_map {
	
	/** Parameter name string. */
	const char* const param_name;
	/** CL device information bitfield. */
	const cl_device_info device_info;
	/** Long description of parameter. */
	const char* const description;
	/** Output formatting function. */
	const ccl_devquery_format format;
	/** Parameter units suffix. */
	const char* const units;
	
} CCLDevQueryMap;

/** @brief Size of parameter information map. */
extern const int ccl_devquery_info_map_size;

/** @brief Map of parameter name strings to respective cl_device_info 
 * bitfields, long description string, format output function and a
 * units suffix. */
extern const CCLDevQueryMap ccl_devquery_info_map[];

/** @brief Get a final device info prefix in the same format as 
 * kept in the ccl_devquery_info_map. */
gchar* ccl_devquery_get_prefix_final(const char* prefix);

/** @brief Return a cl_device_info object given its name. */
cl_device_info ccl_devquery_name(const char* name);

/** @brief Get a list of device information parameters which have the 
 * given prefix. */
const CCLDevQueryMap* ccl_devquery_prefix(const char* prefix, int* size);

/** @brief Search for a device information parameter by matching part
 * of its name. This function is supposed to be used in a loop. */
const CCLDevQueryMap* ccl_devquery_match(const char* substr, int* idx);

/** 
 * @brief Map an OpenCL cl_device_type object to a string identifying
 * the device type.
 * 
 * @param type The OpenCL cl_device_type.
 * */
#define ccl_devquery_type2str(type) \
	(((type) & CL_DEVICE_TYPE_CPU) ? "CPU" : \
		(((type) & CL_DEVICE_TYPE_GPU) ? "GPU" : \
			(((type) & CL_DEVICE_TYPE_ACCELERATOR) ? "Accelerator" : \
				(((type) & CL_DEVICE_TYPE_CUSTOM) ? "Custom" : \
					"Unknown"))))

/** @} */

#endif