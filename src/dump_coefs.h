#ifndef DUMP_COEFS_H
#define DUMP_COEFS_H
#include "opus_types.h"
#include "celt/arch.h"
void dump_silk_coef(int encode,const opus_int16 *vals,int len);
void dump_silk_pulses8(int encode,const opus_int8 *vals,int len);
void dump_silk_pulses16(int encode,const opus_int16 *vals,int len);
void dump_celt_coef(int encode,const celt_norm *vals,int len);
#endif
