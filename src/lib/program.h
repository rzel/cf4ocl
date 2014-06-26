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
 * @brief OpenCL program wrapper.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU Lesser General Public License version 3 (LGPLv3)](http://www.gnu.org/licenses/lgpl.html)
 * */
 
#ifndef CL4_PROGRAM_H
#define CL4_PROGRAM_H 

#include <glib.h>
#if defined(__APPLE__) || defined(__MACOSX)
    #include <OpenCL/opencl.h>
#else
    #include <CL/opencl.h>
#endif
#include "wrapper.h"

/** @brief Program wrapper object. */
typedef struct cl4_program CL4Program;

/** @brief Decrements the reference count of the program wrapper 
 * object. If it reaches 0, the program wrapper object is 
 * destroyed. */
void cl4_program_destroy(CL4Program* prg);

/**
 * @brief Get program information object.
 * 
 * @param prg The program wrapper object.
 * @param param_name Name of information/parameter to get.
 * @param err Return location for a GError, or NULL if error reporting
 * is to be ignored.
 * @return The requested information object. This object will be 
 * automatically freed when the wrapper object is destroyed. If an error 
 * occurs, NULL is returned.
 * */
#define cl4_program_info(prg, param_name, err) \
	cl4_wrapper_get_info((CL4Wrapper*) prg, param_name, \
		(cl4_wrapper_info_function) clGetProgramInfo, err)

/** 
 * @brief Increase the reference count of the program object.
 * 
 * @param prg The program wrapper object. 
 * */
#define cl4_program_ref(prg) \
	cl4_wrapper_ref((CL4Wrapper*) prg)

/**
 * @brief Alias to cl4_program_destroy().
 * 
 * @param prg Program wrapper object to destroy if reference count 
 * is 1, otherwise just decrement the reference count.
 * */
#define cl4_program_unref(prg) cl4_program_destroy(prg)

/**
 * @brief Get the OpenCL program object.
 * 
 * @param prg The program wrapper object.
 * @return The OpenCL program object.
 * */
#define cl4_program_unwrap(prg) \
	((cl_program) cl4_wrapper_unwrap((CL4Wrapper*) prg))		

#endif

