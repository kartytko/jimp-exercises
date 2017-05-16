//
// Created by kartytko on 07.05.17.
//

#include <iostream>
#include "MovieSubtitles.h"

int main(){
  /*  std::stringstream in {"1\nTEXT\n\n2\n00:19:14,141 --> 0:17:20,100\nTT\n"};
    std::stringstream out;
    moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(300, 24, &in, &out);
    char c;
*/

    std::stringstream in2 {"{10}{787}TEXT\n{260}{220NEWLINE\n"};
    std::stringstream out2;
    moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(1000, 24, &in2, &out2);
    char c;
    std::cout<<std::endl<<std::endl;
    while(out2.get(c)){
        std::cout<<c;
   }
    return 0;
}