#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const
   {
       return m_number >= 1000 && m_number <= 9999 && m_balance > 0;
   }


   Account::operator double() const
   {
       return m_balance;
   }
   bool Account::operator~() const {
       return m_number == 0;
    }
 
   // Assign a new account number
   Account& Account::operator=(int number) {
       if (number >= 10000 && number <= 99999) {
           m_number = number;
           m_balance = 0.0;
       }
       return *this;
   }

   // Assign an account to another account
   Account& Account::operator=(Account& other) {
       if (this != &other && other) {  // Ensure not self-assignment and valid account
           m_number = other.m_number;
           m_balance = other.m_balance;
       }
       return *this;
   }

   // Move funds from one account to another (>>) 
   Account& Account::operator>>(Account& other) {
       if (this != &other && *this && other) {  // Valid accounts and not the same
           other.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   // Move funds from another account (<<) 
   Account& Account::operator<<(Account& other) {
       if (this != &other && *this && other) {  // Valid accounts and not the same
           m_balance += other.m_balance;
           other.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator+=(double amount)
   {
           if ( *this) {  // Ensure the amount is positive and the account is valid
               m_balance += amount;
           }
           return *this;
    

   }
   Account& Account::operator-=(double amount)
   {
       if (amount > 0 && m_balance >= amount && *this) {  // Ensure sufficient balance and valid account
           m_balance -= amount;
       }
       return *this;
   }
   Account Account::operator+(const Account& other) const
   {
     
           Account temp = *this;
           if (temp && other) {
               temp.m_balance += other.m_balance;
           }
           return temp;
   
   }
}