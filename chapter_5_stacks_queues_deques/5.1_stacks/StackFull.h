#ifndef _stack_full_
#define _stack_full_
class StackFull: public std::runtime_error {
public:
    StackFull(const std::string& err): std::runtime_error(err) {}
};

#endif