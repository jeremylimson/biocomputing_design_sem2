/*
* 2-18-2022
* jeremy limson a.k.a. "tarantula"
* description : you're gonna need to take an anti virus for that lower hack pain
*/

#include "limsonj_MiniProject0.hpp"

int main(int argc, char * argv[]) {
    std::string snap_hack_to_reality;
    int time = 0;
    
    // prompt user to input hack object
    std::cout << "Tell me what you want hacked, friend:\n";
    std::cin >> snap_hack_to_reality;
    
    // get user input for hack duration
    std::cout << "\nHow long do you want to bully this nerd:\n";
    std::cin >> time;
    
    // create instance of namepsace
    empire_strikes_hack::TimeHacking hack_in_the_box(snap_hack_to_reality);

    // set the time to hack
    hack_in_the_box.setTimeToHack(time);

    // print out private class variables
    std::cout << "\nHacking " << hack_in_the_box.getObjectToHack();
    std::cout << " for " << hack_in_the_box.getTimeToHack() << " seconds...\n";

    // hack to your heart's content
    hack_in_the_box.hackTime();

    // display to user when the hack is complete
    std::cout << "\r\n**Hack complete. Tarantula strikes again.**\r\n";

    std::cout << "\r          (          " << "\n";
    std::cout << "           )          " << "\n";
    std::cout << "          (           " << "\n";
    std::cout << "    /\\  .-\"\"\"-.  /\\   " << "\n";
    std::cout << "   //\\/  ,,,  \\//\\  " << "\n";
    std::cout << "   |/\\| ,;;;;;, |/\\|  " << "\n";
    std::cout << "   //\\\\;-\"\"\"-;///\\  " << "\n";
    std::cout << "  //  \\/   .   \\/  \\ " << "\n";
    std::cout << " (| ,-_| \\ | / |_-, |)" << "\n";
    std::cout << "   //`__\\.-.-./__`\\  " << "\n";
    std::cout << "  // /.-(() ())-.\\ \\ " << "\n";
    std::cout << " (\\ |)   '---'   (| /)" << "\n";
    std::cout << "  ` (|           |) ` " << "\n";
    std::cout << "    \\)           (/   " << "\n";

    return 0;
}