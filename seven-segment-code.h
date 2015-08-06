#ifndef SEVEN_SEGMENT_CODE_H_66BC65DB_AFF6_43C8_8654_D1A2801635E2
#define SEVEN_SEGMENT_CODE_H_66BC65DB_AFF6_43C8_8654_D1A2801635E2

//
//#define   SEVEN_SEGMENT_BIT_A    B00000001
//#define   SEVEN_SEGMENT_BIT_B    B00000010
//#define   SEVEN_SEGMENT_BIT_C    B00000100
//#define   SEVEN_SEGMENT_BIT_D    B00001000
//#define   SEVEN_SEGMENT_BIT_E    B00010000
//#define   SEVEN_SEGMENT_BIT_F    B00100000
//#define   SEVEN_SEGMENT_BIT_G    B01000000
//#define   SEVEN_SEGMENT_BIT_DOT  B10000000
//

//
//#if !defined(SEVEN_SEGMENT_BIT_A)    ||  !defined(SEVEN_SEGMENT_BIT_B)    \
//||  !defined(SEVEN_SEGMENT_BIT_C)    ||  !defined(SEVEN_SEGMENT_BIT_D)    \
//||  !defined(SEVEN_SEGMENT_BIT_E)    ||  !defined(SEVEN_SEGMENT_BIT_F)    \
//||  !defined(SEVEN_SEGMENT_BIT_G)    ||  !defined(SEVEN_SEGMENT_BIT_DOT)
//#   error   SEVEN_SEGMENT_BIT_A/B/C/D/E/F/G/DOT  must be defined
//#endif
//

#define SEVEN_SEGMENT_CODE_0      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_E \
    |   SEVEN_SEGMENT_BIT_F \
)

#define SEVEN_SEGMENT_CODE_1      (0u\
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
)

#define SEVEN_SEGMENT_CODE_2      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_E \
    |   SEVEN_SEGMENT_BIT_G \
)

#define SEVEN_SEGMENT_CODE_3      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_G \
)

#define SEVEN_SEGMENT_CODE_4      (0u\
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_F \
    |   SEVEN_SEGMENT_BIT_G \
)

#define SEVEN_SEGMENT_CODE_5      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_F \
    |   SEVEN_SEGMENT_BIT_G \
)

#define SEVEN_SEGMENT_CODE_6      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_E \
    |   SEVEN_SEGMENT_BIT_F \
    |   SEVEN_SEGMENT_BIT_G \
)

#define SEVEN_SEGMENT_CODE_7      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
)

#define SEVEN_SEGMENT_CODE_8      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_E \
    |   SEVEN_SEGMENT_BIT_F \
    |   SEVEN_SEGMENT_BIT_G \
)

#define SEVEN_SEGMENT_CODE_9      (0u\
    |   SEVEN_SEGMENT_BIT_A \
    |   SEVEN_SEGMENT_BIT_B \
    |   SEVEN_SEGMENT_BIT_C \
    |   SEVEN_SEGMENT_BIT_D \
    |   SEVEN_SEGMENT_BIT_F \
    |   SEVEN_SEGMENT_BIT_G \
)

// common cathode seven segment code
#define CC7S_CODE_(N)   (SEVEN_SEGMENT_CODE_##N)
// common cathode seven segment code
#define CA7S_CODE_(N)   (~SEVEN_SEGMENT_CODE_##N)

#endif
