#ifndef IRCONTROL_H
#define IRCONTROL_H

#include "IRremote.h"

#include "Motors.h"

#define ZERO 16730805
#define ONE 16738455
#define TWO 16750695
#define THREE 16756815
#define FOUR 16724175
#define FIVE 16718055
#define SIX 16743045
#define SEVEN 16716015
#define EIGHT 16726215
#define NINE 16734885

#define UP 16736925
#define DOWN 16754775
#define LEFT 16720605
#define RIGHT 16761405


namespace Car
{
    const int IR_PIN = 12;

    enum action
    {
        up,
        down,
        left,
        right,
        none,
        err,
        one,
        two,
        three,
        four
    };

    class IRControl : public Motors
    {
    public:
        IRControl();
        ~IRControl();

        void enable();
        action decodeIR();
    private:
        decode_results results;
        unsigned long prevKey;
        IRrecv recv;
        int speed = 255;
    };
}

#endif