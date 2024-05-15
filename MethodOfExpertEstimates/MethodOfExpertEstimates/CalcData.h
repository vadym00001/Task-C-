#pragma once

class CCalcData
{
public:
    CCalcData() :
        m_nIndex(0),
        m_dImportenceCriterion(0),
        m_dRankCriterion(0)
    {}

    int m_nIndex;
    double m_dImportenceCriterion;
    double m_dRankCriterion;
};