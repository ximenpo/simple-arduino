#include  <Arduino.h>
#include  "procedure.h"
#include  "timestamp.h"

template<typename STAMP_TYPE = unsigned long>
class  debouncing  : public procedure_context, timestamp_timing<STAMP_TYPE> {
  public:
    void  init(int pin, int expect) {
      this->pin = pin;
      this->expect  = expect;

      pinMode(this->pin, INPUT);
    }

    bool  update(STAMP_TYPE timestamp) {
      this->current_timestamp = timestamp;
      PROCEDURE_BEGIN_RUNLOOP(this);

      //  first trigger
      PROCEDURE_WAIT_(digitalRead(this->pin) == this->expect, false);

      //  second check
      PROCEDURE_SLEEP_(this, 50, false);
      if (digitalRead(this->pin) != this->expect) {
        PROCEDURE_STOP_(false);
      }

      //  waiting for end.
      PROCEDURE_WAIT_(digitalRead(this->pin) != this->expect, false);

      PROCEDURE_END_(true);
    }

  private:
    int   pin;
    int   expect;
};

