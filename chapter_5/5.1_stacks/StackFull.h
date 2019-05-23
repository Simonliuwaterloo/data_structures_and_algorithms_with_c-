class StackFull: public std::runtime_error {
public:
    StackFull(const std::string& err): std::runtime_error(err) {}
};