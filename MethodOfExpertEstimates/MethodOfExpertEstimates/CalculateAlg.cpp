#include "CalculateAlg.h"

void CCalculateAlg::Calculate(std::vector<CData>& arrData)
{
    for (std::vector<CData>::iterator iter = arrData.begin(); iter < arrData.end(); iter++)
    {
        CalculateValues(*iter);
    }

    ImportenceOfCriterion(arrData);

    SortArrayDescending(true);

    Ranking();

    SortArrayDescending(false);
}

void CCalculateAlg::CalculateValues(CData& data) const
{
    double dEducationalExperience = 0;
    double dPracticalExperience = 0;
    double dLaborMarketRequirements = 0;
    double dIntuition = 0;

    if (data.m_nEducationalExperience == 1)
        dEducationalExperience = 0.3;
    else if (data.m_nEducationalExperience == 2)
        dEducationalExperience = 0.1;
    else if (data.m_nEducationalExperience == 3)
        dEducationalExperience = 0.2;

    if (data.m_nPracticalExperience == 1)
        dPracticalExperience = 0.5;
    else if (data.m_nPracticalExperience == 2)
        dPracticalExperience = 0.2;
    else if (data.m_nPracticalExperience == 3)
        dPracticalExperience = 0.4;

    if (data.m_nLaborMarketRequirements == 1)
        dLaborMarketRequirements = 0.1;
    else if (data.m_nLaborMarketRequirements == 2)
        dLaborMarketRequirements = 0.04;
    else if (data.m_nLaborMarketRequirements == 3)
        dLaborMarketRequirements = 0.08;

    if (data.m_nIntuition == 1)
        dIntuition = 0.05;
    else if (data.m_nIntuition == 2)
        dIntuition = 0.02;
    else if (data.m_nIntuition == 3)
        dIntuition = 0.04;

    data.m_dCompetenceLevel = (data.m_nKnowProblem * 0.1 + dEducationalExperience + dPracticalExperience + dLaborMarketRequirements + dIntuition) / 2;
}

void CCalculateAlg::ImportenceOfCriterion(const std::vector<CData>& arrData)
{
    int i = 0;

    for (std::vector<CCalcData>::iterator iter1 = m_arrCalcData.begin();
        iter1 < m_arrCalcData.end(); iter1++, i++)
    {
        iter1->m_nIndex = i;
        for (std::vector<CData>::const_iterator iter2 = arrData.begin(); iter2 < arrData.end(); iter2++)
        {
            iter1->m_dImportenceCriterion += iter2->m_dCompetenceLevel * iter2->m_arrSubject[i];
        }

        iter1->m_dImportenceCriterion /= arrData.size();
    }
}

void CCalculateAlg::SortArrayDescending(bool bImportance)
{
    for (unsigned int i = 0; i < m_arrCalcData.size() - 1; i++)
    {
        for (unsigned int j = 0; j < m_arrCalcData.size() - i - 1; j++)
        {
            if (bImportance && (m_arrCalcData[j].m_dImportenceCriterion < m_arrCalcData[j + 1].m_dImportenceCriterion) ||
                !bImportance && (m_arrCalcData[j].m_dRankCriterion < m_arrCalcData[j + 1].m_dRankCriterion))
            {
                CCalcData calcData = m_arrCalcData[j];
                m_arrCalcData[j] = m_arrCalcData[j + 1];
                m_arrCalcData[j + 1] = calcData;
            }
        }
    }
}

void CCalculateAlg::Ranking()
{
    int i = 1;

    for (std::vector<CCalcData>::iterator iter = m_arrCalcData.begin();
        iter < m_arrCalcData.end(); iter++, i++)
    {
        iter->m_dRankCriterion = ((double)m_arrCalcData.size() + 1 - i) / (m_arrCalcData.size() * (m_arrCalcData.size() + 1)) * 2;
    }
}


