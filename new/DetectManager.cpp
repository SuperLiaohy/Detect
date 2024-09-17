//
// Created by lhy on 2024/9/17.
//

#include "DetectManager.h"

namespace liaohy {

    void DetectManager::Register(Detect *detect) {
        detects.push_back(detect);
    }

    void DetectManager::Unregister(Detect *detect) {
        detects.erase(std::remove(detects.begin(), detects.end(), detect), detects.end());
    }

    void DetectManager::JudgeLost() {
        for (auto detect : detects) {
            detect->JudgeLost();
        }

    }

} // liaohy