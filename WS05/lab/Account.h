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

          operator bool() const;
          operator int() const;
          operator double() const;

          bool operator~() const;

          Account& operator=(int);
          Account& operator=(const Account&);

          Account& operator+=(double);
          Account& operator-=(double);
          Account& operator<<(Account&);
          Account& operator>>(Account&);

          friend double operator+(const Account&, const Account&);
          friend double& operator+=(double&, const Account&);
       };




    }
    #endif // SENECA_ACCOUNT_H_