#pragma once

#include "Data.h"
#include "CalcData.h"
#include <vector>

class CCalculateAlg
{
public:    
    CCalculateAlg(int nSubjects) :
        m_arrCalcData(nSubjects)
    {}

    void Calculate(std::vector<CData>& arrData);
    const std::vector<CCalcData>& GetResults() const
    {
        return m_arrCalcData;
    }

protected:
    std::vector<CCalcData> m_arrCalcData;

    void CalculateValues(CData& data) const;
    void ImportenceOfCriterion(const std::vector<CData>& arrData);
    void SortArrayDescending(bool bImportance);
    void Ranking();
};