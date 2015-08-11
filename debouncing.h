#include  <Arduino.h>
#include  "procedure.h"
#include  "timestamp.h"

template<typename STAMP_TYPE = unsigned long>
class  debouncing  : public procedure_context, timestamp_timing<STAMP_TYPE> {
public:
    debouncing() : pin(-1) {
    }

    void  init(int pin) {
        this->pin = pin;

        pinMode(this->pin, INPUT);
    }

    bool  check_state(STAMP_TYPE timestamp, int expected_pin_state, unsigned delay = 50) {
        this->current_timestamp = timestamp;
        PROCEDURE_BEGIN_RUNLOOP(this);

        //  first trigger
        PROCEDURE_WAIT_(digitalRead(this->pin) == expected_pin_state, false);

        //  second check
        PROCEDURE_SLEEP_(this, delay, false);
        if (digitalRead(this->pin) != expected_pin_state) {
            PROCEDURE_STOP_(false);
        }

        PROCEDURE_END_(true);
    }

    bool  check_click(STAMP_TYPE timestamp, int expected_pin_state, unsigned delay = 50) {
        this->current_timestamp = timestamp;
        PROCEDURE_BEGIN_RUNLOOP(this);

        //  first trigger
        PROCEDURE_WAIT_(digitalRead(this->pin) == expected_pin_state, false);

        //  second check
        PROCEDURE_SLEEP_(this, delay, false);
        if (digitalRead(this->pin) != expected_pin_state) {
            PROCEDURE_STOP_(false);
        }

        //  waiting for end.
        PROCEDURE_WAIT_(digitalRead(this->pin) != expected_pin_state, false);

        PROCEDURE_END_(true);
    }

private:
    int   pin;
};
