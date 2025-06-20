#include "src/dump_coefs.h"
#include <stdio.h>
#include <stdlib.h>

static void dump_array(const char *name,const void *data,size_t bytes)
{
    const char *dir=getenv("OPUS_DUMP_DIR");
    if(!dir) return;
    char path[512];
    snprintf(path,sizeof(path),"%s/%s",dir,name);
    FILE *f=fopen(path,"ab");
    if(!f) return;
    fwrite(data,1,bytes,f);
    fclose(f);
}

void dump_silk_coef(int encode,const opus_int16 *vals,int len)
{
    dump_array(encode?"enc_silk.bin":"dec_silk.bin",vals,(size_t)len*sizeof(opus_int16));
}

void dump_silk_pulses8(int encode,const opus_int8 *vals,int len)
{
    dump_array(encode?"enc_silk.bin":"dec_silk.bin",vals,(size_t)len*sizeof(opus_int8));
}

void dump_silk_pulses16(int encode,const opus_int16 *vals,int len)
{
    dump_array(encode?"enc_silk.bin":"dec_silk.bin",vals,(size_t)len*sizeof(opus_int16));
}

void dump_celt_coef(int encode,const celt_norm *vals,int len)
{
    dump_array(encode?"enc_celt.bin":"dec_celt.bin",vals,(size_t)len*sizeof(celt_norm));
}
