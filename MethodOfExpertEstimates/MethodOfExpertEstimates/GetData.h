#pragma once

#include "Data.h"
#include <vector>

class CGetData
{
public:
    CGetData()
    {}
    void GetData(std::vector<CData>& arrData);

protected:
    void GetAnswer(const char* szMessage, const char* szError, int& nNumber,
        int nMin, int nMax = INT_MAX);
};
