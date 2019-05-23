#ifndef _stack_empty_
#define _stack_empty_
class StackEmpty: public std::runtime_error {
public:
    StackEmpty(const std::string& err): std::runtime_error(err) {}
};

#endif