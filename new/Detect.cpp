//
// Created by lhy on 2024/9/17.
//

#include "Detect.h"

namespace liaohy {
    void Detect::lostFunc() {

    }

    void Detect::recoverFunc() {

    }

    void Detect::update() {
        lastRecieveTime = getSysTime();
    }

    void Detect::JudgeLost() {
        uint32_t presentTime = getSysTime();
        if (presentTime - lastRecieveTime > maxInterval) {
            if (!isLost) {
                lostFunc();
                isLost = 1;
            }
        } else {
            if (isLost) {
                recoverFunc();
                isLost = 0;
            }
        }
    }

    Detect::Detect(uint32_t maxInterval, uint32_t lastRecieveTime, uint8_t isLost, DetectManager *manager) : maxInterval(maxInterval), lastRecieveTime(lastRecieveTime), isLost(isLost) {
        detectManager = manager;
        detectManager->Register(this);
    }

    Detect::~Detect()  {
        detectManager->Unregister(this);
    }

} // liaohy