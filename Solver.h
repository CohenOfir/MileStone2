#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H


template <class P, class S>
class Solver {
public:
    virtual S solve(P prob) = 0;
    virtual ~Solver() = default;
};



#endif //EX4_SOLVER_H
