#ifndef _LIFE_H_
#define _LIFE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>

#define BOARDX 64
#define BOARDY 32

    void life_setup(void *);
    void life_loop(void *);

#ifdef __cplusplus
}
#endif

#endif