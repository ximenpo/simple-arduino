#ifndef TIMING_H_66BC65DB_AFF6_43C8_8654_D1A2801635E2
#define TIMING_H_66BC65DB_AFF6_43C8_8654_D1A2801635E2

#include  "procedure.h"
#include  "timestamp.h"

template<typename STAMP_TYPE = unsigned long>
class  timing  : public procedure_context, private timestamp_timing<STAMP_TYPE> {
public:
    void  init() {
    }

    bool  check_timeout(STAMP_TYPE timestamp, unsigned interval) {
        this->current_timestamp = timestamp;
        PROCEDURE_BEGIN(this);

        PROCEDURE_SLEEP_(this, interval, false);
        PROCEDURE_YIELD_(true);

        PROCEDURE_END_(false);
    }

    bool  check_periodic(STAMP_TYPE timestamp, unsigned interval) {
        this->current_timestamp = timestamp;
        PROCEDURE_BEGIN(this);

        for(;;) {
            PROCEDURE_SLEEP_(this, interval, false);
            PROCEDURE_YIELD_(true);
        }

        PROCEDURE_END_(false);
    }

    bool  check_periodic(STAMP_TYPE timestamp, unsigned interval, int times) {
        this->current_timestamp = timestamp;
        PROCEDURE_BEGIN(this);

        for(this->times = 0; (times < 0) || (this->times < times); this->times++) {
            PROCEDURE_SLEEP_(this, interval, false);
            PROCEDURE_YIELD_(true);
        }

        PROCEDURE_END_(false);
    }

private:
    unsigned    times;
};

#endif
