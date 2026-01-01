#include <ta-lib/ta_libc.h>

#include <vector>
#include <iostream>
#include <iomanip>

int main() {
    // Initialize TA-Lib
    if (TA_Initialize() != TA_SUCCESS) {
        std::cerr << "TA-Lib initialization failed\n";
        return 1;
    }

    // Sample price data (e.g. closing prices)
    std::vector<double> prices = {
        44.34, 44.09, 44.15, 43.61, 44.33, 44.83, 45.10,
        45.42, 45.84, 46.08, 45.89, 46.03, 45.61, 46.28,
        46.28, 46.00, 46.03, 46.41, 46.22, 45.64
    };

    int startIdx = 0;
    int endIdx   = static_cast<int>(prices.size()) - 1;

    /* ---------- SMA ---------- */
    int outBeg = 0;
    int outNb  = 0;

    std::vector<double> sma(prices.size());

    TA_RetCode rc = TA_SMA(
        startIdx,
        endIdx,
        prices.data(),
        5,                  // time period
        &outBeg,
        &outNb,
        sma.data()
    );

    if (rc != TA_SUCCESS) {
        std::cerr << "TA_SMA failed\n";
        return 1;
    }

    std::cout << "SMA(5):\n";
    for (int i = 0; i < outNb; ++i) {
        int priceIdx = outBeg + i;
        std::cout << "  idx=" << priceIdx
                  << " price=" << prices[priceIdx]
                  << " sma=" << std::fixed << std::setprecision(2)
                  << sma[i] << "\n";
    }

    /* ---------- RSI ---------- */
    outBeg = 0;
    outNb  = 0;

    std::vector<double> rsi(prices.size());

    rc = TA_RSI(
        startIdx,
        endIdx,
        prices.data(),
        14,                 // RSI period
        &outBeg,
        &outNb,
        rsi.data()
    );

    if (rc != TA_SUCCESS) {
        std::cerr << "TA_RSI failed\n";
        return 1;
    }

    std::cout << "\nRSI(14):\n";
    for (int i = 0; i < outNb; ++i) {
        int priceIdx = outBeg + i;
        std::cout << "  idx=" << priceIdx
                  << " rsi=" << std::fixed << std::setprecision(2)
                  << rsi[i] << "\n";
    }

    TA_Shutdown();
    return 0;
}
