#pragma once

#include <mutex>

namespace bank_account {

    class BankAccount {
    public:
        BankAccount();

        void open();
        void close();
        void deposit(int amount);
        void withdraw(int amount);
        int balance() const;

    private:
        mutable std::mutex mtx; // Mutex para garantir acesso exclusivo
        int _balance;
        bool _is_open;

        void check_open() const; // Função auxiliar para validar o estado
    };

}  // namespace bank_account