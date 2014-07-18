/*   
 * This file is part of cf4ocl (C Framework for OpenCL).
 * 
 * cf4ocl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * cf4ocl is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with cf4ocl.  If not, see <http://www.gnu.org/licenses/>.
 * */
 
 /** 
 * @file
 * @brief OpenCL buffer stub functions.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU General Public License version 3 (GPLv3)](http://www.gnu.org/licenses/gpl.html)
 * */
 
#include "ocl_env.h"
#include "utils.h"


CL_API_ENTRY cl_mem CL_API_CALL
clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size,
	void* host_ptr, cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
		
	seterrcode(errcode_ret, CL_SUCCESS);
	cl_mem memobj = g_slice_new(struct _cl_mem);
	
	memobj->ref_count = 1;
	memobj->type = CL_MEM_OBJECT_BUFFER;
	memobj->flags = flags;
	memobj->size = size;
	memobj->host_ptr = host_ptr;
	memobj->map_count = 0;
	memobj->context = context;
	memobj->associated_object = NULL;
	memobj->offset = 0;
	
	return memobj;
}

CL_API_ENTRY cl_mem CL_API_CALL
clCreateSubBuffer(cl_mem buffer, cl_mem_flags flags,
	cl_buffer_create_type buffer_create_type, 
	const void* buffer_create_info, cl_int* errcode_ret) 
	CL_API_SUFFIX__VERSION_1_1 {

	seterrcode(errcode_ret, CL_SUCCESS);
	cl_mem memobj = g_slice_new(struct _cl_mem);
	
	memobj->ref_count = 1;
	memobj->type = CL_MEM_OBJECT_BUFFER;
	memobj->flags = flags;
	memobj->size = (buffer_create_type == CL_BUFFER_CREATE_TYPE_REGION)
		? ((struct _cl_buffer_region*) buffer_create_info)->size
		: 0;
	memobj->host_ptr = buffer->host_ptr;
	memobj->map_count = 0;
	memobj->context = buffer->context;
	memobj->associated_object = buffer;
	memobj->offset = (buffer_create_type == CL_BUFFER_CREATE_TYPE_REGION)
		? ((struct _cl_buffer_region*) buffer_create_info)->origin
		: 0;

	return memobj;
}

CL_API_ENTRY void * CL_API_CALL
clEnqueueMapBuffer(cl_command_queue command_queue, cl_mem buffer,
	cl_bool blocking_map, cl_map_flags map_flags, size_t offset,
	size_t size, cl_uint num_events_in_wait_list, 
	const cl_event* event_wait_list, cl_event* event, 
	cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_0 {

	command_queue = command_queue;
	buffer = buffer;
	blocking_map = blocking_map;
	num_events_in_wait_list = num_events_in_wait_list;
	event_wait_list = event_wait_list;
	event = event;
	errcode_ret = errcode_ret;
	return NULL;
}