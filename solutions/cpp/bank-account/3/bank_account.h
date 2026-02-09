#pragma once

#include <mutex>

namespace Bankaccount {

class Bankaccount {
public:
    Bankaccount();

    void open();
    void close();
    void deposit(int amount);
    void withdraw(int amount);
    int balance() const;

private:
    mutable std::mutex mtx;
    int _balance;
    bool _is_open;

    void check_open() const;
};

}  // namespace Bankaccount