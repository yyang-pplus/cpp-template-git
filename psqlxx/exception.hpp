#pragma once

#include <exception>
#include <string>


namespace psqlxx {

class Exception : public std::exception {
public:
    explicit Exception(std::string message) noexcept: m_message(std::move(message)) {
    }

    [[nodiscard]]
    const char *
    what() const noexcept override {
        return m_message.c_str();
    }

private:
    std::string m_message;
};

}//namespace psqlxx
