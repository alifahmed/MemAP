#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include "immintrin.h"

__attribute__((always_inline)) static inline uint64_t bounded_rnd(uint64_t bound) {
    static uint64_t hash = 0xC32ED012FEA8B4D3ULL;
    hash = (hash  << 1) ^ (((int64_t)hash < 0) ? 7 : 0);
    return (hash * (__uint128_t)bound) >> 64;
}

#define READ_1b(X)  __asm__ __volatile__ ("movb       (%1,%2), %0" : "=r"(tmp1)  : "r"(gm), "r"(X) : "memory")
#define READ_2b(X)  __asm__ __volatile__ ("movw       (%1,%2), %0" : "=r"(tmp2)  : "r"(gm), "r"(X) : "memory")
#define READ_4b(X)  __asm__ __volatile__ ("movl       (%1,%2), %0" : "=r"(tmp4)  : "r"(gm), "r"(X) : "memory")
#define READ_8b(X)  __asm__ __volatile__ ("movq       (%1,%2), %0" : "=r"(tmp8)  : "r"(gm), "r"(X) : "memory")
#define READ_16b(X) tmp16 = _mm_load_si128((__m128i const*)(gm + (X)))
#define READ_32b(X) tmp32 = _mm256_load_si256((__m256i const*)(gm + (X)))
#define READ_64b(X) tmp64 = _mm512_load_si512((__m512i const*)(gm + (X)))

#define WRITE_1b(X)  __asm__ __volatile__ ("movb      %2, (%0,%1)" : : "r"(gm), "r"(X), "r"(tmp1)  : "memory")
#define WRITE_2b(X)  __asm__ __volatile__ ("movw      %2, (%0,%1)" : : "r"(gm), "r"(X), "r"(tmp2)  : "memory")
#define WRITE_4b(X)  __asm__ __volatile__ ("movl      %2, (%0,%1)" : : "r"(gm), "r"(X), "r"(tmp4)  : "memory")
#define WRITE_8b(X)  __asm__ __volatile__ ("movq      %2, (%0,%1)" : : "r"(gm), "r"(X), "r"(tmp8)  : "memory")
#define WRITE_16b(X) _mm_store_si128((__m128i*)(gm + (X)), tmp16)
#define WRITE_32b(X) _mm256_store_si256((__m256i*)(gm + (X)), tmp32)
#define WRITE_64b(X) _mm512_store_si512((__m512i*)(gm + (X)), tmp64)

#define RMW_1b(X)  __asm__ __volatile__ ("addb $1, (%0,%1)" : : "r"(gm), "r"(X) : "memory")
#define RMW_2b(X)  __asm__ __volatile__ ("addw $1, (%0,%1)" : : "r"(gm), "r"(X) : "memory")
#define RMW_4b(X)  __asm__ __volatile__ ("addl $1, (%0,%1)" : : "r"(gm), "r"(X) : "memory")
#define RMW_8b(X)  __asm__ __volatile__ ("addq $1, (%0,%1)" : : "r"(gm), "r"(X) : "memory")

volatile uint8_t* gm;
#ifdef __SSE2__
    volatile __m128i tmp16;
#endif
#ifdef __AVX__
    volatile __m256i tmp32;
#endif
#ifdef __AVX512F__
    volatile __m512i tmp64;
#endif

