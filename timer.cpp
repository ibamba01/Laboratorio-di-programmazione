//
// Created by Pietro on 16/03/2023.
//

#include <iostream>
#include "timer.h"
#include<math.h>
#include <chrono>
#include <ncurses/ncurses.h>

using namespace std;
using namespace std::chrono;

timer::timer() {
    start = high_resolution_clock::now();
    //stop = high_resolution_clock::now(); //lo stoppo con la funzione
    duration =::duration<int>::zero();
    isrunning = false;
}

 void timer::startTimer() { //avvia il timer
     if (duration != ::duration<int>::zero()) { //fa un precheck che la durata sia stata impostata
         if (!isrunning || remaining_Time() > 0) { //non può partire se il tempo rimasto è 0
             start = high_resolution_clock::now();
             isrunning = true;
         } else {
             cout << "Timer is already running" << endl;
         }
     }
     else {
         cout<<"Set the time first"<<endl;
     }
}

  bool timer::stopTimer() {
    if (isrunning) {

            time_point<high_resolution_clock> now = high_resolution_clock::now(); //tempo corrente
           //duration è il tempo rimanente
          ::duration<int, milli> remaining = duration - duration_cast<::duration<int, milli>>(now - start);
          isrunning = false;
        }
    else {
      cout<<"Timer is not running"<<endl;
    }
  }

  int timer::remaining_Time() {
    if (!isrunning){
        return (int)round(duration.count()/1000); //return time in seconds, .count() returns time in milliseconds
    }
    else {//se il timer è in esecuzione, senza FERMARE prende il tempo corrente e lo sottrae al tempo di partenza
        time_point<high_resolution_clock> now = high_resolution_clock::now(); //tempo corrente
        float elapsed = (float)round(duration_cast<::duration<float>>(now - start).count()/1000.0); //tempo trascorso, devo tenerlo in float per non perdere i decimali
        int remaining = (int)round(duration.count()/1000.0 - elapsed); //tempo rimanente
        if (remaining > 0) { //if the timer is running and the time is > 0
            return remaining;
        }
        else { //no negatives
            return 0;
        }

    }
}

bool timer::set_time(int time) {
    if (isrunning) {
        cout<<"Timer is running, stop it first"<<endl;
        return false;
    }
    else {
        if (time > 0) {
            duration = ::duration<int>(time*1000);
            return true;

        }
        else {
            cout<<"Time must be > 0"<<endl;
            return false;
        }
    }

}

void timer::resetTimer() { //ci pensa da solo a fermare il timer
    stopTimer();
    duration = ::duration<int>::zero();
}
