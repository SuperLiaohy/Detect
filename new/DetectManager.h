//
// Created by lhy on 2024/9/17.
//

#ifndef NEW_PRJ_DETECTMANAGER_H
#define NEW_PRJ_DETECTMANAGER_H
#include "Detect.h"
#include <algorithm>
#include "vector"

namespace liaohy {
    class Detect;
    class DetectManager {
    public:
        DetectManager() {}

        void Register(Detect *detect);
        void Unregister(Detect *detect);
        void JudgeLost();

    private:
        std::vector<Detect *> detects;
    };

} // liaohy

#endif //NEW_PRJ_DETECTMANAGER_H
