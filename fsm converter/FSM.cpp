//
//  FSM.cpp
//  assignment 4a fsm converter
//
//  Created by Vincent Hoang on 6/24/19.
//

#include "FSM.hpp"
#include <iostream>
#include <string>

#define STATE_BANANA    0b01
#define STATE_APPLE     0b10
#define STATE_EMPTY     0b00

#define OUTPUT_BANANA    0b01
#define OUTPUT_APPLE     0b10
#define OUTPUT_EMPTY     0b00

struct FSM::Private {
    static void setOutput(FSM& self, int output) {
        self.mOutput = output;
    }
    
    static void setNextState(FSM& self, int nextState) {
        self.mNextState = nextState;
    }
    
    static void setInputApple(FSM& self, int input) {
        self.mInputApple = input;
    }
    
    static void setInputBanana(FSM& self, int input) {
        self.mInputBanana = input;
    }
};

FSM::FSM() {}

FSM::FSM(const int currentState) {
    mCurrentState = currentState;
    mOutput = -1;
    mNextState = currentState;
}

int FSM::getCurrentState() const {
    return mCurrentState;
}

int FSM::getOutput() const {
    return mOutput;
}

int FSM::getInputApple() const {
    return mInputApple;
}

int FSM::getInputBanana() const {
    return mInputBanana;
}

int FSM::getNextState() const {
    return mNextState;
}

void FSM::calculate(const int inputApple, const int inputBanana) {
    Private::setInputApple(*this, inputApple);
    Private::setInputBanana(*this, inputBanana);
    
    // MSB = 1; Want Apple
    if (getInputApple() == 1) {
        // LSB = 1; Want Both
        if (getInputBanana() == 1) {
            // Can't have both
            Private::setOutput(*this, OUTPUT_EMPTY);
                
            Private::setNextState(*this, STATE_EMPTY);
        } else {
            // Current state is empty; Want Apple, not Banana
            if (getCurrentState() == STATE_EMPTY) {
                Private::setOutput(*this, OUTPUT_APPLE);
                
                Private::setNextState(*this, STATE_APPLE);
            }
            // Current state is Banana; Want Apple, not Banana
            else if (getCurrentState() == STATE_BANANA) {
                Private::setOutput(*this, OUTPUT_APPLE);
                
                Private::setNextState(*this, STATE_EMPTY);
            }
            // Current state is Apple; Want Apple, not Banana
            else if (getCurrentState() == STATE_APPLE) {
                Private::setOutput(*this, OUTPUT_APPLE);
                
                // State stays the same
            }
        }
    } else { // MSB = 0
        // LSB = 1
        if (getInputBanana() == 1) {
            // Current state is empty; Want Banana, not Apple
            if (getCurrentState() == STATE_EMPTY) {
                Private::setOutput(*this, OUTPUT_BANANA);
                
                Private::setNextState(*this, STATE_BANANA);
            }
            // Current state is Banana; Want Banana, not Apple
            else if (getCurrentState() == STATE_BANANA) {
                Private::setOutput(*this, OUTPUT_BANANA);
                
                // State stays the same
            }
            // Current state is Apple; Want Banana, not Apple
            else if (getCurrentState() == STATE_APPLE) {
                Private::setOutput(*this, OUTPUT_BANANA);
                
                Private::setNextState(*this, STATE_EMPTY);
            }
            
        } else { // LSB = 0; Neither Apple or Banana wanted
           // State stays the same
            Private::setOutput(*this, OUTPUT_EMPTY);
        }
    }
}

void FSM::print() {
    std::bitset<2> currentState(getCurrentState());
    std::bitset<1> inputApple(getInputApple());
    std::bitset<1> inputBanana(getInputBanana());
    std::bitset<2> output(getOutput());
    std::bitset<2> nextState(getNextState());
    
    std::cout << "Current State: " << currentState << " InputApple: "
        << inputApple << " InputBanana: " << inputBanana
        << " Output: " << output << " Next State: "
        << nextState << std::endl;
}

