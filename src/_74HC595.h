#ifndef _74HC595_CODE_H_66BC65DB_AFF6_43C8_8654_D1A2801635E2
#define _74HC595_CODE_H_66BC65DB_AFF6_43C8_8654_D1A2801635E2

#include <Arduino.h>

struct _74HC595_DATA {
    unsigned char   data_pin;
    unsigned char   clock_pin;
    unsigned char   latch_pin;
    unsigned int    bit_seq;
};

#define _74HC595_INIT(PO)           {   \
    pinMode((PO).data_pin,OUTPUT);      \
    pinMode((PO).clock_pin,OUTPUT);     \
    pinMode((PO).latch_pin,OUTPUT);     \
}
#define _74HC595_BEGIN(PO)          digitalWrite((PO).latch_pin, LOW)
#define _74HC595_WRITE(PO,value)    shiftOut((PO).data_pin, (PO).clock_pin, (PO).bit_seq, value)
#define _74HC595_END(PO)            digitalWrite((PO).latch_pin, HIGH)

struct  X_74HC595 {
    _74HC595_DATA   data;

    void init()const {
        _74HC595_INIT(data);
    }

    void begin()const {
        _74HC595_BEGIN(data);
    }

    void write(unsigned int value)const {
        _74HC595_WRITE(data, value);
    }

    void end()const {
        _74HC595_END(data);
    }

    void update(unsigned int value)const {
        _74HC595_BEGIN(data);
        _74HC595_WRITE(data, value);
        _74HC595_END(data);
    }
};

#endif
