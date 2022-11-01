#ifndef MYERROR_HPP
#define MYERROR_HPP

#include <string>

typedef enum {
    MISS_SEMI,
    MISS_RC,
    MISS_RP,
    MISS_SPEC,
    MISS_RB 
} MY_ERROR_TYPE;

void my_error(MY_ERROR_TYPE type, int line_num);

#endif 
