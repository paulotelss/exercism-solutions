#include "bank_account.h"
#include <stdexcept>

namespace bank_account {

    BankAccount::BankAccount() : _balance(0), _is_open(false) {}

    void BankAccount::open() {
        std::lock_guard<std::mutex> lock(mtx);
        _balance = 0;
        _is_open = true;
    }

    void BankAccount::close() {
        std::lock_guard<std::mutex> lock(mtx);
        _is_open = false;
    }

    int BankAccount::balance() const {
        std::lock_guard<std::mutex> lock(mtx);
        check_open();
        return _balance;
    }

    void BankAccount::deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        check_open();
        if (amount < 0) throw std::domain_error("Valor de depósito negativo");
        _balance += amount;
    }

    void BankAccount::withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        check_open();
        if (amount < 0) throw std::domain_error("Valor de saque negativo");
        if (amount > _balance) throw std::domain_error("Saldo insuficiente");
        _balance -= amount;
    }

    void BankAccount::check_open() const {
        if (!_is_open) {
            throw std::runtime_error("Conta está fechada");
        }
    }

}  // namespace bank_account