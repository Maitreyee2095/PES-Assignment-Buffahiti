/*
 * log.h
 *
 *  Created on: Oct 13, 2020
 *      Author: maitr
 */

#ifndef LOG_H_
#define LOG_H_


#include <stdio.h>

#ifdef DEBUG
	#define LOG printf // redirect to printf
#else
	#define LOG(...) // do nothing - get rid of output
#endif


#endif /* LOG_H_ */
