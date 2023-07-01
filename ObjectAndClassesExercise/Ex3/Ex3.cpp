#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

class Sale
{
    string m_strTown;
    string m_strProduct;
    double m_dPrice;
    double m_dQuantity;

public:

    Sale(string strTown, string strProduct, double dPrice, double dQuantity)
        : m_strTown(strTown)
        , m_strProduct(strProduct)
        , m_dPrice(dPrice)
        , m_dQuantity(dQuantity)
    {
    }

    ~Sale()
    {
    }

    double GetTotalPrice()
    {
        return m_dPrice * m_dQuantity;
    }

    string GetTown()
    {
        return m_strTown;
    }
        
};

int main()
{
    size_t nSalesCount = 0;
    cin >> nSalesCount;

    map<string, double> oSales;

    for (size_t i = 0; i < nSalesCount; i++)
    {
        string strTown, strProduct;
        double dPrice = 0, dQuantity = 0;

        cin >> strTown >> strProduct >> dPrice >> dQuantity;

        Sale oSale(strTown, strProduct, dPrice, dQuantity);

        if (oSales.find(oSale.GetTown()) == oSales.end())
            oSales[oSale.GetTown()] = oSale.GetTotalPrice();
        else
            oSales[oSale.GetTown()] += oSale.GetTotalPrice();
    }

    for (auto El : oSales)
    {
        cout << fixed << setprecision(2) << El.first << " -> " << El.second << endl;
    }
    return 0;
}