int main(){
    int64_t addr;
    uint64_t tmpRnd;
    uint8_t tmp1;
    uint16_t tmp2;
    uint32_t tmp4;
    uint64_t tmp8;
    uint64_t allocSize = 127750144ULL;
    gm = (volatile uint8_t*)aligned_alloc(4096, allocSize);

    // Interval: 0 - 200000000
    {
        int64_t addr_395600101 = 127746500LL, strd_395600101 = 0;
        int64_t addr_395700101 = 127746512LL, strd_395700101 = 0;
        int64_t addr_395800101 = 127746512LL, strd_395800101 = 0;
        int64_t addr_397000101 = 16LL;
block0:
        goto block2;

block4:
        //Small tile
        WRITE_4b(addr_395800101);
        switch(addr_395800101) {
            case 127746500LL : strd_395800101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395800101 = (127746500LL - 127746620LL); break;
            case 127746512LL : strd_395800101 = (127746516LL - 127746512LL); break;
        }
        addr_395800101 += strd_395800101;

        //Small tile
        WRITE_4b(addr_397000101);
        addr_397000101 += (20LL - 16LL);

        goto block2;

block2:
        //Small tile
        READ_4b(addr_395600101);
        switch(addr_395600101) {
            case 127746500LL : strd_395600101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395600101 = (127746500LL - 127746620LL); break;
        }
        addr_395600101 += strd_395600101;

        //Small tile
        READ_4b(addr_395700101);
        switch(addr_395700101) {
            case 127746500LL : strd_395700101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395700101 = (127746500LL - 127746620LL); break;
            case 127746512LL : strd_395700101 = (127746516LL - 127746512LL); break;
        }
        addr_395700101 += strd_395700101;

        //Few edges. Don't bother optimizing
        static uint64_t out_2 = 0;
        out_2++;
        if (out_2 <= 7142576LL) goto block4;
        else goto block5;


block5:
        int dummy;
    }

    // Interval: 200000000 - 400000000
    {
        int64_t addr_395800101 = 127746596LL, strd_395800101 = 0;
        int64_t addr_395600101 = 127746588LL, strd_395600101 = 0;
        int64_t addr_395700101 = 127746600LL, strd_395700101 = 0;
        int64_t addr_397000101 = 28570320LL;
block6:
        goto block7;

block7:
        //Small tile
        WRITE_4b(addr_395800101);
        switch(addr_395800101) {
            case 127746500LL : strd_395800101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395800101 = (127746500LL - 127746620LL); break;
            case 127746596LL : strd_395800101 = (127746600LL - 127746596LL); break;
        }
        addr_395800101 += strd_395800101;

        //Few edges. Don't bother optimizing
        static uint64_t out_7 = 0;
        out_7++;
        if (out_7 <= 7142838LL) goto block10;
        else goto block11;


block10:
        //Small tile
        WRITE_4b(addr_397000101);
        addr_397000101 += (28570324LL - 28570320LL);

        //Small tile
        READ_4b(addr_395600101);
        switch(addr_395600101) {
            case 127746500LL : strd_395600101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395600101 = (127746500LL - 127746620LL); break;
            case 127746588LL : strd_395600101 = (127746592LL - 127746588LL); break;
        }
        addr_395600101 += strd_395600101;

        //Small tile
        READ_4b(addr_395700101);
        switch(addr_395700101) {
            case 127746500LL : strd_395700101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395700101 = (127746500LL - 127746620LL); break;
            case 127746600LL : strd_395700101 = (127746604LL - 127746600LL); break;
        }
        addr_395700101 += strd_395700101;

        goto block7;

block11:
        int dummy;
    }

    // Interval: 400000000 - 600000000
    {
        int64_t addr_395600101 = 127746604LL, strd_395600101 = 0;
        int64_t addr_395700101 = 127746616LL, strd_395700101 = 0;
        int64_t addr_395800101 = 127746616LL, strd_395800101 = 0;
block12:
        goto block16;

block16:
        for(uint64_t loop0 = 0; loop0 < 7142838ULL; loop0++){
            //Loop Indexed
            addr = 57141672LL + (4 * loop0);
            WRITE_4b(addr);

            //Small tile
            READ_4b(addr_395600101);
            switch(addr_395600101) {
                case 127746500LL : strd_395600101 = (127746504LL - 127746500LL); break;
                case 127746620LL : strd_395600101 = (127746500LL - 127746620LL); break;
                case 127746604LL : strd_395600101 = (127746608LL - 127746604LL); break;
            }
            addr_395600101 += strd_395600101;

            //Small tile
            READ_4b(addr_395700101);
            switch(addr_395700101) {
                case 127746500LL : strd_395700101 = (127746504LL - 127746500LL); break;
                case 127746620LL : strd_395700101 = (127746500LL - 127746620LL); break;
                case 127746616LL : strd_395700101 = (127746620LL - 127746616LL); break;
            }
            addr_395700101 += strd_395700101;

            //Small tile
            WRITE_4b(addr_395800101);
            switch(addr_395800101) {
                case 127746500LL : strd_395800101 = (127746504LL - 127746500LL); break;
                case 127746620LL : strd_395800101 = (127746500LL - 127746620LL); break;
                case 127746616LL : strd_395800101 = (127746620LL - 127746616LL); break;
            }
            addr_395800101 += strd_395800101;

        }
        goto block17;

block17:
        int dummy;
    }

    // Interval: 600000000 - 800000000
    {
        int64_t addr_395600101 = 127746620LL, strd_395600101 = 0;
        int64_t addr_395700101 = 127746508LL, strd_395700101 = 0;
        int64_t addr_397000101 = 85713024LL;
        int64_t addr_395800101 = 127746508LL, strd_395800101 = 0;
block18:
        goto block21;

block21:
        //Small tile
        WRITE_4b(addr_397000101);
        addr_397000101 += (85713028LL - 85713024LL);

        //Small tile
        READ_4b(addr_395600101);
        switch(addr_395600101) {
            case 127746500LL : strd_395600101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395600101 = (127746500LL - 127746620LL); break;
        }
        addr_395600101 += strd_395600101;

        //Small tile
        READ_4b(addr_395700101);
        switch(addr_395700101) {
            case 127746500LL : strd_395700101 = (127746504LL - 127746500LL); break;
            case 127746508LL : strd_395700101 = (127746512LL - 127746508LL); break;
            case 127746620LL : strd_395700101 = (127746500LL - 127746620LL); break;
        }
        addr_395700101 += strd_395700101;

        //Few edges. Don't bother optimizing
        static uint64_t out_21 = 0;
        out_21++;
        if (out_21 <= 7142837LL) goto block22;
        else goto block23;


block22:
        //Small tile
        WRITE_4b(addr_395800101);
        switch(addr_395800101) {
            case 127746500LL : strd_395800101 = (127746504LL - 127746500LL); break;
            case 127746508LL : strd_395800101 = (127746512LL - 127746508LL); break;
            case 127746620LL : strd_395800101 = (127746500LL - 127746620LL); break;
        }
        addr_395800101 += strd_395800101;

        goto block21;

block23:
        int dummy;
    }

    // Interval: 800000000 - 894227715
    {
        int64_t addr_395800101 = 127746520LL, strd_395800101 = 0;
        int64_t addr_397000101 = 114284376LL;
        int64_t addr_395600101 = 127746512LL, strd_395600101 = 0;
        int64_t addr_395700101 = 127746524LL, strd_395700101 = 0;
block24:
        goto block26;

block28:
        //Small tile
        READ_4b(addr_395600101);
        switch(addr_395600101) {
            case 127746500LL : strd_395600101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395600101 = (127746500LL - 127746620LL); break;
            case 127746512LL : strd_395600101 = (127746516LL - 127746512LL); break;
        }
        addr_395600101 += strd_395600101;

        //Small tile
        READ_4b(addr_395700101);
        switch(addr_395700101) {
            case 127746500LL : strd_395700101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395700101 = (127746500LL - 127746620LL); break;
            case 127746524LL : strd_395700101 = (127746528LL - 127746524LL); break;
        }
        addr_395700101 += strd_395700101;

        goto block26;

block26:
        //Small tile
        WRITE_4b(addr_395800101);
        switch(addr_395800101) {
            case 127746500LL : strd_395800101 = (127746504LL - 127746500LL); break;
            case 127746620LL : strd_395800101 = (127746500LL - 127746620LL); break;
            case 127746520LL : strd_395800101 = (127746524LL - 127746520LL); break;
        }
        addr_395800101 += strd_395800101;

        //Small tile
        WRITE_4b(addr_397000101);
        addr_397000101 += (114284380LL - 114284376LL);

        //Few edges. Don't bother optimizing
        static uint64_t out_26 = 0;
        out_26++;
        if (out_26 <= 3365266LL) goto block28;
        else goto block29;


block29:
        int dummy;
    }

    free((void*)gm);
    return 0;
}