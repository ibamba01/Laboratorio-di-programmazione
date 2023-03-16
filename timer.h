//
// Created by Pietro on 16/03/2023.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_TIMER_H
#define LABORATORIO_PROGRAMMAZIONE_TIMER_H
#include <chrono>

using namespace std;
using namespace std::chrono;



class timer {
public:
    timer();

    void startTimer(); //avvia

    bool stopTimer(); //pausa, è in bool per fermare se va sotto zero

    void resetTimer(); //reset

    int remaining_Time();

    bool set_time(int time); //lo tengo in bool almeno so gestire i possibii errori


    private:
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;
    ::duration<int, milli > duration;
    bool isrunning;
    int show_mode;


};


#endif //LABORATORIO_PROGRAMMAZIONE_TIMER_H
