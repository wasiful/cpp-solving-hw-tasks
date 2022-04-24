#ifndef __PROGTEST__
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
using namespace std;
#endif /* __PROGTEST__ */

struct companyData
{
    string Name;
    string Addr;
    string TaxID;
    int Amount;
    int SumIncome;
};

class CVATRegister
{
public:
    CVATRegister(void) {}
    ~CVATRegister(void) {}

    // Function to Create new Company

    string loAns(string lAnswer)
    {
        transform(lAnswer.begin(), lAnswer.end(), lAnswer.begin(), ::tolower);
        return lAnswer;
    }

    bool newCompany(const string &name, const string &addr, const string &taxID)
    {
        string newName = loAns(name);
        string newAddr = loAns(addr);

        for (list<companyData>::iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            if (comp->TaxID == taxID)
            {
                return false;
            }
            else if (loAns(comp->Name) == newName && loAns(comp->Addr) == newAddr)
            {
                return false;
            }
        }

        struct companyData company;
        company.Name = name;
        company.Addr = addr;
        company.TaxID = taxID;
        company.Amount = 0;
        company.SumIncome = 0;

        registry.push_back(company);

        if (sizeof(registry) >= 2)
        {
            struct LastNameComp
            {
                bool operator()(const companyData &a, const companyData &b) const
                {
                    if (a.Name.compare(b.Name) == 0)
                    {
                        if (a.Addr.compare(b.Addr) < 0)
                        {
                            return true;
                        }
                        return false;
                    }
                    if (a.Name.compare(b.Name) < 0)
                    {
                        return true;
                    }
                    return false;
                }
            };
            registry.sort(LastNameComp());
        }
        return true;
    }

    bool cancelCompany(const string &name, const string &addr)
    {
        for (list<companyData>::iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            if (loAns(comp->Name) == loAns(name) && loAns(comp->Addr) == loAns(addr))
            {
                registry.erase(comp);
                return true;
            }
        }
        return false;
    }
    bool cancelCompany(const string &taxID)
    {

        for (list<companyData>::iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            if (comp->TaxID == taxID)
            {
                registry.erase(comp);
                return true;
            }
        }
        return false;
    }
    bool invoice(const string &taxID, unsigned int amount)
    {
        for (list<companyData>::iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            if (comp->TaxID == taxID)
            {
                comp->Amount = amount;
                comp->SumIncome = amount + comp->SumIncome;
                allInvoices.push_back(amount);
                sort(allInvoices.begin(), allInvoices.end());
                return true;
            }
        }
        return false;
    }
    bool invoice(const string &name, const string &addr, unsigned int amount)
    {
        for (list<companyData>::iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            if (loAns(comp->Name) == loAns(name) && loAns(comp->Addr) == loAns(addr))
            {
                comp->Amount = amount;
                comp->SumIncome = amount + comp->SumIncome;
                allInvoices.push_back(amount);
                sort(allInvoices.begin(), allInvoices.end());
                return true;
            }
        }
        return false;
    }
    bool audit(const string &name, const string &addr, unsigned int &sumIncome) const
    {

        string auditName = name;
        string auditAddr = addr;

        transform(auditName.begin(), auditName.end(), auditName.begin(), ::tolower);
        transform(auditAddr.begin(), auditAddr.end(), auditAddr.begin(), ::tolower);

        for (list<companyData>::const_iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            string Name = comp->Name;
            string Addr = comp->Addr;

            transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
            transform(Addr.begin(), Addr.end(), Addr.begin(), ::tolower);

            if (Name == auditName && Addr == auditAddr)
            {
                unsigned int compSumIncome = comp->SumIncome;
                sumIncome = compSumIncome;
                return true;
            }
        }
        return false;
    }
    bool audit(const string &taxID, unsigned int &sumIncome) const
    {

        // string auditTax = taxId;

        for (list<companyData>::const_iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            string auditTax = comp->TaxID;

            if (comp->TaxID == taxID)
            {
                unsigned int compSumIncome = comp->SumIncome;
                sumIncome = compSumIncome;
                return true;
            }
        }
        return false;
    }
    bool firstCompany(string &name, string &addr) const
    {
        if (sizeof(registry) == 0)
        {
            return false;
        }

        for (list<companyData>::const_iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            string firstCompName = comp->Name;
            string firstCompAddr = comp->Addr;
            name = firstCompName;
            addr = firstCompAddr;

            return true;
        }
        return false;
    }
    bool nextCompany(string &name, string &addr) const
    {
        string searchName = name;
        string searchAddr = addr;

        transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
        transform(searchAddr.begin(), searchAddr.end(), searchAddr.begin(), ::tolower);
        bool found = false;

        for (list<companyData>::const_iterator comp = registry.begin(); comp != registry.end(); comp++)
        {
            if (found == true)
            {
                string nextCompName = comp->Name;
                string nextCompAddr = comp->Addr;
                name = nextCompName;
                addr = nextCompAddr;
                return true;
            }

            string Name = comp->Name;
            string Addr = comp->Addr;

            transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
            transform(Addr.begin(), Addr.end(), Addr.begin(), ::tolower);

            if (Name == searchName && Addr == searchAddr)
            {
                found = true;
            }
        }
        return false;
    }
    unsigned int medianInvoice(void) const
    {
        // for (std::vector<unsigned int>::const_iterator i = allInvoices.begin(); i != allInvoices.end(); ++i)
        // {
        //     cout << *i << ' ';
        // }
        if (allInvoices.size() == 0)
        {
            unsigned int medianInvoice = 0;
            // cout << "Current Median is " << medianInvoice << endl;
            return medianInvoice;
        }
        else
        {
            unsigned int medianInvoice = allInvoices[allInvoices.size() / 2];
            // cout << "Current Median is " << medianInvoice << endl;

            return medianInvoice;
        }
    }

private:
    // todo
    std::list<struct companyData> registry;
    vector<unsigned int> allInvoices;
};

