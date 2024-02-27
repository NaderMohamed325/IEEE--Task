
#ifndef  ERRTYPE_H_
#define  ERRTYPE_H_

//@ErrorStatus_t
typedef enum
{
	OK=0,
	NOK,
	NULLPTR,
	OUT_OF_RANGE,
	UNKNOWN,
	RUNTIME_OUT
}ErrorStatus_t;


#define  NullPtr   ((void*)0)

typedef void(*Fptr)(void);

#endif
