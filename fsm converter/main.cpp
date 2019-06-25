//
//  main.cpp
//  assignment 4a fsm converter
//
//  Created by Vincent Hoang on 6/24/19.
//

#include "main.hpp"
#include "FSM.hpp"

#include <iostream>
#include <string>
#include <vector>

#define STATE_BANANA    0b01
#define STATE_APPLE     0b10
#define STATE_EMPTY     0b00

#define OUTPUT_BANANA    0b01
#define OUTPUT_APPLE     0b10
#define OUTPUT_EMPTY     0b00

int main(void) {
    std::vector<FSM> fsmObjectVector;
    
    for (int i = 0b00; i < 0b11; i++) {
        for (int apple = 0; apple <= 1; apple++) {
            for (int banana = 0; banana <= 1; banana++) {
                FSM fsmObject(i);
                fsmObject.calculate(apple, banana);
                fsmObjectVector.push_back(fsmObject);
            }
        }
    }
    
    for (auto& element : fsmObjectVector) {
        element.print();
    }
}


