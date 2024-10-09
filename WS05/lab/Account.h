    #ifndef SENECA_ACCOUNT_H_
    #define SENECA_ACCOUNT_H_
    #include <iostream>

    namespace seneca {
       class Account {
          int m_number;
          double m_balance; 
          void setEmpty();
       public:
          Account();
          Account(int number, double balance);
          std::ostream& display()const;



          explicit operator bool() const; 
          explicit operator double() const; 
          bool operator~() const;

          Account& operator =(int number);
          Account& operator = (Account& other);
          Account& operator >> (Account& other);
          Account& operator << (Account& other);
          Account& operator += (double amount);
          Account& operator -= (double amount);
          Account operator+(const Account& other) const;

       };


    }
    #endif // SENECA_ACCOUNT_H_