#ifndef __PROGTEST__
int main(void)
{
    string name, addr;
    unsigned int sumIncome;

    CVATRegister b1;
    assert(b1.newCompany("ACME", "Thakurova", "666/666"));
    assert(b1.newCompany("ACME", "Kolejni", "666/666/666"));
    assert(b1.newCompany("Dummy", "Thakurova", "123456"));
    assert(b1.invoice("666/666", 2000));
    assert(b1.medianInvoice() == 2000);
    assert(b1.invoice("666/666/666", 3000));
    assert(b1.medianInvoice() == 3000);
    assert(b1.invoice("123456", 4000));
    assert(b1.medianInvoice() == 3000);
    assert(b1.invoice("aCmE", "Kolejni", 5000));
    assert(b1.medianInvoice() == 4000);
    assert(b1.audit("ACME", "Kolejni", sumIncome) && sumIncome == 8000);
    assert(b1.audit("123456", sumIncome) && sumIncome == 4000);
    assert(b1.firstCompany(name, addr) && name == "ACME" && addr == "Kolejni");
    assert(b1.nextCompany(name, addr) && name == "ACME" && addr == "Thakurova");
    assert(b1.nextCompany(name, addr) && name == "Dummy" && addr == "Thakurova");
    assert(!b1.nextCompany(name, addr));
    assert(b1.cancelCompany("ACME", "KoLeJnI"));
    assert(b1.medianInvoice() == 4000);
    assert(b1.cancelCompany("666/666"));
    assert(b1.medianInvoice() == 4000);
    assert(b1.invoice("123456", 100));
    assert(b1.medianInvoice() == 3000);
    assert(b1.invoice("123456", 300));
    assert(b1.medianInvoice() == 3000);
    assert(b1.invoice("123456", 200));
    assert(b1.medianInvoice() == 2000);
    assert(b1.invoice("123456", 230));
    assert(b1.medianInvoice() == 2000);
    assert(b1.invoice("123456", 830));
    assert(b1.medianInvoice() == 830);
    assert(b1.invoice("123456", 1830));
    assert(b1.medianInvoice() == 1830);
    assert(b1.invoice("123456", 2830));
    assert(b1.medianInvoice() == 1830);
    assert(b1.invoice("123456", 2830));
    assert(b1.medianInvoice() == 2000);
    assert(b1.invoice("123456", 3200));
    assert(b1.medianInvoice() == 2000);
    assert(b1.firstCompany(name, addr) && name == "Dummy" && addr == "Thakurova");
    assert(!b1.nextCompany(name, addr));
    assert(b1.cancelCompany("123456"));
    assert(!b1.firstCompany(name, addr));

    CVATRegister b2;
    assert(b2.newCompany("ACME", "Kolejni", "abcdef"));
    assert(b2.newCompany("Dummy", "Kolejni", "123456"));
    assert(!b2.newCompany("AcMe", "kOlEjNi", "1234"));
    assert(b2.newCompany("Dummy", "Thakurova", "ABCDEF"));
    assert(b2.medianInvoice() == 0);
    assert(b2.invoice("ABCDEF", 1000));
    assert(b2.medianInvoice() == 1000);
    assert(b2.invoice("abcdef", 2000));
    assert(b2.medianInvoice() == 2000);
    assert(b2.invoice("aCMe", "kOlEjNi", 3000));
    assert(b2.medianInvoice() == 2000);
    assert(!b2.invoice("1234567", 100));
    assert(!b2.invoice("ACE", "Kolejni", 100));
    assert(!b2.invoice("ACME", "Thakurova", 100));
    assert(!b2.audit("1234567", sumIncome));
    assert(!b2.audit("ACE", "Kolejni", sumIncome));
    assert(!b2.audit("ACME", "Thakurova", sumIncome));
    assert(!b2.cancelCompany("1234567"));
    assert(!b2.cancelCompany("ACE", "Kolejni"));
    assert(!b2.cancelCompany("ACME", "Thakurova"));
    assert(b2.cancelCompany("abcdef"));
    assert(b2.medianInvoice() == 2000);
    assert(!b2.cancelCompany("abcdef"));
    assert(b2.newCompany("ACME", "Kolejni", "abcdef"));
    assert(b2.cancelCompany("ACME", "Kolejni"));
    assert(!b2.cancelCompany("ACME", "Kolejni"));

    return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */