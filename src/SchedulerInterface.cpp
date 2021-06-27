//
// Created by Ben on 5/18/2021.
//

double SchedulerInterface::schedule(std::vector<int>& s) {
    scheduletron.schedule(s);
    return scheduletron.getAccuracy();
}