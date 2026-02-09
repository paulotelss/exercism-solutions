#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {

Bankaccount::Bankaccount() : _balance(0), _is_open(false) {}

void Bankaccount::open() {
    std::lock_guard<std::mutex> lock(mtx);
    _is_open = true;
    _balance = 0;
}

void Bankaccount::close() {
    std::lock_guard<std::mutex> lock(mtx);
    _is_open = false;
}

int Bankaccount::balance() const {
    std::lock_guard<std::mutex> lock(mtx);
    check_open();
    return _balance;
}

void Bankaccount::deposit(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    check_open();
    if (amount < 0) {
        throw std::runtime_error("Valor de depósito negativo");
    }
    _balance += amount;
}

void Bankaccount::withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    check_open();
    if (amount < 0 || amount > _balance) {
        throw std::runtime_error("Valor de saque inválido ou saldo insuficiente");
    }
    _balance -= amount;
}

void Bankaccount::check_open() const {
    if (!_is_open) {
        throw std::runtime_error("A conta não está aberta");
    }
}

}  // namespace Bankaccount