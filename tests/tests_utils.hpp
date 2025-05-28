#pragma once
#include <string>

class MoveCopyFlag {
    public:
    std::string state;
    MoveCopyFlag() : state("default") {}
    MoveCopyFlag(const MoveCopyFlag& other) : state(other.state + ", copied") {}
    MoveCopyFlag(MoveCopyFlag&& other) : state(other.state + ", moved") {}
    
    MoveCopyFlag& operator=(const MoveCopyFlag& other) {
        state = other.state + ", copied";
        return *this;
    }
    
    MoveCopyFlag& operator=(MoveCopyFlag&& other) {
        state = other.state + ", moved";
        return *this;
    }
};

class DestructionFlag {
    public:
    bool* destroyed;
    DestructionFlag(bool* a_destroyed) : destroyed(a_destroyed) {}
    ~DestructionFlag() { *destroyed = true; }
};
