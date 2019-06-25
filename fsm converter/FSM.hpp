//
//  FSM.hpp
//  assignment 4a fsm converter
//
//  Created by Vincent Hoang on 6/24/19.
//

#ifndef FSM_hpp
#define FSM_hpp

class FSM {
private:
    struct Private;
    int mCurrentState;
    int mOutput;
    int mInputApple;
    int mInputBanana;
    int mNextState;
    
    //void setOutput();
    //void setNextState();
public:
    FSM();
    FSM(const int);
    
    int getCurrentState() const;
    int getOutput() const;
    int getInputApple() const;
    int getInputBanana() const;
    int getNextState() const;
    
    void calculate(const int, const int);
    void print();
    
    ~FSM() {}
};

#endif /* FSM_hpp */
